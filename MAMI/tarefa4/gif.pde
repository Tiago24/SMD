/*
 * add the following lines at the end of setup()
 * export = new GifMaker(this, "tarefa4.gif");
 * export.setRepeat(0);
 * add the following lines at the end of draw()
 * export.setDelay(1000/60);
 * export.addFrame();
 */
GifMaker export;

void mousePressed() {
  export.finish();
}