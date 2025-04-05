// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include "Automata.h"

TEST(config, exists) {
  EXPECT_NO_THROW({ Automata automata("products.json"); });
}

TEST(config, notFound) {
  EXPECT_THROW({ Automata automata("notFound.json"); }, std::invalid_argument);
}

TEST(state, initial) {
  Automata automata("products.json");
  EXPECT_EQ(0, automata.getState());
}

TEST(state, wait) {
  Automata automata("products.json");
  automata.on();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, off) {
  Automata automata("products.json");
  automata.on();
  automata.off();
  EXPECT_EQ(0, automata.getState());
}

TEST(state, accept) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  EXPECT_EQ(2, automata.getState());
}

TEST(state, doubleAccept) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  automata.coin(100);
  EXPECT_EQ(2, automata.getState());
}

TEST(state, acceptCancel) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  automata.cancel();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, choice) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  automata.choice(1);
  EXPECT_EQ(3, automata.getState());
}

TEST(state, checkCancel) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  automata.choice(1);
  automata.cancel();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, cook) {
  Automata automata("products.json");
  automata.on();
  automata.coin(1000);
  automata.choice(1);
  automata.cook();
  EXPECT_EQ(4, automata.getState());
}

TEST(state, finish) {
  Automata automata("products.json");
  automata.on();
  automata.coin(1000);
  automata.choice(1);
  automata.cook();
  automata.finish();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, manyOff) {
  Automata automata("products.json");
  automata.off();
  automata.off();
  automata.off();
  EXPECT_EQ(0, automata.getState());
}

TEST(state, rollingOnOff) {
  Automata automata("products.json");
  automata.off();
  automata.off();
  automata.on();
  automata.off();
  automata.off();
  automata.on();
  automata.off();
  EXPECT_EQ(0, automata.getState());
}

TEST(state, manyOn) {
  Automata automata("products.json");
  automata.on();
  automata.on();
  automata.on();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, rollingOffOn) {
  Automata automata("products.json");
  automata.on();
  automata.on();
  automata.off();
  automata.on();
  automata.on();
  automata.off();
  automata.on();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, doubleCancel) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  automata.cancel();
  automata.cancel();
  EXPECT_EQ(1, automata.getState());
}

TEST(state, check) {
  Automata automata("products.json");
  automata.on();
  automata.coin(1000);
  automata.choice(1);
  automata.check();
  EXPECT_EQ(3, automata.getState());
}

TEST(state, doubleCheck) {
  Automata automata("products.json");
  automata.on();
  automata.coin(1000);
  automata.choice(1);
  automata.check();
  automata.check();
  EXPECT_EQ(3, automata.getState());
}

TEST(state, cookCancel) {
  Automata automata("products.json");
  automata.on();
  automata.coin(1000);
  automata.choice(1);
  automata.cook();
  automata.cancel();
  EXPECT_EQ(4, automata.getState());
}

TEST(cash, set) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  EXPECT_EQ(15, automata.getCash());
}

TEST(cash, sum) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  automata.coin(25);
  EXPECT_EQ(40, automata.getCash());
}

TEST(cash, saveChoice) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  automata.choice(1);
  EXPECT_EQ(15, automata.getCash());
}

TEST(cash, saveCheck) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  automata.choice(1);
  automata.check();
  EXPECT_EQ(15, automata.getCash());
}

TEST(cash, clearAccept) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  automata.cancel();
  EXPECT_EQ(0, automata.getCash());
}

TEST(cash, clearCheck) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  automata.choice(1);
  automata.cancel();
  EXPECT_EQ(0, automata.getCash());
}

TEST(cash, clearFinish) {
  Automata automata("products.json");
  automata.on();
  automata.coin(1000);
  automata.choice(1);
  automata.cook();
  automata.finish();
  EXPECT_EQ(0, automata.getCash());
}

TEST(cash, checkNotEnough) {
  Automata automata("products.json");
  automata.on();
  automata.coin(15);
  automata.choice(1);
  EXPECT_EQ(35, automata.check());
}

TEST(cash, checkEnough) {
  Automata automata("products.json");
  automata.on();
  automata.coin(50);
  automata.choice(1);
  EXPECT_EQ(0, automata.check());
}

TEST(cash, checkMore) {
  Automata automata("products.json");
  automata.on();
  automata.coin(100);
  automata.choice(1);
  EXPECT_EQ(0, automata.check());
}