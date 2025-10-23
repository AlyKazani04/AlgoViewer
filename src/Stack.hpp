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

        Node* m_top = nullptr;
    public:
        Stack() =default;
        ~Stack()
        {
            while(!isEmpty())
            {
                pop();
            }
        }

        void push(const T& val)
        {
            m_top = new Node(val, m_top);
        }
        void pop()
        {
            if(m_top != nullptr)
            {
                Node* temp = m_top;
                m_top = m_top->next;
                delete temp;
            }
        }

        bool isEmpty() const
        {
            return (m_top == nullptr);
        }
        T& top()
        {
            return m_top->data;
        }
};
