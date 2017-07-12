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