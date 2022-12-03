//
// Created by vince on 2022-12-03.
//

#ifndef PROGRAMMERINGSMETODIK_LABB3_ORDER_H
#define PROGRAMMERINGSMETODIK_LABB3_ORDER_H
#include <iostream>


class Order {
private:
    std::string owner;
    int price;
public:
    Order(std::string owner, int price);

    const std::string &getOwner() const;
    void setOwner(const std::string &owner);

    int getPrice() const;
    void setPrice(int price);
};


#endif //PROGRAMMERINGSMETODIK_LABB3_ORDER_H
