#include "calculator.h"
#include <algorithm>

Calculator::Calculator(QWidget *parent)
    : QDialog(parent), istr("")
{
    ui.setupUi(this);
}

Calculator::~Calculator()
{

}

void Calculator::on_btn_0_clicked()
{
    if (istr.size() == 1 && istr[0] == '0')
        return;
    ui.output->setText(istr += "0");
}

void Calculator::on_btn_1_clicked()
{
    ui.output->setText(istr += "1");
}

void Calculator::on_btn_2_clicked()
{
    ui.output->setText(istr += "2");
}

void Calculator::on_btn_3_clicked()
{
    ui.output->setText(istr += "3");
}

void Calculator::on_btn_4_clicked()
{
    ui.output->setText(istr += "4");
}

void Calculator::on_btn_5_clicked()
{
    ui.output->setText(istr += "5");
}

void Calculator::on_btn_6_clicked()
{
    ui.output->setText(istr += "6");
}

void Calculator::on_btn_7_clicked()
{
    ui.output->setText(istr += "7");
}

void Calculator::on_btn_8_clicked()
{
    ui.output->setText(istr += "8");
}

void Calculator::on_btn_9_clicked()
{
    ui.output->setText(istr += "9");
}

void Calculator::on_btn_dot_clicked()
{
    if (std::find(istr.begin(), istr.end(), '.') == istr.end()) {
        if (istr.size() == 0)
            istr += "0";
        ui.output->setText(istr += ".");
    }
}

void Calculator::on_btn_add_clicked()
{
    if(core.is_none())
        ui.input->setText("");
    ui.input->setText(ui.input->text() +
                      ui.output->text() +
                      u8"<font color=#F57A75 size=4> + </font>"
                     );
    ui.output->setText(QString::number(core.expr(ui.output->text()), 'g', 9));
    istr.clear();
    core.setOp('+');
}

void Calculator::on_btn_sub_clicked()
{
    if (core.is_none())
        ui.input->setText("");
    ui.input->setText(ui.input->text() +
                      ui.output->text() +
                      u8"<font color=#F57A75 size=4> - </font>"
                     );
    ui.output->setText(QString::number(core.expr(ui.output->text()), 'g', 9));
    istr.clear();
    core.setOp('-');
}

void Calculator::on_btn_mul_clicked()
{
    if (core.is_none())
        ui.input->setText("");
    ui.input->setText(ui.input->text() +
                      ui.output->text() +
                      u8"<font color=#F57A75 size=4> × </font>"
                     );
    ui.output->setText(QString::number(core.expr(ui.output->text()), 'g', 9));
    istr.clear();
    core.setOp('*');
}

void Calculator::on_btn_div_clicked()
{
    if (core.is_none())
        ui.input->setText("");
    ui.input->setText(ui.input->text() +
                      ui.output->text() +
                      u8"<font color=#F57A75 size=4> ÷ </font>"
                     );
    ui.output->setText(QString::number(core.expr(ui.output->text()), 'g', 9));
    istr.clear();
    core.setOp('/');
}

void Calculator::on_btn_del_clicked()
{
    istr.chop(1);
    if (istr.size() == 0 || ((istr.size() == 1) && (istr[0] == '0'))) {
        ui.output->setText("0");
        istr.clear();
        return;
    }
    ui.output->setText(istr);
}

void Calculator::on_btn_sign_clicked()
{
    if(istr.size()) {
        if (istr[0] != '-')
            ui.output->setText(istr = "-" + istr);
        else {
            istr.remove(0, 1);
            ui.output->setText(istr);
        }
    }
}

void Calculator::on_btn_equal_clicked()
{
    if (core.is_none())
        return;
    ui.input->setText(ui.input->text() +
                      ui.output->text() +
                      "<font color=#F57A75 size=4> = </font>"
                     );
    ui.output->setText(QString::number(core.expr(ui.output->text()), 'g', 9));
    clear();
}

void Calculator::on_btn_clear_clicked()
{
    ui.input->setText("");
    ui.output->setText("0");
    clear();
}
