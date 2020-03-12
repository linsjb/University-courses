/*
Filename: main.cpp
Created by Linus Sjöbro on 2017-12-18.
*/

#include <iostream>
#include <ctime>
#include "queue.h"

int main() {
  srand (time(NULL));

  struct order {
    // Name
    std::string payload;

    // Price
    double priority;
  }buyQueue, sellQueue;

  Queue<order> buys;
  Queue<order> sells;

  std::vector<std::string> names;
  names.push_back("Erik Pendel");
  names.push_back("Jarl Wallenburg");
  names.push_back("Joakim von Anka");

  int counter = 0;
  int ordersByPerson = 7;

  for(int i = 0; i < ordersByPerson * names.size(); i++) {
    int sellPrice = std::rand()%50 + 1;
    int buyPrice = std::rand()%50 + 1;

    // Insertion of sells and buys
    switch(counter) {
      case 0:
        buyQueue.payload = names[0];
        buyQueue.priority = sellPrice;
        buys.push(buyQueue);

        sellQueue.payload = names[0];
        sellQueue.priority = buyPrice;
        sells.push(sellQueue);
        counter++;
        break;

      case 1:
        buyQueue.payload = names[1];
        buyQueue.priority = sellPrice;
        buys.push(buyQueue);

        sellQueue.payload = names[1];
        sellQueue.priority = buyPrice;
        sells.push(sellQueue);
        counter++;
        break;

      case 2:
        buyQueue.payload = names[2];
        buyQueue.priority = sellPrice;
        buys.push(buyQueue);

        sellQueue.payload = names[2];
        sellQueue.priority = buyPrice;
        sells.push(sellQueue);
        counter = 0;
        break;
    }
  }

  for(int i = 0; i < sells.size(); i++) {
    if(buys.first().priority < sells.first().priority) {
      buys.pop();
    } else {
      std::cout
      << "Seller: " << sells.first().payload << '\n'
      << "Buyer: " << buys.first().payload << '\n'
      << "Stock price: " << buys.first().priority
      << '\n' << '\n';
      buys.pop();
      sells.pop();
    }
  }


  return 0;
}
