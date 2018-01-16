#include "worker.h"

#include "iteratorviewer.h"

Worker::Worker(double x2, double x, double x0, double initial_point):
    m_x2(x2), m_x(x), m_x0(x0), m_initial_point(initial_point),m_minimum(initial_point)
{
}

Worker::~Worker()
{
}

void Worker::process()
{

    // Emit start
    emit start();

    // Create problem
    ceres::Problem problem;

    // Create cost function
    ceres::CostFunction* cf = new ceres::AutoDiffCostFunction<QuadraticCostFunction,1,1>(new QuadraticCostFunction(m_x2,m_x,m_x0));

    // Add cost function to problem
    problem.AddResidualBlock(cf,NULL,&m_minimum);

    // Run the solver!
    ceres::Solver::Options options;
    options.linear_solver_type = ceres::DENSE_QR;
    options.minimizer_progress_to_stdout = true;
    IteratorViewer* cb = new IteratorViewer(&problem);
    options.callbacks.push_back(cb);
    options.update_state_every_iteration = true;
    ceres::Solver::Summary summary;
    ceres::Solve(options, &problem, &summary);

    // Emit finish
    emit finished();
    emit finished(m_minimum);
}
