class ReverseInteger {
    public static int reverse(int x) {
        int reversed = 0;
        int y = 0;
        
        while(x!=0){
            reversed = y * 10 + x % 10;
            if((reversed - x % 10)/10 == y) {
                y = reversed;
            }else {
                return 0;
            }
            x = x/10;
        }
        
        if(x < 0) {
            return y * -1;
        }
        
        return y;
  }

  public static void main(String[] args) {
    System.out.println(reverse(12345));
  }
}