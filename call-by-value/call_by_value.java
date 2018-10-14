public class call_by_value{
public int add(int x)
  { 
     x=x+10;
     return x;
  }
public static void main(String s[])
  {
    int y=5;
    System.out.println(y);
    add(y);
    System.out.println(y);
  }
}
