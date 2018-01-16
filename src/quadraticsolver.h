#ifndef QUADRATICSOLVER_H
#define QUADRATICSOLVER_H

#include <QWidget>

namespace Ui {
class QuadraticSolver;
}

class QuadraticSolver : public QWidget
{
    Q_OBJECT

public:
    explicit QuadraticSolver(QWidget *parent = 0);
    ~QuadraticSolver();

private slots:
    void on_pushButton_clicked();

private:
    Ui::QuadraticSolver *ui;
};

#endif // QUADRATICSOLVER_H
