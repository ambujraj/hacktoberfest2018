public class CallByValue
{

  public void display(int y)
  {
    y = 20;
  }
  public static void main(String args[])
  {
    CallByValue cbv = new CallByValue();
    int x = 10;
    cbv.display(x);
    System.out.println(x);                        // prints 10 and not 20    
  }
}