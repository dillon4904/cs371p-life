// --------------------------------
// projects/voting/TestVoting.c++
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // ==
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Life.h"

TEST(Life, t1) {
    ConwayCell cell(true);
    cell.changeState(0);
    ASSERT_TRUE(!cell.isAlive());
    
}
/*
TEST(Life, t2) {
    ConwayCell cell(true);
    cell.changeState(1);
    ASSERT_TRUE(!cell.isAlive());
}

TEST(Life, t3) {
    ConwayCell cell(true);
    cell.changeState(2);
    ASSERT_TRUE(c.isAlive());    
}

TEST(Life, t4) {
    ConwayCell cell(true);
    cell.changeState(3);
    ASSERT_TRUE(cell.isAlive());    
}
TEST(Life, t5) {
    ConwayCell cell(true);
    cell.changeState(4);
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, t6) {
    ConwayCell cell(true);
    cell.changeState(8);
    ASSERT_TRUE(!cell.isAlive());    
}

TEST(Life, f1) {
    FredkinCell cell(true);
    cell.changeState(0);
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, f2) {
    FredkinCell cell(true);
    cell.changeState(4);
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, f3) {
    FredkinCell cell(true);
    cell.changeState(3);
    ASSERT_TRUE(cell.isAlive());    
}

TEST(Life, f4) {
    FredkinCell cell(false);
    cell.changeState(3);
    ASSERT_TRUE(cell.isAlive());    
}

TEST(Life, f5) {
    FredkinCell cell(false);
    cell.changeState(0);
    ASSERT_TRUE(!cell.isAlive());    
}
*/
