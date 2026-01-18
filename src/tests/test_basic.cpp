#include <cassert>
#include <iostream>
#include <orderbook/Order.hpp>
#include <orderbook/Level2OrderBook.hpp>
#include <matching/MatchingEngineL2.hpp>

int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;

    match.processOrder({OrderType::LIMIT, Side::SELL, 101, 10}, book);
    match.processOrder({OrderType::MARKET, Side::BUY, 0, 5}, book);

    assert(book.asks.size() == 1);
    assert(book.asks.begin()->first == 101);
    assert(book.asks.begin()->second.front().quantity == 5);

    std::cout << "test_basic passed\n";
}
