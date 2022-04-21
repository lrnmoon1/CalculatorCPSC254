#include "calculator.h"
#include "./ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->results_display->setAlignment(Qt::AlignRight);
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::on_button_0_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("0");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_1_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("1");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_2_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("2");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_3_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("3");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_4_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("4");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_5_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("5");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_6_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("6");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_7_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("7");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_8_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("8");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_9_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("9");
    m_value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_clear_clicked()
{
    m_value = 0;
    m_savedNumber = 0;

    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);
}

void Calculator::on_button_pos_neg_clicked()
{
    m_value *= -1;

    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);

    ui->results_display->insertPlainText(QString::number(m_value));
}

void Calculator::on_button_plus_clicked()
{
    on_button_equals_clicked();
    m_currentOperation = Operation::Add;
}

void Calculator::on_button_minus_clicked()
 {
    on_button_equals_clicked();
    m_currentOperation = Operation::Subtract;
 }

void Calculator::on_button_multiply_clicked()
{
    on_button_equals_clicked();
    m_currentOperation = Operation::Multiply;
}

void Calculator::on_button_divide_clicked()
{
    on_button_equals_clicked();
    m_currentOperation = Operation::Divide;
}

void Calculator::on_button_equals_clicked()
{
    if (m_startingNewValue)
        return;

    switch (m_currentOperation)
    {
        case Operation::None:
        {
            m_savedNumber = m_value;
            m_startingNewValue = true;
            return;
        }
        case Operation::Add:
        {
            m_savedNumber += m_value;
            m_value = m_savedNumber;
            break;
        }
        case Operation::Subtract:
        {
            m_savedNumber -= m_value;
            m_value = m_savedNumber;
            break;
        }
        case Operation::Multiply:
        {
            m_savedNumber *= m_value;
            m_value = m_savedNumber;
            break;
        }
        case Operation::Divide:
        {
            m_savedNumber /= m_value;
            m_value = m_savedNumber;
            break;
        }
    }

    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);
    ui->results_display->insertPlainText(QString::number(m_value));

    m_startingNewValue = true;
}

void Calculator::StartNewValue()
{
    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);

    m_value = 0;
    m_startingNewValue = false;
}
