#pragma once
#include "orderbook/Order.hpp"
#include "orderbook/Level1OrderBook.hpp"


class MatchingEngine{
    public:
    void processOrder(const Order& order, Level1OrderBook& book);
    private:
    void handleBuy(const Order& order, Level1OrderBook& book);
    void handleSell(const Order& order, Level1OrderBook& book);

    void executeBuy(int qty, Level1OrderBook& book);
    void executeSell(int qty, Level1OrderBook& book);

    void addLimitBuy(const Order& order,Level1OrderBook& book);
    void addLimitSell(const Order& order,Level1OrderBook& book);
};
