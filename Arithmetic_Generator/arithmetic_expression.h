#pragma once
#include <vector>
#include <memory>

enum expression_type {
	addition_subtraction = 0
};

class arithmetic_expression
{
public:
	arithmetic_expression(const expression_type type);
	virtual ~arithmetic_expression();

	virtual void create_expression() = 0;
	virtual bool operator==(arithmetic_expression* obj) = 0;

	virtual const int* get_num() = 0;
	virtual const char* get_opr() = 0;
	virtual const int get_result() = 0;


	const expression_type get_type() const { return type_; }
private:
	expression_type type_;
};

typedef std::tr1::shared_ptr<arithmetic_expression> def_expression_ptr;