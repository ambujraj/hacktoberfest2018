import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HashMapDemo {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HashMap<String, Integer> map = new HashMap<>();
		map.put("India", 300);
		map.put("USA", 200);
		map.put("Russia", 250);
		map.put("UK", 175);
		map.put("China", 320);
		map.put("Africa", 180);

		System.out.println(map);

		System.out.println(map.get("India"));
		System.out.println(map.get("China"));
		System.out.println(map.get("Ireland"));

		System.out.println(map.remove("Africa"));

		System.out.println(map.containsKey("Africa"));

		Set<String> keys = map.keySet();
		for (String key : keys) {
			System.out.println(key);
		}

		Collection<Integer> values = map.values();
		for (Integer value : values) {
			System.out.println(value);
		}

		Set<Map.Entry<String, Integer>> entries = map.entrySet();
		for (Map.Entry<String, Integer> entry : entries) {
			System.out.print(entry.getKey() + "=>");
			System.out.println(entry.getValue());
		}

		map.put("India", 325);
		System.out.println(map);

		String str = "aaabbccddeaaa";
		System.out.println(maxFreq(str));

		int[] arr = { 1, 3, 1, 4, 5, 2, 3, 4, 5 };
		System.out.println(getUniqueElements(arr));

	}

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
