#pragma once

class Stack {
private:
    int* stack;
    int top;
    int capacity;

public:
    Stack();

    ~Stack();

    void push(int element);

    int pop();

    bool isEmpty() const;
};
