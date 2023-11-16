// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 5/12/2022
#include <iostream>
#include <string>
#include "LinearFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(testStepInstr1) {
  LinearFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testStepInstr2) {
  LinearFSR l2("1011011000110110");
  BOOST_REQUIRE_EQUAL(l2.generate(9), 51);
}

// New, Original Test Cases
// Check all 0's
BOOST_AUTO_TEST_CASE(testStepInstr3) {
  LinearFSR l3("0000000000000000");
  BOOST_REQUIRE_EQUAL(l3.generate(10), 0);
}

// Check string of alternating 0's and 1's
BOOST_AUTO_TEST_CASE(testStepInstr4) {
  LinearFSR l4("0101010101010101");
  BOOST_REQUIRE_EQUAL(l4.step(), 0);
  BOOST_REQUIRE_EQUAL(l4.step(), 0);
  BOOST_REQUIRE_EQUAL(l4.step(), 0);
  BOOST_REQUIRE_EQUAL(l4.step(), 0);
  BOOST_REQUIRE_EQUAL(l4.step(), 0);
}

// Check identical strings
BOOST_AUTO_TEST_CASE(testStepInstr5) {
  LinearFSR l5("1100111010111010");
  LinearFSR l6("1100111010111010");
  for (int i = 0; i < 16; ++i) {
    BOOST_REQUIRE_EQUAL(l5.step(), l6.step());
  }
}

// Check if throws invalid argument from size > 16
BOOST_AUTO_TEST_CASE(testStepInstr6) {
  BOOST_CHECK_THROW(LinearFSR l7("110011101011010232314"), std::invalid_argument);
}

// Check if throws invalid argument from bad character
BOOST_AUTO_TEST_CASE(testStepInstr7) {
  BOOST_CHECK_THROW(LinearFSR l8("1100111010X11010"), std::invalid_argument);
}
