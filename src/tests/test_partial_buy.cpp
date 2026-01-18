#include <cassert>
#include <iostream>
#include <orderbook/Order.hpp>
#include <orderbook/Level2OrderBook.hpp>
#include <matching/MatchingEngineL2.hpp>

int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;

    match.processOrder({OrderType::LIMIT, Side::SELL, 100, 5}, book);
    match.processOrder({OrderType::LIMIT, Side::SELL, 101, 5}, book);
    match.processOrder({OrderType::LIMIT, Side::BUY, 101, 12}, book);

    assert(book.asks.empty());
    assert(book.bids.size() == 1);
    assert(book.bids.begin()->first == 101);
    assert(book.bids.begin()->second.front().quantity == 2);

    std::cout << "test_partial_buy passed\n";
}
