#ifndef STLPLUS_SAFE_ITERATOR
#define STLPLUS_SAFE_ITERATOR
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   The STLplus safe_iterator superclasses. This implements the STLplus safe
//   iterator principles. Data structures can then be built using subclasses
//   of safe_iterator for their iterator objects and they will inherit the
//   safe iterator behaviour.

//   The data structure must contain a master iterator for each node in the
//   structure. When an iterator is returned to the user, it must be created
//   by the master iterator. When a node is removed from the data structure,
//   its master iterator is destroyed. This sets all iterators pointing to the
//   master iterator to end iterators.

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/containers/containers_fixes.hpp"
#include "stlplus/containers/exceptions.hpp"

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////
  // internals

  template<typename O, typename N>
  class safe_iterator_body;

  template<typename O, typename N>
  class safe_iterator;

  ////////////////////////////////////////////////////////////////////////////////
  // Master Iterator
  // Create one of these in each node in the data structure
  // Generate iterators by obtaining a safe-iterator object from the master iterator
  ////////////////////////////////////////////////////////////////////////////////

  template<typename O, typename N>
  class master_iterator
  {
  public:

    // construct a valid master iterator connected to the node
    master_iterator(const O* owner, N* node) ;

    // destructor - disconnects all iterators from the node
    ~master_iterator(void) ;

    // dereference
    N* node(void) const ;
    const O* owner(void) const ;

    // when you move a node from one owner to another, call this on the node's master iterator
    // this effectively moves all other iterators to the node so that they are owned by the new owner too
    void change_owner(const O* owner) ;

    friend class safe_iterator<O,N>;
  private:
    master_iterator(const master_iterator&) ;
    master_iterator& operator=(const master_iterator&) ;
    safe_iterator_body<O,N>* m_body;
  };

  ////////////////////////////////////////////////////////////////////////////////
  // Safe Iterator
  ////////////////////////////////////////////////////////////////////////////////

  template<typename O, typename N>
  class safe_iterator
  {
  public:
    // constructors
    // an iterator has three possible states: null, valid or end
    // null iterators are not owned, valid and end iterators are owned and can only be used on the owner data structure
    // constructors for each of theses states

    // construct a null iterator
    safe_iterator(void) ;

    // construct a valid iterator from the owner node's master iterator
    safe_iterator(const master_iterator<O,N>&) ;

    // construct an end iterator
    safe_iterator(const O* owner) ;

    // copy operators

    // copy constructor creates a safe iterator with the same properties as the source
    safe_iterator(const safe_iterator<O,N>&) ;

    // copy an iterator by assignment
    safe_iterator<O,N>& operator=(const safe_iterator<O,N>&) ;

    // destructor
    ~safe_iterator(void) ;

    // changing the state of an iterator, e.g. during traversal

    // reassignment to another node - used in increment/decrement operation
    void set(const master_iterator<O,N>&) ;

    // change to an end iterator - e.g. as a result of incrementing off the end
    void set_end(void) ;

    // change to a null iterator - i.e. one that does not belong to any object
    void set_null(void) ;

    // dereference operators to access the internal state

    // get the node that this iterator points to
    N* node(void) const ;
    // get the owner data structure
    const O* owner(void) const ;

    ////////////////////////////////////////////////////////////////////////////////
    // status tests

    // comparison
    bool equal(const safe_iterator<O,N>& right) const ;
    int compare(const safe_iterator<O,N>& right) const ;

    // a null iterator is one that has not been initialised with a value yet
    // i.e. you just declared it but didn't assign to it
    bool null(void) const ;

    // an end iterator is one that points to the end element of the list of nodes
    // in STL conventions this is one past the last valid element and must not be dereferenced
    bool end(void) const ;

    // a valid iterator is one that can be dereferenced
    // i.e. non-null and non-end
    bool valid(void) const ;

    // check ownership of an iterator
    bool owned_by(const O* owner) const;

    // check the rules for an iterator

    // assert the rules for a valid iterator
    // optionally also check that the iterator is owned by the owner
    // exceptions: wrong_object,null_dereference,end_dereference
    void assert_valid(const O* owner = 0) const ;
    // assert the rules for a non-null iterator - i.e. valid or end, values that occur in increment operations
    // optionally also check that the iterator is owned by the owner
    // exceptions: wrong_object,null_dereference
    void assert_non_null(const O* owner = 0) const ;
    // assert that this iterator is owned by this container
    // exceptions: wrong_object
    void assert_owner(const O* owner) const ;

    ////////////////////////////////////////////////////////////////////////////////

    friend class master_iterator<O,N>;
  private:
    safe_iterator_body<O,N>* m_body;
  };

  ////////////////////////////////////////////////////////////////////////////////

} // end namespace stlplus

#include "safe_iterator.tpp"
#endif
