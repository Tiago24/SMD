import gifAnimation.*; //<>//

void setup() {
  size(600, 600);
  frameRate(2);
  export = new GifMaker(this, "trabalho.gif");
  export.setRepeat(0);
}

void draw() {
  background(#FFFFFF);
  final float L = width;

  //PRIMEIRO QUADRADO
  //PARÂMETROS
  //ÂNGULO(-PI/18, PI/18)
  a = random(-PI/18, PI/18);
  // MATIZ(0, 270)
  m = random(0, 270);
  // SATURAÇÃO(80, 100)
  s = 80;
  // BRILHO(50, 100)
  b = 50;
  // LADO(10% DA TELA, 25% DA TELA)
  l = random(L*0.10, L*0.25);
  //DESENHO
  translate(random(L/6, L/4), random(L/6, L/4));
  rotate(a);
  quadrado(0, 0, l, m, s, b);

  //RESETANDO ÂNGULO; ESTE PASSO É IMPORTANTE PARA ROTACIONAR CADA ELEMENTO INDEPENDENTEMENTE
  rotate(-a);

  //FEIXES DE LINHAS
  //ALGUNS PARÂMETROS PODEM/DEVEM SER ALTERADOS
  a = random(0, PI/18);
  //DESENHO
  translate(0, 100);
  rotate(a);
  c = random(L*0.30, L*0.65);
  linha(0, 0, c, 1, 0, 0, 0);
  rotate(-a);
  a = random(-PI/18, PI/18);
  rotate(a);
  translate(0, 15);
  c = random(L*0.30, L*0.65);
  linha(0, 0, c, 1, 0, 0, 0);
  translate(0, 15);
  rotate(-a);
  a = random(-PI/36, 0);
  rotate(a);
  c = random(L*0.30, L*0.65);
  linha(0, 0, c, 1, 0, 0, 0);
  translate(0, 5);
  c = random(L*0.30, L*0.65);
  linha(0, 0, c, 1, 0, 0, 0);
  translate(0, 5);
  c = random(L*0.30, L*0.65);
  linha(0, 0, c, 1, 0, 0, 0);
  rotate(-a);
  a = random(-PI/18, PI/18);
  rotate(a);
  translate(0, 30);
  c = random(L*0.30, L*0.65);
  linha(0, 0, c, 1, 0, 0, 0);

  //LINHA CHEIA
  // ESPESSURA(3, 8)
  e = random(3, 8);
  // COMPRIMENTO(30% DA TELA, 65% DA TELA)
  c = random(L*0.30, L*0.65);
  rotate(-a);
  a = random(-PI/18, PI/18);
  m = random(0, 270);
  translate(0, -20);
  linha(0, 0, c, e, m, s, b);

  rotate(-a);
  // SEGUNDO QUADRADO
  m = random(0, 270);
  l = random(L*0.10, L*0.25);
  //DESENHO
  translate(random(L/3, L/2), random(L/4, L/3));
  rotate(a);
  quadrado(0, 0, l, m, s, b);
  
  //MAIS FEIXES DE LINHAS
  translate(50, -100);
  rotate(-a);
  a = random(-PI/36, 0);
  rotate(a);
  c = random(L*0.30, L*0.45);
  linha(0, 0, -c, 1, 0, 0, 0);
  translate(0, 5);
  c = random(L*0.30, L*0.45);
  linha(0, 0, -c, 1, 0, 0, 0);
  translate(0, 5);
  c = random(L*0.30, L*0.45);
  linha(0, 0, -c, 1, 0, 0, 0);

  //OUTRA LINHA CHEIA
  e = random(3, 8);
  rotate(-a);
  a = random(-PI/18, PI/18);
  m = random(0, 270);
  c = random(L*0.30, L*0.65);
  translate(0, -20);
  linha(0, 0, -c, e, m, s, b);

  rotate(-a);
  // MAIS UM QUADRADO
  m = random(0, 270);
  l = random(L*0.10, L*0.25);
  //DESENHO
  translate(50, -200);
  rotate(a);
  quadrado(0, 0, l, m, s, b);

  export.setDelay(1000/fps);
  export.addFrame();
}