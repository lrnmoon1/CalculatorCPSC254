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
    void on_button_mutiply_clicked();

private:
    void StartNewValue();

private:
    Ui::Calculator *ui;
    double value = 0;
    double multiplyValue = 1;
    double secondValue = 0;
    double savedNumber = 0;
    bool startingNewValue = false;
};
#endif // CALCULATOR_H
