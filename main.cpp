#include <iostream>
#include "p_queue.h"
#include "order.h"

std::ostream& operator << (std::ostream& out, Order& order) {
    std::cout << "Owner: " << order.getOwner() << "\n" << "Price: " << order.getPrice();
    return out;
}

struct less_comp{
    bool operator()(const Order& lhs, const Order& rhs) {
        return lhs.getPrice() < rhs.getPrice();
    }
};

int main() {

    srand(time(NULL));

    p_queue<Order, less_comp> buyOrders;
    p_queue<Order, less_comp> sellOrders;


    for(int i = 0; i < 7; i++) {
        buyOrders.push({"Erik Pendel", rand() % 30 + 15});
        buyOrders.push({"Jarl Wallenburg", rand() % 30 + 15});
        buyOrders.push({"Joakim Von Anka", rand() % 30 + 15});
        sellOrders.push({"Joakim Von Anka", rand() % 30 + 15});
        sellOrders.push({"Joakim Von Anka", rand() % 30 + 15});
        sellOrders.push({"Joakim Von Anka", rand() % 30 + 15});
    }
    Order buyOrder = buyOrders.pop();
    Order sellOrder = sellOrders.pop();

    while (!buyOrders.empty() && !sellOrders.empty()) {
        if (buyOrder.getPrice() > sellOrder.getPrice()) {
            std::cout << "Share purchase has been completed, Buy order Info:" << "\n" << buyOrder << "\n"
            << "has purchased the sell order" << "\n" << sellOrder << "\n";
            buyOrder = buyOrders.pop();
            sellOrder = sellOrders.pop();
        } else {
            std::cout << "Buy order cancelled, Info: " << buyOrder << "\n"
            << "Cheapest Sellorder is priced at " << sellOrder.getPrice() << "\n";
            buyOrder = buyOrders.pop();
        }
        std::cout << "\n";
    }

    std::cout << "Finished" << "\n";



    return 0;
}
