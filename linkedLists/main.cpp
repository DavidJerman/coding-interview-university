#include <iostream>
#include "LinkedList.h"
#include "DLinkedList.h"

int main() {

    // SLinkedList
    LinkedList linkedList;
    linkedList.push_front(10);
    linkedList.pop_front();
    linkedList.pop_front();
    linkedList.push_back(12);
    linkedList.push_front(11);
    std::cout << "Front: " << linkedList.front() << std::endl;
    std::cout << "Back: " << linkedList.back() << std::endl;
    linkedList.insert(42, 1);
    linkedList.insert(43, 3);
    linkedList.insert(41, 0);
    std::cout << "Front: " << linkedList.front() << std::endl;
    linkedList.erase(1);
    linkedList.erase(3);
    linkedList.erase(0);
    std::cout << "Front: " << linkedList.front() << std::endl;
    std::cout << "At 0: " << linkedList.at(0) << std::endl;
    std::cout << "At 1: " << linkedList.at(1) << std::endl;
    std::cout << "Size: " << linkedList.size() << std::endl;
    std::cout << "From back 0: " << linkedList.value_n_from_back(0) << std::endl;
    std::cout << "From back 1: " << linkedList.value_n_from_back(1) << std::endl;
    linkedList.push_front(10);
    linkedList.push_back(9);
    linkedList.reverse();
    linkedList.remove_value(42);

    // DLinkedList
    DLinkedList dLinkedList;
    dLinkedList.push_front(10);
    dLinkedList.pop_front();
    dLinkedList.push_back(10);
    dLinkedList.pop_back();
    dLinkedList.push_front(10);
    dLinkedList.push_front(11);
    dLinkedList.insert(42, 1);
    dLinkedList.insert(43, 3);
    dLinkedList.insert(41, 0);

    return 0;
}