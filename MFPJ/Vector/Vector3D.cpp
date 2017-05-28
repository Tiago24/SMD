#include <cmath>
#include "Vector3D.h"

Vector3D::Vector3D()
{
    m_x = 0.0; m_y = 0.0; m_z = 0.0;
}

Vector3D::Vector3D(double x, double y, double z)
{
    m_x = x; m_y = y; m_z = z;
}

double Vector3D::x()
{
    return m_x;
}

Vector3D Vector3D::x(double x)
{
    m_x = x;
    return *this;
}

double Vector3D::y()
{
    return m_y;
}

Vector3D Vector3D::y(double y)
{
    m_y = y;
    return *this;
}

double Vector3D::z()
{
    return m_z;
}

Vector3D Vector3D::z(double z)
{
    m_z = z;
    return *this;
}

Vector3D Vector3D::operator+(Vector3D v)
{
    Vector3D a;

    a.x(x() + v.x());
    a.y(y() + v.y());
    a.z(z() + v.z());

    return a;
}

Vector3D Vector3D::operator-(Vector3D v)
{
    Vector3D a;

    a.x(x() - v.x());
    a.y(y() - v.y());
    a.z(z() - v.z());

    return a;
}

Vector3D Vector3D::operator*(double d)
{
    Vector3D a;

    a.x(x() * d);
    a.y(y() * d);
    a.z(z() * d);

    return a;
}

double Vector3D::magnitude()
{
    return (m_x * m_x + m_y * m_y + m_z * m_z);
} // THIS RETURNS THE MAGNITUDE SQUARED

double Vector3D::dot(Vector3D v)
{
    return (x() * v.x() + y() * v.y() + z() * v.z());
}

Vector3D Vector3D::cross(Vector3D v)
{
    Vector3D a;

    a.x(y() * v.z() - z() * v.y());
    a.y(z() * v.x() - x() * v.z());
    a.z(x() * v.y() - y() * v.x());

    return a;
}

double Vector3D::angle(Vector3D v)
{
    double a = dot(v) / (sqrt(magnitude()) * sqrt(v.magnitude()));

    return a;
}

double Vector3D::angleD(Vector3D v)
{
    double a = dot(v) / (sqrt(magnitude()) * sqrt(v.magnitude()));
    a *= 180.0 / M_PI;

    return a;
}

Vector3D::~Vector3D()
{
    //dtor
}
