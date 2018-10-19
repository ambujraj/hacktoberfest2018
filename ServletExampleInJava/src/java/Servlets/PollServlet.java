
package Servlets;

import DAO.PollDao;
import Data.Candidate;
import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author jayesh
 */
@WebServlet(name = "PollServlet", urlPatterns = {"/Poll"})
public class PollServlet extends HttpServlet {  
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);        
    }
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }    
    
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try (PrintWriter out = response.getWriter()) {   
            
            switch(request.getParameter("action")){
                
                case "addnames" :
                    String[] split = request.getParameter("candidates").split("\n");  
                    Candidate[] Candidates = poll.setCandidates(split);

                    for(Candidate c : Candidates)
                        out.println(c.getName() + "<br/>");
                break;
                
                case "vote" :
                    if(poll.vote(Integer.parseInt(request.getParameter("id"))))
                        out.println("Your vote has been recorded");
                    else
                        out.println("Some error occoured");
                break;
                
                case "summary" :
                    Candidate[] summary = poll.getSummary();
                    out.println("<b> Candidate Name : Votes <br/>");
                    for(Candidate c : summary)
                        out.println(c.getName() + " : " + c.getVoteCount() + "<br/>");
                    
                    out.println("--------------------------------------<br>" + poll.winner());
                break;
            }
        }
    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }
    
    PollDao poll = new  PollDao();

}
