#include "Automata.h"

#include <exception>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

Automata::Automata(string filename) {
  std::ifstream config("products.json");
  if (!config.is_open()) {
    throw std::invalid_argument("Файл конфигурации меню не найден");
  }

  json menu = json::parse(config);
  for (const auto& product : menu["products"]) {
    for (const auto& [name, price] : product.items()) {
      this->menu.push_back(name);
      this->prices.push_back(price);
    }
  }
}
bool Automata::on() {
  if (this->state != State::OFF) return true;
  this->state = State::WAIT;
  return false;
}
bool Automata::off() {
  if (this->state != State::WAIT) return true;
  this->state = State::OFF;
  return false;
}
int Automata::coin(int amount) {
  if (this->state == State::WAIT || this->state == State::ACCEPT) {
    this->cash += amount;
  }
  return this->cash;
}
string Automata::getMenu() {
  string result = "--- МЕНЮ ---\n";
  for (int i = 0; i < this->menu.size(); i++) {
    result += this->menu[i] + ": " + to_string(this->prices[i]) + "\n";
  }
  return result;
}
State Automata::getState() { return this->state; }