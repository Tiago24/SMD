/*
 * add the following lines at the end of setup()
 * export = new GifMaker(this, "filename.gif");
 * export.setRepeat(0);
 * add the following lines at the end of draw()
 * export.setDelay(1000/fps);
 * export.addFrame();
 */
GifMaker export;
int fps = 2;

void mousePressed() {
  export.finish();
}