#include <iostream>
#include <limits.h>
#include "Stack.h"

#define INITIAL_CAPACITY 5
#define MULTIPLY_CAPACITY_FACTOR 2
#define ADD_CAPACITY_ADDEND 100

Stack::Stack() {
    capacity = INITIAL_CAPACITY;
    top = -1;

    stack = (int*)malloc(capacity * sizeof(int));
    if (stack == NULL) {
        std::cout << "Bad allocation" << std::endl;
        Stack::~Stack();
        // std::abort();
        exit(EXIT_FAILURE);
    }

    std::cout << "Stack has been initialized" << std::endl;
}

Stack::~Stack() {
    free(stack);
}

void Stack::push(int element) {
    if (top == capacity - 1) {
        if (capacity <= INT_MAX / 2) {
            capacity *= 2;
        }
        else if (capacity <= INT_MAX - ADD_CAPACITY_ADDEND) {
            capacity += ADD_CAPACITY_ADDEND;
        }
        else {
            std::cout << "Capacity is too big" << std::endl;
            Stack::~Stack();
            // std::abort();
            exit(EXIT_FAILURE);
        }

        int* temp = (int*)realloc(stack, capacity * sizeof(int));
        if (temp == NULL) {
            std::cout << "Bad reallocation" << std::endl;
            Stack::~Stack();
            // std::abort();
            exit(EXIT_FAILURE);
        }
        stack = temp;
    }
    top++;
    stack[top] = element;

    std::cout << element << " has been pushed to the stack" << std::endl;
}

int Stack::pop() {
    if (!isEmpty()) {
        std::cout << stack[top] << " has been popped from the stack" << std::endl;
        return stack[top--];
    }
    else {
        std::cout << "You cannot pop because the stack is empty" << std::endl;
        Stack::~Stack();
        // std::abort();
        exit(EXIT_FAILURE);
    }
}

bool Stack::isEmpty() const {
    return top == -1;
}
