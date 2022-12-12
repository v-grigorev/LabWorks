#include "List.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
	first = nullptr;
	last = nullptr;
}

LinkedList::Node::Node(int x) {
	data = x;
	next = nullptr;
	prev = nullptr;
}

void LinkedList::add(int x) {

	Node* nw = new Node(x);

	if (first == nullptr) {
		first = nw;
		last = nw;
	}
	else {
		nw->next = nullptr;
		nw->prev = last;
		last->next = nw;
		last = nw;
	}

}

LinkedList::iterator LinkedList::begin() {
	iterator it(first);
	return it;
}

LinkedList::iterator LinkedList::end() {
	return last;
}

LinkedList::iterator LinkedList::iterator::getnext() {
	if (ptr->next == nullptr) {
		throw std::exception("err");
	}

	ptr = ptr->next;
	return *this;
}

LinkedList::iterator LinkedList::iterator::getprev() {
	if (ptr->prev == nullptr) {
		throw std::exception("err");
	}
	ptr = ptr->prev;
	return *this;
}

int& LinkedList::iterator::operator*() {
	return ptr->data;
}

LinkedList::iterator LinkedList::iterator::operator++(int) {
	try {
		return getnext();
	}
	catch (std::exception &ex) {
		cout << ex.what() << endl;
		exit(0);
	}
}

LinkedList::iterator LinkedList::iterator::operator--(int) {
	try {
		return getprev();
	}
	catch (std::exception &ex) {
		cout << ex.what() << endl;
		exit(0);
	}
}

bool LinkedList::iterator::operator==(const iterator& it) {
	return (ptr == it.ptr);
}

bool LinkedList::iterator::operator!=(const iterator& it) {
	return (ptr != it.ptr);
}

LinkedList::iterator::iterator(Node* newptr) {
	ptr = newptr;
}
