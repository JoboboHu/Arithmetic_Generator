// Arithmetic_Generator.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "../include/gflags/gflags.h"
#include <iostream>
#include <time.h>
#include "expression_factory.h"
#include <fstream>

DEFINE_int32(n, 100, "expression count");
DEFINE_string(t, "txt", "output file type: \"txt\" or \"csv\"");

using namespace std;



void output_txt(const vector<def_expression_ptr>& vec_expressions)
{
	char path_buffer_answer[_MAX_PATH];
	char path_buffer_expression[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	char* path = nullptr;
	_get_pgmptr(&path);
	_splitpath_s(path, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

	_makepath_s(path_buffer_answer, _MAX_PATH, drive, dir, "answer", "txt");
	_makepath_s(path_buffer_expression, _MAX_PATH, drive, dir, "expression", "txt");

	ofstream ofs_answer(path_buffer_answer);
	ofstream ofs_expression(path_buffer_expression);
	for (auto item : vec_expressions)
	{
		auto num = item->get_num();
		auto opr = item->get_opr();

		ofs_answer << num[0] << opr[0] << num[1] << opr[1] << num[2] << "=" << item->get_result() << endl;
		ofs_expression << num[0] << opr[0] << num[1] << opr[1] << num[2] << "=" << endl;
	}
	ofs_answer.close();
	ofs_expression.close();
}

void output_csv(const vector<def_expression_ptr>& vec_expressions)
{
	char path_buffer_answer[_MAX_PATH];
	char path_buffer_expression[_MAX_PATH];
	char drive[_MAX_DRIVE];
	char dir[_MAX_DIR];
	char fname[_MAX_FNAME];
	char ext[_MAX_EXT];
	char* path = nullptr;
	_get_pgmptr(&path);
	_splitpath_s(path, drive, _MAX_DRIVE, dir, _MAX_DIR, fname, _MAX_FNAME, ext, _MAX_EXT);

	_makepath_s(path_buffer_answer, _MAX_PATH, drive, dir, "answer", "csv");
	_makepath_s(path_buffer_expression, _MAX_PATH, drive, dir, "expression", "csv");

	ofstream ofs_answer(path_buffer_answer);
	ofstream ofs_expression(path_buffer_expression);
	for (auto item : vec_expressions)
	{
		auto num = item->get_num();
		auto opr = item->get_opr();

		ofs_answer << num[0] << "," << opr[0] << "," << num[1] << "," << opr[1] << "," << num[2] << "," << "=," 
			<< item->get_result() << endl;
		ofs_expression << num[0] << "," << opr[0] << "," << num[1] << "," << opr[1] << "," << num[2] << "," << "=" << endl;
	}
	ofs_answer.close();
	ofs_expression.close();
}

void create_math_question(const int expression_count, const string& output_type)
{
	srand((int)time(0));

	vector<def_expression_ptr> vec_expressions;
	for (int i = 0; i < expression_count; ++i)
	{
		while (true)
		{
			bool flag = true;
			auto expression = expression_factory::create_expression(addition_subtraction);
			expression->create_expression();
			for (auto item : vec_expressions)
			{
				if (item == expression)
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				continue;
			vec_expressions.push_back(expression);
			break;
		}
	}

	if (output_type.compare("txt") == 0)
		output_txt(vec_expressions);
	else if (output_type.compare("csv") == 0)
		output_csv(vec_expressions);
}

int main(int argc, char* argv[])
{
	google::ParseCommandLineFlags(&argc, &argv, true);
	int expression_count = FLAGS_n;
	std::string output_type = FLAGS_t;
	if (output_type.compare("txt") != 0 && output_type.compare("csv") != 0)
	{
		cout << "output file type error!" << endl;
		return 1;
	}
	
	create_math_question(expression_count, output_type);
	cout << "finish" << endl;
	getchar();
    return 0;
}

