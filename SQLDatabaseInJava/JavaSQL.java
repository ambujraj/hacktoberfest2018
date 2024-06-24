// Voperak | https://github.com/Voperak
// 09/06/2018
// A program interface to send SQL querys to a database through Java using JDBC API.
// Created by following tutorial at https://www.tutorialspoint.com/jdbc/jdbc-create-tables.htm


// Imports
import java.sql.*; // SQL
import java.util.*; // Scanner
import java.io.*; // Password Obfuscator

public class JavaSQL {

	// JDBC_DRIVER url taken from tutorialspoint.com
	static final String JDBC_DRIVER = "com.mysql.jdbc.Driver"; 

	// Credentials cache
	static String db_url;
	static String db_user;
	static String db_pass;

	// Database cache
	static Connection conn = null;
	static Statement stmt = null;

	// App cache
	static String userInput;
	static int argStart;
	static Scanner scnr = new Scanner(System.in);

	// Get user command
	public static void getUserInput() {

		userInput = scnr.nextLine();
		argStart = (userInput.indexOf(" "));

		if (argStart == -1) {
			argStart = userInput.length();
		}
	}

	// Print commands
	public static void printCommands() {
		System.out.println("\n~ Commands:\n"
							+ " -setUser\n"
							+ " (Set the username credential)\n\n"
							+ " -setPass\n"
							+ " (Set the password credential (enter command only))\n\n"
							+ " -setUrl\n"
							+ " (Set the URL of the database)\n\n"
							+ " -connect\n"
							+ " (Attempt database connection)\n\n"
							+ " -query\n"
							+ " (Query an SQL statement (after connection))\n\n"
							+ " -disconnect\n"
							+ " (Close the connection to the database (may mess up your database by dumping buffer if you don't close))\n\n"
							+ " -smash\n"
							+ " (Exit the program)\n\n");
	}

	// Connect to Database
	public static void requestConnection() {
		try {

			// Registering a JDBC Driver
			Class.forName(JDBC_DRIVER);
			System.out.println("~ Success: JDBC driver registered");

			// Requesting Connection
			conn = DriverManager.getConnection("jdbc:mysql://" + db_url, db_user, db_pass);
			System.out.println("~ Success: Connected to database");

		} catch(SQLException se) { // Catch connection exception
			System.out.println("~ Error: Database connection failed");
			se.printStackTrace();

		} catch(Exception e) { // Catch driver exception
			System.out.println("~ Error: Registering JDBC driver failed");
			e.printStackTrace();

		}
	}

	// Close the database connection (end program)
	public static void closeConnection() {
		
		try {
	        if (stmt!=null) {
	            conn.close();
	            System.out.println("~ Success: Connection closed");
	        }
	    } catch(SQLException se) {
	    	System.out.println("~ Error: Closing connection failed");
	    	se.printStackTrace();
	    }
	    
	    try {
	        if (conn!=null) {
		        conn.close();
	            System.out.println("~ Success: Connection closed");
	    	}
	    } catch(SQLException se) {
	    		System.out.println("~ Error: Closing connection failed");
	        	se.printStackTrace();
	    }
	}

	// Query the statement for the database
	public static void queryStatement(String passedQuery, Statement stmt1, Connection conn1) {

		try {
			stmt1 = conn1.createStatement();
			stmt1.executeUpdate(passedQuery);
			System.out.println("~ Success: Query was executed on database");
		} catch (SQLException se) {
			System.out.println("~ Error: Query could not be executed");
			se.printStackTrace();
		}
	}

	// Main Method
	public static void main(String[] args) {


		Console console = System.console();
		// Check if console var exists
		if (console == null) {
			System.out.println("~ Error: Could not get console instance. Aborting!");
			System.exit(0);
		}

		printCommands();

		getUserInput(); // Grab command

		while (!(userInput.equals("-smash"))) {

			String cmd = userInput.substring(0, argStart);

			// Command Case
			if (cmd.equals("-setUser")) {
				db_user = userInput.substring(argStart + 1);
				System.out.println("~ Username has been set!");

			} else if (cmd.equals("-setPass")) {
				char[] password = System.console().readPassword("Password: ");
				db_pass = new String(password);
				System.out.println("~ Password set!");

			} else if (cmd.equals("-setUrl")) {
				db_url = userInput.substring(argStart + 1);
				System.out.println("~ URL has been set!");

			} else if (cmd.equals("-connect")) {
				System.out.println("~ Attempting connection");
				requestConnection();

			} else if (cmd.equals("-disconnect")) {
				closeConnection();
			
			} else if (cmd.equals("-query")) {
				queryStatement(userInput.substring(argStart), stmt, conn);
			
			} else if (cmd.equals("-cmd")) {
				printCommands();

			} else {
				System.out.println("~ Error: Invalid command! Type -cmd to list all commands!");
			}

			getUserInput(); // Grab next command

		}

	}

}
