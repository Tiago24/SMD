/*
void setup() {
  size(600, 600);
  frameRate(1);
  a = random(45);
}

void draw() {
  // PRIMEIRO PASSO: QUADRADO INICIAL
  background(#FFFFFF);
  int i = (int) random(4);
  switch(i) {
    case 0: x = random(50, 100); y = random(50, 100); break;
    case 1: x = random(50, 100); y = random(height-100, height-50); break;
    case 2: x = random(width-100, width-50); y = random(50, 100); break;
    case 3: x = random(width-100, width-50); y = random(height-100, height-50); break;
  }
  translate(x, y);
  rectMode(CENTER);
  chooseSquareColor((int) random(6));
  strokeWeight(0);
  rect(0, 0, 50, 50);

  // SEGUNDO PASSO: LINHAS ADJACENTES
  chooseLineColor((int) random(6));
  strokeWeight(random(1, 7));
  strokeCap(SQUARE);
  i = (int) random(2);
  switch(i) {
    case 0:
      if(x < width/2) {
        translate(0, 100);
        line(0, 0, random(width/3, width/2), 0);
        strokeWeight(1);
        stroke(0);
        translate(0, 6);
        line(0, 0, random(width/3, width/2), 0);
        translate(0, 2);
        line(0, 0, random(width/3, width/2), 0);
        translate(0, 2);
        line(0, 0, random(width/3, width/2), 0);
      }
      else {
        translate(0, -100);
        line(0, 0, -random(width/3, width/2), 0);
        strokeWeight(1);
        stroke(0);
        translate(0, -6);
        line(0, 0, -random(width/3, width/2), 0);
        translate(0, -2);
        line(0, 0, -random(width/3, width/2), 0);
        translate(0, -2);
        line(0, 0, -random(width/3, width/2), 0);
      }
      break;
    case 1:
      if(y < height/2) {
        translate(100, 0);
        line(0, 0, 0, random(height/3, height/2));
        strokeWeight(1);
        stroke(0);
        translate(-6, 0);
        line(0, 0, 0, random(height/3, height/2));
        translate(-2, 0);
        line(0, 0, 0, random(height/3, height/2));
        translate(-2, 0);
        line(0, 0, 0, random(height/3, height/2));
      }
      else {
        translate(-100, 0);
        line(0, 0, 0, -random(height/3, height/2));
        strokeWeight(1);
        stroke(0);
        translate(-6, 0);
        line(0, 0, 0, -random(height/3, height/2));
        translate(-2, 0);
        line(0, 0, 0, -random(height/3, height/2));
        translate(-2, 0);
        line(0, 0, 0, -random(height/3, height/2));
      }
      break;
  }
  
  // PRIMEIRO PASSO: QUADRADO INICIAL
  switch(i) {
    case 0: translate(random(20, 50), random(20, 50)); break;
    case 1: translate(random(20, 50), random(20, 50)); break;
  }
  rectMode(CENTER);
  chooseSquareColor((int) random(6));
  strokeWeight(0);
  rect(0, 0, 50, 50);
}
*/