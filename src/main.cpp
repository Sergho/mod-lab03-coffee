#include <filesystem>
#include <iostream>

#include "Automata.h"
#include "States.h"

using namespace std;
int main() {
  Automata automata("products.json");
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  automata.on();
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  cout << automata.getMenu();
  automata.coin(70);
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  automata.coin(50);
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  automata.choice(9);
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  cout << automata.getSelected() << endl;
  cout << automata.check() << endl;
  automata.cancel();
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  automata.coin(60);
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  automata.choice(1);
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  cout << automata.getSelected() << endl;
  cout << automata.check() << endl;
  automata.cook();
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
  automata.finish();
  cout << automata.getStateDesc() << " " << automata.getCash() << endl;
}