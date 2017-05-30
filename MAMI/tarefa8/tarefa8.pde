import gifAnimation.*;

void setup() {
  size(300, 300);
  frameRate(fps);

  export = new GifMaker(this, "tarefa8.gif");
  export.setRepeat(0);
}

void draw() {
  background(0);
  //moveBox(0.0, 100.0, 10.0);
  moveBox2D(0.0, 0.0, 200.0, 100.0, 10.0);

  export.setDelay(1000/fps);
  export.addFrame();
}