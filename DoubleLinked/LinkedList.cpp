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

ListNode* LinkedList::createFirst()
{
	ListNode* firstNode = new ListNode();
	head = firstNode;
	tail = firstNode;
	return firstNode;
}

ListNode* LinkedList::pushBack()
{
	ListNode* newNode;
	if (listLength == 0)
	{
		newNode = createFirst();
	}
	else
	{
		newNode = new ListNode(tail, nullptr);
		tail->setNext(newNode);
		tail = newNode;
	}
	listLength++;

	return newNode;
}

ListNode* LinkedList::pushBack(int _data)
{
	ListNode* newNode = pushBack();
	newNode->setData(_data);
	return newNode;
}

ListNode* LinkedList::pushFront()
{
	ListNode* newNode;
	if (listLength == 0)
	{
		newNode = createFirst();
	}
	else
	{
		newNode = new ListNode(nullptr, head);
		head->setPrevious(newNode);
		head = newNode;
	}
	listLength++;

	return newNode;
}

ListNode* LinkedList::pushFront(int _data)
{
	ListNode* newNode = pushFront();
	newNode->setData(_data);
	return newNode;
}

ListNode* LinkedList::insert(ListNode* _next)
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

	return newNode;
}

ListNode* LinkedList::insert(ListNode* _next, int _data)
{
	ListNode* newNode = insert(_next);
	newNode->setData(_data);
	return newNode;
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

ListNode* LinkedList::search(int _target)
{
	ListNode* iter = head;
	while (true)
	{
		if (iter->getData() == _target)
		{
			return iter;
		}
		else
		{
			if (iter->getNext() == nullptr)
				break;
			else
				iter = iter->getNext();
		}
	}
	return nullptr;
}
