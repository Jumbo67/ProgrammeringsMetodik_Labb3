//
// Created by vince on 2022-11-26.
//

#ifndef PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#define PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
#include <iostream>
#include <vector>

template<class T, class Comparator = std::greater<T> >
class p_queue {

    std::vector<T> que;
    Comparator comparator;

public:

    T pop() {
        T value = que.front();
        que.erase(que.begin());
        return value;
    }

    void push(T e) {

    }
    int size() {
        return que.size();
    }
    bool empty() {
        return que.empty();
    }
};


#endif //PROGRAMMERINGSMETODIK_LABB3_P_QUEUE_H
