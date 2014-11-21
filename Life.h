// --------
// Original outline taken from Shapes.h
// --------

#ifndef Shapes_h
#define Shapes_h

#include <iostream> // istream, ostream

class AbstractCell {
    protected:
        bool alive;
        int neighbors;      

        virtual bool equals (const AbstractCell& that) const = 0;

        
    public:
      //Abstract methods
      virtual bool diagNeighbors() = 0;
      virtual void changeState() = 0;
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
/*
      AbstractShape (const AbstractShape& that) :
                _x (that._x),
                _y (that._y)
            {}
*/
      // virtual AbstractCell* clone () const = 0;

};

class ConwayCell : public AbstractCell {
    public:
      ConwayCell(bool living) : AbstractCell(living) {}
      ConwayCell(const ConwayCell& that) : AbstractCell(that)   { }
      bool equals(const AbstractCell& that) const{
        return true; 
      }
      
      bool diagNeighbors();
      void changeState();
      char getState();
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
      void changeState();
      char getState();

};
// ---------
// Cell Handle
// ---------

#include <algorithm> // swap

template <typename T>
class Cell {
    friend bool operator == (const Cell& lhs, const Cell& rhs) {
        if (!lhs._p && !rhs._p)
            return true;
        if (!lhs._p || !rhs._p)
            return false;
        return (*lhs._p == *rhs._p);}

    friend bool operator != (const Cell& lhs, const Cell& rhs) {
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
        Cell (pointer p) {
            _p = p;}

        Cell (const Cell& that) {
            if (!that._p)
                _p = 0;
            else
                _p = that._p->clone();}

        ~Cell () {
            delete _p;}

        Cell& operator = (Cell that) {
            swap(that);
            return *this;}

        void swap (Cell& that) {
            std::swap(_p, that._p);}};

// End Cell Handle

using namespace std;
template<typename T>
class Life {
  private:
    int x;
    int y; 
    vector< vector<T> > grid; 
  
  public:
    Life<T>(int x1, int y1){
      x = x1;
      y = y1;
      T filler(false);
      vector<T> filled(y, filler);
      grid.resize(x, filled );
    }

    void printGrid(ostream& out){
      for(vector<T> row : grid){
        for(T cell : row){
          out << cell.getState();
        }
        out << endl;
      }
    }  
    void move(int n);
    void AddCell(T cell, int r, int c);
};



#endif // Shapes_h
