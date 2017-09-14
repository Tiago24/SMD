#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "colorConvert.h"

using namespace std;

int main()
{
    rgb a;
    hsv b;
    ycbcr c;

    cout << "RGB: ";
    scanf("%lf", &(a.r));
    scanf("%lf", &(a.g));
    scanf("%lf", &(a.b));
    //cin << a.r << a.g << a.b;

/*
    cout << "RGB(" << (int) a.r << ", " << (int) a.g << ", " << (int) a.b << ")" << endl;
    b = rgb2hsv(a);
    cout << "HSV(" << (int) b.h << ", " << (int) b.s << ", " << (int) b.v << ")" << endl;
    c = hsv2rgb(b);
    cout << "RGB(" << (int) c.r << ", " << (int) c.g << ", " << (int) c.b << ")" << endl;
    d = rgb2ycbcr(a);
    cout << "YCbCr(" << (int) d.y << ", " << (int) d.cb << ", " << (int) d.cr << ")" << endl;
    e = ycbcr2rgb(d);
    cout << "RGB(" << (int) e.r << ", " << (int) e.g << ", " << (int) e.b << ")" << endl;
*/

    for(int i = 0; i < 3; i++) {
            cout << endl << "Iteration " << i+1 << ":" << endl;
            b = rgb2hsv(a);
            cout << "HSV(" << (int) b.h << ", " << (int) b.s << ", " << (int) b.v << ")" << endl;
            c = rgb2ycbcr(hsv2rgb(b)); // POTENTIAL TRIGGER FOR INFORMATION LOSS
            cout << "YCbCr(" << (int) c.y << ", " << (int) c.cb << ", " << (int) c.cr << ")" << endl;
            a = ycbcr2rgb(c);
            cout << "RGB(" << (int) a.r << ", " << (int) a.g << ", " << (int) a.b << ")" << endl;
    }

    return 0;
}
