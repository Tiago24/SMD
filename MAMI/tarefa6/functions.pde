void rectangle(float x, float y, float b, float a, int rgb) {
  stroke(#000000); fill(rgb);
  rect(x, y, b, a);
}

void diamond(float x, float y, float b, float a, int rgb) {
  stroke(rgb); fill(rgb);
  quad(x, y-a/2, x+b/2, y, x, y+a/2, x-b/2, y);
}

void circle(float x, float y, float d, int rgb) {
  stroke(rgb); fill(rgb);
  ellipse(x, y, d, d);
}

void flagBrazil(float x, float y, float t) {
  float rHeight = t*14.0;
  float rWidth = t*20.0;
  float dHeight = rHeight - t*3.4;
  float dWidth = rWidth - t*3.4;
  float cDiameter = rHeight/2.0;
  rectangle(x-rWidth/2, y-rHeight/2, rWidth, rHeight, #00A859);
  diamond(x, y, dWidth, dHeight, #FFCC29);
  circle(x, y, cDiameter, #3E4095);
}

void rectangleMode(float x, float y, float b, float a, int rgb) {
  stroke(#000000); fill(rgb);
  rectMode(CENTER);
  rect(x, y, b, a);
}

void diamondMode(float x, float y, float b, float a, int rgb) {
  stroke(rgb); fill(rgb);
  quad(x, y-a/2, x+b/2, y, x, y+a/2, x-b/2, y);
}

void circleMode(float x, float y, float d, int rgb) {
  stroke(rgb); fill(rgb);
  ellipseMode(CENTER);
  ellipse(x, y, d, d);
}

void flagBrazilMode(float x, float y, float t) {
  float rHeight = t*14.0;
  float rWidth = t*20.0;
  float dHeight = rHeight - t*3.4;
  float dWidth = rWidth - t*3.4;
  float cDiameter = rHeight/2.0;
  rectangleMode(x, y, rWidth, rHeight, #00A859);
  diamond(x, y, dWidth, dHeight, #FFCC29);
  circle(x, y, cDiameter, #3E4095);
}