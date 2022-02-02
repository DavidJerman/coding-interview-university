#include <iostream>

#include "vector.h"

int main() {

    // Pointers
    double dbl = 0.9;
    double * dblPointer = &dbl;

    // De-Referencing a pointer
    std::cout << "Double value: " << *dblPointer << std::endl;

    // Pointer to an array
    bool arr[5];
    bool * arrPointer = arr;
    // bool * arrPointer = &arr[0];

    arrPointer[0] = false;
    std::cout << "Array[0] value: " << arrPointer[0] << std::endl;

    // Using pointer math to init values
    for (int i = 1; i < 5; i++) *(arrPointer + i) = true;
    std::cout << "Array[4] value: " << *(arrPointer + 4) << std::endl;

    // Testing the vector
    std::cout << std::endl;
    Vector vector;
    std::cout << "Vector contents: ";
    for (int i = 1; i <= 1; i++) std::cout << vector.pop() << " ";
    std::cout << std::endl;
    for (int i = 1; i <= 67; i++) vector.push(i);
    std::cout << "Vector size: " << vector.size() << std::endl;
    std::cout << "Vector capacity: " << vector.capacity() << std::endl;
    std::cout << "Is empty: " << ((vector.isEmpty()) ? "true" : "false") << std::endl;
    std::cout << "Vector contents: ";
    for (int i = 1; i <= 68; i++) std::cout << vector.pop() << " ";
    std::cout << std::endl;
    std::cout << "Vector size: " << vector.size() << std::endl;
    std::cout << "Vector capacity: " << vector.capacity() << std::endl;
    std::cout << "Is empty: " << ((vector.isEmpty()) ? "true" : "false") << std::endl;
    std::cout << std::endl;

    for (int i = 1; i <= 67; i++) vector.push(i);

    vector.insert(10, 120);
    std::cout << "Vector contents: ";
    for (int i = 0; i < vector.size(); i++) std::cout << vector.at(i) << " ";
    std::cout << std::endl;

    vector.prepend(420);
    std::cout << "Vector contents: ";
    for (int i = 0; i < vector.size(); i++) std::cout << vector.at(i) << " ";
    std::cout << std::endl;

    // Removing the number 120
    vector._delete(11);
    std::cout << "Vector contents: ";
    for (int i = 0; i < vector.size(); i++) std::cout << vector.at(i) << " ";
    std::cout << std::endl;

    std::cout << "Index of 420: " << vector.find(420) << std::endl;
    std::cout << "Index of 421: " << vector.find(421) << std::endl;

    vector.insert(42, 22);
    vector.insert(33, 22);
    std::cout << "Vector contents: ";
    for (int i = 0; i < vector.size(); i++) std::cout << vector.at(i) << " ";
    std::cout << std::endl;
    vector.remove(22);
    std::cout << "Vector contents: ";
    for (int i = 0; i < vector.size(); i++) std::cout << vector.at(i) << " ";
    std::cout << std::endl;

    return 0;
}
