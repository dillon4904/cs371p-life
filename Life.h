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
        AbstractCell& operator = (const AbstractCell& that) {
            alive = that.alive;
            neighbors = that.neighbors;
            return *this;}

        virtual bool equals (const AbstractCell& that) const = 0;

    public:
      virtual bool diagNeighbors() = 0;
      virtual void setNeighbors(int n) = 0;
      virtual void changeState() = 0;
      virtual char getState() = 0;
      virtual bool isAlive() = 0;
      
      AbstractCell (bool living){
        alive = living;
      }
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
      bool equals(const AbstractCell& that) const{
       //TODO
        return true; 
      }
      bool diagNeighbors();
      void setNeighbors(int n);
      void changeState();
      char getState();
      bool isAlive();
};

class FredkinCell : public AbstractCell {
    public:
      FredkinCell(bool living) : AbstractCell(living) {}
      bool diagNeighbors();
      void setNeighbors(int n);
      void changeState();
      char getState();
      bool isAlive();

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
/* start
class ConwayCell : public AbstractShape {
    private:
        int _r;

    protected:
        virtual bool equals (const AbstractShape& that) const {
            if (const Circle* const p = dynamic_cast<const Circle*>(&that))
                return AbstractShape::equals(*p) && (_r == p->_r);
            return false;}

        virtual std::istream& read (std::istream& in) {
            return AbstractShape::read(in) >> _r;}

        virtual std::ostream& write (std::ostream& out) const {
            return AbstractShape::write(out) << " " << _r;}

    public:
        Circle (int x, int y, int r) :
                AbstractShape (x, y),
                _r            (r)
            {}
end*/
/*
        Circle (const Circle& that) :
                AbstractShape (that),
                _r            (that._r)
            {}

        virtual ~Circle ()
            {}

        Circle& operator = (const Circle& that) {
            AbstractShape::operator=(that);
            _r = that._r;
            return *this;}
*/

/*restart        virtual double area () const {
            return 3.14 * _r * _r;}

        virtual Circle* clone () const {
            return new Circle(*this);}

        int radius () const {
            return _r;}};
*/
#endif // Shapes_h
