#include <filesystem>
#include <iostream>

#include "Automata.h"
#include "States.h"

using namespace std;
void logInfo(Automata automata) {
  cout << "Текущий баланс: " << automata.getCash() << endl;
  string selected = automata.getSelected();
  if (selected == "") {
    cout << "Сейчас ничего не выбрано" << endl;
  } else {
    cout << "Сейчас выбрано: " << automata.getSelected() << endl;
    if (!automata.check()) {
      cout << "Можем себе позволить" << endl;
    } else {
      cout << "Слишком дорого" << endl;
    }
  }
  cout << "Состояние: " + automata.getStateDesc() << endl << endl;
}
int main() {
  Automata automata("products.json");
  cout << "Создан кофейный автомат" << endl;
  logInfo(automata);

  cout << "Включение..." << endl;
  automata.on();
  logInfo(automata);

  cout << automata.getMenu() << endl;

  cout << "Вносим 70 рублей..." << endl;
  automata.coin(70);
  logInfo(automata);

  cout << "Вносим 50 рублей..." << endl;
  automata.coin(50);
  logInfo(automata);

  cout << "Выбираем Раф-кофе..." << endl;
  automata.choice(9);
  logInfo(automata);

  cout << "Передумал. Отмена..." << endl;
  automata.cancel();
  logInfo(automata);

  cout << "Вносим 40 рублей..." << endl;
  automata.coin(40);
  logInfo(automata);

  cout << "Выбираем Эспрессо..." << endl;
  automata.choice(1);
  logInfo(automata);

  cout << "Отмена..." << endl;
  automata.cancel();
  logInfo(automata);

  cout << "Вносим 50 рублей..." << endl;
  automata.coin(50);
  logInfo(automata);

  cout << "Начинаем готовить..." << endl;
  automata.cook();
  logInfo(automata);

  cout << "Кофе готов!" << endl;
  automata.finish();
  logInfo(automata);
}