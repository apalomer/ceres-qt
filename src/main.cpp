#include <QApplication>
#include "quadraticsolver.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QuadraticSolver solver;
    solver.show();
    return app.exec();
}
