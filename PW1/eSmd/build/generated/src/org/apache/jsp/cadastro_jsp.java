package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class cadastro_jsp extends org.apache.jasper.runtime.HttpJspBase
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
      out.write("        <link rel=\"stylesheet\" type=\"text/css\" href=\"CSS/cadastro.css\"/>\n");
      out.write("    </head>\n");
      out.write("    <body>\n");
      out.write("        <form method=\"post\" action=\"ServletDao\" id=\"formulario\">\n");
      out.write("            <span>e-Smd</span>\n");
      out.write("            <fieldset>\n");
      out.write("                <table>\n");
      out.write("                    <legend>Dados Pessoais</legend>\n");
      out.write("                    <tr><td><label for=\"nome\">Nome</label></td> <td><input type=\"text\" name=\"nome\" id=\"nome\" placeholder=\"Digite seu nome completo\"/></td></tr></br>\n");
      out.write("                    <tr><td><label for=\"email\">E-mail</label></td> <td><input type=\"email\" name=\"email\" id=\"email\" placeholder=\"Digite seu email principal\"/></td></tr></br>\n");
      out.write("                    <tr><td><label for=\"celular\">Celular</label></td> <td><input type=\"tel\" name=\"celular\" id=\"celular\" placeholder=\"Digite seu número para contato\"/></td></tr><br/>\n");
      out.write("                    <tr><td><label for=\"dataNasc\">Data de Nascimento</label></td> <td><input type=\"date\" name=\"dataNasc\" id=\"dataNasc\" size=\"13\"/></td></tr><br/>\n");
      out.write("                    <tr><td><label for=\"sexo\">Sexo</label></td> \n");
      out.write("                        <td><select id=\"sexo\">\n");
      out.write("                                <option value=\"M\">Masculino</option>\n");
      out.write("                                <option value=\"F\">Feminino</option>\n");
      out.write("                            </select>\n");
      out.write("                        </td>\n");
      out.write("                    </tr>\n");
      out.write("                </table>\n");
      out.write("            </fieldset>\n");
      out.write("            <fieldset>\n");
      out.write("                <table>\n");
      out.write("                    <legend>Endereço de entrega</legend>\n");
      out.write("                    <tr><td><label for=\"nome\">Nome</label></td> <td><input type=\"text\" name=\"nome\" id=\"nome\" placeholder=\"Digite seu nome completo\"/></td></tr></br>\n");
      out.write("                    <tr><td><label for=\"email\">E-mail</label></td> <td><input type=\"email\" name=\"email\" id=\"email\" placeholder=\"Digite seu email principal\"/></td></tr></br>\n");
      out.write("                    <tr><td><label for=\"celular\">Celular</label></td> <td><input type=\"tel\" name=\"celular\" id=\"celular\" placeholder=\"Digite seu número para contato\"/></td></tr><br/>\n");
      out.write("                    <tr><td><label for=\"dataNasc\">Data de Nascimento</label></td> <td><input type=\"date\" name=\"dataNasc\" id=\"dataNasc\" size=\"13\"/></td></tr><br/>\n");
      out.write("                    <tr><td><label for=\"sexo\">Sexo</label></td> \n");
      out.write("                        <td><select id=\"sexo\">\n");
      out.write("                                <option value=\"M\">Masculino</option>\n");
      out.write("                                <option value=\"F\">Feminino</option>\n");
      out.write("                            </select>\n");
      out.write("                        </td>\n");
      out.write("                    </tr>\n");
      out.write("                </table>\n");
      out.write("            </fieldset>\n");
      out.write("            <fieldset>\n");
      out.write("                <legend>Acesso no e-Smd</legend>\n");
      out.write("            </fieldset>\n");
      out.write("            <input type=\"submit\" value=\"Cadastrar\"/>\n");
      out.write("        </form>\n");
      out.write("        <footer>\n");
      out.write("            \n");
      out.write("        </footer>\n");
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
