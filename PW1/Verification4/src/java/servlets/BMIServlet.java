/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package servlets;

import java.io.IOException;
import java.io.PrintWriter;
import static java.lang.Math.pow;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author William Ribeiro
 */
@WebServlet(name = "BMIServlet", urlPatterns = {"/BMIServlet"})
public class BMIServlet extends HttpServlet {
    
    private float bmi;
    private String condition;

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        
        float height = Float.parseFloat(request.getParameter("height"));
        float weight = Float.parseFloat(request.getParameter("weight"));
        
        if(height > 0.0 && weight > 0.0) {
            HttpSession session = request.getSession(true);
            
            bmi = (float) (weight / pow(height, 2.0));
            
            if(bmi < 15.0) condition = "Very severely underweight";
            else if(bmi >= 15.0 && bmi < 16.0) condition = "Severely underweight";
            else if(bmi >= 16.0 && bmi < 18.5) condition = "Underweight";
            else if(bmi >= 18.5 && bmi < 25.0) condition = "Healthy";
            else if(bmi >= 25.0 && bmi < 30.0) condition = "Overweight";
            else if(bmi >= 30.0 && bmi < 35.0) condition = "Moderately obese";
            else if(bmi >= 35.0 && bmi < 40.0) condition = "Severely obese";
            else if(bmi >= 40.0) condition = "Very severely obese";
            
            request.setAttribute("condition", condition);
            request.setAttribute("bmi", bmi);
            
            request.getRequestDispatcher("result.jsp").forward(request, response);
        } else {
            response.sendRedirect("logout.html");
        }
    }
}
