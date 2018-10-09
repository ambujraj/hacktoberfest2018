import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Trie {
	private class Node {
		Character data;
		HashMap<Character, Node> children;
		boolean isTerminal;

		Node(Character data, boolean isTerminal) {
			this.data = data;
			this.children = new HashMap<>();
			this.isTerminal = isTerminal;
		}
	}

	private Node root;
	private int numWords;

	Trie() {
		this.root = new Node('\0', false);
		this.numWords = 0;
	}
	public int getNumWords() { // To get number of words in Trie
		return numWords;
	}

	public boolean isEmpty() {    // To check if Trie is empty
		return this.getNumWords() == 0;
	}

	public void addWord(String word) {    // To add a word in Trie
		this.addWord(this.root, word);
	}
	private void addWord(Node parent, String word) {
		if (word.length() == 0) {
			if (parent.isTerminal) {

			} else {
				parent.isTerminal = true;
				this.numWords++;
			}
			return;
		}
		char cc = word.charAt(0);
		String ros = word.substring(1);
		Node child = parent.children.get(cc);
		if (child == null) {
			child = new Node(cc, false);
			parent.children.put(cc, child);
		}
		this.addWord(child, ros);
	}

	public void display() {
		this.display(this.root, "");
	}


}
