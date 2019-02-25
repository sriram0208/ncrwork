#include<iostream>
using namespace std;
struct node {
	int data;
	struct node *left;
	struct node *right;
};
class Bst {
	struct node *root;
public:
	Bst() {
		root = NULL;
	}
	void insert(int);
	void Delete(int);
	void inorder();
	void preorder();
	void postorder();
	int findMax(node *);
	int findMin(node *);
	int height(node *);
	int leafNodesCnt(node *);
	int nonLeafNodesCnt(node *);
	~Bst() {
		if (root != NULL)
			deleteNode(root);
	}
	void deleteNode(node *);
	node * delete_ele(int, node *,int &);
};
void Bst::deleteNode(node *curr) {
	if (curr != NULL)
	{
		deleteNode(curr->left);
		deleteNode(curr->right);
		delete curr;
	}
}
int Bst::findMax(node *curr) {
	if (curr != NULL) {
		while (curr->right != NULL)
			curr = curr->right;
		return curr->data;
	}
	return -1;
}
int Bst::findMin(node *curr) {
	if (curr != NULL) {
		while (curr->left != NULL)
			curr = curr->left;
		return curr->data;
	}
	return -1;
}
int max(int height1, int height2) {
	return (height1 > height2) ? height1 : height2;
}
int Bst::height(node *curr) {
	if (curr == NULL)
		return -1;
	return max(height(curr->left), height(curr->right))+1;
}
node *insertElement(int ele, node *curr) {
	if (curr == NULL) {
		node *temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else {
		if (ele < curr->data)
			curr->left = insertElement(ele, curr->left);
		else
			curr->right = insertElement(ele, curr->right);
		return curr;
	}
}

void Bst::insert(int ele) {
	root = insertElement(ele, root);
}
void Bst::Delete(int ele) {
	static int cnt = 0;
	root = delete_ele(ele, root,cnt);
	if (cnt == 0)
		cout << "Element not found\n";
}
node * Bst::delete_ele(int ele, node *curr,int &cnt) {
	if (curr != NULL) {
		if (ele > curr->data)
			curr->right = delete_ele(ele, curr->right,cnt);
		else if (ele < curr->data)
			curr->left = delete_ele(ele, curr->left,cnt);
		else {
			cnt++;
			if (curr->left != NULL && curr->right != NULL) {
				curr->data = findMax(curr->left);
				curr->left = delete_ele(curr->data, curr->left,cnt);
			}
			else {
				node *temp;
				temp = curr;
				if (curr->left == NULL)
					curr = curr->right;
				else
					curr = curr->left;
				delete temp;
			}
		}
	}
	return curr;
}
void printInorder(node *curr) {
	if (curr != NULL) {
		printInorder(curr->left);
		cout << curr->data << " ";
		printInorder(curr->right);
	}
}
void Bst::inorder() {
	if (root != NULL) {
		printInorder(root);
		cout << "\n";
	}
}
void printPreorder(node *curr) {
	if (curr != NULL) {
		cout << curr->data << " ";
		printPreorder(curr->left);
		printPreorder(curr->right);
	}
}
void Bst::preorder() {
	if (root != NULL) {
		printPreorder(root);
		cout << "\n";
	}
}
void printPostorder(node *curr) {
	if (curr != NULL) {
		printPostorder(curr->left);
		printPostorder(curr->right);
		cout << curr->data << " ";
	}
}
void Bst::postorder() {
	if (root != NULL) {
		printPostorder(root);
		cout << "\n";
	}
}
int Bst::leafNodesCnt(node *curr) {
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return leafNodesCnt(curr->left) + leafNodesCnt(curr->right);
}
int Bst::nonLeafNodesCnt(node *curr) {
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	return (nonLeafNodesCnt(curr->left) + nonLeafNodesCnt(curr->right) + 1);
}

int main() {
	Bst B;
	char choice;
	int ele;
	cout << "Choose the operation to be performed :\n";
	cout<<"1)Insert \t\t2)Delete\n3)PrintInorder \t\t4)PrintPreorder\n5)PrintPostorder\t6)Exit\n";
	cin >> choice;
	while (choice>='1'&&choice<='5' ) {
		switch (choice) {
		case '1':cout << "Enter the element to be inserted :";
			cin >> ele;
			B.insert(ele);
			break;
		case '2':cout << "Enter the element to be deleted :";
			cin >> ele;
			B.Delete(ele);
			break;
		case '3':cout << "Inorder traversal : ";
			B.inorder();
			break;
		case '4':cout << "Preorder traversal : ";
			B.preorder();
			break;
		case '5':cout << "Postorder traversal : ";
			B.postorder();
			break;
		}
		cout << "Choose the operation to be performed :\n";
		cout << "1)Insert \t\t2)Delete\n3)PrintInorder \t\t4)PrintPreorder\n5)PrintPostorder\t6)Exit\n";
		cin >> choice;
	}
	getchar();
}