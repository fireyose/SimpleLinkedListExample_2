/************************************************************************//** 
 * @file linklist.h 
 *
 * FILE: linklist.h
 *          This is the header file for the templated singularly linked linklist class with a native implemention.
 * 
 * AUTHOR: Dr. Greg Schaper
 *
 * PURPOSE: This class defines a general purpose single linked-list ADT container. 
*                          The collection of methods are designed to allow client appplications
*                          to manipulate sequential lists of data values organized either spatially, by
*                           relative worth, or temporally. 
*                           Additional methods are provided for operations that are frequently used,
*                           such as, insertFront, removeFront, etc..
*                           This basic sequential container is designed to be a building block for 
 *                          other ADTs implements either using aggregation or inheritance. However,
 *                          it can be used directly by client applications also.
 * 
 *
 * DEPENDENCIES: The functions and/or methods in this file should allow manipulation of
 *                          any data type for which all value semantic operations, 
 *                          relational operations, <<, and >> operations have been implemented.
 *
 * Compiler Version:  gcc version 3.4.6
 *
 * Modification History: 
 *            - 10/14/2012: Created original version.
 *            -  9/15/2014: Added comprehensive documentation for each method.
****************************************************************************/

#ifndef XXXX_LINKLISTCLASS_XXXX
#define XXXX_LINKLISTCLASS_XXXX
#include<iostream>
#include<fstream>
#include<cstdlib>

template <class T>
class linklist
{
 public:

        /***************************************************************************
            NAME:   linklist();
            PURPOSE: Create a new object of type linklist. Initialize all global class attributes
                                      to a state that creates a new empty empty object that is ready for use.
            PRECONDITIONS: none.
                - Parameters
                - Return Value
                - Other
           POSTCONDITIONS: New object of type linklist has been created as an empty list.
         ****************************************************************************/
  linklist();


        /***************************************************************************
            NAME: linklist(const linklist<T>& original);
            PURPOSE: Create a new object of type linklist that is a duplicate copy of the 
                        object pointed to by the parameter original. Must perform a deep copy.
            PRECONDITIONS: orignial object exists and meets all invarient properties.
                - Parameters : original contains the address of the object to copy.
                - Return Value: 
                - Other:
           POSTCONDITIONS: The *this object is a duplicate copy of original. *this object
                 meets all invarient properties.  
         ****************************************************************************/
  linklist(const linklist<T>& original);


        /***************************************************************************
            NAME: linklist operator =(linklist<T> rhs);
            PURPOSE: Make the *this object a duplicate copy of the rhs (RightHandSide) object.
            PRECONDITIONS: *this and rhs objects already exist and meet all invarient properties.
                - Parameters: rhs object is a copy of the actual argument.
                - Return Value: A copy of rhs is return by value as is customary for operator =.
                - Other
           POSTCONDITIONS: *this object is a duplicate copy of rhs and satisfied all 
                invarient properties.
         ****************************************************************************/
  linklist operator =(linklist<T> rhs);


        /***************************************************************************
            NAME:  ~linklist();
            PURPOSE: Return all memory that was dynamically allocated to the *this object
                     back to the operating system for reuse. Set all state of object's attributes to 
                     represent an empty object.
            PRECONDITIONS: *this satisfies all invarient properties.
                - Parameters
                - Return Value
                - Other
           POSTCONDITIONS: *this is an empty list that satisfies all invarient properties.
                All dynamic memory allocated to the object has been returned to the 
                 operating system.
         ****************************************************************************/
  ~linklist();


        /***************************************************************************
            NAME: bool isEmpty() const;
            PURPOSE: Determine if *this object contains any data values.
            PRECONDITIONS: *this exists and satisfies all invarient properties
                - Parameters:
                - Return Value: bool. true if *this contains no data, false otherwise.
                - Other
           POSTCONDITIONS: State of *this is not modified. 
         ****************************************************************************/
  bool isEmpty() const;


        /***************************************************************************
            NAME:  std::size_t NumberOfItems() const;
            PURPOSE: Determine the number of data values stored in *this. 
            PRECONDITIONS:
                - Parameters
                - Return Value: std::size_t is a non-negative integer indicating the number
                        of data values currently stored in *this.
                - Other
           POSTCONDITIONS: State of *this is not modified.
         ****************************************************************************/
  std::size_t NumberOfItems() const;


        /***************************************************************************
            NAME:   void insertFront(T anItem);
            PURPOSE: Insert a new data value as the first node of *this.
            PRECONDITIONS: *this exists and satisfies all invarient properties.
                - Parameters: anItem is a copy of the actual argument and contains the 
                        data value to be inserted.
                - Return Value
                - Other
           POSTCONDITIONS: *this state is modified to contain a new first node that 
                 contains the data value stored in anItem.
         ****************************************************************************/
  void insertFront(T anItem);


        /***************************************************************************
            NAME:   void insertEnd(T anItem);
            PURPOSE: Insert a new data value as the last node of *this.
            PRECONDITIONS: *this exists and satisfies all invarient properties.
                - Parameters: anItem is a copy of the actual argument and contains the 
                        data value to be inserted.
                - Return Value
                - Other
           POSTCONDITIONS: *this state is modified to contain a new last node that 
                 contains the data value stored in anItem.
         ****************************************************************************/
  void insertEnd(T anItem);


        /***************************************************************************
            NAME: void insertByPosition(size_t index, T anItem);
            PURPOSE: Add a new node to *this containing data value anItem. The new node
                    will be in position specified by index from the begining of the list. 
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    index > 0.
                - Parameters: index specified the position the new node will be located at from the 
                          begining of the list. If index is larger than the size of *this then append the new 
                          node at the end of *this. Index must be larger than 0. anItem contains a copy 
                          of the actual argument and contains the data value to be inserted into *this.
                - Return Value
                - Other
           POSTCONDITIONS: A new node containing data value anItem is added to *this at
                     position index.
         ****************************************************************************/
  void insertByPosition(size_t index, T anItem);


        /***************************************************************************
            NAME: void swapDataItem(T& x, T& y);
            PURPOSE: Exchange the the data values held in the nodes pointed to by x and y.
                    This method supports creating a sorted list from an unsorted list.
                    This method supports the implementation of an insert sort to maintain 
                    a sorted list. (might consider making this a private method)
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty and contains at least 2 nodes.
                                                     x and y contain the address of valid nodes in *this.
                - Parameters: x and y hold the address of two nodes of *this.
                - Return Value
                - Other
           POSTCONDITIONS: State of *this is modified so that the data values contianed
                by the nodes pointed to by x and y have been exchanged.
         ****************************************************************************/
  void swapDataItem(T& x, T& y);


        /***************************************************************************
            NAME:   void insertByValue(T anItem);
            PURPOSE: Insert a new node containing the value stored in anItem into *this
                   before the first node in *this that contains a data value larger than anItem.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                - Parameters: anItem is a copy of the actual argument and contains the data value to
                         insert into *this.
                - Return Value
                - Other
           POSTCONDITIONS:
         ****************************************************************************/
  void insertByValue(T anItem);


        /***************************************************************************
            NAME:  T peekFront() const;
            PURPOSE: Return a copy of the data stored in the first node of *this.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                - Parameters
                - Return Value: Copy of the data value contained in first node of *this.
                - Other
           POSTCONDITIONS: State of *this is not modified.
         ****************************************************************************/
  T peekFront() const;


        /***************************************************************************
            NAME: T peekEnd() const;
            PURPOSE: Return a copy of the data stored in the last node of *this.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                - Parameters
                - Return Value: Copy of the data value contained in last node of *this.
                - Other
           POSTCONDITIONS: State of *this is not modified.
         ****************************************************************************/
  T peekEnd() const;


        /***************************************************************************
            NAME: T peekByPosition(std::size_t index) const;
            PURPOSE: Return a copy of the data stored in the node of *this at position 
                   specified by index from the front of the list.
            PRECONDITIONS:  *this exists and satisfies all invarient properties. 
                                                    *this is not empty.
                - Parameters
                - Return Value: Copy of the data value contained in node at postion index of *this.
                - Other
           POSTCONDITIONS: State of *this is not modified.
         ****************************************************************************/
  T peekByPosition(std::size_t index) const;


        /***************************************************************************
            NAME:   std::size_t peekByValue(T anItem) const;
            PURPOSE: Return the index of the first node in *this that contains the value anItem.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                - Parameters: anItem is a copy of the actual argument.
                - Return Value: 0 if anItem is not in the list, otherwise the index of the first
                         node in *this that contains the value anItem.
                - Other
           POSTCONDITIONS: State of *this is not modified.
         ****************************************************************************/
  std::size_t peekByValue(T anItem) const;


        /***************************************************************************
            NAME: void removeFront();
            PURPOSE: Remove the first node of *this and deallocated its memory.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                - Parameters
                - Return Value
                - Other
           POSTCONDITIONS: The first node of *this has been removed.
         ****************************************************************************/
  void removeFront();


        /***************************************************************************
            NAME:   void removeEnd();
            PURPOSE: Remove the last node of *this and deallocated its memory.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                - Parameters
                - Return Value
                - Other
           POSTCONDITIONS: The last node of *this has been removed.
         ****************************************************************************/
  void removeEnd();


        /***************************************************************************
            NAME: void removeByPosition(std::size_t index);
            PURPOSE: Remove node as position specifed by index from *this.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                                                    index > 0.
                                                    index <= number of nodes in *this.
                - Parameters: index is a copy of the actual argument and specifies the 
                         position of the node in *this to remove from *this.
                - Return Value
                - Other
           POSTCONDITIONS: *this is modified to no longer contain the node at position 
                         spedified by index.
         ****************************************************************************/
  void removeByPosition(size_t index);


        /***************************************************************************
            NAME:   void removeByValue(T anItem);
            PURPOSE: Remove the first node in *this that contains the value anItem.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                                                    *this contains a node with the value spedified by anItem.
                - Parameters: anItem contains a copy of the actual argument and specifies
                          the data value whose node is to be removed from *this.
                - Return Value
                - Other
           POSTCONDITIONS: *this is modfied to no longer contain the first node that 
                    contains the data value anItem.
         ****************************************************************************/
  void removeByValue(T anItem);


        /***************************************************************************
            NAME:   void removeAll();
            PURPOSE: Remove all nodes from *this.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                - Parameters
                - Return Value
                - Other
           POSTCONDITIONS: *this contains no nodes and is same state as a newly instantiated
                   empty object.
         ****************************************************************************/
  void removeAll();


        /***************************************************************************
            NAME:   void print(std::ostream& outStream, char separator = '\n') const;
            PURPOSE: Insert all data values contained in *this outStream. The data values
                are separated by the character specified by separator.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                   outStream is in a valid state.
                - Parameters: outStream is a reference to a valid ostream object. 
                                              separator is a character inserted to outStream after each
                                              data value is inserted. Serves to separate the data values
                                              in the outStream. 
                - Return Value
                - Other
           POSTCONDITIONS: State of *this is not modified. State of outStream is modified
                   to contain all the data values stored in *this in sequential order from the 
                    first to last node in *this. separator character used to control format of
                    outStream.
         ****************************************************************************/
  void print(std::ostream& outStream, char) const;


        /***************************************************************************
            NAME:   T const& operator[](std::size_t index) const;
            PURPOSE: Return the address of the node in the *this at position specified by index.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                                                     index > 0.
                                                     index <= number of nodes in *this.
                - Parameters: index specifies the position of the node in *this whose
                         address is to be returned.
                - Return Value
                - Other
           POSTCONDITIONS: State of *this is not modified. 
         ****************************************************************************/
  T const& operator[](std::size_t position) const;


        /***************************************************************************
            NAME:  T& operator[](std::size_t position);
            PURPOSE: Return the address of the node in the *this at position specified by index.
            PRECONDITIONS:  *this exists and satisfies all invarient properties.
                                                    *this is not empty.
                                                     index > 0.
                                                     index <= number of nodes in *this.
                - Parameters: index specifies the position of the node in *this whose
                         address is to be returned.
                - Return Value
                - Other
           POSTCONDITIONS: State of *this is not modified. 
         ****************************************************************************/
  T& operator[](std::size_t position);


 private:

        /***************************************************************************
            NAME: node
            PURPOSE: container for a data value in the link list.
         ****************************************************************************/
   class node
   {
     public:
       T dataItem;
       node* linkPointer;
       // construct a new node and initialize its attributes with the given parameters.
       node(T i, node* l): dataItem(i), linkPointer(l)
         {
         };
   };


   node* headPointer;    


};



        /***************************************************************************
            NAME: std::ostream& operator <<(std::ostream& outStream, linklist<T> list);
            PURPOSE: Define << for linklist class.
            PRECONDITIONS: outStream is in a valid state.
                                                   list is a copy of the actual argument and is a linklist object
                                                   that statisfies all invarient properties.
                - Parameters
                - Return Value
                - Other
           POSTCONDITIONS: Data vaues stored in list are inserted to outStream.
         ****************************************************************************/
template <class T>
std::ostream& operator <<(std::ostream& outStream, linklist<T> list);




#include "linklist.cxx"
#endif


