// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2014
// Glenn P. Downing
// -------------------------
  
// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <string> 
#include <utility> 
#include <cstring> 
#include "Life.h"


using namespace std;
pair<int, int> readHeader(istream& in){
  pair<int, int> out;
  string notUsed;
  in >> notUsed;
  in >> out.first;
  in >> out.second;
  return out;
}

string readGrid(istream& in){
  string out; 
  in >> out; 
  return out; 
}

int main () {
    using namespace std;

    // -----------------
    // Conway Cell 21x13
    // -----------------
  {
    cout << "*** Life<ConwayCell> 21x13 ***" << endl;
    pair<int, int> sizes = readHeader(cin);
    Life<ConwayCell> life(sizes); 
    string line;
    int x, y;
    for(x = 0; x < sizes.first; x++){
      line = readGrid(cin); 
      const char *cstr = line.c_str();
      for(y = 0; y < sizes.second; y++){
        if(cstr[y] == '*') life.addCell(CONWAY, x, y);
      }
    }
    life.printGrid(cout);
    int moves;
    for(moves = 0; moves < 12; moves++){
      life.move(1);
      life.printGrid(cout); 
    }
  }
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    // -----------------
    // Conway Cell 20x29
    // -----------------
  {
    cout << "*** Life<ConwayCell> 20x29 ***" << endl;
    pair<int, int> sizes = readHeader(cin);
    Life<ConwayCell> life(sizes); 
    string line;
    int x, y;
    for(x = 0; x < sizes.first; x++){
      line = readGrid(cin); 
      const char *cstr = line.c_str();
      for(y = 0; y < sizes.second; y++){
        if(cstr[y] == '*') life.addCell(CONWAY, x, y);
      }
    }
    life.printGrid(cout);
    int moves;
    for(moves = 0; moves <= 28; moves++){
      if(moves % 4 == 0)
        life.printGrid(cout); 
      life.move(1);
    }
  }  /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    // ------------------
    // Conway Cell 109x69
    // ------------------
  {
    cout << "*** Life<ConwayCell> 109x69 ***" << endl;
    pair<int, int> sizes = readHeader(cin);
    Life<ConwayCell> life(sizes); 
    string line;
    int x, y;
    for(x = 0; x < sizes.first; x++){
      line = readGrid(cin); 
      const char *cstr = line.c_str();
      for(y = 0; y < sizes.second; y++){
        if(cstr[y] == '*') life.addCell(CONWAY, x, y);
      }
    }
    life.printGrid(cout);
    int moves;
    for(moves = 0; moves <= 9; moves++){
      life.printGrid(cout); 
      life.move(1);
    }
    life.move(273);
    life.printGrid(cout);
    life.move(40);
    life.printGrid(cout);
    life.move(2177);
    life.printGrid(cout);  
    
  }  
 
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    // ------------------
    // Fredkin Cell 20x20
    // ------------------
/*
  {
    cout << "*** Life<FredkinCell> 20x20 ***" << endl;
    pair<int, int> sizes = readHeader(cin);
    Life<FredkinCell> life(sizes); 
    string line;
    int x, y;
    for(x = 0; x < sizes.first; x++){
      line = readGrid(cin); 
      const char *cstr = line.c_str();
      for(y = 0; y < sizes.second; y++){
        if(cstr[y] == '0') life.addCell(FREDKIN, x, y);
      }
    }
    life.printGrid(cout);
    int moves;
    for(moves = 0; moves <= 5; moves++){
      life.printGrid(cout); 
      life.move(1);
    }
  } */  
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    // ----------
    // Cell 20x20
    // ----------

    cout << "*** Life<Cell> 20x20 ***" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    return 0;}


