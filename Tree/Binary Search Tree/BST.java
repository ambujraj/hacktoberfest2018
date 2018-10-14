class Node
{
	int value;
	Node left;
	Node right;
	public Node(int value)
	{
		this.value = value;
		left = null;
		right = null;
	}
}
class BinarySearchTree
{
	Node root;
	public BinarySearchTree()
	{
		root = null;
	}
	public boolean is_left(Node current)
	{
		if(current.left==null) return false;
		else return true;
	}
	public boolean is_right(Node current)
	{
		if(current.right==null) return false;
		else return true;
	}
	public Node add_node(Node current, int value)
	{
		if(value<current.value)
		{
			if(is_left(current))
				return add_node(current.left, value);
			else return current;
		}
		else
		{
			if(is_right(current))
				return add_node(current.right, value);
			else return current;
		}
	}
	public void add(int value)
	{
		Node temp = new Node(value);
		if(root==null)
			root = temp;
		else
		{
			Node x = add_node(root, value);
			if(value < x.value) x.left = temp;
			else x.right = temp;
		}
	}
	public Node find(Node current, int value)
	{
		if(current == null) return null;
		if(current.value == value) return current;
		else if(value < current.value) return find(current.left, value);
		else return find(current.right, value);
	}
	public Node search(int value)
	{
		return find(root, value);
	}
	public void preorder(Node current)
	{
		if(current != null)
		{
			System.out.print(current.value + " ");
			preorder(current.left);
			preorder(current.right);
		}
	}
	public void preorder_traversal()
	{
		System.out.println("Preorder Traversal :");
		preorder(root);
		System.out.println();
	}
	public void inorder(Node current)
	{
		if(current != null)
		{
			inorder(current.left);
			System.out.print(current.value + " ");
			inorder(current.right);
		}
	}
	public void inorder_traversal()
	{
		System.out.println("Inorder Traversal :");
		inorder(root);
		System.out.println();
	}
	public void postorder(Node current)
	{
		if(current != null)
		{
			postorder(current.left);
			postorder(current.right);
			System.out.print(current.value + " ");
		}
	}
	public void postorder_traversal()
	{
		System.out.println("Postorder Traversal :");
		postorder(root);
		System.out.println();
	}
}
class BSTApp
{
	public static void main(String args[])
	{
		Scanner in = new Scanner(Sysetm.in);
		BinarySearchTree app = new BinarySearchTree();
		app.add(50);
		app.add(70);
		app.add(10);
		app.add(80);
		app.add(30);
		app.add(20);
		app.add(90);
		app.add(60);
		app.add(0);
		app.add(40);
		
		app.preorder_traversal();
		app.inorder_traversal();
		app.postorder_traversal();
		
		System.out.print("Enter a number to search : ");
		int sch = in.nextInt();
		Node sch_node = app.search(sch);
		if(sch_node != null) System.out.print("Value Found");
		else System.out.print("Value Not Found");
	}
}