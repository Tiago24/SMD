import controlP5.*; //<>//

void setup() {
  size(800, 600);
  frameRate(2);
  
  L = height;
  s = 80;
  b = 50;
  
  gui = new ControlP5(this);
  
  //gui.setFont(new ControlFont(createFont("Verdana", 8)));

  gui.addBang("reset")
    .setPosition(height+20, height-360).setSize(60, 20)
    .setColorValue(0).setColorLabel(0)
    .getCaptionLabel().align(ControlP5.CENTER, ControlP5.CENTER);

  gui.addSlider("x1")
    .setRange(L/6, L/4).setValue(L/6).setPosition(height+20, height-330)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);

  gui.addSlider("y1")
    .setRange(L/6, L/4).setValue(L/6).setPosition(height+20, height-320)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);

  gui.addSlider("x7")
    .setRange(L/3, L/2).setValue(L/3).setPosition(height+20, height-310)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);

  gui.addSlider("y7")
    .setRange(L/4, L/3).setValue(L/3).setPosition(height+20, height-300)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  
  gui.addSlider("angulo1")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-290)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo2")
    .setRange(0, PI/18).setValue(0).setPosition(height+20, height-280)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo3")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-270)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo4")
    .setRange(-PI/36, 0).setValue(0).setPosition(height+20, height-260)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo5")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-250)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo6")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-240)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo7")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-230)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo8")
    .setRange(-PI/36, 0).setValue(0).setPosition(height+20, height-220)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo9")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-210)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("angulo10")
    .setRange(-PI/18, PI/18).setValue(0).setPosition(height+20, height-200)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);

  gui.addSlider("matiz1")
    .setRange(0, 270).setValue(270).setPosition(height+20, height-190)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("matiz6")
    .setRange(0, 270).setValue(30).setPosition(height+20, height-180)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("matiz7")
    .setRange(0, 270).setValue(270).setPosition(height+20, height-170)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("matiz9")
    .setRange(0, 270).setValue(270).setPosition(height+20, height-160)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("matiz10")
    .setRange(0, 270).setValue(270).setPosition(height+20, height-150)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);

  gui.addSlider("comprimento1")
    .setRange(L*0.10, L*0.25).setValue(L*0.10).setPosition(height+20, height-140)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento2")
    .setRange(L*0.30, L*0.65).setValue(L*0.65).setPosition(height+20, height-130)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento3")
    .setRange(L*0.30, L*0.65).setValue(L*0.30).setPosition(height+20, height-120)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento4")
    .setRange(L*0.30, L*0.65).setValue(L*0.65).setPosition(height+20, height-110)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento5")
    .setRange(L*0.30, L*0.65).setValue(L*0.30).setPosition(height+20, height-100)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento6")
    .setRange(L*0.30, L*0.65).setValue(L*0.40).setPosition(height+20, height-90)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento7")
    .setRange(L*0.10, L*0.25).setValue(L*0.10).setPosition(height+20, height-80)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento8")
    .setRange(L*0.30, L*0.55).setValue(L*0.55).setPosition(height+20, height-70)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento9")
    .setRange(L*0.30, L*0.55).setValue(L*0.55).setPosition(height+20, height-60)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("comprimento10")
    .setRange(L*0.10, L*0.25).setValue(L*0.10).setPosition(height+20, height-50)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);

  gui.addSlider("espessura6")
    .setRange(3, 8).setValue(3).setPosition(height+20, height-40)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
  gui.addSlider("espessura9")
    .setRange(3, 8).setValue(3).setPosition(height+20, height-30)
    .setSize(60, 10).setColorValue(0).setColorLabel(0);
}

void draw() {
  background(#FFFFFF);

  pushMatrix();

  translate(x1, y1);
  rotate(a1);
  quadrado(0, 0, c1, m1, s, b);
  rotate(-a1);

  translate(0, 100);
  rotate(a2);
  linha(0, 0, c2, 1, 0, 0, 0);
  rotate(-a2);

  translate(0, 15);
  rotate(a3);
  linha(0, 0, c3, 1, 0, 0, 0);
  rotate(-a3);

  translate(0, 15);
  rotate(a4);
  linha(0, 0, c4, 1, 0, 0, 0);
  translate(0, 5);
  linha(0, 0, c4, 1, 0, 0, 0);
  translate(0, 5);
  linha(0, 0, c4, 1, 0, 0, 0);
  rotate(-a4);

  translate(0, 30);
  rotate(a5);
  linha(0, 0, c5, 1, 0, 0, 0);
  rotate(-a5);

  translate(0, -20);
  rotate(a6);
  linha(0, 0, c6, e6, m6, s, b);
  rotate(-a6);

  translate(x7, y7);
  rotate(a7);
  quadrado(0, 0, c7, m7, s, b);
  rotate(-a7);
  
  translate(50, -100);
  rotate(a8);
  linha(0, 0, -c8, 1, 0, 0, 0);
  translate(0, 5);
  linha(0, 0, -c8, 1, 0, 0, 0);
  translate(0, 5);
  linha(0, 0, -c8, 1, 0, 0, 0);
  rotate(-a8);

  translate(0, -20);
  rotate(a9);
  linha(0, 0, -c9, e9, m9, s, b);
  rotate(-a9);

  translate(50, -200);
  rotate(a10);
  quadrado(0, 0, c10, m10, s, b);
  rotate(-a10);

  popMatrix();
}