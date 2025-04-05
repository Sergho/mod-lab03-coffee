
#pragma once
#include <string>
#include <vector>

#include "States.h"

using namespace std;

class Automata {
 private:
  int cash;
  vector<string> menu;
  vector<int> prices;
  State state = State::OFF;

 public:
  Automata(string filename);
  bool on();
  bool off();
  int coin(int amount);
  string getMenu();
  State getState();
  bool choice(int index);
  int check();
  bool cancel();
  bool cook();
  bool finish();
};