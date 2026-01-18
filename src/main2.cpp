#include <iostream>
#include <orderbook/Order.hpp>
#include <orderbook/Level2OrderBook.hpp>
#include <matching/MatchingEngineL2.hpp>

void printBook(const Level2OrderBook& book){

    if(book.asks.empty() && book.bids.empty()){
        std::cout<<"EMPTY BOOK"<<std::endl;
        return;
    }

    if(!(book.bids.empty())){
        std::cout<<"BIDS"<<std::endl;
        std::cout<<"Price"<<" "<<"Quantity"<<std::endl;

        for(auto& it : book.bids){
            std::cout<<it.first<<"   ";
            for(auto& q: it.second){
                std::cout<<q.quantity<<std::endl;
            }
        }
        std::cout<<std::endl;
    }
        if(!(book.asks.empty())){
        std::cout<<"ASKS"<<std::endl;
        for(auto& it : book.asks){
            std::cout<<it.first<<"   ";
            for(auto& q: it.second){
                std::cout<<q.quantity<<std::endl;
            }
        }
    }
}


int main(){
    MatchingEngineL2 match;
    Level2OrderBook book;
    
Order o1{OrderType::MARKET, Side::BUY, 0, 10};

match.processOrder(o1, book);
printBook(book);
}