// Linked List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct node {
	int data;
	node* link;
};

class LinkedList {
private:
	node* head = new node;

public:
	LinkedList();
	void pushFirst(int value);
	void push(int value);
	void show();
};

int main() {
	LinkedList ll;
	ll.push(91);
	ll.push(34);
	ll.push(61);
	ll.pushFirst(19);

	ll.show();
}

LinkedList::LinkedList() {
	head = NULL;
}

void LinkedList::push(int value) {
	node* tmp = new node;
	node* cursor = head;
	tmp->data = value;
	tmp->link = NULL;
	if (head == NULL)
	{
		head = tmp;
	}
	else
	{
		while (cursor->link != NULL)
		{
			cursor = cursor->link;
		}
		cursor->link = tmp;
	}
}

void LinkedList::show() {
	node* cursor = head;
	if (head == NULL)
	{
		std::cout << "List is empty" << std::endl;
	}
	else
	{
		while (cursor->link != NULL)
		{
			std::cout << cursor->data << std::endl;
			cursor = cursor->link;
		}
		std::cout << cursor->data << std::endl;
	}
}

void LinkedList::pushFirst(int value) {
	node* tmp = new node;
	node* cursor = head;
	tmp->data = value;
	if (head == NULL)
	{
		head = tmp;
	}
	else
	{
		while (cursor != NULL)
		{
			while (cursor->link != NULL)
			{
				cursor = cursor->link;
			}
			cursor->link = cursor;
			cursor = NULL;
		}
		head = tmp;
	}
}