#ifndef STLPLUS_HASH
#define STLPLUS_HASH
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   A chained hash table using STL semantics

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/containers/containers_fixes.hpp"
#include "stlplus/containers/exceptions.hpp"
#include "stlplus/containers/safe_iterator.hpp"
#include <map>
#include <iostream>
#include <iterator>

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////
  // internals

  template<typename K, typename T, class H, class E> class hash;
  template<typename K, typename T, class H, class E> class hash_element;

  ////////////////////////////////////////////////////////////////////////////////
  // iterator class

  template<typename K, typename T, class H, class E, typename V>
  class hash_iterator : public safe_iterator<hash<K,T,H,E>,hash_element<K,T,H,E> >
  {
  public:
    friend class hash<K,T,H,E>;

    // local type definitions

    // iterator traits, were inherited from std::iterator but inheriting from that was deprecated in C++17
    // the hash iterators are unidirectional, not random-access
    typedef std::forward_iterator_tag iterator_category;
    typedef V value_type;
    typedef V* pointer;
    typedef V& reference;
    // this is not random access, so declare a void difference type, not sure this is supported by everything
    // typedef std::ptrdiff_t difference_type;
    typedef void difference_type;

    // an iterator points to a value pair whilst a const_iterator points to a const value pair
    typedef hash_iterator<K,T,H,E,std::pair<const K,T> >       iterator;
    typedef hash_iterator<K,T,H,E,const std::pair<const K,T> > const_iterator;
    typedef hash_iterator<K,T,H,E,V>                           this_iterator;

    // constructor to create a null iterator - you must assign a valid value to this iterator before using it
    // any attempt to dereference or use a null iterator is an error
    // the only valid thing you can do is assign an iterator to it
    hash_iterator(void);
    ~hash_iterator(void);

    // Type conversion methods allow const_iterator and iterator to be converted
    // convert an iterator/const_iterator to a const_iterator
    const_iterator constify(void) const;
    // convert an iterator/const_iterator to an iterator
    iterator deconstify(void) const;

    // increment operators used to step through the set of all values in a hash
    // it is only legal to increment a valid iterator
    // there's no decrement - I've only implemented this as a unidirectional iterator
    // pre-increment
    // exceptions: null_dereference,end_dereference
    this_iterator& operator ++ (void);
    // post-increment
    // exceptions: null_dereference,end_dereference
    this_iterator operator ++ (int);

    // test useful for testing whether iteration has completed
    bool operator == (const this_iterator& r) const;
    bool operator != (const this_iterator& r) const;
    bool operator < (const this_iterator& r) const;

    // access the value - a const_iterator gives you a const value, an iterator a non-const value
    // it is illegal to dereference an invalid (i.e. null or end) iterator
    // exceptions: null_dereference,end_dereference
    reference operator*(void) const;
    // exceptions: null_dereference,end_dereference
    pointer operator->(void) const;

  private:
    friend class hash_element<K,T,H,E>;

    // constructor used by hash to create a non-null iterator
    // you cannot create a valid iterator except by calling a hash method that returns one
    explicit hash_iterator(hash_element<K,T,H,E>* element);
    // constructor used to create an end iterator
    explicit hash_iterator(const hash<K,T,H,E>* owner);
    // used to create an alias of an iterator
    explicit hash_iterator(const safe_iterator<hash<K,T,H,E>, hash_element<K,T,H,E> >& iterator);
  };

  ////////////////////////////////////////////////////////////////////////////////
  // Hash class
  // K = key type
  // T = value type
  // H = hash function object with the profile 'unsigned H(const K&)'
  // E = equal function object with profile 'bool E(const K&, const K&)' defaults to equal_to which in turn calls '=='

  template<typename K, typename T, class H, class E = std::equal_to<K> >
  class hash
  {
  public:
    typedef unsigned                                size_type;
    typedef K                                       key_type;
    typedef T                                       data_type;
    typedef T                                       mapped_type;
    typedef std::pair<const K, T>                   value_type;
    typedef hash_iterator<K,T,H,E,value_type>       iterator;
    typedef hash_iterator<K,T,H,E,const value_type> const_iterator;

    // construct a hash table with specified number of bins
    // the default 0 bins means leave it to the table to decide
    // specifying 0 bins also enables auto-rehashing, otherwise auto-rehashing defaults off
    hash(unsigned bins = 0);
    ~hash(void);

    // copy and equality copy the data elements but not the size of the copied table
    hash(const hash&);
    hash& operator = (const hash&);

    // test for an empty table and for the size of a table
    // efficient because the size is stored separately from the table contents
    bool empty(void) const;
    unsigned size(void) const;

    // test for equality - two hashes are equal if they contain equal values
    bool operator == (const hash&) const;
    bool operator != (const hash&) const;

    // switch auto-rehash on
    void auto_rehash(void);
    // switch auto-rehash off
    void manual_rehash(void);
    // force a rehash now
    // default of 0 means implement built-in size calculation for rehashing (recommended - it doubles the number of bins)
    void rehash(unsigned bins = 0);
    // test the loading ratio, which is the size divided by the number of bins
    // use this if you are doing your own rehashing
    // the recommendation is to double the bins when the loading exceeds 0.5 which is what auto-rehashing does
    float loading(void) const;

    // test for the presence of a key
    bool present(const K& key) const;
    // provide map equivalent key count function (0 or 1, as not a multimap)
    size_type count(const K& key) const;

    // insert a new key/data pair - replaces any previous value for this key
    iterator insert(const K& key, const T& data);
    // insert a copy of the pair into the table (std::map compatible)
    std::pair<iterator, bool> insert(const value_type& value);
    // insert a new key and return the iterator so that the data can be filled in
    iterator insert(const K& key);

    // remove a key/data pair from the hash table
    // as in map, this returns the number of elements erased
    size_type erase(const K& key);
    // remove an element from the hash table using an iterator
    // as in map, returns an iterator to the next element
    iterator erase(iterator it);
    // remove all elements from the hash table
    void erase(void);
    // map equivalent of above
    void clear(void);

    // find a key and return an iterator to it
    // The iterator is like a pointer to a pair<const K,T>
    // end() is returned if the find fails
    // Note that ALL hash functions that use iterators are **NOT** thread safe!!!
    // This is due to the usage of a reference counted master iterator.
    const_iterator find(const K& key) const;
    iterator find(const K& key);

    // returns the data corresponding to the key
    // const version is used for const hashes and cannot change the hash, so failure causes an exception
    // non-const version is for non-const hashes and is like map - it creates a new key/data pair if find fails
    // exceptions: std::out_of_range
    const T& operator[] (const K& key) const ;
    T& operator[] (const K& key);

    // synonym for const version of operator[]
    // avoids problem where overloading of operator[] means non-const version can be called, causing a write operation
    // exceptions: std::out_of_range
    const T& at(const K& key) const ;

    // as above, but accesses a pointer to the value
    // returns a null pointer if not found, eliminating an exception handler
    const T* at_pointer(const K& key) const;

    // iterators allow the hash table to be traversed
    // iterators remain valid unless an item is removed or unless a rehash happens
    const_iterator begin(void) const;
    iterator begin(void);
    const_iterator end(void) const;
    iterator end(void);

    // diagnostic report shows the number of items in each bin so can be used
    // to diagnose effectiveness of hash functions
    void debug_report(std::ostream&) const;

    // internals
  private:
    // find a key and return the element pointer
    // zero is returned if the find fails
    // this is used internally where iterator usage may not be required (after profiling by DJDM)
    hash_element<K,T,H,E>* _find_element(const K& key) const;

    friend class hash_element<K,T,H,E>;
    friend class hash_iterator<K,T,H,E,std::pair<const K,T> >;
    friend class hash_iterator<K,T,H,E,const std::pair<const K,T> >;

    unsigned m_rehash;
    unsigned m_bins;
    unsigned m_size;
    hash_element<K,T,H,E>** m_values;
  };

  ////////////////////////////////////////////////////////////////////////////////

} // end namespace stlplus

#include "hash.tpp"
#endif
