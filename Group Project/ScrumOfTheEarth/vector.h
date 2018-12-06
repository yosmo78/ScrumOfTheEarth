/*! \file */
#ifndef VECTOR_H
#define VECTOR_H
#include <algorithm> // std::copy


using std::copy;

//This is the templated class required in the instructions

/*!
 * \brief Contains Templated Vector
 */
namespace myStd
{
  template <typename T>
/*!
   * \brief The vector class provides a templated dynamic array for use
   */
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
      /*!
       * \brief vector default constructor
       */
      vector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor
      /*!
       * \brief vector constructor with size
       * \param s size of vector
       */
      explicit vector(int s) : size_v{0}, elem{new T[s]}, space{s}  // alternate constructor
      {
          for (int i = 0; i < size_v; ++i)
            elem[i] = T(); // elements are initialized
      }
      /*!
       * \brief vector copy constructor
       * \param src vector to copy
       */
      vector(const vector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} // copy constructor
      {
          copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
      }
      /*!
       * \brief vector move constructor
       * \param src vector to steal contents of
       */
      vector( vector &&src) : size_v{src.size_v}, elem{src.elem}, space{src.space} // move constructor
      {
          src.elem = nullptr;  //make sure src does not delete elem when destructor is called
          src.size_v = 0;
      }
      /*!
       * \brief operator = copy assignment
       * \param src vector to copy
       * \return this vector
       */
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

      /*!
       * \brief operator = move assignment
       * \param src vector to steal contents of
       * \return this vector
       */
      vector& operator=(vector &&src)
      {
          elem = src.elem;//steal array
          size_v = src.size_v;
          space = src.space;
          src.elem = nullptr;//set array to nullptr in order to not delete it
          return *this;//return self-reference

      }

      /*!
       * \brief Vector destructor (Does not delete pointed to data)
       */
      ~vector() {
        delete[] elem; // destructor
      }
      /*!
       * \brief operator [] gets the element at the n-th position by reference
       * \param n index of element
       * \return element
       */
      T &operator[](int n) {
        return elem[n]; // access: return reference
      }
      /*!
       * \brief operator [] gets the element at the n-th position by value
       * \param n index of element
       * \return element
       */
      const T &operator[](int n) const {
        return elem[n];
      }
      /*!
       * \brief size gets the number of elements in the vector
       * \return int num of elements
       */
      int size() const {
        return size_v;
      }
      /*!
       * \brief capacity Amount of elements that can be stored in vector
       * \return int size of arrays
       */
      int capacity() const {
        return space;
      }
      /*!
       * \brief resize changes the size of the vector to the specified size
       * \param newsize int new size of vector
       */
      void resize(int newsize) // growth
      // make the vector have newsize elements
      // initialize each new element with the default value 0.0
      {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = T(); // initialize new elements
        size_v = newsize;
      }
      /*!
       * \brief push_back adds an element to the end of the vector
       * \param d element to push back
       */
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
        ++size_v;               // increase the size (size_v is the number of elements)w
      }
      /*!
       * \brief reserve sets aside a new vector of the given size
       * \param newalloc size of new vector
       */
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
        if(elem != NULL) copy(elem,elem+size_v,tmp);
        delete [] elem;
        elem = tmp;
        tmp = nullptr;
        space = newalloc;
        // copy old elements
        // deallocate old space
      }
      using iterator = T *;
      using const_iterator = const T *;

      /*!
       * \brief begin returns an iterator of the beginning of the vector
       * \return iterator of the beginning
       */
      iterator begin() // points to first element
      {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
      }
      /*!
       * \brief begin returns a const_iterator to the first element
       * \return const_iterator to first element
       */
      const_iterator begin() const
      {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
      }
      /*!
       * \brief end returns an iterator to one past the last element
       * \return iterator to one past the last element
       */
      iterator end() // points to one beyond the last element
      {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
      }

      /*!
       * \brief end returns a const_iterator to one past the last element
       * \return  iterator to one past the last element
       */
      const_iterator end() const
      {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
      }

      /*!
       * \brief insert inserts a given value before the position p
       * \param p iterator of place in vector
       * \param val value to be inserted
       * \return
       */
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

      /*!
       * \brief erase takes out the element at position p
       * \param p iterator to element at that position
       * \return
       */
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

      /*!
       * \brief deallocPtrData deallocates all of the pointer data of the vector if the vector is a vector of pointers
       */
      void deallocPtrData()  //if type it pointer to data
      {
          T tmp;
          for(int i = 0;i < size_v; ++i)
          {
              tmp = *(elem+i);
              delete tmp;
          }

      }

      /*!
       * \brief deallocPtrArrayData dellocates all pointed to arrays of the vector if the vector is a vector of dynamic arrays
       */
      void deallocPtrArrayData() //if type is dynamic arrays
      {
          T tmp;
          for(int i = 0;i < size_v; ++i)
          {
              tmp = *(elem+i);
              delete [] tmp;
          }
      }
      /*!
       * \brief deleteList deletes the whole vector of pointed to data
       */
      void deleteList()
      {
          deallocPtrData();
          delete[] elem; // destructor
          space = 0;
          size_v =0;
          elem = NULL;
      }
      /*!
       * \brief deleteArrayList deletes the whole vector of pointed to arrays
       */
      void deleteArrayList()
      {
          deallocPtrArrayData();
          delete[] elem; // destructor
          space = 0;
          size_v =0;
          elem = NULL;
      }
  };
}

#endif // VECTOR_H

