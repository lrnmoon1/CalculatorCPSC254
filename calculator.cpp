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

void Calculator::on_button_1_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("1");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_2_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("2");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_3_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("3");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_4_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("4");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_5_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("5");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_6_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("6");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_7_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("7");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_8_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("8");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_9_clicked()
{
    if (startingNewValue)
        StartNewValue();

    ui->results_display->insertPlainText("9");
    value = ui->results_display->toPlainText().toDouble();
}

void Calculator::on_button_clear_clicked()
{
    value = 0;
    savedNumber = 0;

    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);
}

void Calculator::on_button_pos_neg_clicked()
{
    value *= -1;

    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);

    ui->results_display->insertPlainText(QString::number(value));
}

void Calculator::on_button_plus_clicked()
{
    savedNumber += value;
    value = savedNumber;

    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);
    ui->results_display->insertPlainText(QString::number(value));

    startingNewValue = true;
}

void Calculator::StartNewValue()
{
    ui->results_display->clear();
    ui->results_display->setAlignment(Qt::AlignRight);

    value = 0;
    startingNewValue = false;
}

