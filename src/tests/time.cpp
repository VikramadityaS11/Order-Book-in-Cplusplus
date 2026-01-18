#include <chrono>
#include <vector>
#include <orderbook/Level2OrderBook.hpp>
#include <orderbook/Order.hpp>
#include <matching/MatchingEngineL2.hpp>
#include <iostream>

int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;

    const int N = 1'000'000;

    std::vector<Order> orders;
    orders.reserve(N);

    // generate test orders
    for(int i = 0; i < N; i++){
        orders.push_back({OrderType::LIMIT, Side::BUY, 100.0 + (i % 5), 1});
    }

    auto start = std::chrono::high_resolution_clock::now();

    for(const auto& o : orders){
        match.processOrder(o, book);
    }

    auto end = std::chrono::high_resolution_clock::now();

    auto ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    std::cout << "Processed " << N << " orders in "
              << ns << " ns\n";
    std::cout << "Avg per order: "
              << (double)ns / N << " ns\n";
}
