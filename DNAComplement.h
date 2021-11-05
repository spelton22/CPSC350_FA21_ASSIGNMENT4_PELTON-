/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    DNAComplement.h
*/

#ifndef DNACOMPLEMENT_H
#define DNACOMPLEMENT_H

#include <iostream>
#include <exception>
#include "GenStack.h"
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class DNAComplement{
  public:
    DNAComplement(); //default constructor
    ~DNAComplement(); //default destructor
    string complement(string s); //method to compute the DNA complement of an inputted string
    string reverseComplement(string s); //method to compute the DNA reverseComplement of an inputted string

  private:
    GenStack<char> *myStack; //stack to push the characters from the dna string on for reverse complement
};

#endif
