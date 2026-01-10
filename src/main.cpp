#include <iostream>
#include "orderbook/Order.hpp"
#include "orderbook/Level1OrderBook.hpp"
#include "matching/MatchingEngine.hpp"

    void printBook(const Level1OrderBook& book){
        if(book.bestBidQuantity > 0){
            std::cout<<"Best bid: "<<book.bestBidPrice<<" | QTY: "<<book.bestBidQuantity<<"\n";
        } else {
            std::cout<<"Best bid: EMPTY \n";
        }

        if(book.bestAskQuantity > 0){
            std::cout<<"Best ask: "<<book.bestAskPrice<<" QTY: "<<book.bestAskQuantity<<"\n";
        } else {
            std::cout<<"Best bid: EMPTY \n";
        }
    }


    int main(){

        Level1OrderBook book;
        MatchingEngine engine;

        Order sell1 {OrderType::LIMIT, Side::SELL,100.5,40};
        engine.processOrder(sell1,book);

        printBook(book);

        Order buy1 {OrderType::LIMIT,Side::BUY,90,20};
        engine.processOrder(buy1,book);

        printBook(book);

        Order buy2 {OrderType::LIMIT,Side::BUY,100.5,40};
        engine.processOrder(buy2,book);

        printBook(book);
    }







