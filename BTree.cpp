#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <class T>
struct BNode                                                 //описывает узел
{
	T data;
	BNode<T> *left, *right;
	BNode(T dd, BNode<T> *l = nullptr, BNode<T> *r = nullptr) : data(dd), left(l), right(r) {}
	BNode() {
		data = -1;
		left = nullptr;
		right = nullptr;
	}
};

template <class T>
void print(BNode<T> *root, int offset = 0)                   //печатает дерево
{
	if (root == nullptr) return;
	print(root->right, offset + 3);
	for (int i = 0; i < offset; i++)
		cout << " ";
	cout << root->data << endl;
	print(root->left, offset + 3);
}

template <class T>
int childrenNumber(BNode<T> *root)                           //возвращает количество сыновей корня
{
	int i = 0;
	if (root == nullptr) return 0;
	if (root->left != nullptr) i++;
	if (root->right != nullptr) i++;
	return i;
}

template <class T>
void delLeftSon(BNode<T> *root)                            //удаляет левого сына если он лист
{
	if (root->left == nullptr) return;
	delete root->left;
	root->left = nullptr;
}

template <class T>
BNode<T> * obtainRightGrandson(BNode<T> *root)           //Возврашает указатель самого правого внукв
{
	if (root != nullptr && root->right != nullptr && root->right->right != nullptr)
		return root->right->right;
    if (root != nullptr && root->right != nullptr && root->right->left != nullptr)
		return root->right->left;
    if (root != nullptr && root->left != nullptr && root->left->right != nullptr)
		return root->left->right;
	if (root != nullptr && root->left != nullptr && root->left->left != nullptr)
		return root->left->left;
	return nullptr;
}

template <class T>
int NodeCount(BNode<T> * root)                                       //число узлов
{
	if (root->left == nullptr && root->right== nullptr)
		return 1;
	int l, r;
	if (root->left != nullptr)
		l = NodeCount(root->left);
	else
		l = 0;
	if (root->right!= nullptr)
		r = NodeCount(node->right);
	else
		r = 0;

	return l + r + 1;
}

template <class T>
int grandsonNumber(BNode<T> *root) {
	int count = 0;
	if (root == nullptr) return count;
	count = childrenNumber(root->left) + childrenNumber(root->right);
	return count;
}

template <class T>
void delRoot(BNode<T> **root) {
	if ((*root) == nullptr || (*root)->right != nullptr) return;
	(*root) = (*root)->left;

}

template <class T>
void addNewRoot(BNode<T> ** root, T d) {
	BNode<T> *newRoot = new BNode<T>;
	BNode<T> *temp = new BNode<T>;
	temp->data = (*root)->data;
	if ((*root)->left != nullptr) {
		temp->left = (*root)->left;
	}
	if ((*root)->right != nullptr) {
		temp->right = (*root)->right;
	}
	newRoot->right = temp;
	newRoot->data = d;
	*root = newRoot;
	
}

template <class T>
void addNewLeftSon(BNode<T> *root, T d) {
	BNode<T> *newLeftSon = new BNode<T>(d, root->left, nullptr);
	root->left = newLeftSon;
}

template <class T>
void addNewLeftCoolSon(BNode<T> *root, T d) {
	BNode<T> *newLeftCoolSon = new BNode<T>(d, root->left, root->right);
	root->left = newLeftCoolSon;
	root->right = nullptr;
}

template <class T>
void swapRootAndLeftSon(BNode<T> **root) {
	BNode<T> *temp = new BNode<T>;
	temp->data = (*root)->data;
	if ((*root)->left != nullptr) {
		temp->left = (*root)->left;
	}
	if ((*root)->right != nullptr) {
		temp->right = (*root)->right;
	}

	*root = temp->left;
	swap((*root)->right, temp->right);
	temp->left = (*root)->left;
	(*root)->left = temp;
}

template <class T>
void leftSwap(BNode<T> **root) {
	BNode<T> *temp = new BNode<T>;
	temp->data = (*root)->data;
	if ((*root) -> left != nullptr)
	{
		temp->left =(*root)->left;
	}
	if ((*root) -> right != nullptr)
	{
		temp->right = (*root)->right;
	}
	*root = temp->right;
	temp->right = (*root)->left;
	(*root)->left = temp;
}

template <class T>
void rightSwap(BNode<T> **root) {
	BNode<T> *temp = new BNode<T>;
	temp->data = (*root)->data;
	if ((*root)->left != nullptr)
	{
		temp->left = (*root)->left;
	}
	if ((*root)->right != nullptr)
	{
		temp->right = (*root)->right;
	}
	*root = temp->left;
	temp->left = (*root)->right;
	(*root)->right = temp;
}


template <class T>
BNode<T> *obtainLeftNode(BNode<T> * root) {
	if (root == nullptr)
		return nullptr;
	BNode<T> *temp = new BNode<T>;
	while (root != nullptr)
	{
		temp = root;
		root = root->left;
	}
	return temp;

}

template <class T>
void rotation(BNode<T> **root) {      //не работает
		rightSwap(root);
		leftSwap(root);
	

}

template <class T>
BNode<T> *obtainLeftLeaf(BNode<T> *root) {
	BNode<T> *temp = new BNode<T>;
	temp = obtainLeftNode(root);
	if (temp->right == nullptr) {
		retutn temp;
	}
	else {
		obtainLeftNode(root)
	}
}

template <class T>
int countNodes(BNode <T> * root) {
	int count = 0;
	BNode<T> *current;
	stack<BNode<T> *> st;
	st.push(root);
	if (root == nullptr) return 0;

	while (!st.empty()) {
		current = st.top();
		st.pop();
		count++;

		if (current->left != nullptr) {
			st.push(current->left);
		}
		if (current->right != nullptr) {
			st.push(current->right);
		}
	}
	return count;

}

template <class T>
bool leaf(BNode<T> * p) {
	return !(p->left || p->right);
}

template <class T>
int numLeafSons(BNode<T> * root) {
	queue<BNode<T> *> q;
	q.push(root);
	int leafCount = 0;
	while (!q.empty()) {
		BNode<T> *current = q.front();
		if (leaf(current)) leafCount++;
		if (current->left != nullptr) {
			q.push(current->left);
		}
		if (current->right != nullptr) {
			q.push(current->right);
		}
		q.pop();



	}
	return leafCount;
}







int main()
{
	setlocale(LC_ALL, "Russian");
	BNode<int>*cooltree = new BNode<int>(1, new BNode<int>(2,new BNode<int>(4),new BNode<int>(5)),  new BNode<int>(3, new BNode<int>(6)));
	print(cooltree);
	cout << endl;
	cout <<"Количество сыновей корня: "<< childrenNumber(cooltree) << endl;
	

	/*BNode<int>*cooltree2 = new BNode<int>(1, new BNode<int>(2), new BNode<int>(3, new BNode<int>(6)));
	delLeftSon(cooltree2);
	print(cooltree2);
	cout << endl;
	cout << "Количество сыновей корня: " << childrenNumber(cooltree2) << endl;
	
	BNode<int> *rightGrandson = obtainRightGrandson(cooltree);
	cout << "Указатель на самого правого внука: " << rightGrandson << endl;
	if (rightGrandson) {
		cout << "Значение самого правого внука: " << rightGrandson->data << endl;
	}

	cout << "Количество внуков: " << grandsonNumber(cooltree) << endl;

	BNode<int>*cooltree3 = new BNode<int>(1, new BNode<int>(2, new BNode<int>(4), new BNode<int>(5)));
	delRoot(&cooltree3);
	print(cooltree3);
	cout << endl;

	int v;
	cout << "Введите данные нового корня: ";
	cin >> v;
	addNewRoot(&cooltree,v);
	print(cooltree);
	cout << endl;

	int u;
	cout << "Введите данные нового левого сына: ";
	cin >> u;
	addNewLeftSon(cooltree, u);
	print(cooltree);
	cout << endl;

	int p;
	cout << "Введите данные нового левого крутого сына: ";
	cin >> p;
	addNewLeftCoolSon(cooltree, p);
	print(cooltree);
	cout << endl;

	swapRootAndLeftSon(&cooltree);
	print(cooltree);
	cout << endl;

	leftSwap(&cooltree);
	print(cooltree);
	cout << endl;

	cout << "Указатель на самого левый узел: " << obtainLeftNode(cooltree) << endl;
	cout << "Данные самого левого узла: " << obtainLeftNode(cooltree)->data << endl;

	rightSwap(&cooltree);
	print(cooltree);*/

	cout << numLeafSons(cooltree) << endl;
	BNode<int>*cooltree2 = new BNode<int>(1, new BNode<int>(2), new BNode<int>(3, new BNode<int>(6)));
	print(cooltree2);
	cout << endl;
	cout << numLeafSons(cooltree2) << endl;

	
}
