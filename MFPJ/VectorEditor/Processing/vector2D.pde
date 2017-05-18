class Vector2D {

  private Point2D m_initial;
  private Point2D m_terminal;
  
  public Vector2D() {
    this(new Point2D(), new Point2D());
  }
  
  public Vector2D(float x1, float y1, float x2, float y2) {
    this(new Point2D(x1, y1), new Point2D(x2, y2));
  }
  
  public Vector2D(Point2D initial, Point2D terminal) {
    m_initial = initial;
    m_terminal = terminal;
  }
  
  public Point2D initial() {
    return m_initial;
  }

  public Point2D terminal() {
    return m_terminal;
  }

  public float magnitude() {
    // THIS RETURNS THE MAGNITUDE OF THE VECTOR SQUARED
    return (pow(m_terminal.x() - m_initial.x(), 2.0) + 
    pow(m_terminal.y() - m_initial.y(), 2.0));
  }

}