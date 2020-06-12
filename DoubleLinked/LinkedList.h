#pragma once
#include "ListNode.h"

#ifndef uint
	#define uint unsigned int
#endif // !uint

class LinkedList
{
public:

	LinkedList();
	~LinkedList();

	uint length() { return listLength; };

	ListNode* getHead() { return head; };
	ListNode* getTail() { return tail; };

	ListNode* getPtrFromIndex(uint index);

	bool isEmpty() { return (listLength == 0); };

	ListNode* pushBack();
	ListNode* pushBack(int _data);

	ListNode* pushFront();
	ListNode* pushFront(int _data);

	ListNode* insert(ListNode* _next);
	ListNode* insert(ListNode* _next, int _data);

	void popFront();

	void popBack();

	void erase(ListNode* _target);

	void remove(int _target);

	ListNode* searchFirst(int _target);

	ListNode* searchLast(int _target);

	void bubbleSort();

	void printAll();

private:

	uint listLength;
	ListNode* head;
	ListNode* tail;

	ListNode* createFirst();

	void swap(ListNode* a, ListNode* b);
};
