function linkedList(){
  this.head = null;
  this.tail = null;
}
function Node(value,next,prev){
  this.value = value;
  this.next = next;
  this.prev = prev;
}

//why are they null? In the beginning, we don't have any code.

//creating the head node:
linkedList.prototype.addToHead = function(value){
  const newNode = new Node(value, this.head, null);
  if (this.head) this.head.prev = newNode;
  else this.tail = newNode
  this.head = newNode;
}
//we create method inside linkedList prototype to prevent duplicating methods
//for each object

//creating tail Node

linkedList.prototype.addToTail = function(value){
  const newNode = new Node(value, null, this.tail);
  if (this.tail) this.tail.next = newNode;
  else this.head = newNode;
  this.tail = newNode;
}

//searching nodes:
linkedList.prototype.search = function(searchValue){
  let currentNode = this.head;

  while (currentNode){
    if (currentNode.value === searchValue) return currentNode;
    currentNode = currentNode.next;
  }
  return null;
}
//we are saving currentNode variable the value of this.head
//then! while the currentNode is not undefined, we compare to existing node
//with the value that we are passing in, if not we return null

//searching node...
const list = new linkedList();
list.addToHead(1);
list.addToTail(2);

console.log(list.search(1));
console.log(list.search(2));
console.log(list.search(5)); //false. there is no node 5.
