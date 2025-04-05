// Copyright 2025 Sergho

#pragma once
#include <string>
#include <vector>

#include "States.h"

using std::string;
using std::vector;

class Automata {
 private:
  int cash = 0;
  vector<string> menu;
  vector<int> prices;
  State state = State::OFF;
  int selectedIndex = -1;

 public:
  Automata(string filename);
  bool on();
  bool off();
  int coin(int amount);
  string getMenu();
  State getState();
  string getStateDesc();
  string getSelected();
  int getCash();
  bool choice(int index);
  int check();
  bool cancel();
  bool cook();
  bool finish();
};
