#include "pq.h"
#include "Order.h"
#include <cstdlib>
#include <ctime>
struct comp_order {
    bool operator()(const Order& lhs, const Order& rhs) const {
        return lhs.getPrice() > rhs.getPrice(); // Orders with lower price have higher priority
    }
};
int main() {
    srand(time(NULL));
    pq<Order, comp_order> sellOrders;//
    pq<Order, comp_order> buyOrders;
    for(int i=0;i<7;i++){
        sellOrders.push(Order("Erik Pendel", rand()%16+15));
        buyOrders.push(Order("Erik Pendel", rand()%16+15));
    }
    for(int i=0;i<7;i++){
        sellOrders.push(Order("Jarl Wallenburg", rand()%16+15));
        buyOrders.push(Order("Jarl Wallenburg", rand()%16+15));
    }
    for(int i=0;i<7;i++){
        sellOrders.push(Order("Joakim Von Anka", rand()%16+15));
        buyOrders.push(Order("Joakim Von Anka", rand()%16+15));
    }
    while (!sellOrders.empty() && !buyOrders.empty()) {
        Order sellOrder = sellOrders.top();
        Order buyOrder = buyOrders.top();

        if (sellOrder.getPrice() <= buyOrder.getPrice() && sellOrder.getName()!=buyOrder.getName()) {
            std::cout << "Trade successful!" <<
            "\n\tSeller name: " << sellOrder.getName() << 
            "\n\tBuyer name: " << buyOrder.getName() << 
            "\n\tAgreed price: "<<buyOrder.getPrice() << std::endl;

            sellOrders.pop();
            buyOrders.pop();
        } else {
            if(sellOrder.getPrice() < buyOrder.getPrice())
                buyOrders.pop();
            else sellOrders.pop();
        }
    }

    std::cout << "No more trades can be made." << std::endl;

    return 0;
}
