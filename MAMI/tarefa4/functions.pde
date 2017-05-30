int MRU(int v, int t) {
  return v * t;
}

void grid() {
  for(int i = 0; i < 10; i++) {
    line(i*width/10, 0, i*width/10, height);
    line(0, i*height/10, width, i*height/10);
  }
}