/*
 * Tarefa 3
 * Apresentar o desenvolvimento de uma aplicação que
 * mostra diversas flores implementando a função
 * flor4(x, y, r) e utilizando uma GUI para a entrada
 * de parâmetros.
 */
import controlP5.*;

ControlP5 gui;

void setup() {
  size(600, 400);

  gui = new ControlP5(this);

  gui.addSlider("x_axis")
    .setRange(0, width)
    .setValue(width/2)
    .setPosition(20, 20)
    .setSize(130, 20);
  gui.addSlider("y_axis")
    .setRange(0, height)
    .setValue(height/2)
    .setPosition(20, 50)
    .setSize(130, 20);
  gui.addSlider("diameter")
    .setRange(10, 100)
    .setValue(55)
    .setPosition(20, 80)
    .setSize(130, 20);
  //gui.addBang("increment")
  //  .setPosition(55, 110)
  //  .setSize(60, 20)
  //  .getCaptionLabel()
  //  .align(ControlP5.CENTER, ControlP5.CENTER);
} //<>//

void draw() {
  background(128);
  flowerx(x, y, d);
  flowerx(width*3/4-x, height*3/4-y, d*1.5);
  flowerx(width-x/2, height-y/2, d/2);
}