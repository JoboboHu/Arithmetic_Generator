#pragma once
#include "arithmetic_expression.h"

class add_sub_expression
	: public arithmetic_expression
{
public:
	add_sub_expression();
	virtual ~add_sub_expression();

	virtual void create_expression();
	virtual bool operator==(arithmetic_expression* obj);

	virtual const int* get_num() { return num_; }
	virtual const char* get_opr() { return operator_; }
	virtual const int get_result() { return result_; }

private:
	int result_;
	int num_[3];
	char operator_[2];

	int calc(const int num_1, const int num_2, const char opr);
};

