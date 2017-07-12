void linha(float x, float y, float c, float sw, float h, float s, float b) {
  // MATIZ(0, 360)
  // SATURAÇÃO(80, 100)
  // BRILHO(50, 100)
  colorMode(HSB, 360, 100, 100);
  stroke(h, s, b);

  // ESPESSURA(3, 8)
  strokeCap(SQUARE);
  strokeWeight(sw);

  // TAMANHO(30% DA TELA, 65% DA TELA)
  line(x, y, x+c, y);
}

void quadrado(float x, float y, float l, float h, float s, float b) {
  // MATIZ(0, 360)
  // SATURAÇÃO(80, 100) - random(80, 100)
  // BRILHO(60, 100) - random(60, 100)
  colorMode(HSB, 360, 100, 100);
  fill(h, s, b);

  // SEM BORDA
  strokeWeight(0);

  // PARAMETRIZADO PELO CENTRO GEOMÉTRICO
  rectMode(CENTER);
  
  // LADO(10% DA TELA, 25% DA TELA) - random(width*0.1, width*0.25)
  rect(x, y, l, l);
}

void x1(float f) {x1 = f;}
void y1(float f) {y1 = f;}

void x7(float f) {x7 = f;}
void y7(float f) {y7 = f;}

void angulo1(float f) {a1 = f;}
void angulo2(float f) {a2 = f;}
void angulo3(float f) {a3 = f;}
void angulo4(float f) {a4 = f;}
void angulo5(float f) {a5 = f;}
void angulo6(float f) {a6 = f;}
void angulo7(float f) {a7 = f;}
void angulo8(float f) {a8 = f;}
void angulo9(float f) {a9 = f;}
void angulo10(float f) {a10 = f;}

void matiz1(float f) {m1 = f;}
void matiz6(float f) {m6 = f;}
void matiz7(float f) {m7 = f;}
void matiz9(float f) {m9 = f;}
void matiz10(float f) {m10 = f;}

void comprimento1(float f) {c1 = f;}
void comprimento2(float f) {c2 = f;}
void comprimento3(float f) {c3 = f;}
void comprimento4(float f) {c4 = f;}
void comprimento5(float f) {c5 = f;}
void comprimento6(float f) {c6 = f;}
void comprimento7(float f) {c7 = f;}
void comprimento8(float f) {c8 = f;}
void comprimento9(float f) {c9 = f;}
void comprimento10(float f) {c10 = f;}

void espessura6(float f) {e6 = f;}
void espessura9(float f) {e9 = f;}

void reset() {
  gui.getController("x1").setValue((L/6 + L/4) / 2);
  gui.getController("y1").setValue((L/6 + L/4) / 2);
  gui.getController("x7").setValue((L/3 + L/2) / 2);
  gui.getController("y7").setValue((L/4 + L/3) / 2);

  gui.getController("angulo1").setValue(0);
  gui.getController("angulo2").setValue(0);
  gui.getController("angulo3").setValue(0);
  gui.getController("angulo4").setValue(0);
  gui.getController("angulo5").setValue(0);
  gui.getController("angulo6").setValue(0);
  gui.getController("angulo7").setValue(0);
  gui.getController("angulo8").setValue(0);
  gui.getController("angulo9").setValue(0);
  gui.getController("angulo10").setValue(0);

  gui.getController("matiz1").setValue(0);
  gui.getController("matiz6").setValue(0);
  gui.getController("matiz7").setValue(0);
  gui.getController("matiz9").setValue(0);
  gui.getController("matiz10").setValue(0);

  gui.getController("comprimento1").setValue(L*0.35/2);
  gui.getController("comprimento2").setValue(L*0.95/2);
  gui.getController("comprimento3").setValue(L*0.95/2);
  gui.getController("comprimento4").setValue(L*0.95/2);
  gui.getController("comprimento5").setValue(L*0.95/2);
  gui.getController("comprimento6").setValue(L*0.95/2);
  gui.getController("comprimento7").setValue(L*0.35/2);
  gui.getController("comprimento8").setValue(L*0.85/2);
  gui.getController("comprimento9").setValue(L*0.85/2);
  gui.getController("comprimento10").setValue(L*0.35/2);

  gui.getController("espessura6").setValue(3);
  gui.getController("espessura9").setValue(3);
}