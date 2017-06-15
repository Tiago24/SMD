#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <cmath>
#include <iostream>

class Vector3D
{
    public:
                Vector3D  ();
                Vector3D  (double, double, double);
        virtual ~Vector3D () noexcept;

        double x() const noexcept;
        double y() const noexcept;
        double z() const noexcept;

        Vector3D& x(double) noexcept;
        Vector3D& y(double) noexcept;
        Vector3D& z(double) noexcept;

        Vector3D operator +  (const Vector3D&) noexcept;
        Vector3D operator -  (const Vector3D&) noexcept;
        Vector3D operator -  ()                noexcept;
        Vector3D operator *  (double)          noexcept;
        bool     operator == (const Vector3D&) const noexcept;

        double   magnitude() const noexcept;
        Vector3D normalize() const noexcept;
        double   dot(const Vector3D&) const noexcept;
        Vector3D cross(const Vector3D&) const noexcept;
        double   angle(const Vector3D&) const noexcept;  // RADIANS
        double   angleD(const Vector3D&) const noexcept; // DEGREES

        friend std::ostream& operator << (std::ostream& os, Vector3D& vec) {
            os << vec.x() << ", " << vec.y() << ", " << vec.z();
            return os;
        }

    protected:

    private:
        double m_x;
        double m_y;
        double m_z;
};

#endif // VECTOR3D_H
