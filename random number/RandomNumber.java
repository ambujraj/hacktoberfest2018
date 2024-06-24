/* Class that provides a random number
@Author: Rasmus Knoth Nielsen
 */

public class RandomNumber
{
    // Constructor
    public RandomNumber(){}

    // Method that provides a random number between the two provided numbers
    int intWithRange(int min, int max)
    {
        int range = (max - min) + 1;
        return (int)(Math.random() * range) + min;
    }

    // Main method to test if the method works as intended
    public static void main(String[] args) {
        RandomNumber random = new RandomNumber();
        System.out.println(random.intWithRange(2,7));
    }
}