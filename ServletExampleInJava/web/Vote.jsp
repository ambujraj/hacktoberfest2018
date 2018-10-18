<%-- 
    Document   : Vote.jsp
    Created on : Aug 20, 2018, 1:14:28 AM
    Author     : jayesh
--%>

<%@page import="Data.Candidate"%>
<%@page import="DAO.PollDao"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%! int i = 0; %>
        <%
            out.println(i++);
           %>
<!--        <form action="Poll">
        <%
            PollDao pd = new PollDao(); 
            Candidate cd[] = pd.getSummary();
            out.println("<input type='hidden' name='action' value='vote'/>");
            for(Candidate c : cd)               
            {
             %>
             <button type="submit" name="id" value="<%= c.getID()%>"> <%=c.getName()%></button><br/><br/>
             <%
            }
        %>
        </form>-->
    </body>
</html>
