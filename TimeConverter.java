import java.util.Scanner;

public class TimeConverter
{

	public static void main(String[] args)
	{
		// TODO Auto-generated method stub
		// Declare variables necessary for storing user input and making conversions

		Scanner keyboard = new Scanner(System.in).useDelimiter("\\s*:\\s*");
		int days = 0;
		int hours = 0;
		int minutes = 0;
		int seconds = 0;
		int remainingTime;
		int secondsTotal;
		boolean negativeSeconds = false;
		String outputFormat = "";
		final int SECONDS_PER_MINUTE = 60;
		final int SECONDS_PER_HOUR = 3600;
		final int SECONDS_PER_DAY = 86400;

		/*
		 * Prompt user to enter the number of hours, minutes, and seconds in the
		 * stated format and store the values
		 */
		System.out.println("Enter time in the form <hours : minutes : seconds>:");

		hours = keyboard.nextInt();
		minutes = keyboard.nextInt();
		seconds = keyboard.nextInt();

		// Calculate total seconds and convert to appropriate unit for simplified time
		secondsTotal = (minutes * SECONDS_PER_MINUTE) + (hours * SECONDS_PER_HOUR) + seconds;

		days = secondsTotal / SECONDS_PER_DAY;
		remainingTime = secondsTotal % SECONDS_PER_DAY;

		hours = remainingTime / SECONDS_PER_HOUR;
		remainingTime = remainingTime % SECONDS_PER_HOUR;

		minutes = remainingTime / SECONDS_PER_MINUTE;
		remainingTime = remainingTime % SECONDS_PER_MINUTE;

		seconds = remainingTime;

		/*
		 * Checks if seconds are negative. If so, get rid of the negative sign
		 * and make the variable negativeSeconds TRUE
		 */
		if (seconds < 0)
		{
			seconds = -seconds;
			negativeSeconds = true;
		}

		// Displays minutes and seconds
		if (hours == 0 && days == 0 && (minutes > 0 || minutes < 0))
		{
			outputFormat = (minutes + ":" + seconds + ":");
		}
		
		// Displays only seconds and makes negative if applicable
		else if (days == 0 && hours == 0 && minutes == 0)
		{
			if (seconds > 0 && negativeSeconds == true)
			{
				seconds = -seconds;
			}
			outputFormat = (seconds + ":");
		}
		
		// Displays hours, minutes, and seconds and removes negative from minutes
		else if (hours != 0)
		{
			if (minutes < 0)
			{
				minutes = -minutes;
			}
			outputFormat = (hours + ":" + minutes + ":" + seconds + ":");
		}
		
		// Displays days, hours, and minutes and removes negatives from latter units
		else
		{
			if (hours < 0)
			{
				hours = -hours;
			}
			if (minutes < 0)
			{
				minutes = -minutes;
			}
			outputFormat = (days + ":" + hours + ":" + minutes + ":" + seconds + ":");
		}

		// Display the total seconds and simplified time
		System.out.println("The time consists of: " + secondsTotal + " seconds." + "\nSimplified time: " + outputFormat);

		keyboard.close();
	}

}
