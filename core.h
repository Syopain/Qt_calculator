#ifndef CORE_H
#define CORE_H

#include <QString>

class Core {
public:
	Core();
	~Core();

	double expr(const QString &rhs);
	void clear();
	void setOp(char c);
	bool is_none() {
		return op == NONE; }

private:
	double result;
	enum {
		NONE = 0, SUM, SUB, MUL, DIV
	}op;
};

#endif // CORE_H