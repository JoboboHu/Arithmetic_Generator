#include "expression_factory.h"
#include "add_sub_expression.h"


expression_factory::expression_factory()
{
}


expression_factory::~expression_factory()
{
}

def_expression_ptr expression_factory::create_expression(expression_type type)
{
	switch (type)
	{
	case addition_subtraction:
		return std::tr1::make_shared<add_sub_expression>();
	default:
		break;
	}
	return def_expression_ptr(nullptr);
}
