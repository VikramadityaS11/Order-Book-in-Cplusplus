#include <cassert>
#include <iostream>
#include <orderbook/Order.hpp>
#include <orderbook/Level2OrderBook.hpp>
#include <matching/MatchingEngineL2.hpp>

int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;

    match.processOrder({OrderType::LIMIT, Side::SELL, 100, 5}, book);
    match.processOrder({OrderType::LIMIT, Side::SELL, 100, 7}, book);
    match.processOrder({OrderType::MARKET, Side::BUY, 0, 6}, book);

    assert(book.asks.size() == 1);
    auto& queue = book.asks.begin()->second;

    assert(queue.size() == 1);
    assert(queue.front().quantity == 6); // second order partially filled

    std::cout << "test_fifo passed\n";
}
