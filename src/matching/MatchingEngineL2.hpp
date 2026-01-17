#include "orderbook/Order.hpp"
#include "orderbook/Level2OrderBook.hpp"
class MatchingEngineL2{
    public:
    void processOrder(const Order& order, Level2OrderBook& book);
    private:
    void handleBuy(const Order& order, Level2OrderBook& book);
    void handleSell(const Order& order, Level2OrderBook& book);
    void executeBuy(int quantity, Level2OrderBook& book);
    void executeSell(int quantity, Level2OrderBook& book);
};