#ifndef STACK_H_INCLUDED                                                        //LIFO
#define STACK_H_INCLUDED

#include "linkedlist.h"

template<class T> class Stack
{
    public:

    Stack()
    {

    };

    //Jafngildir LinkedList::push_front
    void push(T value)
    {
        _list.push_front(value);
    };

    //Jafngildir LinkedList::pop_front
    T pop()
    {
        T dataToReturn;
        dataToReturn = _list.pop_front();

        return dataToReturn;
    };

    bool is_empty()
    {
        return (_list.is_empty());
    };

    friend ostream& operator <<(ostream& outs, const Stack& stac)
    {
        outs << stac._list;

        return outs;
    };

    private:

        LinkedList<T> _list;

};

#endif // STACK_H_INCLUDED
