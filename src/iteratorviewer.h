#ifndef ITERATORVIEWER_H
#define ITERATORVIEWER_H

// Qt
#include <QObject>

// Ceres
#include <ceres/ceres.h>

class IteratorViewer: public QObject, public ceres::IterationCallback
{
    Q_OBJECT
public:
    IteratorViewer(ceres::Problem* problem);

    ceres::CallbackReturnType operator()(const ceres::IterationSummary& summary);

signals:

    void message(QString msg);
    void variable(double x);

private:
    ceres::Problem* m_problem;
};

#endif // ITERATORVIEWER_H
