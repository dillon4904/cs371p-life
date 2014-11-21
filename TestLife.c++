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

TEST(Life, n1) {
    ConwayCell cell(true);
    ASSERT_TRUE(cell.getState() == '*');
    
}

TEST(Life, n2) {
    FredkinCell cell(true);
    ASSERT_TRUE(cell.getState() == '0');
}

TEST(Life, n3) {
    ConwayCell cell(false);
    ASSERT_TRUE(cell.getState() == '.');
}
TEST(Life, n4) {
    FredkinCell cell(false);
    ASSERT_TRUE(cell.getState() == '.');
}


TEST(Life, t1) {
    ConwayCell cell(true);
    cell.setNeighbors(0);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());
    
}

TEST(Life, t2) {
    ConwayCell cell(true);
    cell.setNeighbors(1);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());
}

TEST(Life, t3) {
    ConwayCell cell(true);
    cell.setNeighbors(2);
    cell.changeState();
    ASSERT_TRUE(cell.isAlive());    
}

TEST(Life, t4) {
    ConwayCell cell(true);
    cell.setNeighbors(3);
    cell.changeState();
    ASSERT_TRUE(cell.isAlive());    
}
TEST(Life, t5) {
    ConwayCell cell(true);
    cell.setNeighbors(4);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, t6) {
    ConwayCell cell(true);
    cell.setNeighbors(8);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, t7) {
    ConwayCell cell(false);
    cell.setNeighbors(3);
    cell.changeState();
    ASSERT_TRUE(cell.isAlive());    
}

TEST(Life, f1) {
    FredkinCell cell(true);
    cell.setNeighbors(0);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, f2) {
    FredkinCell cell(true);
    cell.setNeighbors(4);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());    
}
TEST(Life, f3) {
    FredkinCell cell(true);
    cell.setNeighbors(3);
    cell.changeState();
    ASSERT_TRUE(cell.isAlive());    
}

TEST(Life, f4) {
    FredkinCell cell(false);
    cell.setNeighbors(0);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());    
}

