#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm> // std::copy

//test commit
using std::copy;

namespace myStd
{
  template <typename T>
  class vector
  {
    /*

    NOTE: elem[n] is vector component n for all n >= 0 AND n < size_v
          size_v = the number of items stored in the vector
          space = the available storage capacity of the vector where size_v <= space
          if size_v < space there is space for (space - size_v) doubles after elem[size_v-1]
    */

      int size_v;   // the size
      T *elem; // pointer to the elements (or 0)
      int space;    // number of elements plus number of free slots
    public:
      vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor

      explicit vector(int s) : size_v{0}, elem{new T[s]}, space{s}  // alternate constructor
      {
          for (int i = 0; i < size_v; ++i)
            elem[i] = T(); // elements are initialized
      }
      vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} // copy constructor
      {
          copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
      }

      vector( vector &&src) : size_v{src.size_v}, elem{src.elem}, space{src.space} // move constructor
      {
          src.elem = nullptr;  //make sure src does not delete elem when destructor is called
          src.size_v = 0;
      }

      vector &operator=(const vector &src) // copy assignment
      {
        T *p = new T[src.size_v];       // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = src.size_v;
        space = src.space;
        return *this;  // return a self-reference
      }

      vector& operator=(vector &&src)
      {
          elem = src.elem;//steal array
          size_v = src.size_v;
          space = src.space;
          src.elem = nullptr;//set array to nullptr in order to not delete it
          return *this;//return self-reference

      }

      ~vector() {
        delete[] elem; // destructor
      }

      T &operator[](int n) {
        return elem[n]; // access: return reference
      }

      const T &operator[](int n) const {
        return elem[n];
      }

      int size() const {
        return size_v;
      }

      int capacity() const {
        return space;
      }

      void resize(int newsize) // growth
      // make the vector have newsize elements
      // initialize each new element with the default value 0.0
      {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = T(); // initialize new elements
        size_v = newsize;
      }

      void push_back(T d)
      // increase vector size by one; initialize the new element with d
      {
        if (space == 0)
            reserve(8);         // start with space for 8 elements
        else if (size_v == space)
        {

            reserve(2 * space); // get more space
            if (size_v == space) //if still equal
                return ; //bad alloc out of memory
        }
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
      }

      void reserve(int newalloc)
      {
          //need to test
        // never decrease allocation
        // allocate new space
        if(newalloc <= space)
           return ; //exit func if new space is < or ==
        T* tmp = new(std::nothrow) T[newalloc];
        if(!tmp) //check if bad_alloc
            return ; //if bad alloc return with old vector
        copy(elem,elem+size_v,tmp);
        delete [] elem;
        elem = tmp;
        tmp = nullptr;
        space = newalloc;
        // copy old elements
        // deallocate old space
      }

      using iterator = T *;
      using const_iterator = const T *;

      iterator begin() // points to first element
      {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
      }

      const_iterator begin() const
      {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
      }

      iterator end() // points to one beyond the last element
      {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
      }

      const_iterator end() const
      {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
      }

      iterator insert(iterator p, const T &val) // insert a new element val before p
      {
          //need to test
        // make sure we have space
        if(p < begin()|| p > end())
        {
           return nullptr;
        }
        if(size_v == space)
            reserve(2*space);
        for (iterator pos = end(); pos != p; --pos)
            *(pos) = *(pos-1);
        *p = val;
        // the place to put value

        // copy element one position to the right
        // insert value

        return p;
      }

      iterator erase(iterator p) // remove element pointed to by p
      {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; // copy element one position to the left
        //delete (end() - 1);
        --size_v;
        return p;
      }
  };
}

#endif // VECTOR_H

