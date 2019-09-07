#include "add_sub_expression.h"



add_sub_expression::add_sub_expression()
	: arithmetic_expression(addition_subtraction),
	result_(-1),
	num_{ -1,-1,-1 },
	operator_{ ' ', ' ' } 
{
}


add_sub_expression::~add_sub_expression()
{
}

void add_sub_expression::create_expression()
{
	while (true)
	{
		for (size_t i = 0; i < 2; ++i)
		{
			if (rand() % 2 == 0)
				operator_[i] = '+';
			else
				operator_[i] = '-';
		}
		for (size_t i = 0; i < 3; ++i)
		{
			num_[i] = rand() % 90 + 10;
		}

		int median = calc(num_[0], num_[1], operator_[0]);
		if (median < 0 || median >= 100)
			continue;

		result_ = calc(median, num_[2], operator_[1]);
		if (result_ < 0 || result_ >= 100)
			continue;

		break;
	}
}

bool add_sub_expression::operator==(arithmetic_expression * obj)
{
	if (obj->get_type() != addition_subtraction)
		return false;

	add_sub_expression* expression = (add_sub_expression*)obj;
	bool res = result_ == expression->result_;
	if (res)
	{
		for (size_t i = 0; i < 2; ++i)
		{
			if (operator_[i] != expression->operator_[i])
			{
				res = false;
				break;
			}
		}
	}
	if (res)
	{
		for (size_t i = 0; i < 3; ++i)
		{
			if (num_[i] != expression->operator_[i])
			{
				res = false;
				break;
			}
		}
	}
	return res;
}

int add_sub_expression::calc(const int num_1, const int num_2, const char opr)
{
	if (opr == '+')
		return num_1 + num_2;
	else
		return num_1 - num_2;
}
