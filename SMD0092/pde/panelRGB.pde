final int RED = #FF0000;
final int GREEN = #00FF00;
final int BLUE = #0000FF;
boolean lightR, lightG, lightB;
int bg, red, green, blue;
float xR, yR;
float xG, yG;
float xB, yB;
final float R = 37.5;

float dxR, dyR, dR;
float dxG, dyG, dG;
float dxB, dyB, dB;

void setup() {
  size(640, 480);
  lightR = lightG = lightB = false;
  bg = #000000;
  red = #7F0000;
  green = #007F00;
  blue = #00007F;
  xR = width*0.10;
  xG = width*0.5;
  xB = width*0.90;
  yR = yG = yB = height*0.10;
}

void draw() {
  background(bg);
  strokeWeight(3);
  stroke(#3F0000);
  fill(red);
  ellipse(xR, yR, R*2.0, R*2.0);
  stroke(#003F00);
  fill(green);
  ellipse(xG, yG, R*2.0, R*2.0);
  stroke(#00003F);
  fill(blue);
  ellipse(xB, yB, R*2.0, R*2.0);

  dxR = mouseX - xR;
  dyR = mouseY - yR;
  dR = sqrt(pow(dxR, 2.0) + pow(dyR, 2.0));

  dxG = mouseX - xG;
  dyG = mouseY - yG;
  dG = sqrt(pow(dxG, 2.0) + pow(dyG, 2.0));

  dxB = mouseX - xB;
  dyB = mouseY - yB;
  dB = sqrt(pow(dxB, 2.0) + pow(dyB, 2.0));
}

void lightOn(int c) {
  switch(c) {
    case RED:
      bg += RED;
      red *= 2;
      break;
    case GREEN:
      bg += GREEN;
      green *= 2;
      break;
    case BLUE:
      bg += BLUE;
      blue *= 2;
      break;
  }
}

void lightOff(int c) {
  switch(c) {
    case RED:
      bg -= RED;
      red /= 2;
      break;
    case GREEN:
      bg -= GREEN;
      green /= 2;
      break;
    case BLUE:
      bg -= BLUE;
      blue /= 2;
      break;
  }
}

void mousePressed() {
  if(dR < R) {
    if(lightR) {
     lightOff(RED);
     lightR = false;
    }
    else {
      lightOn(RED);
      lightR = true;
    }
  }
  else if(dG < R) {
    if(lightG) {
     lightOff(GREEN);
     lightG = false;
    }
    else {
      lightOn(GREEN);
      lightG = true;
    }
  }
  else if(dB < R) {
    if(lightB) {
     lightOff(BLUE);
     lightB = false;
    }
    else {
      lightOn(BLUE);
      lightB = true;
    }
  }
}