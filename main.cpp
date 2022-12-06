#include <iostream>
#include "p_queue.h"
#include "Order.h"

std::ostream& operator << (std::ostream& out, Order& order) {
    std::cout << "Owner: " << order.getOwner() << "\n" << "Price: " << order.getPrice();
    return out;
}

struct price_comp{
    bool operator()(const Order& lhs, const Order& rhs) {
        return lhs.getPrice() < rhs.getPrice();
    }
};

int main() {

    srand(time(nullptr));

    p_queue<Order, price_comp> buyOrders;
    p_queue<Order, price_comp> sellOrders;

    std::vector investors = {"Erik Pendel", "Jarl Wallenburg", "Joakim Von Anka"};

    for (auto investor  : investors) {
        for (int i = 0; i < 7; i++) {
            buyOrders.push(Order(investor, std::rand() % 15 + 15));
            sellOrders.push(Order(investor, std::rand() % 15 + 15));
        }
    }

    Order buyOrder = buyOrders.pop();
    Order sellOrder = sellOrders.pop();

    int i = 1;

    while (!buyOrders.empty() && !sellOrders.empty()) {
        std::cout << i++ << "." << "\n";
        if (buyOrder.getPrice() >= sellOrder.getPrice()) {
            std::cout << "Share purchase has been completed, Buy order Info:" << "\n" << buyOrder << "\n"
            << "has purchased the sell order" << "\n" << sellOrder << "\n";
            buyOrder = buyOrders.pop();
            sellOrder = sellOrders.pop();
        } else {
            std::cout << "Buy order cancelled," << "\n" << "Info: " << "\n" << buyOrder << "\n"
            << "Cheapest Sellorder is priced at " << sellOrder.getPrice() << "\n";
            buyOrder = buyOrders.pop();
        }
        std::cout << "\n";
    }

    return 0;
}
