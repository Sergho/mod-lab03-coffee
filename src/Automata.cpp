// Copyright 2025 Sergho

#include <exception>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#include "Automata.h"

using json = nlohmann::json;
using std::ifstream;
using std::invalid_argument;
using std::string;
using std::to_string;

Automata::Automata(string filename) {
  ifstream config(filename);
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
    this->state = State::ACCEPT;
  }
  return this->cash;
}
string Automata::getMenu() {
  string result = "--- МЕНЮ ---\n";
  for (int i = 0; i < this->menu.size(); i++) {
    result += to_string(i + 1) + ". " + this->menu[i] + ": " +
              to_string(this->prices[i]) + "\n";
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
string Automata::getSelected() {
  if (this->selectedIndex == -1) return "";
  return this->menu[this->selectedIndex] + " - " +
         to_string(this->prices[this->selectedIndex]);
}
int Automata::getCash() { return this->cash; }
bool Automata::choice(int index) {
  if (this->state != State::ACCEPT) return true;
  this->selectedIndex = index - 1;
  this->state = State::CHECK;
  return false;
}
int Automata::check() {
  if (this->state != State::CHECK) {
    return this->prices[this->selectedIndex];
  }
  int cashLeft = this->prices[this->selectedIndex] - this->cash;
  if (cashLeft < 0) cashLeft = 0;
  return cashLeft;
}
bool Automata::cancel() {
  if (this->state != State::ACCEPT && this->state != State::CHECK) {
    return true;
  }
  this->state = State::WAIT;
  this->cash = 0;
  this->selectedIndex = -1;
  return false;
}
bool Automata::cook() {
  if (this->state != State::CHECK) return true;
  if (this->check() != 0) return true;
  if (this->selectedIndex == -1) return true;

  this->state = State::COOK;
  this->cash -= this->prices[this->selectedIndex];
  return false;
}
bool Automata::finish() {
  if (this->state != State::COOK) {
    return true;
  }
  this->state = State::WAIT;
  this->cash = 0;
  this->selectedIndex = -1;
  return false;
}
