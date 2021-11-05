/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    FileProcessor.h
*/

#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileProcessor{
  public:
    FileProcessor(); //default constructor
    ~FileProcessor(); //default destructor
    void processFile(string in); //method to process the inputted file and send the contents to calculcate the complement and reverse complement
};

#endif
