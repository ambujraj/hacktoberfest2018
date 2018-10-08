import java.util.Scanner;
import java.util.ArrayList;

class Main {

  public static int getInput() {
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the your number: ");
    int number = sc.nextInt();
    sc.close();
    return number;
  }

  public static boolean checklist(ArrayList<Integer> num, int digits) {
    int x = 0;
    int y = digits - 1;
    while (x < digits / 2) {
      if (num.get(x) == num.get(y)) {
        x += 1;
        y -= 1;
      } else {
        return false;
      }
    }
    return true;
  }

  public static void main(String[] args) {

    int number = Main.getInput();

    // determining number of digits
    int digits = 1;
    int divider = number;
    while (divider / 10 >= 1) {
      divider /= 10;
      digits += 1;
    }

    // listing digits of number
    ArrayList<Integer> num = new ArrayList<>();
    while (number > 0) {
      num.add(number % 10);
      number /= 10;
    }

    // check for palindrome
    boolean palin = Main.checklist(num, digits);
    if (palin) {
      System.out.println("Number is a palindrome");
    } else {
      System.out.println("Number is not a palindrome");
    }

  }
}