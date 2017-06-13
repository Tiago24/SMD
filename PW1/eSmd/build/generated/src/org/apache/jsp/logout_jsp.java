package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class logout_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent {

  private static final JspFactory _jspxFactory = JspFactory.getDefaultFactory();

  private static java.util.List<String> _jspx_dependants;

  private org.glassfish.jsp.api.ResourceInjector _jspx_resourceInjector;

  public java.util.List<String> getDependants() {
    return _jspx_dependants;
  }

  public void _jspService(HttpServletRequest request, HttpServletResponse response)
        throws java.io.IOException, ServletException {

    PageContext pageContext = null;
    HttpSession session = null;
    ServletContext application = null;
    ServletConfig config = null;
    JspWriter out = null;
    Object page = this;
    JspWriter _jspx_out = null;
    PageContext _jspx_page_context = null;

    try {
      response.setContentType("text/html;charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;
      _jspx_resourceInjector = (org.glassfish.jsp.api.ResourceInjector) application.getAttribute("com.sun.appserv.jsp.resource.injector");

      out.write("\n");
      out.write("\n");
      out.write("\n");
      out.write("<!DOCTYPE html>\n");
      out.write("<html>\n");
      out.write("    <head>\n");
      out.write("        <meta http-equiv=\"Content-Type\" content=\"text/html; charset=UTF-8\">\n");
      out.write("        <title>eSmd</title>\n");
      out.write("        <link rel=\"stylesheet\" type=\"text/css\" href=\"CSS/login.css\">\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <table id=\"acesso\">\n");
      out.write("            <tr><th colspan=\"2\">e-Smd</th></tr>\n");
      out.write("            <form method=\"post\" action=\"loginServlet\">\n");
      out.write("                <tr><td><label for=\"login\">Login</label></td> <td><input type=\"text\" id=\"login\" name=\"login\" placeholder=\"Digite seu login\" size=\"13\" length=\"20\"></td></tr></br>\n");
      out.write("                <tr><td><label for=\"senha\">Senha</label></td> <td><input type=\"password\" id=\"senha\" name=\"senha\" placeholder=\"Digite sua senha\" size=\"13\" length=\"20\"></td></tr></br>\n");
      out.write("                <tr><td colspan=\"2\"><input type=\"submit\" value=\"Entrar\"></td> <td></td></tr>\n");
      out.write("            </form>\n");
      out.write("        </table>\n");
      out.write("        <b>*Sua sessão foi encerrada</b>\n");
      out.write("    </body>\n");
      out.write("</html>\n");
    } catch (Throwable t) {
      if (!(t instanceof SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          out.clearBuffer();
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
