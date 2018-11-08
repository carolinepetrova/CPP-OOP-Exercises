#include <iostream>
#include <cstddef>
// ConsoleApplication3.cpp : Defines the entry point for the console application.
//
struct Node {
	int data;
	Node * next;
};


class Stack {
public:
	Stack():top(NULL) {}

	~Stack() {
        while(top->next!=NULL) {
            pop();
        }
	}


	void push(int elem) {
      if(sizeOfStack == 0) {
        top = new Node;
        top->data = elem;
        top->next = NULL;
      }
      else {
        Node * newNode = new Node;
        newNode->data = top->data;
        newNode->next = top->next;
        top->data = elem;
        top->next = newNode;
      }
       ++sizeOfStack;
	}
	void pop() {
        Node * newTop = new Node;
        newTop = top->next;
        delete top->next;
        top->data = newTop->data;
        top->next = newTop->next;
        --sizeOfStack;
        delete newTop;
	}
	int peek() const {
        return top->data;
	}
	bool empty() const {
        if(sizeOfStack == 0)
            return true;
        else return false;
	}

	int size() const {
        return sizeOfStack;
	}
	void print() {
     Node * current = new Node;
     current = top;
      while(current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
      }
      delete current;
}

private:
	Node * top;
	int sizeOfStack = 0;
};

using namespace std;

int main()
{
    Stack s1;
    s1.push(5);
    s1.push(4);
    s1.push(7);
    s1.push(8);
    s1.print();
    return 0;
}
