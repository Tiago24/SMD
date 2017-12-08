final int RED = #FF0000;
final int GREEN = #00FF00;
final int BLUE = #0000FF;
final int CYAN = 0, MAGENTA = 1, YELLOW = 2;
boolean lightC, lightM, lightY;
int bg, cyan, magenta, yellow;
float xC, yC;
float xM, yM;
float xY, yY;
final float R = 37.5;

float dxC, dyC, dC;
float dxM, dyM, dM;
float dxY, dyY, dY;

void setup() {
  size(640, 480);
  lightC = lightM = lightY = false;
  bg = #FFFFFF;
  cyan = #007F7F;
  magenta = #7F007F;
  yellow = #7F7F00;
  xC = width*0.10;
  xM = width*0.5;
  xY = width*0.90;
  yC = yM = yY = height*0.10;
}

void draw() {
  background(bg);
  strokeWeight(3);
  stroke(#003F3F);
  fill(cyan);
  ellipse(xC, yC, R*2.0, R*2.0);
  stroke(#3F003F);
  fill(magenta);
  ellipse(xM, yM, R*2.0, R*2.0);
  stroke(#3F3F00);
  fill(yellow);
  ellipse(xY, yY, R*2.0, R*2.0);

  dxC = mouseX - xC;
  dyC = mouseY - yC;
  dC = sqrt(pow(dxC, 2.0) + pow(dyC, 2.0));

  dxM = mouseX - xM;
  dyM = mouseY - yM;
  dM = sqrt(pow(dxM, 2.0) + pow(dyM, 2.0));

  dxY = mouseX - xY;
  dyY = mouseY - yY;
  dY = sqrt(pow(dxY, 2.0) + pow(dyY, 2.0));
}

void lightOn(int c) {
  switch(c) {
    case CYAN:
      bg -= RED;
      cyan *= 2;
      break;
    case MAGENTA:
      bg -= GREEN;
      magenta *= 2;
      break;
    case YELLOW:
      bg -= BLUE;
      yellow *= 2;
      break;
  }
}

void lightOff(int c) {
  switch(c) {
    case CYAN:
      bg += RED;
      cyan /= 2;
      break;
    case MAGENTA:
      bg += GREEN;
      magenta /= 2;
      break;
    case YELLOW:
      bg += BLUE;
      yellow /= 2;
      break;
  }
}

void mousePressed() {
  if(dC < R) {
    if(lightC) {
     lightOff(CYAN);
     lightC = false;
    }
    else {
      lightOn(CYAN);
      lightC = true;
    }
  }
  else if(dM < R) {
    if(lightM) {
     lightOff(MAGENTA);
     lightM = false;
    }
    else {
      lightOn(MAGENTA);
      lightM = true;
    }
  }
  else if(dY < R) {
    if(lightY) {
     lightOff(YELLOW);
     lightY = false;
    }
    else {
      lightOn(YELLOW);
      lightY = true;
    }
  }
}