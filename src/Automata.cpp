#include "Automata.h"

void Automata::on() { this->state = State::WAIT; }
void Automata::off() { this->state = State::OFF; }