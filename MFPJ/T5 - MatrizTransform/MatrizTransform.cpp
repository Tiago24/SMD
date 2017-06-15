#include "MatrizTransform.h"

MatrizTransform::MatrizTransform() noexcept
{
    for(int i = 0; i < 16; i++) a[i] = 0.0;
}
MatrizTransform::MatrizTransform(double d ...) noexcept
{
    va_list arg;
    va_start(arg, d);

    a[0] = d;
    for(int i = 1; i < 16; i++) a[i] = va_arg(arg, double);

    va_end(arg);
}

MatrizTransform& MatrizTransform::m(int i, double d) noexcept
{
    a[i] = d;
    return *this;
}

double MatrizTransform::m(int i) const noexcept
{
    return a[i];
}

MatrizTransform MatrizTransform::identity() noexcept
{
    return MatrizTransform(1.0, 0.0, 0.0, 0.0,
                           0.0, 1.0, 0.0, 0.0,
                           0.0, 0.0, 1.0, 0.0,
                           0.0, 0.0, 0.0, 1.0);
}

MatrizTransform MatrizTransform::translate(double x, double y, double z) noexcept
{
    return MatrizTransform(1.0, 0.0, 0.0, x,
                           0.0, 1.0, 0.0, y,
                           0.0, 0.0, 1.0, z,
                           0.0, 0.0, 0.0, 1.0);
}

MatrizTransform MatrizTransform::scale(double x, double y, double z) noexcept
{
    return MatrizTransform(x,   0.0, 0.0, 0.0,
                           0.0, y,   0.0, 0.0,
                           0.0, 0.0, z,   0.0,
                           0.0, 0.0, 0.0, 1.0);
}

MatrizTransform MatrizTransform::rotate(Axis a, double theta) noexcept
{
    const double c = cos(theta);
    const double s = sin(theta);
    switch(a) {
    case Axis::X:
        return MatrizTransform(1.0, 0.0, 0.0, 0.0,
                               0.0, c,   -s,  0.0,
                               0.0, s,   c,   0.0,
                               0.0, 0.0, 0.0, 1.0);
    case Axis::Y:
        return MatrizTransform(c,   0.0, s,   0.0,
                               0.0, 1.0, 0.0, 0.0,
                               -s,  0.0, c,   0.0,
                               0.0, 0.0, 0.0, 1.0);
    default: // case Axis::Z
        return MatrizTransform(c,   -s,  0.0, 0.0,
                               s,   c,   0.0, 0.0,
                               0.0, 0.0, 1.0, 0.0,
                               0.0, 0.0, 0.0, 1.0);
    }
}

std::ostream& operator << (std::ostream& os, const MatrizTransform& mat) noexcept
{
    os << std::fixed << std::setprecision(2);
    os << "[";
    for(int i = 0; i < 16; i++) {
        os << mat.m(i) << "\t";
        if(i == 15) os << "]";
        if((i + 1) % 4 == 0) os << std::endl << " ";
    }
    return os;
}
