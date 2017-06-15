#include <iostream>
#include <cmath>
#include "MatrizTransform.h"

#define PI 3.14

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    MatrizTransform m = MatrizTransform();
    cout << m << endl;

    MatrizTransform a = MatrizTransform::identity();
    cout << a << endl;
    MatrizTransform b = MatrizTransform::rotate(Axis::X, PI);
    cout << b << endl;
    MatrizTransform c = MatrizTransform::rotate(Axis::Y, PI/3);
    cout << c << endl;
    MatrizTransform d = MatrizTransform::rotate(Axis::Z, PI/4);
    cout << d << endl;
    MatrizTransform e = MatrizTransform::translate(30.0, 40.0, 50.0);
    cout << e << endl;
    MatrizTransform f = MatrizTransform::scale(30.0, 40.0, 50.0);
    cout << f << endl;
    return 0;

//    MatrizTransform e(0.0, 1.0, 2.0, 3.0, 4.0, 0.0, 1.0, 2.0, 3.0, 4.0, 0.0, 1.0, 2.0, 3.0, 4.0, 0.0, 1.0, 2.0, 3.0, 4.0);
}
