/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    main.cpp
*/

#include <iostream>
#include "DNAComplement.h"
#include "FileProcessor.h"
#include "RPNCalc.h"

using namespace std;

int main(int argc, const char *argv[]){

  string userChoice; //variable for the command line arguement
  string inputFile; //variable for the run time user input for file to read from
  string calculation; //variable for run time user input for calculation equation
  RPNCalc *rc = new RPNCalc(); //instance of RPNCalc class
  int output = 0; //calculation output number
  FileProcessor *fp = new FileProcessor(); //instance of FileProcessor class
  userChoice = argv[1];

  //try catch to catch any run time errors
  try{
    while(true){
      if(userChoice.compare("RPN") == 0){ //compares user input for RPN

        cout<< "enter the calculation you want to carry out in post-fix notation." << endl;
        cout << "put a space between each operator and operatands" << endl;
        std::getline(std::cin, calculation);
        //process the string and carry out calculation
        output = rc->processString(calculation);
        //prints out the result of the calculation
        cout << "Result: " << output << endl;
        break; //exits the loop
      }else if(userChoice.compare("DNA") == 0){
        //prompt for file name to read DNA input
        cout << "enter the input file name" << endl;
        cin >> inputFile;
        //calls process string on the inputted file
        cout << "the complement and reverse complement are being written to dnaoutput.txt" << endl;
        fp->processFile(inputFile);
        //writes output to a file
        cout << "check dnaoutput.txt for the output" << endl;
        break; //exits the loop
      }else{
        cout << "incorrect input. Try again" << endl; //incorrect input and allows them to try agian
        cin >> userChoice;
      }
    }
  }
  catch(runtime_error &excpt){ //catches any run time errors
      cerr << excpt.what() << endl;
      //catch errors and prints it to the console
  }

  delete rc;
  delete fp;
  return 0;
}
