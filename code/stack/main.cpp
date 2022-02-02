#include "Stack.h"
#include <iostream>

int main() {

    Stack stack;
    stack.push(10);
    std::cout << "Value at the top: " << stack.top() << std::endl;

    return 0;
}
