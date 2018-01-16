#ifndef WORKER_H
#define WORKER_H

// Qt
#include <QObject>

// Ceres
#include <ceres/ceres.h>

// Local
#include "quadraticcostfunction.h"

class Worker: public QObject
{
    Q_OBJECT
public:
    Worker(double x2, double x, double x0, double initial_point);
    ~Worker();

public slots:
    void process();

signals:
    void start();
    void finished();
    void finished(double minimum);
    void iteration(int it, double value, double error);

private:
    double m_x2, m_x, m_x0, m_initial_point,m_minimum;
    QuadraticCostFunction* m_qcf;
};

#endif // WORKER_H
