#include <cassert>
#include <iostream>
#include <orderbook/Order.hpp>
#include <orderbook/Level2OrderBook.hpp>
#include <matching/MatchingEngineL2.hpp>

int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;

    match.processOrder({OrderType::MARKET, Side::BUY, 0, 10}, book);

    assert(book.bids.empty());
    assert(book.asks.empty());

    std::cout << "test_empty_market passed\n";
}
