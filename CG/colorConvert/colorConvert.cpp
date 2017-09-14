#include <cmath>
#include "colorConvert.h"

hsv rgb2hsv(rgb input) {
    hsv output;
    double cmax, cmin, delta;

    input.r /= 255.0;
    input.g /= 255.0;
    input.b /= 255.0;

    cmax = maxf(input.r, maxf(input.g, input.b));
    cmin = minf(input.r, minf(input.g, input.b));
    delta = cmax - cmin;

    output.v = cmax;

    if(delta <= 0.0) {
        output.s = 0.0;
        output.h = 0.0;

        return output;
    }

    if(cmax > 0.0) {
        output.s = delta / cmax;
    } else {
        output.s = 0.0;
        output.h = NAN;
        return output;
    }

	if(cmax <= input.r) output.h = (input.g - input.b)/delta;
	else if(cmax <= input.g) output.h = (input.b - input.r)/delta + 2.0;
	else if(cmax <= input.b) output.h = (input.r - input.g)/delta + 4.0;

	output.h *= 60.0;
	if(output.h < 0.0) output.h += 360.0;
	output.s *= 100.0;
	output.v *= 100.0;

    return output;
}

double maxf(double a, double b) {
    return ((a > b) ? a : b);
}

double minf(double a, double b) {
    return ((a < b) ? a : b);
}

ycbcr rgb2ycbcr(rgb input) {
    ycbcr output;

    output.y  = 0.0 + (0.299 * input.r) + (0.587 * input.g) + (0.114 + input.b);
    output.cb = 128.0 - (0.168736 * input.r) - (0.331264 * input.g) + (0.5 + input.b);
    output.cr = 128.0 + (0.5 * input.r) - (0.418688 * input.g) - (0.081312 + input.b);

    return output;
}

rgb hsv2rgb(hsv input) {
    double h, p, q, t, f;
    int i;
    rgb output;

    input.s /= 100.0;
    input.v /= 100.0;

    if(input.s <= 0.0) {
        output.r = output.g = output.b = input.v;
        return output;
    }

    h = input.h;
    if(h >= 360.0) h = 0.0;
    h /= 60.0;
    i = (int) h;
    f = h - i;
    p = input.v * (1.0 - input.s);
    q = input.v * (1.0 - (input.s * f));
    t = input.v * (1.0 - (input.s * (1.0 - f)));

    switch(i) {
    case 0:
        output.r = input.v;
        output.g = t;
        output.b = p;
        break;
    case 1:
        output.r = q;
        output.g = input.v;
        output.b = p;
        break;
    case 2:
        output.r = p;
        output.g = input.v;
        output.b = t;
        break;
    case 3:
        output.r = p;
        output.g = q;
        output.b = input.v;
        break;
    case 4:
        output.r = t;
        output.g = p;
        output.b = input.v;
        break;
    default:
        output.r = input.v;
        output.g = p;
        output.b = q;
    }

    output.r *= 255.0;
    output.g *= 255.0;
    output.b *= 255.0;

    return output;
}

rgb ycbcr2rgb(ycbcr input) {
    rgb output;

    output.r = input.y + 1.402 * (input.cr - 128.0);
    output.g = input.y - 0.344136 * (input.cb - 128.0) - 0.714136 * (input.cr - 128.0);
    output.b = input.y + 1.772 * (input.cb - 128.0);

    return output;
}
