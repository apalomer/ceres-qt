#ifndef QUADRATICCOSTFUNCTION_H
#define QUADRATICCOSTFUNCTION_H

class QuadraticCostFunction
{
public:
    QuadraticCostFunction(double x2, double x, double x0);

    template<typename T>
    bool operator()(T const* x, T* residual) const
    {
        residual[0] = T(m_x2)*x[0]*x[0] + T(m_x)*x[0] + T(m_x0);
        return true;
    }

private:
    double m_x2,m_x,m_x0;
};

#endif // QUADRATICCOSTFUNCTION_H
