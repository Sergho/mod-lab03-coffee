#include "Automata.h"

void Automata::on() { this->state = State::WAIT; }
void Automata::off() { this->state = State::OFF; }
int Automata::coin(int amount) {
  this->cash += amount;
  return this->cash;
}