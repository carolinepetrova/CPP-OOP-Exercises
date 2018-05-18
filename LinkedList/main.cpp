// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include <iostream>

int main()
{
	LinkedList<int> l1;
	l1.insertAtBeginning(1);
	l1.insertAtBeginning(6);
	l1.insertAtBeginning(5);
	l1.insertAtBeginning(10);
	l1.insertToEnd(8);
	l1.insertAfter(9, 8);
	l1.insertBefore(7, 10);
	l1.removeAt(1);
	for (int i = 0; i < l1.Size(); i++) {
		std::cout << l1.getAt(i)->data << " ";
	}
    return 0;
}

