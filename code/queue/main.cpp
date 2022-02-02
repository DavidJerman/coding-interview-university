#include "ListQueue.h"
#include "ArrayQueue.h"
#include <iostream>

int main() {

    ListQueue lQueue;
    lQueue.enqueue(10);
    lQueue.enqueue(12);
    std::cout << lQueue.dequeue() << " " << lQueue.dequeue() << std::endl;
    std::cout << "Empty: " << ((lQueue.empty()) ? "Yes" : "No") << std::endl;

    ArrayQueue aQueue;
    for (int i = 0; i < 6; i++) aQueue.enqueue(i);
    for (int i = 0; i < 6; i++) std::cout << aQueue.dequeue() << " ";
    std::cout << std::endl;
    for (int i = 0; i < 6; i++) aQueue.enqueue(i);
    for (int i = 0; i < 6; i++) std::cout << aQueue.dequeue() << " ";
    std::cout << std::endl;

    return 0;
}