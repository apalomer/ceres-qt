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
    emit variable(value);

    // Send message
    QString msg;
    if (summary.iteration == 0)
    {
        msg = "iter      cost      cost_change  |gradient|   |step|    tr_ratio  tr_radius  ls_iter  iter_time  total_time";
        emit message(msg);
    }
    const char* kReportRowFormat = "% 4d % 8e   % 3.2e   % 3.2e  % 3.2e  % 3.2e % 3.2e     % 4d   % 3.2e   % 3.2e";
    msg.clear();
    char buffer [300];
    int n;
    n = sprintf(buffer,kReportRowFormat,
                summary.iteration,
                summary.cost,
                summary.cost_change,
                summary.gradient_max_norm,
                summary.step_norm,
                summary.relative_decrease,
                summary.trust_region_radius,
                summary.linear_solver_iterations,
                summary.iteration_time_in_seconds,
                summary.cumulative_time_in_seconds);
    msg = QString::fromUtf8(buffer,n);
    emit message(msg);

    // Exit
    return ceres::SOLVER_CONTINUE;
}
