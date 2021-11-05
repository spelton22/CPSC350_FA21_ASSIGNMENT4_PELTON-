/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    GenStack.h
*/

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Node{
  public:
    Node(T data); //overloaded constructor
    Node(); //default constructor
    ~Node(); //default destructor
    T value; //template value for the value of the node
    Node<T> *next; //pointer to the next element
  private:
    template<typename U>friend class LinkedList; //specifies that the Linked list class is a friend class to this class
};

template <typename T>
Node<T>::Node(){ //default constructor
  value = NULL; //sets value of the node to NULL
  next = nullptr; //next pointer is null
}

template <typename T>
Node<T>::Node(T data){ //overloaded constructor
  value = data; //sets value to inputted data
  next = nullptr; //sets next pointer to null
}

template <typename T>
Node<T>::~Node(){ // default destructor
}

template <typename T>
class GenStack{
  public:
    GenStack<T>();//default constructor
    ~GenStack();//destructor

    //core functions
    void push(T data); // aka insert at top
    T peek(); //retruns the top of the stack
    T pop(); //aka delete from top
    bool isEmpty(); //checks if it is empty
    int getSize(); //returns size of the stack

  private:
    Node<T> *head; //top of the stack/ front of the linked  list
    int size; //size of the stack
};

template <typename T>
GenStack<T>::GenStack(){ //default constructor
  head = nullptr;
  size = 0;
}

template <typename T>
GenStack<T>::~GenStack(){ // default destructor
}

//core functions
template <typename T>
void GenStack<T>::push(T data){ //adding an element to the top of the stack

  Node<T> *p = new Node<T>(data); //new node with value = data
  if(head == NULL){ //checks if stack is empty
    head = p; //sets new node to head
    p->next = NULL; //sets pointer to null because there is only one element in the stack
  }else{ //if stack is not empty
    p->next = head; //sets p pointer to the current head
    head = p; //head is now p
  }
  size++; //increase size since element added
}

template <typename T>
T GenStack<T>::pop(){ //deleting an element from the top of the stack
  T retValue; //value of the deleted node
  if(size == 0){ //checks if the stack is empty
    throw runtime_error("stack is empty can not remove");
  }else if(size == 1){ //checks if there is only one element in the stack
    retValue = head->value; //gets the value of the element
    head = NULL; //head is now null and stack is empty
  }else{ //if there is more than one element in the stack
    retValue = head->value; //gets the value of the head node
    head = head->next; //sets the head to the the heads next elment in the stack
  }
  size--; //decrement the size
  return retValue; //return the value of the node deleted
}

template <typename T>
T GenStack<T>::peek(){ //returns the value at the head
  if(size == 0){ //checks if stack is empty
    throw runtime_error("stack is empty can not remove");
  }
  return head->value; //returns the value of the head
}

template <typename T>
bool GenStack<T>::isEmpty(){ //checks if stack is empty
  return (size == 0); //checks if size equals 0
}

template <typename T>
int GenStack<T>::getSize(){ //returns the size of the stack
  return size;
}

#endif
