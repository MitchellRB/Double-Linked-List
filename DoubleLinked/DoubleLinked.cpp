// DoubleLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "LinkedList.h"

#include <time.h>
#include <random>

int main()
{
    LinkedList list;

    srand(time(nullptr));

    for (size_t i = 0; i < 5; i++)
    {
        list.pushFront(rand() % 100);
    }

    list.pushBack(200);

    for (size_t i = 0; i < 15; i++)
    {
        list.pushBack(rand() % 100);
    }

    list.pushBack(200);

    for (size_t i = 0; i < 10; i++)
    {
        list.pushBack(rand() % 100);
    }

    list.printAll();

    std::cout << std::endl;

    std::cout << list.searchFirst(200) << std::endl;
    std::cout << list.searchLast(200) << std::endl;

    list.bubbleSort();

    list.printAll();

    return 0;
}
