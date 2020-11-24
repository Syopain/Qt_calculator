#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QtWidgets/QDialog>
#include "ui_calculator.h"
#include "core.h"

class Calculator : public QDialog
{
	Q_OBJECT

public:
	Calculator(QWidget *parent = 0);
	~Calculator();

private:
	Ui::CalculatorClass ui;
	Core core;

	QString istr;

	void clear() {
		istr.clear();
		core.clear();
	}

private slots:
	void on_btn_0_clicked();
	void on_btn_1_clicked();
	void on_btn_2_clicked();
	void on_btn_3_clicked();
	void on_btn_4_clicked();
	void on_btn_5_clicked();
	void on_btn_6_clicked();
	void on_btn_7_clicked();
	void on_btn_8_clicked();
	void on_btn_9_clicked();
	void on_btn_dot_clicked();
	void on_btn_add_clicked();
	void on_btn_sub_clicked();
	void on_btn_mul_clicked();
	void on_btn_div_clicked();
	void on_btn_del_clicked();
	void on_btn_sign_clicked();
	void on_btn_equal_clicked();
	void on_btn_clear_clicked();
};

#endif // CALCULATOR_H