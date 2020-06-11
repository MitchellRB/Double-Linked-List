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

//Create the first node in an empty list
ListNode* LinkedList::createFirst()
{
	ListNode* firstNode = new ListNode();
	head = firstNode;
	tail = firstNode;
	return firstNode;
}

//Add a new node to the end
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

//Add a new node to the end with data
ListNode* LinkedList::pushBack(int _data)
{
	ListNode* newNode = pushBack();
	newNode->setData(_data);
	return newNode;
}

//Add a new node to the front
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

//Add a new node to the fron with data
ListNode* LinkedList::pushFront(int _data)
{
	ListNode* newNode = pushFront();
	newNode->setData(_data);
	return newNode;
}

//Insert a node before another node
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

//Insert a node with data before another node
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

//Removes a node from the list
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
		listLength--;
	}
}

//Removes all nodes with the target data
void LinkedList::remove(int _target)
{
	while (search(_target))
		erase(search(_target));
}

//Returns the first instance of a value in the list
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

//Sort all nodes into ascending order
void LinkedList::bubbleSort()
{
	//Not enough elements to sort
	if (listLength < 2)
		return;

	bool swapped;
	int i;
	ListNode* ptr;
	ListNode* endPtr = nullptr;

	do
	{
		swapped = false;
		ptr = head;

		while (ptr->getNext() != endPtr)
		{
			if (ptr->getData() > ptr->getNext()->getData())
			{
				swap(ptr, ptr->getNext());
				swapped = true;
			}
			ptr = ptr->getNext();
		}
		endPtr = ptr;
	} while (swapped);
}

//Swap the data of two nodes
void LinkedList::swap(ListNode* a, ListNode* b)
{
	int t = a->getData();
	a->setData(b->getData());
	b->setData(t);
}

//Print the value of all nodes
void LinkedList::printAll()
{

	ListNode* iter = head;
	while (iter->getNext() != nullptr)
	{
		iter->print();
		std::cout << ' ';
		iter = iter->getNext();
	}
	tail->print();
}