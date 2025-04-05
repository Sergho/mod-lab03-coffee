#include <string>
#include <vector>

#include "States.h"

using namespace std;

class Automata {
 private:
  int cash;
  vector<string> menu;
  vector<int> prices;
  State state;

 public:
  Automata(string filename);
  void on();
  void off();
  int coin(int amount);
  string getMenu();
  State getState();
  void choice(int index);
  int check();
  void cancel();
  void cook();
  void finish();
};