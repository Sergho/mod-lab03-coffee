#include "Automata.h"

#include <exception>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;
using namespace std;

Automata::Automata(string filename) {
  ifstream config("products.json");
  if (!config.is_open()) {
    throw invalid_argument("Файл конфигурации меню не найден");
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
string Automata::getStateDesc() {
  const string descriptions[] = {
      "Автомат сейчас выключен", "Автомат ожидает действий",
      "Автомат принимает деньги", "Автомат проверяет деньги",
      "Автомат готовит напиток"};
  return descriptions[this->state];
}