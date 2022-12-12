#include "List.h"
#include <iostream>

using namespace std;

int main(void) {
	LinkedList list;
	LinkedList list2;

	list.add(2);
	list.add(3);
	list.add(1);
	list.add(10);
	list.add(100);

	LinkedList::iterator it;

	it = list.begin();
	while (it != nullptr) {
		cout << *it << endl;
		it++;
	}

	it = list.end();
	while (true) {
		cout << *it << endl;
		it--;
	}

	cout << endl;

	it = list.begin();
	cout << *it << endl;
	it++;
	cout << *it << endl;
	it--;
	cout << *it << endl;
	it = list.end();
	cout << *it << endl;
	it = list.begin();
	LinkedList::iterator it2(list.last);
	cout << (it != it2) << endl;
	return 0;
}
