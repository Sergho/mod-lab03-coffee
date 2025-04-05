#include <filesystem>
#include <iostream>

#include "Automata.h"
#include "States.h"

using namespace std;
int main() {
  Automata automata("products.json");
  cout << automata.getState() << endl;
  automata.on();
  cout << automata.getState() << endl;
  cout << automata.getMenu();
}