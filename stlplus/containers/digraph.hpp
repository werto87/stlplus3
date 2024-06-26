#ifndef STLPLUS_DIGRAPH
#define STLPLUS_DIGRAPH
////////////////////////////////////////////////////////////////////////////////

//   Author:    Andy Rushton
//   Copyright: (c) Southampton University 1999-2004
//              (c) Andy Rushton           2004 onwards
//   License:   BSD License, see ../docs/license.html

//   STL-style Directed graph template component
//   Digraph stands for directed-graph, i.e. all arcs have a direction

////////////////////////////////////////////////////////////////////////////////
#include "stlplus/containers/containers_fixes.hpp"
#include "stlplus/containers/safe_iterator.hpp"
#include "stlplus/containers/exceptions.hpp"
#include <vector>
#include <map>
#include <set>
#include <iterator>

namespace stlplus
{

  ////////////////////////////////////////////////////////////////////////////////
  // Internals

  template<typename NT, typename AT> class digraph_node;
  template<typename NT, typename AT> class digraph_arc;
  template<typename NT, typename AT> class digraph;

  ////////////////////////////////////////////////////////////////////////////////
  // The Digraph iterator classes
  // a digraph_iterator points to a node whilst a digraph_arc_iterator points to an arc
  // Note that these are redefined as:
  //   digraph<NT,AT>::iterator           - points to a non-const node
  //   digraph<NT,AT>::const_iterator     - points to a const node
  //   digraph<NT,AT>::arc_iterator       - points to a non-const arc
  //   digraph<NT,AT>::const_arc_iterator - points to a const arc
  // and this is the form in which they should be used

  template<typename NT, typename AT, typename NRef, typename NPtr>
  class digraph_iterator : public safe_iterator<digraph<NT,AT>, digraph_node<NT,AT> >
  {
  public:
    friend class digraph<NT,AT>;

    // iterator traits, were inherited from std::iterator but inheriting from that was deprecated in C++17
    // the digraph iterators are bidirectional but not random-access
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef NT value_type;
    typedef NPtr pointer;
    typedef NRef reference;
    // this is not random access, so declare a void difference type, not sure this is supported by everything
    // typedef std::ptrdiff_t  difference_type;
    typedef void difference_type;

    // local type definitions
    // an iterator points to an object whilst a const_iterator points to a const object
    typedef digraph_iterator<NT,AT,NT&,NT*> iterator;
    typedef digraph_iterator<NT,AT,const NT&,const NT*> const_iterator;
    typedef digraph_iterator<NT,AT,NRef,NPtr> this_iterator;

    // constructor to create a null iterator - you must assign a valid value to this iterator before using it
    digraph_iterator(void);
    ~digraph_iterator(void);

    // Type conversion methods allow const_iterator and iterator to be converted
    // convert an iterator/const_iterator to a const_iterator
    const_iterator constify(void) const;
    // convert an iterator/const_iterator to an iterator
    iterator deconstify(void) const;

    // increment/decrement operators used to step through the set of all nodes in a graph
    // it is only legal to increment a valid iterator
    // pre-increment
    // exceptions: null_dereference,end_dereference
    this_iterator& operator ++ (void);
    // post-increment
    // exceptions: null_dereference,end_dereference
    this_iterator operator ++ (int);
    // pre-decrement
    // exceptions: null_dereference,end_dereference
    this_iterator& operator -- (void);
    // post-decrement
    // exceptions: null_dereference,end_dereference
    this_iterator operator -- (int);

    // test useful for testing whether iteration has completed and for inclusion in other containers
    // Note: this class also inherits the safe_iterator methods: valid(), null(), end()
    bool operator == (const this_iterator& r) const;
    bool operator != (const this_iterator& r) const;
    bool operator < (const this_iterator& r) const;

    // access the node data - a const_iterator gives you a const element, an iterator a non-const element
    // it is illegal to dereference an invalid (i.e. null or end) iterator
    // exceptions: null_dereference,end_dereference
    reference operator*(void) const;
    // exceptions: null_dereference,end_dereference
    pointer operator->(void) const;

  public:
    // constructor used by digraph to create a non-null iterator
    explicit digraph_iterator(digraph_node<NT,AT>* node);
    // constructor used by digraph to create an end iterator
    explicit digraph_iterator(const digraph<NT,AT>* owner);
    // used to create an alias of an iterator
    explicit digraph_iterator(const safe_iterator<digraph<NT,AT>, digraph_node<NT,AT> >& iterator);
  };

  ////////////////////////////////////////////////////////////////////////////////

  template<typename NT, typename AT, typename ARef, typename APtr>
  class digraph_arc_iterator : public safe_iterator<digraph<NT,AT>, digraph_arc<NT,AT> >
  {
  public:
    friend class digraph<NT,AT>;

    // iterator traits, were inherited from std::iterator but inheriting from that was deprecated in C++17
    // the digraph iterators are bidirectional but not random-access
    typedef std::bidirectional_iterator_tag iterator_category;
    typedef AT value_type;
    typedef APtr pointer;
    typedef ARef reference;
    // this is not random access, so declare a void difference type, not sure this is supported by everything
    // typedef std::ptrdiff_t difference_type;
    typedef void difference_type;

    // local type definitions
    // an iterator points to an object whilst a const_iterator points to a const object
    typedef digraph_arc_iterator<NT,AT,AT&,AT*> iterator;
    typedef digraph_arc_iterator<NT,AT,const AT&,const AT*> const_iterator;
    typedef digraph_arc_iterator<NT,AT,ARef,APtr> this_iterator;

    // constructor to create a null iterator - you must assign a valid value to this iterator before using it
    digraph_arc_iterator(void);
    ~digraph_arc_iterator(void);

    // Type conversion methods allow const_iterator and iterator to be converted
    // convert an iterator/const_iterator to a const_iterator
    const_iterator constify(void) const;
    // convert an iterator/const_iterator to an iterator
    iterator deconstify(void) const;

    // increment/decrement operators used to step through the set of all nodes in a graph
    // it is only legal to increment a valid iterator
    // pre-increment
    // exceptions: null_dereference,end_dereference
    this_iterator& operator ++ (void);
    // post-increment
    // exceptions: null_dereference,end_dereference
    this_iterator operator ++ (int);
    // pre-decrement
    // exceptions: null_dereference,end_dereference
    this_iterator& operator -- (void);
    // post-decrement
    // exceptions: null_dereference,end_dereference
    this_iterator operator -- (int);

    // test useful for testing whether iteration has completed and for inclusion in other containers
    // Note: this class also inherits the safe_iterator methods: valid(), null(), end()
    bool operator == (const this_iterator&) const;
    bool operator != (const this_iterator&) const;
    bool operator < (const this_iterator&) const;

    // access the node data - a const_iterator gives you a const element, an iterator a non-const element
    // it is illegal to dereference an invalid (i.e. null or end) iterator
    // exceptions: null_dereference,end_dereference
    reference operator*(void) const;
    // exceptions: null_dereference,end_dereference
    pointer operator->(void) const;

  public:
    // constructor used by digraph to create a non-null iterator
    explicit digraph_arc_iterator(digraph_arc<NT,AT>* arc);
    // constructor used by digraph to create an end iterator
    explicit digraph_arc_iterator(const digraph<NT,AT>* owner);
    // used to create an alias of an iterator
    explicit digraph_arc_iterator(const safe_iterator<digraph<NT,AT>, digraph_arc<NT,AT> >& iterator);
  };

  ////////////////////////////////////////////////////////////////////////////////
  // The Graph class
  // NT is the Node type and AT is the Arc type
  ////////////////////////////////////////////////////////////////////////////////

  template<typename NT, typename AT>
  class digraph
  {
  public:
    // STL-like typedefs for the types and iterators
    typedef NT node_type;
    typedef AT arc_type;
    typedef digraph_iterator<NT,AT,NT&,NT*> iterator;
    typedef digraph_iterator<NT,AT,const NT&,const NT*> const_iterator;
    typedef digraph_arc_iterator<NT,AT,AT&,AT*> arc_iterator;
    typedef digraph_arc_iterator<NT,AT,const AT&,const AT*> const_arc_iterator;

    // iterator ownership - can check whether the graph owns an iterator
    bool owns(iterator) const;
    bool owns(const_iterator) const;
    bool owns(arc_iterator) const;
    bool owns(const_arc_iterator) const;

    // supplementary types used throughout

    // a path is represented as a vector of arcs so the forward traversal is
    // done by going from begin() to end() or 0 to size-1 - of course a backward
    // traversal can be done by traversing the vector backwards
    typedef std::vector<arc_iterator> arc_vector;
    typedef std::vector<const_arc_iterator> const_arc_vector;
    // exceptions: wrong_object,null_dereference,end_dereference
    const_arc_vector constify_arcs(const arc_vector&) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_vector deconstify_arcs(const const_arc_vector&) const;

    // a path vector is a vector of paths used to represent all the paths from one node to another
    // there is no particular ordering to the paths in the vector
    typedef std::vector<arc_vector> path_vector;
    typedef std::vector<const_arc_vector> const_path_vector;
    // exceptions: wrong_object,null_dereference,end_dereference
    const_path_vector constify_paths(const path_vector&) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    path_vector deconstify_paths(const const_path_vector&) const;

    // a node vector is a simple vector of nodes used to represent the reachable sets
    // there is no particular ordering to the nodes in the vector
    typedef std::vector<iterator> node_vector;
    typedef std::vector<const_iterator> const_node_vector;
    // exceptions: wrong_object,null_dereference,end_dereference
    const_node_vector constify_nodes(const node_vector&) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    node_vector deconstify_nodes(const const_node_vector&) const;

    // callback used in the path algorithms to select which arcs to consider
    typedef bool (*arc_select_fn) (const digraph<NT,AT>&, const_arc_iterator);

    // a value representing an unknown offset
    // Note that it's static so use in the form digraph<NT,AT>::npos()
    static unsigned npos(void);

    //////////////////////////////////////////////////////////////////////////
    // Constructors, destructors and copies

    digraph(void);
    ~digraph(void);

    // copy constructor and assignment both copy the graph
    digraph(const digraph<NT,AT>&);
    digraph<NT,AT>& operator=(const digraph<NT,AT>&);

    //////////////////////////////////////////////////////////////////////////
    // Basic Node functions
    // Nodes are referred to by iterators created when the node is inserted.
    // Iterators remain valid unless the node is erased (they are list iterators, so no resize problems)
    // It is also possible to walk through all the nodes using a list-like start() to end() loop
    // Each node has a set of input arcs and output arcs. These are indexed by an unsigned i.e. they form a vector.
    // The total number of inputs is the fanin and the total number of outputs is the fanout.
    // The contents of the node (type NT) are accessed, of course, by dereferencing the node iterator.

    // tests for the number of nodes and the special test for zero nodes
    bool empty(void) const;
    unsigned size(void) const;

    // add a new node and return its iterator
    iterator insert(const NT& node_data);

    // remove a node and return the iterator to the next node
    // erasing a node erases its arcs
    // exceptions: wrong_object,null_dereference,end_dereference
    iterator erase(iterator);
    // remove all nodes
    void clear(void);

    // traverse all the nodes in no particular order using STL-style iteration
    const_iterator begin(void) const;
    iterator begin(void);
    const_iterator end(void) const;
    iterator end(void);

    // access the inputs of this node
    // the fanin is the number of inputs and the inputs are accessed using an index from 0..fanin-1
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned fanin(const_iterator) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned fanin(iterator);
    // exceptions: wrong_object,null_dereference,end_dereference,std::out_of_range
    const_arc_iterator input(const_iterator, unsigned) const;
    // exceptions: wrong_object,null_dereference,end_dereference,std::out_of_range
    arc_iterator input(iterator, unsigned);

    // access the outputs of this node
    // the fanout is the number of outputs and the outputs are accessed using an index from 0..fanout-1
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned fanout(const_iterator) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned fanout(iterator);
    // exceptions: wrong_object,null_dereference,end_dereference,std::out_of_range
    const_arc_iterator output(const_iterator, unsigned) const;
    // exceptions: wrong_object,null_dereference,end_dereference,std::out_of_range
    arc_iterator output(iterator, unsigned);

    // convenience routines for getting the set of all inputs or all outputs as vectors
    // exceptions: wrong_object,null_dereference,end_dereference
    const_arc_vector inputs(const_iterator) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_vector inputs(iterator);
    // exceptions: wrong_object,null_dereference,end_dereference
    const_arc_vector outputs(const_iterator) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_vector outputs(iterator);

    // find the output index of an arc which goes from this node
    // returns digraph<NT,AT>::npos if the arc is not an output of from
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned output_offset(const_iterator from, const_arc_iterator arc) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned output_offset(iterator from, arc_iterator arc);
    // ditto for an input arc
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned input_offset(const_iterator to, const_arc_iterator arc) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    unsigned input_offset(iterator to, arc_iterator arc);

    //////////////////////////////////////////////////////////////////////////
    // Basic Arc functions
    // to avoid name conflicts, arc functions have the arc_ prefix
    // Arcs, like nodes, are referred to by a list iterator which is returned by the arc_insert function
    // They may also be visited from arc_begin() to arc_end()
    // Each arc has a from field and a to field which contain the node iterators of the endpoints of the arc
    // Of course, the arc data can be accessed by simply dereferencing the iterator

    // tests for the number of arcs and the special test for zero arcs
    bool arc_empty (void) const;
    unsigned arc_size(void) const;

    // add a new arc and return its iterator
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_iterator arc_insert(iterator from, iterator to, const AT& arc_data = AT());

    // remove an arc and return the iterator to the next arc
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_iterator arc_erase(arc_iterator);
    // remove all arcs
    void arc_clear(void);

    // traverse all the arcs in no particular order using STL-style iteration
    const_arc_iterator arc_begin(void) const;
    arc_iterator arc_begin(void);
    const_arc_iterator arc_end(void) const;
    arc_iterator arc_end(void);

    // find the node that an arc points from or to
    // exceptions: wrong_object,null_dereference,end_dereference
    const_iterator arc_from(const_arc_iterator) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    iterator arc_from(arc_iterator);
    // exceptions: wrong_object,null_dereference,end_dereference
    const_iterator arc_to(const_arc_iterator) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    iterator arc_to(arc_iterator);

    // reconnect an arc to a different from and to node
    // exceptions: wrong_object,null_dereference,end_dereference
    void arc_move(arc_iterator arc, iterator from, iterator to);
    // reconnect just the from node
    // exceptions: wrong_object,null_dereference,end_dereference
    void arc_move_from(arc_iterator arc, iterator from);
    // reconnect just the to node
    // exceptions: wrong_object,null_dereference,end_dereference
    void arc_move_to(arc_iterator arc, iterator to);
    // reverse the arc direction so that to becomes from and vice-versa
    // exceptions: wrong_object,null_dereference,end_dereference
    void arc_flip(arc_iterator arc);

    ////////////////////////////////////////////////////////////////////////////////
    // whole graph manipulations

    // move one graph into another by moving all its nodes/arcs
    // this leaves the source graph empty
    // all iterators to nodes/arcs in the source graph will still work and will be owned by this
    void move(digraph<NT,AT>& source);

    ////////////////////////////////////////////////////////////////////////////////
    // Adjacency algorithms

    // test whether the nodes are adjacent i.e. whether there is an arc going from from to to
    // exceptions: wrong_object,null_dereference,end_dereference
    bool adjacent(const_iterator from, const_iterator to) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    bool adjacent(iterator from, iterator to);

    // as above, but returns the arc that makes the nodes adjacent
    // returns the first arc if there's more than one, returns arc_end() if there are none
    // exceptions: wrong_object,null_dereference,end_dereference
    const_arc_iterator adjacent_arc(const_iterator from, const_iterator to) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_iterator adjacent_arc(iterator from, iterator to);

    // as above, but returns the set of all arcs that make two nodes adjacent (there may be more than one)
    // returns an empty vector if there are none
    // exceptions: wrong_object,null_dereference,end_dereference
    const_arc_vector adjacent_arcs(const_iterator from, const_iterator to) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_vector adjacent_arcs(iterator from, iterator to);

    // return the adjacency sets for the node inputs or outputs, i.e. the set of nodes adjacent to this node
    // each adjacent node will only be entered once even if there are multiple arcs between the nodes
    // exceptions: wrong_object,null_dereference,end_dereference
    const_node_vector input_adjacencies(const_iterator to) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    node_vector input_adjacencies(iterator to);
    // exceptions: wrong_object,null_dereference,end_dereference
    const_node_vector output_adjacencies(const_iterator from) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    node_vector output_adjacencies(iterator from);

    ////////////////////////////////////////////////////////////////////////////////
    // Topographical Sort Algorithm
    // This generates a node ordering such that each node is visited after its fanin nodes.

    // This only generates a valid ordering for a Directed Acyclic Graph (DAG).

    // The return value is a pair :
    //  - the node vector which is a set of iterators to the nodes in sorted order
    //  - the arc vector is the set of backward arcs that were broken to achieve the sort
    // If the arc vector is empty then the graph formed a DAG.

    // The arc selection callback can be used to ignore arcs that are not part
    // of the ordering, i.e. arcs that are meant to be backwards arcs

    std::pair<const_node_vector,const_arc_vector> sort(arc_select_fn = 0) const;
    std::pair<node_vector,arc_vector> sort(arc_select_fn = 0);

    // Simplified variant of above for graphs that are known to be DAGs.
    // If the sort fails due to backward arcs, the
    // return vector is empty. Note that this will also be empty if the graph
    // has no nodes in it, so use the empty() method to differentiate.

    const_node_vector dag_sort(arc_select_fn = 0) const;
    node_vector dag_sort(arc_select_fn = 0);

    ////////////////////////////////////////////////////////////////////////////////
    // Basic Path Algorithms
    // A path is a series of arcs - you can use arc_from and arc_to to convert
    // that into a series of nodes. All the path algorithms take an arc_select
    // which allows arcs to be selected or rejected for consideration in a path.

    // A selection callback function is applied to each arc in the traversal and
    // returns true if the arc is to be selected and false if the arc is to be
    // rejected. If no function is provided the arc is selected. If you want to
    // use arc selection you should create a function with the type profile given
    // by the arc_select_fn type. The select function is passed both the graph and
    // the arc iterator so that it is possible to select an arc on the basis of
    // the nodes it is connected to.

    // Note: I used a callback because the STL-like predicate idea wasn't working for me...

    // test for the existence of a path from from to to
    // exceptions: wrong_object,null_dereference,end_dereference
    bool path_exists(const_iterator from, const_iterator to, arc_select_fn = 0) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    bool path_exists(iterator from, iterator to, arc_select_fn = 0);

    // get the set of all paths from from to to
    // exceptions: wrong_object,null_dereference,end_dereference
    const_path_vector all_paths(const_iterator from, const_iterator to, arc_select_fn = 0) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    path_vector all_paths(iterator from, iterator to, arc_select_fn = 0);

    // get the set of all nodes that can be reached by any path from from
    // exceptions: wrong_object,null_dereference,end_dereference
    const_node_vector reachable_nodes(const_iterator from, arc_select_fn = 0) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    node_vector reachable_nodes(iterator from, arc_select_fn = 0);

    // get the set of all nodes that can reach to to by any path
    // exceptions: wrong_object,null_dereference,end_dereference
    const_node_vector reaching_nodes(const_iterator to, arc_select_fn = 0) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    node_vector reaching_nodes(iterator to, arc_select_fn = 0);

    ////////////////////////////////////////////////////////////////////////////////
    // Unweighted Shortest path algorithms

    // find the shortest path from from to to
    // This is an unweighted shortest path algorithm, i.e. the weight of each
    // arc is assumed to be 1, so just counts the number of arcs
    // if there is more than one shortest path it returns the first one
    // If there are no paths, returns an empty path
    // exceptions: wrong_object,null_dereference,end_dereference
    const_arc_vector shortest_path(const_iterator from, const_iterator to, arc_select_fn = 0) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    arc_vector shortest_path(iterator from, iterator to, arc_select_fn = 0);

    // find the set of shortest paths from from to any other node in the graph
    // that is reachable (i.e. for which path_exists() is true)
    // This is an unweighted shortest path, so just counts the number of arcs
    // if there is more than one shortest path to a node it returns the first one
    // If there are no paths, returns an empty list
    // exceptions: wrong_object,null_dereference,end_dereference
    const_path_vector shortest_paths(const_iterator from, arc_select_fn = 0) const;
    // exceptions: wrong_object,null_dereference,end_dereference
    path_vector shortest_paths(iterator from, arc_select_fn = 0);

  private:
    friend class digraph_iterator<NT,AT,NT&,NT*>;
    friend class digraph_iterator<NT,AT,const NT&,const NT*>;
    friend class digraph_arc_iterator<NT,AT,AT&,AT*>;
    friend class digraph_arc_iterator<NT,AT,const AT&, const AT*>;

    typedef std::set<const_iterator> const_iterator_set;
    typedef typename const_iterator_set::iterator const_iterator_set_iterator;

    // exceptions: wrong_object,null_dereference,end_dereference
    bool path_exists_r(const_iterator from, const_iterator to, const_iterator_set& visited, arc_select_fn) const;

    // exceptions: wrong_object,null_dereference,end_dereference
    void all_paths_r(const_iterator from, const_iterator to, const_arc_vector& so_far, const_path_vector& result, arc_select_fn) const;

    // exceptions: wrong_object,null_dereference,end_dereference
    void reachable_nodes_r(const_iterator from, const_iterator_set& visited, arc_select_fn) const;

    // exceptions: wrong_object,null_dereference,end_dereference
    void reaching_nodes_r(const_iterator to, const_iterator_set& visited, arc_select_fn) const;

    digraph_node<NT,AT>* m_nodes_begin;
    digraph_node<NT,AT>* m_nodes_end;
    digraph_arc<NT,AT>* m_arcs_begin;
    digraph_arc<NT,AT>* m_arcs_end;
  };

  ////////////////////////////////////////////////////////////////////////////////

} // end namespace stlplus

#include "digraph.tpp"
#endif
