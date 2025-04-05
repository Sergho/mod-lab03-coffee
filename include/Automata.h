
#pragma once
#include <string>
#include <vector>

#include "States.h"

using namespace std;

class Automata {
 private:
  int cash = 0;
  vector<string> menu;
  vector<int> prices;
  State state = State::OFF;
  int selectedIndex;

 public:
  Automata(string filename);
  bool on();
  bool off();
  int coin(int amount);
  string getMenu();
  State getState();
  string getStateDesc();
  bool choice(int index);
  int check();
  bool cancel();
  bool cook();
  bool finish();
};