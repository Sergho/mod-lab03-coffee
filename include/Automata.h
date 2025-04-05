#include <string.h>

#include "States.h"

using namespace std;

class Automata {
 private:
  int cash;
  string* menu;
  int* prices;
  State state;

 public:
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