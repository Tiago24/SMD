void moveBox(float x0, float d, float s) {
  rect(x0 + i * d, height/2.0, 20, 20);
  if(i <= 1.0) i += 1.0 / s;
}

void moveBox2D(float x1, float y1, float x2, float y2, float n) {
  rect(x1 + i * x2, y1 + i * y2, 20, 20);
  if(i <= 1.0) i += 1.0 / n;
}