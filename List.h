#pragma once
#include <exception>

class LinkedList {
public:
	LinkedList();
	void add(int x);

	class Node {
	public:
		Node(int x);

		int data;
		Node* next;
		Node* prev;
	};

	class iterator {
	public:
		Node* ptr;

		int& operator*();
		iterator operator++(int);
		iterator operator--(int);
		bool operator==(const iterator& it);
		bool operator!=(const iterator& it);
		


		iterator(Node* newptr = nullptr);
		iterator getnext();
		iterator getprev();
	private:
		
	};

	iterator begin();
	iterator end();

	Node* first;
	Node* last;
};
