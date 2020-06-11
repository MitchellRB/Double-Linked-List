#pragma once
#include <iostream>

class ListNode
{
public:

	ListNode();
	ListNode(ListNode* _previous, ListNode* _next);
	ListNode(int _data, ListNode* _previous, ListNode* _next);
	~ListNode();

	int getData() { return data; };
	void setData(int _data) { data = _data; };

	ListNode* getPrevious() { return previous; };
	ListNode* getNext() { return next; };

	void setPrevious(ListNode* ptr) { previous = ptr; };
	void setNext(ListNode* ptr) { next = ptr; };

	void print();

private:

	int data;
	ListNode* previous;
	ListNode* next;
};
