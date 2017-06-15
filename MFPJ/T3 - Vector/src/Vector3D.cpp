#include "Vector3D.h"

Vector3D::Vector3D() :
    Vector3D(0.0, 0.0, 0.0)
{
    //m_x = 0.0; m_y = 0.0; m_z = 0.0;
}

Vector3D::Vector3D(double a, double b, double c) :
    m_x(a),
    m_y(b),
    m_z(c)
{
    //m_x = a; m_y = b; m_z = c;
}

double Vector3D::x() const noexcept
{
    return m_x;
}

Vector3D& Vector3D::x(double d) noexcept
{
    m_x = d;
    return *this;
}

double Vector3D::y() const noexcept
{
    return m_y;
}

Vector3D& Vector3D::y(double d) noexcept
{
    m_y = d;
    return *this;
}

double Vector3D::z() const noexcept
{
    return m_z;
}

Vector3D& Vector3D::z(double d) noexcept
{
    m_z = d;
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D& v) noexcept
{
    return Vector3D(
               x() + v.x(),
               y() + v.y(),
               z() + v.z()
               );
}

Vector3D Vector3D::operator-(const Vector3D& v) noexcept
{
    return Vector3D(
               x() - v.x(),
               y() - v.y(),
               z() - v.z()
               );
}

Vector3D Vector3D::operator-() noexcept
{
    return Vector3D(
               -x(),
               -y(),
               -z()
               );
}

Vector3D Vector3D::operator*(double d) noexcept
{
    return Vector3D(
               x() * d,
               y() * d,
               z() * d
               );
}

double Vector3D::magnitude() const noexcept
{
    return (x() * x() + y() * y() + z() * z());
} // THIS RETURNS THE MAGNITUDE SQUARED

Vector3D Vector3D::normalize() const noexcept
{
    if(magnitude() == 0.0) return *this;

    const double mag = sqrt(magnitude());

    return Vector3D(
                x() / mag,
                y() / mag,
                z() / mag
               );
}

double Vector3D::dot(const Vector3D& v) const noexcept
{
    return (x() * v.x() + y() * v.y() + z() * v.z());
}

Vector3D Vector3D::cross(const Vector3D& v) const noexcept
{
    //Vector3D a;

    //a
    //  .x(y() * v.z() - z() * v.y())
    //  .y(z() * v.x() - x() * v.z())
    //  .z(x() * v.y() - y() * v.x());

    return Vector3D(
               y() * v.z() - z() * v.y(),
               z() * v.x() - x() * v.z(),
               x() * v.y() - y() * v.x()
               );
}

double Vector3D::angle(const Vector3D& v) const noexcept
{
    if(*this == v) return 0.0;

    const double mag = sqrt(magnitude() * v.magnitude());

    if(mag == 0.0) return 0.0;

    return acos(dot(v) / mag);
}

bool Vector3D::operator==(const Vector3D& v) const noexcept
{
    if(v.x()!=x()) return false;
    if(v.y()!=y()) return false;
    if(v.z()!=z()) return false;

    return true;
}

double Vector3D::angleD(const Vector3D& v) const noexcept
{
    const double PI = 3.14;
    return (angle(v) * 180.0 / PI);
}

Vector3D::~Vector3D()
{
    //dtor
}
