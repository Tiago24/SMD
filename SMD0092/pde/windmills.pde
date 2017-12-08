float angle, a, fps;
int n, s, b;

void setup() {
  size(640, 480);
  colorMode(HSB, 360, 100, 100);
  n = 3;
  angle = sectorAngle(n);
  a = 0;
  fps = 0;
}

public void draw() {
  background(0, 0, 100);
  noStroke();
  circleRGB(width/4, height/2);
  circleCMYK(width*3/4, height/2);
  a += 1 * fps / 60.0;
  s = b = (abs(fps) > 100.0)? 0 : (100 - abs((int) fps));
}

float sectorAngle(int n) {
  return (TWO_PI / n);
}

void circleRGB(int x, int y) {
  for(int i = 0; i < n; i += 1) {
    if((i % 3) == 0) fill(0, s, 100);
    else if((i % 3) == 1) fill(120, s, 100);
    else fill(240, s, 100);
    arc(x, y, height/3, height/3, a + angle * i, a + angle * (i + 1));
  }
}

void circleCMYK(int x, int y) {
  for(int i = 0; i < n; i += 1) {
    if((i % 3) == 0) fill(180, 100, b);
    else if((i % 3) == 1) fill(300, 100, b);
    else fill(60, 100, b);
    arc(x, y, height/3, height/3, a + angle * i, a + angle * (i + 1));
  }
}

void mousePressed() {
  if(mouseButton == LEFT && fps < 90) {
    fps += 10;
  }
  else if(mouseButton == RIGHT && fps > -90) {
    fps -= 10;
  }
  else if(mouseButton == CENTER) {
    fps = 0;
  }
}