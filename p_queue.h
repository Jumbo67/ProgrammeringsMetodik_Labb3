//
// Created by vince on 2022-11-26.
//

#ifndef PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#define PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#include <iostream>
#include <vector>
#include <list>

template<class T, class Comparator = std::less<>>
class p_queue {

    std::list<T> que;
    Comparator comp;

    /**
     * Used to find the position of insertion
     * @param value - Value to check insertion
     * @return - Iterator for position, otherwise end of list will be returned
     */
    typename std::list<T>::iterator insertPosition(T value) {
        for (typename std::list<T>::iterator i = que.begin(); i != que.end() ; i++) {
            if (comp(*i, value)) {
                return i;
            }
        }
        return que.end();
    }

public:

    p_queue(Comparator comp = Comparator()) : comp(comp) {
    }

    T pop() {

    }
    void push(T elem) {
        que.insert(insertPosition(elem), elem);
    }

    int size(){
        return que.size();
    }
    bool empty() {
        return que.empty();
    }

};



#endif //PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
