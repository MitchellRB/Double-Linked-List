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

ListNode* LinkedList::getPtrFromIndex(uint index)
{
	if (index >= listLength)
		return nullptr;

	ListNode* node = head;

	for (size_t i = 0; i < index; i++)
	{
		node = node->getNext();
	}

	return node;
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
		ListNode* newNode = new ListNode(tail, nullptr);
		tail->setNext(newNode);
		tail = newNode;
	}
	listLength++;
}

void LinkedList::addToBeginning()
{
	if (listLength == 0)
	{
		createFirst();
	}
	else
	{
		ListNode* newNode = new ListNode(nullptr, head);
		head->setPrevious(newNode);
		head = newNode;
	}
	listLength++;
}

bool LinkedList::addIndex(uint index)
{
	if (index >= listLength)
		return false;

	//Go to position in list
	ListNode* previous = getPtrFromIndex(index - 1);

	//Create new node
	ListNode* newNode = new ListNode();
	newNode->setPrevious(previous);
	newNode->setNext(previous->getNext());

	//Set pointers to new node
	previous->setNext(newNode);
	newNode->getNext()->setPrevious(newNode);

	listLength++;
	return true;
}

bool LinkedList::remove(uint index)
{
	if (index >= listLength)
		return false;

	ListNode* target = getPtrFromIndex(index);

	delete target;

	listLength--;

	return true;
}