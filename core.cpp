#include "core.h"

Core::Core()
	: result(0.0), op(NONE)
{
}

Core::~Core()
{
}

double Core::expr(const QString &rhs)
{
	switch (op) {
	case SUM: result += rhs.toDouble();
		break;
	case SUB: result -= rhs.toDouble();
		break;
	case MUL: result *= rhs.toDouble();
		break;
	case DIV: result /= rhs.toDouble();
		break;
	case NONE: result = rhs.toDouble();
//		ui.input->setText("");
	}
	return result;
}

void Core::setOp(char c) {
	switch (c) {
	case '+': op = SUM;
		break;
	case '-': op = SUB;
		break;
	case '*': op = MUL;
		break;
	case '/': op = DIV;
		break;
	default:  op = NONE;
	}
}

void Core::clear()
{
	result = 0.0;
	op = NONE;
}