#ifndef QUEUE_H_INCLUDED                                            //FIFO
#define QUEUE_H_INCLUDED

#include "linkedlist.h"

template<class T> class Queue
{
    public:

    //Jafngildir push_back
    void add(T value)
    {
        _list.push_back(value);
    };

    //Jafngildir pop_front
    T remove()
    {
        T dataToReturn;
        dataToReturn = _list.pop_front();

        return dataToReturn;
    };

    bool is_empty()
    {
        return (_list.is_empty());
    };

    friend ostream& operator <<(ostream& outs, const Queue& que)
    {
        outs << que._list;

        return outs;
    };

    private:

        LinkedList<T> _list;
};

#endif // QUEUE_H_INCLUDED
