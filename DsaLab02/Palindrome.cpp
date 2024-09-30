#include <iostream>
#include <string>
using namespace std;

template<typename T>
class Stack {
private:
    int top;
    T* arr;
    int size;
public:
    Stack(int size) : size(size) {
        arr = new T[size];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(T element) {
        if (isFull()) {
            cout << "Stack Overflow.\n";
            return;
        }
        arr[++top] = element;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return T();
        }
        return arr[top--];
    }

    bool isFull() {
        return top == size - 1;
    }
};

bool isPalindrome(const string& str) {
    int size = str.length();
    Stack<char> s(size);
    string reversed;
    for (char ch : str) {
        s.push(ch);
    }
    for (int i = 0; i < size; i++) {
        reversed += s.pop();
    }
    return str == reversed;
}

int main() {
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << str << " is a Palindrome.";
    }
    else {
        cout << str << " is not a Palindrome.";
    }

    return 0;
}
