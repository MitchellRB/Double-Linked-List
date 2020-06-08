#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	listLength = 0;
}

LinkedList::~LinkedList()
{
	ListNode* next;
	do
	{
		//Get the next node in the list
		next = head->getNext();
		//Delete the current node
		delete head;
		//Move to the next node
		head = next;
	} while (head != tail);
	delete tail;
}

void LinkedList::createFirst()
{
		ListNode* firstNode = new ListNode();
		head = firstNode;
		tail = firstNode;
}

void LinkedList::addToEnd()
{
	if (listLength == 0)
	{
		createFirst();
	}
	else
	{
		ListNode* newNode = new ListNode();
		tail->setNext(newNode);
		tail = newNode;
	}
}
