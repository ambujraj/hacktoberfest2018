import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HashMapDemo {

	public static void main(String[] args) {
		HashMap<String, Integer> map = new HashMap<>();
		map.put("India", 300);
		map.put("USA", 200);
		map.put("Russia", 250);
		map.put("UK", 175);
		map.put("China", 320);
		map.put("Africa", 180);

		System.out.println("The keys and values of the HashMap are:" + map);

		System.out.println("The value of key India is " + map.get("India"));
		System.out.println("The value of key China is " + map.get("China"));
		System.out.println("The value of key Ireland is " + map.get("Ireland"));

		System.out.println("The value: " + map.remove("Africa") + " and the key Africa is removed");

		System.out.println("The hash map contains key Africa: " + map.containsKey("Africa"));

		System.out.println("");
		System.out.println("The set of keys in the HashMap are:");
		Set<String> keys = map.keySet();
		for (String key : keys) {
			System.out.println(key);
		}

		System.out.println("");
		System.out.println("The collection of values in the HashMap are:");
		Collection<Integer> values = map.values();
		for (Integer value : values) {
			System.out.println(value);
		}
		System.out.println("");
		System.out.println("The keys and corresponding values of the entries in the HashMap are");
		Set<Map.Entry<String, Integer>> entries = map.entrySet();
		for (Map.Entry<String, Integer> entry : entries) {
			System.out.print(entry.getKey() + "=>");
			System.out.println(entry.getValue());
		}
		System.out.println("");
		
		map.put("India", 325);
		System.out.println("India's value changed to 325 and the HashMap is: " + map);

		String str = "aaabbccddeaaa";
		System.out.println("The most frequent character in the String str is: " + maxFreq(str));

		int[] arr = { 1, 3, 1, 4, 5, 2, 3, 4, 5 };
		System.out.println("The unique elements in the array arr are: " + getUniqueElements(arr));

	}
	
	//Will return the character that most frequently occurs in any given string 
	public static char maxFreq(String str) {
		HashMap<Character, Integer> map = new HashMap<>();
		for (int i = 0; i < str.length(); i++) {
			char cc = str.charAt(i);
			if (map.containsKey(cc)) {
				int ov = map.get(cc);
				ov = ov + 1;
				map.put(cc, ov);
			} else {
				map.put(cc, 1);
			}
		}

		Set<Map.Entry<Character, Integer>> entries = map.entrySet();
		int maxValue = 0;
		char maxChar = '\0';

		for (Map.Entry<Character, Integer> entry : entries) {
			if (entry.getValue() > maxValue) {
				maxValue = entry.getValue();
				maxChar = entry.getKey();
			}
		}

		return maxChar;
	}

	//Will return only unique elements in a list (no repeats)
	public static ArrayList<Integer> getUniqueElements(int[] arr) {
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int value : arr) {
			map.put(value, 1);
		}
		ArrayList<Integer> list = new ArrayList<>();
		Set<Integer> keys = map.keySet();
		for (Integer key : keys) {
			list.add(key);
		}

		return list;
	}

}
