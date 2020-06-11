// DoubleLinked.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "LinkedList.h"

#include <time.h>
#include <random>

int main()
{
    LinkedList list;

    srand(time(nullptr));

    for (size_t i = 0; i < 10; i++)
    {
        list.pushBack(rand() % 100);
    }

    list.printAll();

    std::cout << std::endl;

    list.bubbleSort();

    std::cin.get();

    return 0;
}
