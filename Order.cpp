//
// Created by vince on 2022-12-03.
//

#include "Order.h"

const std::string &Order::getOwner() const {
    return owner;
}

void Order::setOwner(const std::string &owner) {
    this->owner = owner;
}

Order::Order(std::string owner, int price) {
    this->owner = owner;
    this->price = price;
}

int Order::getPrice() const {
    return price;
}

void Order::setPrice(int price) {
    this->price = price;
}
