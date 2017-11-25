int r = 0;
color cor = color(r, 100, 100);

void setup() {
  size(500, 500);

  colorMode(HSB, 360, 100, 100);
  re();
}

void draw() {
}

void circulo() {
  for (r=0; r<360; r++) {
    color cor = color(r, 100, 100);
    stroke(cor);
    pushMatrix();
    translate(250, 250);

    rotate(r);
    strokeWeight(5);
    line(0, 0, 200, 0);
    popMatrix();
  }
}

void re() {
  noStroke();
  int x = 250;
  int y = 250;
  float p = TWO_PI/360;
  for (int i = 0; i<360; i++) {
    smooth();
    color cor = color(i, 80, 100);
    fill(cor);
    arc(x, y, 500, 500, p*i, p*(i+1));
  }
}
