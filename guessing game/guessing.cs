void Main()
{
	int randint = new Random().Next(0,10);	
	while(true)
	{
		int guessed = Convert.ToInt32(Console.ReadLine());
		if(guessed==randint)
			break;
		Console.WriteLine( guessed>randint? "Value too big!" : "Value too low!" );
	}
	Console.WriteLine($"Congratulations :D {randint} was the number.");
}
