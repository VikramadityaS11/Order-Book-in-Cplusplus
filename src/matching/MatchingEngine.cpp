#include "MatchingEngine.hpp"
#include <algorithm>
#include <limits>


    void MatchingEngine::processOrder(const Order& order, Level1OrderBook& book){
        if(order.side == Side::BUY){
            handleBuy(order, book);
        } else {
            handleSell(order,book);
        }
    }
    void MatchingEngine::handleBuy(const Order& order, Level1OrderBook& book){
        if(order.orderType == OrderType::MARKET){
            executeBuy(order.quantity,book);
            return;
        }
        if(order.price >= book.bestAskPrice && book.bestAskQuantity > 0){
            executeBuy(order.quantity,book);
        } else {
            addLimitBuy(order,book);
        }
    }

    void MatchingEngine::handleSell(const Order& order, Level1OrderBook& book){
        if(order.orderType == OrderType::MARKET){
            executeSell(order.quantity,book);
            return;
        }
        if(order.price <= book.bestBidPrice && book.bestBidQuantity > 0){
            executeSell(order.quantity,book);
        } else {
            addLimitSell(order,book);
        }
    }

    void MatchingEngine::executeBuy(int qty, Level1OrderBook& book){
        if(book.bestAskQuantity == 0){
            return;
        }
        int traded = std::min(qty,book.bestAskQuantity);
        book.bestAskQuantity -= traded;

        if(book.bestAskQuantity == 0){
            book.bestAskPrice = std::numeric_limits<double>::max();
        }
    }

    void MatchingEngine::executeSell(int qty, Level1OrderBook& book){
        if(book.bestBidQuantity == 0){
            return;
        }
        int traded = std::min(book.bestBidQuantity,qty);
        book.bestBidQuantity -= traded;

        if(book.bestBidQuantity == 0){
            book.bestBidPrice = 0.0;
        }
    }

    void MatchingEngine::addLimitBuy(const Order& order,Level1OrderBook& book){
        if(order.price > book.bestBidPrice){
            book.bestBidPrice = order.price;
            book.bestBidQuantity = order.quantity;
        }
    }

    void MatchingEngine::addLimitSell(const Order& order,Level1OrderBook& book){
        if(order.price < book.bestAskPrice){
            book.bestAskPrice = order.price;
            book.bestAskQuantity = order.quantity;
        }
    }