#include "Life.h"


/* Both types of cell */

bool AbstractCell::isAlive(){
  return alive;
}

void AbstractCell::setNeighbors(int n){ 
  neighbors = n;
}

/*ConwayCell */

bool ConwayCell::changeState(){
  if(alive){
    if(neighbors > 3 || neighbors < 2){
      alive = false;
    }
  }
  else{ //not alive
    if(neighbors == 3){
      alive = true;
    }
  }
  return alive; 
}

bool ConwayCell::diagNeighbors(){
  return true;
}

char ConwayCell::getState(){
  if(alive) return '*';
  else return '.';
}

ConwayCell* ConwayCell::clone() const{
  return new ConwayCell(*this);
}
//FredkinCell
bool FredkinCell::changeState(){
  bool prev = alive;
  alive = (neighbors % 2); 
  if(prev && alive) age++;
  return alive;
}

bool FredkinCell::diagNeighbors(){
  return false;
}

char FredkinCell::getState(){
  if(!alive) return '-';
  if(age == 0) return '0';
  if(age == 1) return '1';
  if(age == 2) return '2';
  if(age == 3) return '3';
  if(age == 4) return '4';
  if(age == 5) return '5';
  if(age == 6) return '6';
  if(age == 7) return '7';
  if(age == 8) return '8';
  if(age == 9) return '9';
  return '+';
}

FredkinCell* FredkinCell::clone() const{
  return new FredkinCell(*this);
}
