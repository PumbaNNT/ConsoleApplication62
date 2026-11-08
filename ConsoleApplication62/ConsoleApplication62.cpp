#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        if (size <= 0)
            throw invalid_argument("Invalid stack size");

        capacity = size;
        top = -1;

        try {
            arr = new int[capacity];
        }
        catch (bad_alloc&) {
            throw runtime_error("Memory allocation failed");
        }
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int value) {
        if (top == capacity - 1)
            throw overflow_error("Stack overflow");

        arr[++top] = value;
    }

    int pop() {
        if (top == -1)
            throw underflow_error("Stack is empty");

        return arr[top--];
    }

    int peek() {
        if (top == -1)
            throw underflow_error("Stack is empty");

        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    void display() {
        if (isEmpty())
            throw underflow_error("Stack is empty");

        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";

        cout << endl;
    }
};

int main() {
    try {
        Stack s(3);

        s.push(10);
        s.push(20);
        s.push(30);

        s.display();

        s.push(40);

        cout << "Deleted: " << s.pop() << endl;
        cout << "Top element: " << s.peek() << endl;
    }
    catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}