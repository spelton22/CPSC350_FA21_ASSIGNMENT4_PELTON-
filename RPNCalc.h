/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    RPNCalc.h
*/

#ifndef RPNCALC_H
#define RPNCALC_H

#include <iostream>
#include <string>
#include "GenStack.h"
#include<ctype.h>
#include <exception>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class RPNCalc{
  public:
    RPNCalc(); //default constructor
    ~RPNCalc(); //default destructor
    int sum(int num1, int num2); //calculates addition
    int multiply(int num1, int num2); //calculates multiplication
    int subtract(int num1, int num2); //calculates subtraction
    int division(int num1, int num2); //calculates division
    int modulus(int num1, int num2); //calculates modulus
    int processString(string input); //process the string and puts each element on the stack
    int recCalc(GenStack<string> *s); //processes stack and returns the number from the calculations
    int operation(int num1, int num2, string op); //processes which operation op is and does calculation

  private:
    GenStack<string> *st; //declares the stack that will be used 
};

#endif
