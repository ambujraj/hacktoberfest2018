public class HelloHacktoberfest{

     public static void main(String []args){
        int thisYear = 2018;
        int previousYear = 2017;
        System.out.println("Hello Hacktoberfest "+returnBiggerInt(thisYear,previousYear));
     }
     
    public static int returnBiggerInt(int a , int b)
    {
        if(a>b)
        {
            return a;
        }
        return b;
    }
}