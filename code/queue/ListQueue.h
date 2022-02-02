#include "DLinkedList.h"

class ListQueue {
private:
    DLinkedList list;
public:
    ListQueue() {}

    /**
     * Adds a value to the queue
     * @param value Value
     */
    void enqueue(int value) {
        list.push_back(value);
    }

    /**
     * Returns the front value of the queue
     * @return First value
     */
    int dequeue() {
        return list.pop_front();
    }

    /**
     * Is the queue empty
     * @return Is it empty
     */
    bool empty() {
        return list.empty();
    }
};