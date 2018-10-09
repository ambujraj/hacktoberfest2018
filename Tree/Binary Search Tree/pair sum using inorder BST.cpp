   #include <stack>

int countNodes(BinaryTreeNode<int> *root) {
	if(root == NULL) {
		return 0;
	}
	return countNodes(root -> left) + countNodes(root -> right) + 1;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
	if(root == NULL) {
		return;
	}
	int totalCount = countNodes(root);
	int count = 0;
	stack<BinaryTreeNode<int>*> inorder;
	stack<BinaryTreeNode<int>*> revInorder;
	BinaryTreeNode<int> *temp = root;
	while(temp != NULL) {
		inorder.push(temp);
		temp = temp -> left;
	}
	temp = root;
	while(temp != NULL) {
		revInorder.push(temp);
		temp = temp -> right;
	}

	while(count < totalCount - 1) {
		BinaryTreeNode<int> *top1 = inorder.top();
		BinaryTreeNode<int> *top2 = revInorder.top();
		if(top1 -> data + top2 -> data == s) {
			cout << top1 -> data << " " << top2 -> data << endl;

			BinaryTreeNode<int> *top = top1;
			inorder.pop();
			count++;
			if(top -> right != NULL) {
				top = top -> right;
				while(top != NULL) {
					inorder.push(top);
					top = top -> left;
				}
			}

			top = top2;
			revInorder.pop();
			count++;
			if(top -> left != NULL) {
				top = top -> left;
				while(top != NULL) {
					revInorder.push(top);
					top = top -> right;
				}
			}
		}
		else if(top1 -> data + top2 -> data > s) {
			BinaryTreeNode<int> *top = top2;
			revInorder.pop();
			count++;
			if(top -> left != NULL) {
				top = top -> left;
				while(top != NULL) {
					revInorder.push(top);
					top = top -> right;
				}
			}
		}
		else {
			BinaryTreeNode<int> *top = top1;
			inorder.pop();
			count++;
			if(top -> right != NULL) {
				top = top -> right;
				while(top != NULL) {
					inorder.push(top);
					top = top -> left;
				}
			}
		}
	}
}