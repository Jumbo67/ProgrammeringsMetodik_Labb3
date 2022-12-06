//
// Created by vince on 2022-11-26.
//

#ifndef PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#define PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#include <iostream>
#include <vector>
#include <list>
#include "algorithm"

template<class T, class Comparator = std::less<>>
class p_queue {

    std::list<T> que;
    Comparator comp;


public:
    T pop() {
        T returnValue = que.front();
        que.pop_front();
        return returnValue;
    }
    void push(T elem) {
        que.insert(std::lower_bound(que.begin(), que.end(), elem, comp), elem);
        ;
    } // lower_bound

    int size(){
        return que.size();
    }
    bool empty() {
        return que.empty();
    }

};


/**
 *     * Used to find the position of insertion
     * @param value - Value to check insertion
     * @return - Iterator for position to insert
typename std::list<T>::iterator insertPosition(T value) {
    for (typename std::list<T>::iterator i = que.begin(); i != que.end() ; i++) {
        if (comp(value, *i)) {
            return i;
        }
    }
    return que.end();
}
*/




#endif //PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
