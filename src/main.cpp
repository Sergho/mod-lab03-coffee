#include <filesystem>
#include <iostream>

#include "Automata.h"
#include "States.h"

using namespace std;
int main() {
  Automata automata("products.json");
  cout << automata.getStateDesc() << endl;
  automata.on();
  cout << automata.getStateDesc() << endl;
  cout << automata.getMenu();
}