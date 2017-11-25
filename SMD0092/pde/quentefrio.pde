int cont = 1;
void setup() {
  size(500, 200);
  background(100);
  noStroke();
  fill(0);
}

void draw() {
  Controle();
  if (cont == 0) {
    Fria();
  }
  if (cont == 1) {
    Quente();
  }
}

void Controle() {
  if (cont<0) {
    cont = 0;
  }

  if (cont>1) {
    cont = 1;
  }
}
void Quente() {
  background(255);
  //botão
  fill(0, 110, 140);
  stroke(1);
  rect(0, 0, 99, 199);
  colorMode(RGB, 255, 255, 255, 100);
  //background
  noStroke();
  fill(210, 105, 30, 100);
  rect(100, 0, 400, 200);
  fill(218, 165, 32, 100);
  ellipse(130, 50, 20, 20);
  //primeiro layer
  fill(139, 69, 19, 100);
  rect(160, 80, 60, 220);
  rect(230, 80, 50, 220);
  rect(310, 70, 50, 210);
  rect(370, 75, 40, 205);
  //segundo layer
  fill(205, 133, 63, 100);
  rect(140, 100, 50, 200);
  rect(200, 130, 50, 200);
  rect(270, 100, 50, 200);
  rect(340, 100, 50, 200);
  rect(400, 120, 40, 80);
}

void Fria() {
  background(255);

  fill(210, 105, 30, 100);
  rect(100, 0, 400, 200);
  //botão
  stroke(1);
  fill(200, 100, 80);
  rect(0, 0, 99, 199);
  colorMode(RGB, 255, 255, 255, 100);
  //background
  noStroke();
  fill(95, 158, 160, 100);
  rect(100, 0, 400, 200);
  fill(210, 210, 210, 100);
  ellipse(130, 50, 20, 20);
  //primeiro layer
  fill(0, 128, 128, 100);
  rect(160, 80, 60, 220);
  rect(230, 80, 50, 220);
  rect(310, 70, 50, 210);
  rect(370, 75, 40, 205);
  //segundo layer
  fill(32, 178, 170, 100);
  rect(140, 100, 50, 200);
  rect(200, 130, 50, 200);
  rect(270, 100, 50, 200);
  rect(340, 100, 50, 200);
  rect(400, 120, 40, 80);
}

void mouseClicked() {
  if (mouseX >= 0 && mouseX <= 100 && mouseY >=0 && mouseY <=200) {
    if (cont == 0) {
      cont=1;
    } else if (cont == 1) {
      cont=0;
    }
  }
}