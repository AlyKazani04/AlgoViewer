#include "Stack.hpp"

template <typename T>
Stack<T>::~Stack()
{
    while(!isEmpty())
    {
        pop();
    }
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}

template <typename T>
T& Stack<T>::top()
{
    return top->data;
}

template <typename T>
void Stack<T>::push(const T& val)
{
    top = new Node(val, top);
}

template <typename T>
void Stack<T>::pop()
{
    if(top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}
