
#ifndef MYLINKEDLIST_H_
#define MYLINKEDLIST_H_

#include <iostream>
using namespace std;

// Basic setup: nodes, traversal with temps 

template <class type>
class myLinkedList
{
protected:
    // Nodes for linked list
    struct Node
    {
        type data;
        Node *next;
        Node(const type &item, Node *nextPtr = nullptr) : data(item), next(nextPtr) {}
    };

    Node *first; // First node
    Node *last;  // Last node
    int count;   // Num of nodes

public:
    // Initialize data members
    void setDataMembers()
    {
        first = nullptr;
        last = nullptr;
        count = 0;
    }

    // Default constructor
    myLinkedList()
    {
        setDataMembers();
    }

    // Destructor
    ~myLinkedList()
    {
        while (first != nullptr)
        {
            Node *temp = first;
            first = first->next;
            delete temp;
        }
    }

    // Check if list empty, helper
    bool isEmpty() const
    {
        return count == 0;
    }

    // Add node to beginning
    void push(const type &item)
    {
        // Handle original first node before 
        // reassiging
        Node *newNode = new Node(item, first);
        if (isEmpty())
        {
            last = newNode;
        }
        first = newNode;
        count++;
    }

    // Pop first node
    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = first;
            first = first->next;
            delete temp;
            count--;
            if (isEmpty())
            {
                last = nullptr;
            }
        }
    }

    // Get first node
    type getTop() const
    {
        if (!isEmpty())
        {
            return first->data;
        }
    }

    // Get node count
    int getCount() const
    {
        return count;
    }

    // Print list
    void print(ostream &outStream) const
    {
        Node *current = first;
        while (current != nullptr)
        {
            outStream << current->data << " ";
            current = current->next;
        }
        outStream << endl;
    }
};

#endif /* MYLINKEDLIST_H_ */