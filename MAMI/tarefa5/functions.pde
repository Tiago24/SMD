void grid() {
  for(float i = 0; i < 10; i++) {
    line(i*width/10, 0, i*width/10, height);
    line(0, i*height/10, width, i*height/10);
  }
}

void projectile() {
  fill(255);
  ellipse(x, y, 2*r, 2*r);
}

float MRU(float v, float t) {
  return v * t;
}

float MRUV(float v, float t, float a) {
  return v * t + a * t * t / 2.0;
}

void bounce() {
  if(y > height) {
    y = height - r;
    tY = 0;
    vY *= 0.9;
  }
}

void textBox() {
  fill(200, 200, 200);
  rect(0, 0, 250, 200);
  fill(0);
  text("time = " + tX + "s", 10, 10, 200, 20);
  text("Vertical distance = " + dY + "m", 10, 30, 200, 20);
  text("Horizontal distance = " + dX + "m", 10, 50, 200, 20);
  text("Vertical velocity (initial) = " + v0Y + "m/s", 10, 70, 250, 20);
  text("Horizontal velocity = " + vX + "m/s", 10, 90, 200, 20);
}