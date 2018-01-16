
// Qt
#include <QProgressDialog>
#include <QThread>

// Local
#include "quadraticsolver.h"
#include "ui_quadraticsolver.h"
#include "worker.h"

QuadraticSolver::QuadraticSolver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QuadraticSolver)
{
    ui->setupUi(this);
}

QuadraticSolver::~QuadraticSolver()
{
    delete ui;
}

void QuadraticSolver::on_pushButton_clicked()
{
    // Create work
    QThread* th = new QThread;
    Worker* work = new Worker(ui->x2->value(),ui->x->value(),ui->x0->value(),ui->initial_condition->value());
    work->moveToThread(th);
    connect(th, SIGNAL(started()), work, SLOT(process()));
    connect(work, SIGNAL(finished()), th, SLOT(quit()));
    connect(work, SIGNAL(finished()), work, SLOT(deleteLater()));
    connect(th, SIGNAL(finished()), th, SLOT(deleteLater()));
    connect(work,SIGNAL(finished(double)),ui->initial_condition,SLOT(setValue(double)));

    // Create Progress Bar
    QProgressDialog* progress = new QProgressDialog("Solving...","",0,0);
    progress->setCancelButton(0);
    progress->setMaximum(0);
    progress->show();
    connect(th,SIGNAL(finished()),progress,SLOT(close()));
    connect(th,SIGNAL(finished()),progress,SLOT(deleteLater()));

    // Do work
    th->start();
}
