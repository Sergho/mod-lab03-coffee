// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include "Automata.h"

TEST(config, exists) {
  Automata automata("products.json");
  EXPECT_EQ(0, automata.getState());
}

TEST(config, notFound) {
  EXPECT_THROW({ Automata automata("notFound.json"); }, std::invalid_argument);
}