public class Factorial{
    public static void main(String []args){
        int x=fact(5);
        System.out.print(x);


    }

    public static int fact(int num){
        int answer = num;
        if(num == 0){
            answer = 1;
        }

        while(num>0){
            return answer*fact(num-1);

        }
        
        return answer;

    }
}