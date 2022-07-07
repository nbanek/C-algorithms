// Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


struct node { //node object, initializes input data and sets next pointer to nullptr
	int data;
	node *next;
	node(int val): data(val), next(nullptr) {};
		
};

class list {
public:
	node *head, *tail; //creates head and tail pointer in new list
	int size; //keeps track of size of list


	list() : head(nullptr), tail(nullptr) { size = 0; }; //initializes head and tail to nullptr

	void addAtIndex(int index, int val) { //adds node before index position
		if (index > size || index < 0) { //if user inputs index > list size, error statement;
			return;
		}
		else if (index == size) {
			add_tail(val);
		}
		else { //creates a new node with associative pointer, translates to index, inserts before index
			node *temp = new node(val);
			node **insert = &head;

			for (int i = 0; i < index; i++) {
				insert = &(*insert)->next;
			}
			
			temp->next = *insert;
			*insert = temp;
			size++;
		}
	}

	void add_head(int val) { //adds input to head position
		node *temp = new node(val);

		if (head == nullptr) {//if list is empty, points head and tail to same node
			head = temp;
			tail = temp;
			size++;
		}
		else {
			temp->next = head;
			head = temp;
			size++;
		}
	}

	void add_tail(int val) { //adds input to end of list
		if (tail == nullptr) {//prevents user from inputing tail to empty list;
			add_head(val);
		}
		else {
			node *temp = new node(val);
			tail->next = temp;
			tail = temp;
			size++;
		}
	}


	void delete_index(int index) {
		node *temp = head;
		node **del = &head;

		for (int i = 0; i < index; i++) {
			del = &(*del)->next;
		}
		temp = *del;
		*del = temp->next;
		delete temp;
		size--;

		}

	void test(int val) {
		node **del = &head;
		
		while (*del) {
			node *temp = *del;
			if ((*del)->data == val) {
				*del = temp->next;
				delete temp;
			}
			else
				del = &temp->next;

		}
	}

	void test2() {
		node *odd = head;
		node *temp = head->next;
		node *even = odd->next;

		while (odd->next || even->next) {
			odd->next = even->next;
			if (odd->next) {
				odd = odd->next;
				even->next = odd->next;
			}
			if(even->next)
				even = odd->next;
		}
		odd->next = temp;

	}


	node *swapPairs(node *h){
			
			if (!h || !h->next)
				return h;

			std::swap(h->data, h->next->data);

			return swapPairs(h->next->next);

	}

	void reverse(){
		node *prev = nullptr;
		node *temp = nullptr;
		node *current = head;

		while (current != nullptr) {
			temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
		head = prev;
		
	}
	

	void print_list() { //prints values of list
		node *current;
		current = head;

		while (current != nullptr) {
			cout << current->data << endl;
			current = current->next;
		}
	}

	void lsize() { //prints current size of list
		cout << size << endl;
	}

	int get(int index) {

		if (index < 0 || index >= size) {
			return -1; 
		}
		else {
			node *current;
			current = head;

			for (int i = 0; i < index; i++) {
				current = current->next;
			}

			return current->data;
		}
	}

};

int main()
{
	list l;

	l.add_head(6);
	l.add_head(5);
	l.add_head(4);
	l.add_head(3);
	l.add_head(2);
	l.add_head(1);

	l.swapPairs(l.head);

	
	l.print_list();

	

	
		

	return 0;

}


