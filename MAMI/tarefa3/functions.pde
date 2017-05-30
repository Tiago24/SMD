void circle(float x, float y, float d) {
  ellipse(x, y, d, d);
}

void flower(float x, float y, float d) {
  circle(x - d, y, d); circle(x, y - d, d);
  circle(x + d, y, d); circle(x, y + d, d);
  circle(x, y, d);
}

void flowerx(float x, float y, float d) {
  circle(x - d*cos(PI/4.0), y - d*cos(PI/4.0), d);
  circle(x - d*cos(PI/4.0), y + d*cos(PI/4.0), d);
  circle(x + d*cos(PI/4.0), y - d*cos(PI/4.0), d);
  circle(x + d*cos(PI/4.0), y + d*cos(PI/4.0), d);
  circle(x, y, d);
}

void x_axis(float f) {
  x = f;
}

void y_axis(float f) {
  y = f;
}

void diameter(float f) {
  d = f;
}