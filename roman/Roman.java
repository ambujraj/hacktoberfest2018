import java.util.*;

public class Roman{

	public static int romanToInt(String s) {
        	Map<Character, Integer> map = new HashMap<>();
        	map.put('I', 1);
        	map.put('V', 5);
        	map.put('X', 10);
        	map.put('L', 50);
        	map.put('C', 100);
        	map.put('D', 500);
        	map.put('M', 1000);
        	char[] characters = s.toCharArray();
        	int sum = 0;
        	int lastVal = 0;
        	for (Character c : characters) {
			if(!map.containsKey(c)){
				System.out.println("Not valid Roman Numeral");
				System.exit(0);
			}
            		int val = map.get(c);
            		if (val > lastVal){
                		sum = sum - 2 * lastVal + val;
            		}else{
                		sum += val;
            		}
            		lastVal = val;
        	}
        	return sum;
        
    	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Please type in a roman numeral number: ");
		String number = sc.nextLine();
		int result = romanToInt(number);
		System.out.println("The number is " + result);
	}

}
