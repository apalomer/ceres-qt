#ifndef ITERATORVIEWER_H
#define ITERATORVIEWER_H

#include <ceres/ceres.h>

class IteratorViewer: public ceres::IterationCallback
{
public:
    IteratorViewer(ceres::Problem* problem);

    ceres::CallbackReturnType operator()(const ceres::IterationSummary& summary);

private:
    ceres::Problem* m_problem;
};

#endif // ITERATORVIEWER_H
