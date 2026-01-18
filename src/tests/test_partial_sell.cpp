#include <cassert>
#include <iostream>
#include <orderbook/Order.hpp>
#include <orderbook/Level2OrderBook.hpp>
#include <matching/MatchingEngineL2.hpp>

int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;

    match.processOrder({OrderType::LIMIT, Side::BUY, 100, 5}, book);
    match.processOrder({OrderType::LIMIT, Side::BUY, 99, 5}, book);
    match.processOrder({OrderType::LIMIT, Side::SELL, 99, 12}, book);

    assert(book.bids.empty());
    assert(book.asks.size() == 1);
    assert(book.asks.begin()->first == 99);
    assert(book.asks.begin()->second.front().quantity == 2);

    std::cout << "test_partial_sell passed\n";
}
