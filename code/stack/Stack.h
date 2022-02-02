#include "Vector.h"

class Stack {
private:
    Vector vector;
public:
    Stack() {}

    /**
     * Pushes a value on the stack
     * @param value Value
     */
    void push(int value) {
        vector.push(value);
    }

    /**
     * Pops a value from the stack
     * @return Value
     */
    int pop() {
        return vector.pop();
    }

    /**
     * Returns the top element on the stack
     * @return Top element
     */
    int top() {
        return vector.at(vector.size() - 1);
    }

    /**
     * Returns the size of the stack
     * @return Size
     */
    int size() {
        return vector.size();
    }

    /**
     * Returns the capacity of the stack
     * @return Capacity
     */
    int capacity() {
        return vector.capacity();
    }
};
