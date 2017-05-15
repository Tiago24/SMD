<%-- 
    Document   : result
    Created on : May 14, 2017, 4:57:59 PM
    Author     : William Ribeiro
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Your Result</title>
    </head>
    <body>
        <h3>You are: </h3>
        <% String condition = (String) request.getParameter("condition");
        out.println(condition);
        %>
        <h4>Your BMI: </h4>
        <% String bmi = (String) request.getParameter("bmi");
        out.println(bmi);
        %>
    </body>
</html>
