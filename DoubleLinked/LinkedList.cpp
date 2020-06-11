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
	while (head != tail)
	{
		//Get the next node in the list
		next = head->getNext();
		//Delete the current node
		delete head;
		//Move to the next node
		head = next;
	}
	if (tail != nullptr)
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

void LinkedList::createFirst(int _data)
{
	ListNode* firstNode = new ListNode(_data, nullptr, nullptr);
	head = firstNode;
	tail = firstNode;
}

void LinkedList::pushBack()
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

void LinkedList::pushBack(int _data)
{
	if (listLength == 0)
	{
		createFirst();
	}
	else
	{
		ListNode* newNode = new ListNode(_data, tail, nullptr);
		tail->setNext(newNode);
		tail = newNode;
	}
	listLength++;
}

void LinkedList::pushFront()
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

void LinkedList::pushFront(int _data)
{
	if (listLength == 0)
	{
		createFirst();
	}
	else
	{
		ListNode* newNode = new ListNode(_data, nullptr, head);
		head->setPrevious(newNode);
		head = newNode;
	}
	listLength++;
}

void LinkedList::insert(ListNode* _next)
{
	ListNode* newNode = new ListNode();

	newNode->setNext(_next);

	if (_next != nullptr)
	{
		newNode->setPrevious(_next->getPrevious());
	}

	if (_next->getPrevious() != nullptr)
	{
		_next->getPrevious()->setNext(newNode);
	}

	if (head == _next)
	{
		head = newNode;
	}

	_next->setPrevious(newNode);

	listLength++;
}

void LinkedList::popBack()
{
	tail = tail->getPrevious();
	delete tail->getNext();
	listLength--;
}

void LinkedList::popFront()
{
	head = head->getNext();
	delete head->getPrevious();
	listLength--;
}

void LinkedList::erase(ListNode* _target)
{
	if (_target == head)
	{
		popFront();
		return;
	}

	if (_target == tail)
	{
		popBack();
		return;
	}

	if (_target != nullptr)
	{
		delete _target;
	}
}