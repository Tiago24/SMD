import gifAnimation.*;

void setup() {
  size(120, 120);
  frameRate(60);
  background(255);
  grid();
  export = new GifMaker(this, "tarefa4.gif");
  export.setRepeat(0);
}

void draw() {
  distance = MRU(velocity, time);
  ellipse(distance+radius, height/2, 2*radius, 2*radius);
  time++;
  export.setDelay(1000/60);
  export.addFrame();
}