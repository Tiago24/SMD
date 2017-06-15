class Point2D {

  private float m_x;
  private float m_y;
    
  public Point2D() {
      this(0.0, 0.0);
    }

  public Point2D(float x, float y) {
      x(x);
      y(y);
    }
    
  public void x(float x) {
      m_x = x;
    }

  public float x() {
      return m_x;
    }

  public void y(float y) {
      m_y = y;
    }

  public float y() {
      return m_y;
    }

}