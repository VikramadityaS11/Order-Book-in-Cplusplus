#include "MatchingEngineL2.hpp"


void MatchingEngineL2::processOrder(const Order& order, Level2OrderBook& book){
    if(order.side == Side::BUY){
        handleBuy(order,book);
    }else{
        handleSell(order,book);
    }
}

void MatchingEngineL2::handleBuy(const Order& order, Level2OrderBook& book){
    if(order.orderType == OrderType::MARKET){
        executeBuy(order.quantity,book);
        return;
    }
    if(!book.asks.empty() && order.price >= book.asks.begin()->first){
        executeBuy(order.quantity,book);
    } else {
        book.bids[order.price].push_back(order);
    }
}

void MatchingEngineL2::handleSell(const Order& order, Level2OrderBook& book){
    if(order.orderType == OrderType::MARKET){
        executeSell(order.quantity,book);
        return;
    }
    if(!book.bids.empty() && order.price <= book.bids.begin()->first){
        executeSell(order.quantity,book);
    } else {
        book.asks[order.price].push_back(order);
    }
}

void MatchingEngineL2::executeBuy(int quantity, Level2OrderBook& book){
while(quantity > 0 && !book.asks.empty()){
    auto it = book.asks.begin();
    auto& queue = it->second;
    Order& front = queue.front();

    int traded = std::min(quantity,front.quantity);
    quantity -= traded;
    front.quantity -= traded;

    if(front.quantity == 0){
        queue.pop_front();
    }

    if(queue.empty()){
        book.asks.erase(it);
    }
}
}