#include "pch.h"
#include <iostream>
#include <stack>

using namespace std;

struct node {
	int data;
	node *left, *right, *p;
	node(int val) : data(val), left(nullptr), right(nullptr), p(nullptr) {};
};

class BTree {
private:
	node *root;
	stack<int> next;

public:

	BTree() : root(nullptr) {};

	bool validate(node *root) {
		int min;
		int max;
		return isValidBST(root, min, max);
	}

	bool isValidBST(node *root, node *&prev) {
		
		if (root){
			if(!isValidBST(root->left, prev))
				return false;
			if (prev != nullptr && root->data <= prev->data)
				return false;
			prev = root;
			return isValidBST(root->right, prev);
		}
		return true;
	}

	int next() {
		if(next.empty())
			inordernext(root);
		else
			return next.pop()
	}

	void inordernext(node *root) {
		if (root) {
			inordernext(root->left);
			next.push(root->data);
			inordernext(root->right);
		}

	}

	

	void print() {
		from_print(root);
	}

	void from_print(node *p) {
		
		if (p != nullptr) {
			from_print(p->left);
			cout << p->data << " ";
			from_print(p->right);
		}

	}

	void insert_node(int val) {
		node *temp = new node(val);
		node *current = nullptr;
		node *prev = nullptr;
		node **p = &current;
		
		if (root == nullptr) {
			root = temp;
			return;
		}
		
		current = root;
		while (current != nullptr) {
			prev = current;
			if (val == current->data) {
				cout << "Duplicates cannot exist" << endl;
				return;
			}
			else if (val < current->data) {
				current = current->left;
			}
			else {
				current = current->right;
			}
		}
		if (val < prev->data) {
			prev->left = temp;
		}
		else {
			prev->right = temp;
		}
	}

};

int main()
{
	BTree b;

	node *root = new node(1);
	root->left = new node(1);


	cout << b.validate(root);


	//b.print();
	

	

	
}
