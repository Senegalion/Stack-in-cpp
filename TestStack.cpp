#include <iostream>
#include "Stack.h"

int main() {
    Stack stack;

    // TEST 1
    // pushing elements into the stack and popping them
    for (int element = 0; element < 100; element++) {
        stack.push(element);
    }

    while (!stack.isEmpty()) {
        std::cout << "Popped: " << stack.pop() << std::endl;
    }

    // TEST 2
    // popping from an empty stack
    std::cout << "Popped: " << stack.pop() << std::endl;

    return 0;
}
