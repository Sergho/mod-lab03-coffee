#include "Automata.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Automata::Automata(string filename) {
  std::ifstream config(filename);
  json menu = json::parse(config);
  for (auto& [name, price] : menu["products"].items()) {
    this->menu.push_back(name);
    this->prices.push_back(price);
  }
}
void Automata::on() { this->state = State::WAIT; }
void Automata::off() { this->state = State::OFF; }
int Automata::coin(int amount) {
  this->cash += amount;
  return this->cash;
}