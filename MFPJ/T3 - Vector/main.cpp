#include <iostream>
#include "Vector3D.h"

using namespace std;

int main()
{
    cout << "Calculando vetores 3D" << endl;

    Vector3D u = Vector3D(2.0, -5.0, 0.0);
    Vector3D v = Vector3D(1.0, 1.0, 0.0);

    cout << "u: " << u << endl;
    cout << "v: " << v << endl;

    Vector3D a = u + v;
    cout << "u + v: " << a << endl;
    cout << "|u + v|: " << sqrt(a.magnitude()) << endl;

    Vector3D b = u - v;
    cout << "u - v: " << b << endl;
    cout << "|u - v|: " << sqrt(b.magnitude()) << endl;

    Vector3D c = v - u;
    cout << "v - u: " << c << endl;
    cout << "|v - u|: " << sqrt(c.magnitude()) << endl;

    Vector3D d = u * 3 - v * 2;
    cout << "3u - 2v: " << d << endl;
    cout << "|3u - 2v|: " << sqrt(d.magnitude()) << endl;

    double e = u.dot(v);
    cout << "u.v: " << e << endl << endl;

    double f = Vector3D(1.0, 2.0, 5.0).dot(Vector3D(2.0, -7.0, 12.0));
    cout << "U.V: " << f << endl;

    double g = Vector3D(2.0, 5.0, 8.0).dot(Vector3D(-5.0, 2.0, 0.0));
    cout << "U.V: " << g << endl;

    return 0;
}
