// Iterative way to search an element in linked list in Java
class Node 
{ 
    int data; 
    Node next; 
    Node(int n) 
    { 
        data = n; 
        next = null; 
    } 
} 
class LinkedList 
{ 
    Node head;    
    public void push(int new_data) 
    { 
        Node new_node = new Node(new_data); 
        new_node.next = head; 
        head = new_node; 
    } 
    public boolean search(Node head, int x) 
    { 
        Node current = head;    
        while (current != null) 
        { 
            if (current.data == x) 
                return true;   
            current = current.next; 
        } 
        return false;    
    } 
    // Main Function
    public static void main(String args[]) 
    {
        LinkedList new_list = new LinkedList(); 
  
        new_list.push(10); 
        new_list.push(30); 
        new_list.push(20); 
        new_list.push(40); 
        new_list.push(50); 
  
        if (llist.search(new_list.head, 40)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
    } 
} 
