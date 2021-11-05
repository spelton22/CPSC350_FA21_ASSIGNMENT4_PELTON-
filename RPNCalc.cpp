/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    RPNCalc.cpp
*/

#include "RPNCalc.h"

RPNCalc::RPNCalc(){ //default constructor
}

RPNCalc::~RPNCalc(){ //default destructor
}

//parses the given string and pushes each element onto the stack
int RPNCalc::processString(string input){
  //parses input string and puts contents on the stack as string
  st = new GenStack<string>();
  string subs = input; //substring that changes with each iteration of the loop
  int calc = 0; //final calculation from given string
  int pos  = 0; //position of each space from find()
  string stackstr = ""; //string that is pushed on the stack

  while(true){
    pos = subs.find(" "); //find the first occurance of a space in the string and returns the position
    if(pos != std::string::npos){ //if a space was found
      stackstr = subs.substr(0 , pos); //substring from the begining to the first space (not included)
      st->push(stackstr); //pushes string to stack
      subs = subs.substr(pos+1); //resets the substring from the index after the space to the end
    }else if(subs.length() > 0){ //if there are no more spaces but there is still an element in the string
      st->push(subs); //push that string to the stack
      break;
    }else{
      break;
    }
  }

  //calls recCalc on that stack and returns the number from the calculations
  calc = recCalc(st);

  //checks if there is still an element in the stack after recCalc has been called on it
    // for case of 3+ numbers in a row in the beginning of the string
  if(st->isEmpty() == false){
    throw runtime_error("result: invalid input");
  }

  delete st;
  return calc; //return value
}

//method to do calculation from the inputted stack
int RPNCalc::recCalc(GenStack<string> *s){

  int num;//number that is popped off the stack
  int rightval; //right value of the equation from the stack
  int leftval; //left value of the equation from the stack
  int retval; //return value from the calculation

  //checks if the given stack is empty
  if(s->isEmpty()){
    throw runtime_error("stack is empty can not remove");
  }
  //pops the first element of the stack and sets it to curr
  string curr = s->pop();
  //checks if curr is a number
  if(std::isdigit(curr.at(0))){
    //make the string an int and sets to num
    num = stoi(curr);
    //returns the number
    return num;
  }else{
    //if curr is not a number than it should be an operator
    if((curr.compare("+") == 0) || (curr.compare("-") == 0) || (curr.compare("*") == 0) || (curr.compare("/") == 0) || (curr.compare("%") == 0)){
      //recursively calls recCalc on the stack to get the right value
      rightval = recCalc(s);
      //recursively calls recCalc on the stack to get the right value
      leftval = recCalc(s);
      //calls the operation() method to get the return value
      retval = operation(leftval, rightval, curr);
      //returns the final value of calculation
      return retval;
    }else{ //not a number or not a valid operator
      throw runtime_error("unexpected input");
    }
  }
}
//method to check which operation to compute
int RPNCalc::operation(int num1, int num2, string op){
  //checks which operation op is
  if(op.compare("-") == 0){ //subtraction
    return subtract(num1, num2);
  }else if(op.compare("+")== 0){ //addition
    return sum(num1, num2);
  }else if(op.compare("*")== 0){ //multiplication
    return multiply(num1, num2);
  }else if(op.compare("/")== 0){ //division
    return division(num1, num2);
  }else if(op.compare("%")== 0){ //modulus
    return modulus(num1, num2);
  }else{ //not a valid operator
    throw runtime_error("incorrect operation");
  }
}
//method to compute the addition calculation
int RPNCalc::sum(int num1, int num2){
  return (num1+num2);
}
//method to compute the multiplication calculation
int RPNCalc::multiply(int num1, int num2){
  return (num1*num2);
}
//method to compute the subtractions calculation
int RPNCalc::subtract(int num1, int num2){
  return (num1-num2);
}
//method to compute the division calculation
int RPNCalc::division(int num1, int num2){
  return (num1/num2);
}
//method to compute the modulus calculation
int RPNCalc::modulus(int num1, int num2){
  return (num1%num2);
}
