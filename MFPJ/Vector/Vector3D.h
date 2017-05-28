#ifndef VECTOR3D_H
#define VECTOR3D_H


class Vector3D
{
    public:
        Vector3D();
        Vector3D(double, double, double);
        virtual ~Vector3D();

        double x();
        Vector3D x(double);
        double y();
        Vector3D y(double);
        double z();
        Vector3D z(double);
        Vector3D operator+(Vector3D);
        Vector3D operator-(Vector3D);
        Vector3D operator*(double);
        double magnitude();
        double dot(Vector3D);
        Vector3D cross(Vector3D);
        double angle(Vector3D);  // RADIANS
        double angleD(Vector3D); // DEGREES

    protected:

    private:
        double m_x;
        double m_y;
        double m_z;
};

#endif // VECTOR3D_H
