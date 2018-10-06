
public class CallByReference
{
  public void display(StringBuffer sb2)
  {
    sb2.append("World");
    System.out.println(sb2);                       // prints HelloWorld
  }
  public static void main(String args[])
  {
    CallByReference cbr = new CallByReference();
    StringBuffer sb1 = new StringBuffer("Hello");
    cbr.display(sb1);
    System.out.println(sb1);                       // prints HelloWorld
  }
}