// --------
// Original outline taken from Shapes.h
// --------

#ifndef Shapes_h
#define Shapes_h

#include <iostream> // istream, ostream
#include <utility>
#define CELL 0
#define CONWAY 1
#define FREDKIN 2

class AbstractCell {
    protected:
        bool alive;
        int neighbors;      

        virtual bool equals (const AbstractCell& that) const = 0;

        
    public:
      //Abstract methods
      virtual bool diagNeighbors() = 0;
      virtual bool changeState() = 0;
      virtual char getState() = 0;
      //Methods with default implementation
      virtual bool isAlive();
      virtual void setNeighbors(int n);
      
      AbstractCell (bool living){
        alive = living;
      }
      AbstractCell& operator = (const AbstractCell& that) {
            alive = that.alive;
            neighbors = that.neighbors;
            return *this;}

      virtual ~AbstractCell() {

      }
/*
      AbstractShape (const AbstractShape& that) :
                _x (that._x),
                _y (that._y)
            {}
*/
      virtual AbstractCell* clone () const = 0;

};

class ConwayCell : public AbstractCell {
    public:
      ConwayCell(bool living) : AbstractCell(living) {}
      ConwayCell(const ConwayCell& that) : AbstractCell(that)   { }
      bool equals(const AbstractCell& that) const{
        return true; 
      }
      
      bool diagNeighbors();
      bool changeState();
      char getState();
      ConwayCell* clone() const;
};

class FredkinCell : public AbstractCell {
    private: 
      int age;
    public:
      FredkinCell(bool living) : AbstractCell(living) { age = 0; }
      bool equals(const AbstractCell& that) const{
       //TODO
        return true; 
      }
      bool diagNeighbors();
      bool changeState();
      char getState();
      FredkinCell* clone() const;

};
// ---------
// Cell Handle
// ---------

#include <algorithm> // swap

template <typename T>
class Handle {
    friend bool operator == (const Handle& lhs, const Handle& rhs) {
        if (!lhs._p && !rhs._p)
            return true;
        if (!lhs._p || !rhs._p)
            return false;
        return (*lhs._p == *rhs._p);}

    friend bool operator != (const Handle& lhs, const Handle& rhs) {
        return !(lhs == rhs);}

    public:
        typedef T                 value_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

    private:
        pointer _p;

    protected:
        pointer get () {
            return _p;}

        const_pointer get () const {
            return _p;}

    public:
        Handle (pointer p) {
            _p = p;}

        Handle (const Handle& that) {
            if (!that._p)
                _p = 0;
            else
                _p = that._p->clone();}

        ~Handle () {
            delete _p;}

        Handle& operator = (Handle that) {
            swap(that);
            return *this;}

        void swap (Handle& that) {
            std::swap(_p, that._p);}};

class Cell : Handle<AbstractCell> {
  public: 
  
  Cell(bool alive) :  Handle<AbstractCell> (new FredkinCell(alive)) {}
  Cell(AbstractCell* p) : 
    Handle<AbstractCell> (p) {}
  bool diagNeighbors(){
    return get()-> diagNeighbors();
  }
  bool changeState(){
    bool out = get()-> changeState();
    char c = get()-> getState();
    
    if(c == '.' || c== '*' || c=='-' || c == '0' || c== '1'){
      return out;
    }
    Cell cell(new ConwayCell(true));
    swap(cell);
    return out;
  }
  char getState(){
    return get() -> getState();
  }
  bool isAlive(){
    return get()-> isAlive();
  }
  void setNeighbors(int n){
    get()->setNeighbors(n); 
  }
  
};
// End Cell Handle

using namespace std;
template<typename T>
class Life {
  private:
    int gen;
    int pop;
    int x;
    int y; 
    vector< vector<T> > grid; 
  
  public:
    Life<T>(pair<int, int> size){
      gen = 0;
      pop = 0;  
      x = size.first;
      y = size.second;
      T filler(false);
      vector<T> filled(y, filler);
      grid.resize(x, filled );
    }

    void printGrid(ostream& out){
      out << "Generation = " << gen << ", Population = " << pop << "." << endl;
      for(vector<T> row : grid){
        for(T cell : row){
          out << cell.getState();
        }
        out << endl;
      }
      out << endl;
    }  


    void move(int n){
      for(int i = 0; i < n; i++){
        //Set number of neighbors
        gen++;
        for(int r = 0; r < x; r++){
          for(int c = 0; c < y; c++){
             int num = 0;
             bool diagNeighbors = grid[r][c].diagNeighbors();
             bool rightSafe = (r+1 < x);
             bool leftSafe = (r-1 >= 0);
             bool upSafe = (c-1 >= 0);
             bool downSafe = (c+1 < y);
             if(upSafe){
               if(grid[r][c-1].isAlive()) num++;  
             }
             if(downSafe){
               if(grid[r][c+1].isAlive()) num++;  
             }
             if(leftSafe) {
               if(grid[r-1][c].isAlive()) num++;
             }
             if(rightSafe){
               if(grid[r+1][c].isAlive()) num++;  
             }
             if(diagNeighbors){
               if(leftSafe && upSafe){
                 if(grid[r-1][c-1].isAlive()) num++;
               }
               if(leftSafe && downSafe){
                 if(grid[r-1][c+1].isAlive()) num++;  
               }
               if(rightSafe && downSafe){
                 if(grid[r+1][c+1].isAlive()) num++;  
               }
               if(rightSafe && upSafe){
                 if(grid[r+1][c-1].isAlive()) num++;  
               }
             }
            grid[r][c].setNeighbors(num);
          }
        }
        pop = 0;
        //neighbors set up
        for(int r = 0; r < x; r++){
          for(int c = 0; c < y; c++){
            if(grid[r][c].changeState()) pop++;
          }
        }
      }
    }
    void addCell(int type, int r, int c){
      pop++;
      if(type == CONWAY)
        grid[r][c] = T(true);
      else if(type == FREDKIN)
        grid[r][c] = T(true);
      //else if(type == CELL)
        //TODO
        //grid[r][c] = Cell(0);
    }    
};



#endif // Shapes_h
