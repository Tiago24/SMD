int r = 0;
int opc = 0;
int bas = 0;
int compcor1 = 0;
int ancor1 = 0;
int semicom1 = 0;
color cor = color(r, 100, 100);

void setup() {
  text(" ", 0, 0);
  background(255);
  size(800, 500);
  colorMode(HSB, 360, 100, 100);
  re();
  opc = 0;
}

void draw() {
  switch(opc) {
  case 0:
    background(255);
    re();
    complementar();
    fill(120);
    stroke(0);
    rect(325, 20, 50, 50);
    fill(200);
    rect(375, 20, 50, 50);
    fill(200);
    rect(425, 20, 50, 50);
    textAlign(CENTER, CENTER);
    fill(0);
    text("Complementares", 620, 370); 
    text("Comp", 350, 45);
    text("Ana", 400, 45);
    text("SComp", 450, 45);
    break;
  case 1:
    background(255);
    re();
    analoga();
    fill(200);
    stroke(0);
    rect(325, 20, 50, 50);
    fill(120);
    rect(375, 20, 50, 50);
    fill(200);
    rect(425, 20, 50, 50);
    textAlign(CENTER, CENTER);
    fill(0);
    text("Análogas", 620, 370);
    text("Comp", 350, 45);
    text("Ana", 400, 45);
    text("SComp", 450, 45);
    break;
  case 2:
    background(255);
    re();
    semicomp();
    fill(200);
    stroke(0);
    rect(325, 20, 50, 50);
    fill(200);
    rect(375, 20, 50, 50);
    fill(120);
    rect(425, 20, 50, 50);
    fill(0);
    text("Semi Complementares", 620, 370);
    text("Comp", 350, 45);
    text("SComp", 450, 45);
    text("Ana", 400, 45);
    break;
  }
}

void mouseClicked() {
  switch(opc) {
  case 0:
    if (mouseX>=375&&mouseX<425&&mouseY>=20&&mouseY<=70) {
      opc = 1;
    }
    if (mouseX>=425&&mouseX<475&&mouseY>=20&&mouseY<=70) {
      opc = 2;
    }
    break;   
  case 1:
    if (mouseX>=325&&mouseX<375&&mouseY>=20&&mouseY<=70) {
      opc = 0;
    }
    if (mouseX>=425&&mouseX<475&&mouseY>=20&&mouseY<=70) {
      opc = 2;
    }
    break;
  case 2:
    if (mouseX>=325&&mouseX<375&&mouseY>=20&&mouseY<=70) {
      opc = 0;
    }
    if (mouseX>=375&&mouseX<425&&mouseY>=20&&mouseY<=70) {
      opc = 1;
    }
    break;
  }
}

//cores complementares
void complementar() {
  //Modulo 360 para resetar ao numero 0 assim que passar.
  int compcor2 = (compcor1+180)%360;
  color corbas1 = color(compcor1, 80, 90);
  color corbas2 = color(compcor2, 80, 90);
  fill(corbas1);
  rect(500, 150, 240, 200);
  fill(corbas2);
  ellipse(620, 250, 100, 100);

  if (mousePressed) {
    //compcor1 = (compcor1+1)%360;
    if (mouseX>50&&mouseX<350&&mouseY>100&&mouseY<500) {
      loadPixels();
      color c = pixels[mouseY*width+mouseX];
      updatePixels();
      compcor1 = (int) hue(c);
    }
  }
}

//Faz a distribuição de cores análogas
void analoga() {
  //Modulo 360 para resetar ao numero 0 assim que passar.
  int ancor2 = (ancor1+30)%360;
  int ancor3 = (ancor2+30)%360;
  color corbas1 = color(ancor1, 80, 90);
  color corbas2 = color(ancor2, 80, 90);
  color corbas3 = color(ancor3, 80, 90);

  fill(corbas1);
  rect(500, 150, 80, 200);
  fill(corbas2);
  rect(580, 150, 80, 200);
  fill(corbas3);
  rect(660, 150, 80, 200);

  if (mousePressed) {
    //ancor1 = (ancor1+1)%360;
    if (mouseX>50&&mouseX<350&&mouseY>100&&mouseY<500) {
      loadPixels();
      color c = pixels[mouseY*width+mouseX];
      updatePixels();
      ancor1 = (int) hue(c);
    }
  }
}

// faz as cores semi complementares
void semicomp() {
  //Modulo 360 para resetar ao numero 0 assim que passar.
  int semicom2 = (semicom1+150)%360;
  int semicom3 = (semicom1+210)%360;
  color corbas1 = color(semicom1, 80, 90);
  color corbas2 = color(semicom2, 80, 90);
  color corbas3 = color(semicom3, 80, 90);

  fill(corbas1);
  rect(500, 150, 80, 200);
  fill(corbas2);
  rect(580, 150, 80, 200);
  fill(corbas3);
  rect(660, 150, 80, 200);

  if (mousePressed) {
    //semicom1 = (semicom1+1)%360;
    //color c = get(mouseX, mouseY);
    if (mouseX>50&&mouseX<350&&mouseY>100&&mouseY<500) {
      loadPixels();
      color c = pixels[mouseY*width+mouseX];
      updatePixels();
      semicom1 = (int) hue(c);
    }
  }
}

void re() {
  noStroke();
  int x = 200;
  int y = 250;
  float p = TWO_PI/360;
  for (int i = 0; i<360; i++) {
    smooth();
    color cor = color(i, 80, 100);
    fill(cor);
    arc(x, y, 300, 300, p*i, p*(i+1));
  }

  //strokeWeight(3);
  //stroke(0);
  //line(x, y, 300, 300);
  //ellipse(300, 300, 10, 10);
  //noStroke();
}