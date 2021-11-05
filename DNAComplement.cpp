/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    DNAComplement.cpp
*/

#include "DNAComplement.h"

DNAComplement::DNAComplement(){ //default constructor
  myStack = new GenStack<char>();
}

DNAComplement::~DNAComplement(){ //default destructor
  delete myStack;
}

//method to calculate the dna complement of an inputed string
string DNAComplement::complement(string s){
  string output = ""; //output string that is the complement of the inputted string

  for(int i=0; i < s.length(); ++i){
    //goes through the entire string and evaluates each character in the string
    switch(toupper(s.at(i)))
    {
    case 'A':
      output.append(1, 'T');
      break;
    case 'T':
      output.append(1, 'A');
      break;
    case 'C':
      output.append(1, 'G');
      break;
    case 'G':
      output.append(1, 'C');
      break;
    default:
      //if they input the a character that is not T, A, G, or C, it is added to the output, nothing changes for that character
      output.append(1, s.at(i));
    }
  }
  return output; //dna complement of string
}

//calculates the reverse complement of a string
string DNAComplement::reverseComplement(string s){
  string output;
  s = complement(s); // calls complement on the inputted string

  for(int i = 0; i< s.length(); ++i){ //pushes each item in the stack onto the stack
    myStack->push(s.at(i));
  }

  while(!myStack->isEmpty()){ //pops off each item of the stack to get the reverse of the string
    output.append(1, myStack->pop());
  }
  //returns the reverse complement of the inputted string
  return output;
}
