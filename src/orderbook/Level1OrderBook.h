// State of order book
#include <iostream>
#include <limits>
class Level1OrderBook{
    public:
    double bestBidPrice;
    int bestBidQuantity;

    double bestAskPrice;
    int bestAskQuantity;

    Level1OrderBook(){
        bestBidPrice = 0.0;
        bestBidQuantity = 0;
        bestAskPrice = std::numeric_limits<double>::max();
        bestAskQuantity = 0;
    };
};