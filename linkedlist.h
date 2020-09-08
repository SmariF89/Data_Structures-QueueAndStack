#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>                                 //DELETE
using namespace std;

class EmptyException{};

template<class T> struct Node
{
    T data;
    Node *next;
};

template<class T> class LinkedList
{
public:

    LinkedList()
    {
        head = NULL;
        tail = NULL;
    };

    ~LinkedList()
    {
        Node<T>* subjectToDestruction = head;
        while(subjectToDestruction != NULL)
        {
            head = subjectToDestruction;
            subjectToDestruction = subjectToDestruction->next;

            delete head;
        }
    };

    void push_front(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;

        if(is_empty())
        {
            head = newNode;
            tail = newNode;

            newNode->next = NULL;

            return;
        }

        newNode->next = head;
        head = newNode;
    };

    void push_back(T value)
    {
        if(is_empty())
        {
            push_front(value);
            return;
        }

        Node<T>* newNode = new Node<T>;
        newNode->data = value;

        tail->next = newNode;
        tail = newNode;
        newNode->next = NULL;
    };

    T pop_front()
    {
        if(is_empty())
        {
            throw EmptyException();
        }

        T dataToReturn = head->data;
        Node<T>* nodeToPop = head;

        head = head->next;

        if(is_empty())
        {
            tail = head;
        }

        delete nodeToPop;

        return dataToReturn;
    };

    bool is_empty()
    {
        return head == NULL;
    };

    friend ostream& operator <<(ostream& outs, const LinkedList<T>& TheList)
    {
        Node<T>* nodeToPrint = TheList.head;

        while(nodeToPrint != NULL)
        {
            outs << nodeToPrint->data << " ";
            nodeToPrint = nodeToPrint->next;
        }

        return outs;
    };

private:
    Node<T>* head;
    Node<T>* tail;
};

#endif // LINKEDLIST_H_INCLUDED
