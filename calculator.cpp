#include "calculator.h"
#include "./ui_calculator.h"
#include <QtMath>
#include <iostream>

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

    m_currentOperation = Operation::None;

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

void Calculator::on_button_sin_clicked()
{
    m_currentOperation = Operation::Sin;
    on_button_equals_clicked();
}

void Calculator::on_button_cos_clicked()
{
    m_currentOperation = Operation::Cos;
    on_button_equals_clicked();
}

void Calculator::on_button_tan_clicked()
{
    m_currentOperation = Operation::Tan;
    on_button_equals_clicked();
}

void Calculator::on_button_derivatives_clicked()
{
    if(!m_startingNewValue)
    {
        SavePolynomial();
        m_currentOperation = Operation::Derivative;
    }
    else
    {
        calcDerivative();
    }

}
void Calculator::SavePolynomial()
{
    std::string polynomial = ui->results_display->toPlainText().toStdString();
    m_polynomial = std::stoi(polynomial);
    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);
    m_exponent = std::stoi(polynomial);


}

void Calculator::on_button_integral_clicked()
{
    if(!m_startingNewValue)
    {
        SavePolynomial();
        m_currentOperation = Operation::Integral;
    }
    else
    {
        calcIntegral();
    }

}

void Calculator::on_button_factorial_clicked()
{
    m_currentOperation = Operation::Factorial;
    on_button_equals_clicked();
}

void Calculator::on_button_sqroot_clicked()
{
    m_currentOperation = Operation::Sqrt;
    on_button_equals_clicked();
}

void Calculator::on_button_x_y_power_clicked()
{
    ui->results_display->insertPlainText("^");
    if(!ui->results_display->toPlainText().contains("x"))
    {
        on_button_equals_clicked();
        m_currentOperation = Operation::Power;
    }
}

void Calculator::on_button_xsquared_clicked()
{
    ui->results_display->insertPlainText("^2");
    if(!ui->results_display->toPlainText().contains("x"))
    {
        on_button_equals_clicked();
        m_currentOperation = Operation::Sqrd;
    }
}

void Calculator::on_button_x_clicked()
{
    if (m_startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("x");
    m_value = ui->results_display->toPlainText().toDouble();
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
        case Operation::Factorial:
        {
            m_savedNumber = CalcFactorial();
            m_value = m_savedNumber;
            break;
        }
        case Operation::Sin:
        {
            m_savedNumber = qSin(qreal(m_value));
            m_value = m_savedNumber;
            break;
        }
        case Operation::Cos:
        {
            m_savedNumber = qCos(qreal(m_value));
            m_value = m_savedNumber;
            break;
        }
        case Operation::Tan:
        {
            m_savedNumber = qTan(qreal(m_value));
            m_value = m_savedNumber;
            break;
        }
        case Operation::Sqrt:
        {
            m_savedNumber = qSqrt(m_value);
            m_value = m_savedNumber;
            break;
        }
        case Operation::Sqrd:
        {
            m_savedNumber = m_value * m_value;
            m_value = m_savedNumber;
            break;
        }
        case Operation::Power:
        {
            m_savedNumber = qPow(m_savedNumber, m_value);
            m_value = m_savedNumber;
            break;
        }
        case Operation::Derivative:
        {
            m_savedNumber = calcDerivative();
            m_value = m_savedNumber;
            break;
        }
        case Operation::Integral:
        {
            m_savedNumber = calcIntegral();
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

int Calculator::CalcFactorial()
{
    int fact = 1;

    if (m_value == 0)
        return fact;

    for (int i = 1; i <= m_value; i++)
        fact = fact * i;

    return fact;
}
double Calculator::calcDerivative() // need to store user input of constant and exponent in an array?
{

    double coefficient = m_polynomial;
    double exponent = m_exponent;

    m_value = ui->results_display->toPlainText().toDouble();
    double answer = (coefficient*m_exponent)*pow(m_value, m_exponent-1);

    return answer;

}
double Calculator::calcIntegral()
{

    double coefficient = m_polynomial;
    double exponent = m_exponent;

    m_value = ui->results_display->toPlainText().toDouble();
    double answer = (coefficient/(m_exponent+1))*pow(m_value, m_exponent+1);

    return answer;

}

