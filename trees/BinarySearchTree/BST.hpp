#ifndef BSTREE_HPP
#define BSTREE_HPP 1

#include <iostream>

#define MIN(a, b) (a < b)?(a):(b)
#define MAX(a, b) (a > b)?(a):(b)

using namespace std;

template <typename Key, typename Value>
class BinaryNode
{
public:
  Key key;
  Value val;
  BinaryNode<Key, Value> * root,* left,* right,* parent;
  BinaryNode();
  BinaryNode(Key key, Value value);
};

template <typename Key, typename Value>
class BSTree
{
 protected:

  int getHeight(BinaryNode<Key, Value> *curr, int level);
  void print_in_order(BinaryNode<Key, Value>* curr);
  void print_pre_order(BinaryNode<Key, Value>* curr);
  void print_post_order(BinaryNode<Key, Value>* curr);

 public:

  int getHeight();
  int size();
  void print();
  Value get(const Key& key);
  void remove(const Key& key);
  bool has(const Key& key);
  void put(const Key& key, const Value& value);
  Key minimum();
  Key maximum();
  Key successor(const Key& key);
  Key predecessor(const Key& key);
  void print_in_order();
  void print_pre_order();
  void print_post_order();
};

template<typename Key, typename Value>
int BSTree<Key, Value>::getHeight(BinaryNode<Key, Value> *curr, int level)
{
  static int height = 0;
  if(curr == NULL)
  {
    return -1;
  }
  if(curr->left)
  {
    height = getHeight(curr->left, level+1);
  }
  if(curr->right)
  {
    height = getHeight(curr->right, level+1);
  }
  height = MAX(height, level);
  return height;
}

template<typename Key, typename Value>
int BSTree<Key, Value>::getHeight()
{
  return getHeight(this->root, 0);
}

template<typename Key, typename Value>
int BSTree<Key, Value>::size()
{
  return this->currSize;
}

template<typename Key, typename Value>
void BSTree<Key, Value>::print()
{
  this->print_in_order();
}

template<typename Key, typename Value>
Value BSTree<Key, Value>::get(const Key& key)
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return Value();
  }
  while(curr->key != key)
  {
    if(key < curr->key && curr->left)
    {
      curr = curr->left;
    }
    else if(key > curr->key && curr->right)
    {
      curr = curr->right;
    }
    else
    {
      return Value();
    }
  }
  return curr->val;
}

template<typename Key, typename Value>
void BSTree<Key, Value>::remove(const Key& key)
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return;
  }
  while(curr->key != key)
  {
    if(key < curr->key && curr->left)
    {
      curr = curr->left;
    }
    else if(key > curr->key && curr->right)
    {
      curr = curr->right;
    }
    else
    {
      return;
    }
  }
  if(!curr->left && !curr->right)
  {
    if((curr->parent)->left == curr)
    {
      (curr->parent)->left = NULL;
    }
    else if((curr->parent)->right == curr)
    {
      (curr->parent)->right = NULL;
    }
    delete curr;
  }
  else if(curr->left && !curr->right)
  {
    if((curr->parent)->left == curr)
    {
      (curr->parent)->left = curr->left;
    }
    else if((curr->parent)->right == curr)
    {
      (curr->parent)->right = curr->left;
    }
    (curr->left)->parent = curr->parent;
    delete curr;
  }
  else if(!curr->left && curr->right)
  {
    if((curr->parent)->left == curr)
    {
      (curr->parent)->left = curr->right;
    }
    else if((curr->parent)->right == curr)
    {
      (curr->parent)->right = curr->right;
    }
    (curr->right)->parent = curr->parent;
    delete curr;
  }
  else
  {
    BinaryNode<Key, Value> *succ = curr->right;
    while(succ->left)
    {
      succ = succ->left;
    }
    curr->key = succ->key;
    curr->val = succ->val;
    if(succ->right)
    {
      (succ->right)->parent = succ->parent;
    }
    (succ->parent)->left = succ->right;
    delete succ;
  }
}

template<typename Key, typename Value>
bool BSTree<Key, Value>::has(const Key& key)
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return false;
  }
  while(curr->key != key)
  {
    if(key < curr->key && curr->left)
    {
      curr = curr->left;
    }
    else if(key > curr->key && curr->right)
    {
      curr = curr->right;
    }
    else
    {
      return false;
    }
  }
  return true;
}

template<typename Key, typename Value>
void BSTree<Key, Value>::put(const Key& key, const Value& value)
{
  BinaryNode<Key, Value> *curr = this->root;
  (this->currSize)++;
  BinaryNode<Key, Value> *newNode = new BinaryNode<Key, Value>;
  newNode->key = key;
  newNode->val = value;
  newNode->root = this->root;
  if(curr == NULL)
  {
    this->root = newNode;
    newNode->root = newNode;
    return;
  }
  while(1)
  {
    if(key <= curr->key && curr->left)
    {
      curr = curr->left;
    }
    else if(key > curr->key && curr->right)
    {
      curr = curr->right;
    }
    else
    {
      break;
    }
  }
  if(key <= curr->key)
  {
    curr->left = newNode;
    newNode->parent = curr;
  }
  else if(key > curr->key)
  {
    curr->right = newNode;
    newNode->parent = curr;
  }
}

template<typename Key, typename Value>
Key BSTree<Key, Value>::minimum()
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return Key();
  }
  while(curr->left)
  {
    curr = curr->left;
  }
  return curr->key;
}

template<typename Key, typename Value>
Key BSTree<Key, Value>::maximum()
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return Key();
  }
  while(curr->right)
  {
    curr = curr->right;
  }
  return curr->key;
}

template<typename Key, typename Value>
Key BSTree<Key, Value>::successor(const Key& key)
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return Key();
  }
  Key min = Key();
  while(curr->key != key)
  {
    if(key < curr->key && curr->left)
    {
      min = curr->key;
      curr = curr->left;
    }
    else if(key > curr->key && curr->right)
    {
      curr = curr->right;
    }
    else
    {
      return Key();
    }
  }
  if(curr->right)
  {
    curr = curr->right;
    while(curr->left)
    {
      curr = curr->left;
    }
    return curr->key;
  }
  else
  {
    return min;
  }
}

template<typename Key, typename Value>
Key BSTree<Key, Value>::predecessor(const Key& key)
{
  BinaryNode<Key, Value> *curr = this->root;
  if(curr == NULL)
  {
    return Key();
  }
  Key  max = Key();
  while(curr->key != key)
  {
    if(key < curr->key && curr->left)
    {
      curr = curr->left;
    }
    else if(key > curr->key && curr->right)
    {
      max = curr->key;
      curr = curr->right;
    }
    else
    {
      return Key();
    }
  }
  if(curr->left)
  {
    curr = curr->left;
    while(curr->right)
    {
      curr = curr->right;
    }
    return curr->key;
  }
  else
  {
    return max;
  }
}

template<typename Key, typename Value>
void BSTree<Key, Value>::print_in_order(BinaryNode<Key, Value>* curr)
{ 
  if(curr->left)
  {
    print_in_order(curr->left);
  }
  cout << "(" << curr->key << ", " << curr->val << ")" << endl;
  if(curr->right)
  {
    print_in_order(curr->right);
  }
}

template<typename Key, typename Value>
void BSTree<Key, Value>::print_pre_order(BinaryNode<Key, Value>* curr)
{ 
  cout << "(" << curr->key << ", " << curr->val << ")" << endl;
  if(curr->left)
  {
    print_pre_order(curr->left);
  }
  if(curr->right)
  {
    print_pre_order(curr->right);
  }
}

template<typename Key, typename Value>
void BSTree<Key, Value>::print_post_order(BinaryNode<Key, Value>* curr)
{ 
  if(curr->left)
  {
    print_post_order(curr->left);
  }
  if(curr->right)
  {
    print_post_order(curr->right);
  }
  cout << "(" << curr->key << ", " << curr->val << ")" << endl;
}

#endif