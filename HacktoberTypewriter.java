import java.util.*;

class HacktoberTypewriter {
  public static void main(String []args) {
    String text = "HACKTOBERFEST 2018 :)";
    int i;
    System.out.printf("\t");
    for(i = 0; i < text.length(); i++){
	System.out.printf("%c", text.charAt(i));
    	try{
          Thread.sleep(150);//0.5s pause between characters
    	} catch(InterruptedException ex){
          Thread.currentThread().interrupt();
    	}
    }
  }
}