#pragma once
#include "arithmetic_expression.h"

class expression_factory
{
private:
	expression_factory();
	~expression_factory();

public:
	static def_expression_ptr create_expression(expression_type type);
};

