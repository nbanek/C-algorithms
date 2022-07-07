

#include "pch.h"
#include <iostream>

using namespace std;

struct node{
	int value;
	node *link;
	node(int value) : value(value), link(nullptr) {};
};


class stack {
private:
	int stack_size;
	node *stack_back;

public:
	stack() : stack_size(0), stack_back(nullptr) {};

	void check_stack_size() {
		cout << stack_size << endl;
	}
	void push(int value) {
		node *temp = new node(value);

		if (!stack_back) {
			stack_back = temp;
			stack_size++;
		}
		else {
			temp->link = stack_back;
			stack_back = temp;
			stack_size++;
			
		}
	}

	void peek(){
		if (!stack_back) {
			cout << "Stack is empty" << endl;
		}
		else {
			cout << stack_back->value << endl;
		}
	}

	int pop() {
		if (!stack_back) {
			cout << "Stack is empty" << endl;
		}
		else {
			node *temp = stack_back;
			int copy_stack_back = stack_back->value;
			stack_back = stack_back->link;
			delete temp;
			stack_size--;
			return copy_stack_back;
		}
	}

};


int main()
{
	stack st;

	st.push(1);
	st.push(2);
	st.pop();
	st.peek();
	st.push(55);
	st.check_stack_size();
   
}


