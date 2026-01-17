#pragma once
#include<map>
#include<deque>
#include "Order.hpp"
#include <functional>
class Level2OrderBook{
    public:
    std::map<double,std::deque<Order>,std::greater<double>> bids;
    std::map<double,std::deque<Order>> asks;
};