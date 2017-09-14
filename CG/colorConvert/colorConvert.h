#ifndef COLORCONVERT_H_INCLUDED
#define COLORCONVERT_H_INCLUDED

#define KR 0.299
#define KG 0.587
#define KB 0.114

typedef struct {
    double r; //0-255
    double g; //0-255
    double b; //0-255
} rgb;

typedef struct {
    double h; //0-360
    double s; //0-100
    double v; //0-100
} hsv;

typedef struct {
    double y;  //0-255
    double cb; //0-255
    double cr; //0-255
} ycbcr;

hsv rgb2hsv(rgb);
ycbcr rgb2ycbcr(rgb);
rgb hsv2rgb(hsv);
rgb ycbcr2rgb(ycbcr);

double maxf(double, double);
double minf(double, double);

#endif // COLORCONVERT_H_INCLUDED
