#include "iteratorviewer.h"

IteratorViewer::IteratorViewer(ceres::Problem* problem):
    m_problem(problem)
{
}

ceres::CallbackReturnType IteratorViewer::operator ()(const ceres::IterationSummary& summary)
{

    // Get value
    std::vector<double*> parameters;
    m_problem->GetParameterBlocks(&parameters);
    double value = parameters[0][0];

    // Display
    std::cout<<summary.iteration<<","<<summary.cost<<","<<value<<std::endl;
    return ceres::SOLVER_CONTINUE;
}
