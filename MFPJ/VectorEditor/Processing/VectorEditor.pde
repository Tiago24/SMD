Vector2D[] v;
Vector2D s;
int l;

void setup() {
  size(800, 600);
  v = new Vector2D[4];
  l = v.length - 1;
  v[0] = new Vector2D(random(0.0, 600.0), random(0.0, 400.0), random(0.0, 600.0), random(0.0, 400.0));
  v[1] = new Vector2D(v[0].terminal().x(), v[0].terminal().y(), random(0.0, 600.0), random(0.0, 400.0));
  v[2] = new Vector2D(v[1].terminal().x(), v[1].terminal().y(), random(0.0, 600.0), random(0.0, 400.0));
  v[3] = new Vector2D(v[2].terminal().x(), v[2].terminal().y(), random(0.0, 600.0), random(0.0, 400.0));
  s = new Vector2D(v[0].initial().x(), v[0].initial().y(), v[l].terminal().x(), v[l].terminal().y());
}

void draw() {
  stroke(#000000);
  fill(#000000);
  for(int i = 0; i <= l; i++) {
    line(v[i].initial().x(), v[i].initial().y(), v[i].terminal().x(), v[i].terminal().y());
    ellipse(v[i].terminal().x(), v[i].terminal().y(), 5.0, 5.0);
    text("v[" + i + "]", v[i].initial().x(), v[i].initial().y());
  }
  stroke(#0000FF);
  fill(#0000FF);
  line(s.initial().x(), s.initial().y(), s.terminal().x(), s.terminal().y());
  ellipse(s.terminal().x(), s.terminal().y(), 5.0, 5.0);
  text("s", s.terminal().x(), s.terminal().y());
}