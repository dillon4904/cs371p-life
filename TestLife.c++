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

TEST(Life, n0){
  ConwayCell cell(false);
  FredkinCell cell2(true);
  ASSERT_TRUE(cell.diagNeighbors());
  ASSERT_FALSE(cell2.diagNeighbors());
}

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
    ASSERT_TRUE(cell.getState() == '-');
}

TEST(Life, n5) {
    FredkinCell cell(true);
    cell.setNeighbors(1);
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '3');
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '+');
}
TEST(Life, n6) {
    ConwayCell cell(true);
    cell.setNeighbors(1);
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '.');
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '.');
}

TEST(Life, n7) {
    FredkinCell cell(true);
    cell.setNeighbors(2);
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '-');
    cell.setNeighbors(1);
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '+');
}
TEST(Life, n8) {
    FredkinCell cell(true);
    cell.setNeighbors(3);
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '3');
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '+');
}
TEST(Life, n9) {
    FredkinCell cell(true);
    cell.setNeighbors(4);
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '-');
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '-');
}

TEST(Life, n10) {
    FredkinCell cell(true);
    cell.setNeighbors(1);
    cell.changeState();
    ASSERT_TRUE(cell.getState() == '1');
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

TEST(Life, c1) {
   ConwayCell cell(true); 
   ConwayCell cell2 = cell.clone();
   ASSERT_TRUE(cell.getState() == cell2.getState());
}

TEST(Life, c2) {
   FredkinCell cell(true); 
   FredkinCell cell2 = cell.clone();
   ASSERT_TRUE(cell.getState() == cell2.getState());
}

TEST(Life, c3) {
   ConwayCell cell(true); 
   ConwayCell cell2 = cell.clone();
   cell2.changeState();
   ASSERT_TRUE(cell.getState() != cell2.getState());
}

TEST(Life, c4) {
   FredkinCell cell(true); 
   FredkinCell cell2 = cell.clone();
   cell.changeState();
   ASSERT_TRUE(cell.getState() != cell2.getState());
}

TEST(Life, x1) {
    FredkinCell cell(true);
    cell.setNeighbors(4);
    cell.changeState();
    ASSERT_TRUE(!cell.isAlive());    
}
 
TEST(Life, x2) {
    FredkinCell cell(true);
    cell.setNeighbors(3);
    cell.changeState();
    ASSERT_TRUE(cell.isAlive());    
}

TEST(Life, l1){
   Life<ConwayCell> life(pair<int, int>(0,0));
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 0.\n\n") == 0);
}

TEST(Life, l2){
   Life<ConwayCell> life(pair<int, int>(1,1));
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 0.\n.\n\n") == 0);
}

TEST(Life, l3){
   Life<ConwayCell> life(pair<int, int>(1,1));
   life.addCell(CONWAY, 0, 0);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 1.\n*\n\n") == 0);
}

TEST(Life, l4){
   Life<FredkinCell> life(pair<int, int>(1,1));
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 0.\n-\n\n") == 0);
}

TEST(Life, l5){
   Life<FredkinCell> life(pair<int, int>(1,1));
   life.addCell(FREDKIN, 0, 0);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 1.\n0\n\n") == 0);
}

TEST(Life, l6){
   Life<ConwayCell> life(pair<int, int>(1,2));
   life.addCell(CONWAY, 0, 0);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 1.\n*.\n\n") == 0);
}
TEST(Life, l7){
   Life<FredkinCell> life(pair<int, int>(1,2));
   life.addCell(FREDKIN, 0, 0);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 1.\n0-\n\n") == 0);
}

TEST(Life, l8){
   Life<ConwayCell> life(pair<int, int>(1,1));
   life.addCell(CONWAY, 0, 0);
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n.\n\n") == 0);
}

TEST(Life, l9){
   Life<FredkinCell> life(pair<int, int>(1,1));
   life.addCell(FREDKIN, 0, 0);
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n-\n\n") == 0);
}

TEST(Life, l10){
   Life<ConwayCell> life(pair<int, int>(1,1));
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n.\n\n") == 0);
}

TEST(Life, l11){
   Life<FredkinCell> life(pair<int, int>(1,1));
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n-\n\n") == 0);
}
TEST(Life, l12){
   Life<Cell> life(pair<int, int>(1,1));
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n-\n\n") == 0);
}

TEST(Life, l13){
   Life<Cell> life(pair<int, int>(1,1));
   life.addCell(FREDKIN,0,0);
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n-\n\n") == 0);
}

TEST(Life, l14){
   Life<Cell> life(pair<int, int>(1,1));
   life.addCell(FREDKIN, 0,0);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 0, Population = 1.\n0\n\n") == 0);
}

TEST(Life, l15){
   Life<Cell> life(pair<int, int>(1,2));
   life.addCell(FREDKIN,0,1);
   life.addCell(FREDKIN,0,0);
   life.move(2);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 2, Population = 2.\n**\n\n") == 0);
}
TEST(Life, l151){
   Life<Cell> life(pair<int, int>(1,2));
   life.addCell(FREDKIN,0,1);
   life.addCell(FREDKIN,0,0);
   life.move(3);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 3, Population = 0.\n..\n\n") == 0);
}

TEST(Life, l16){
   Life<Cell> life(pair<int, int>(1,10));
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n----------\n\n") == 0);
}

TEST(Life, l17){
   Life<Cell> life(pair<int, int>(1,1));
   life.move(100);
   life.addCell(FREDKIN,0,0);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 1.\n0\n\n") == 0);
}

TEST(Life, l18){
   Life<Cell> life(pair<int, int>(7,1));
   life.move(100);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 100, Population = 0.\n-\n-\n-\n-\n-\n-\n-\n\n") == 0);
}

TEST(Life, l19){
   Life<Cell> life(pair<int, int>(1,1));
   life.addCell(FREDKIN, 0, 0);
   life.move(1);
   std::ostringstream stream;
   life.printGrid(stream);
   ASSERT_TRUE(strcmp(stream.str().c_str(), "Generation = 1, Population = 0.\n-\n\n") == 0);
}


