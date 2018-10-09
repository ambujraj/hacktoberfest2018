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

}
