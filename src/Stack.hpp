#pragma once

template <typename T>
class Stack
{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node(const T& val, Node* nxt = nullptr)
                : data(val), next(nxt) {}
        };

        Node* top = nullptr;
    public:
        Stack() =default;
        ~Stack();

        void push(const T& val);
        void pop();

        bool isEmpty() const;
        T& top();
};
