#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

    enum Operation
    {
        None = 0,
        Add = 1,
        Subtract = 2,
        Multiply = 3,
        Divide = 4,
    };

private slots:
    void on_button_0_clicked();
    void on_button_1_clicked();
    void on_button_2_clicked();
    void on_button_3_clicked();
    void on_button_4_clicked();
    void on_button_5_clicked();
    void on_button_6_clicked();
    void on_button_7_clicked();
    void on_button_8_clicked();
    void on_button_9_clicked();

    void on_button_clear_clicked();
    void on_button_pos_neg_clicked();
    void on_button_plus_clicked();
    void on_button_minus_clicked();
    void on_button_multiply_clicked();
    void on_button_divide_clicked();
    void on_button_equals_clicked();

private:
    void StartNewValue();

private:
    Ui::Calculator *ui;
    double m_value = 0;
    double m_savedNumber = 0;
    bool m_startingNewValue = false;

    Operation m_currentOperation = Operation::None;


};
#endif // CALCULATOR_H
