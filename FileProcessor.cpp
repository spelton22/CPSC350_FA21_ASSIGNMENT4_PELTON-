/* Sophie Pelton
  2370862
  spelton@chapman.edu
  CPSC350-01
  Assignemnt 4
    FileProcessor.cpp
*/

#include "FileProcessor.h"
#include "DNAComplement.h"

FileProcessor::FileProcessor(){
  //default constructor
}

FileProcessor::~FileProcessor(){
  //default destructor
}

void FileProcessor::processFile(string input){

  //instantiate DNAComplement to use the methods from that class
  DNAComplement *dna = new DNAComplement();

  //creates an input stream to read from a file
  std::ifstream myfileIN;
  //creates an output stream to write to a file
  std::ofstream myfileOUT;

  //string where the line from the file is put
  std::string line;
  //string that is returned at the end
  std::string outputComplement ="";
  std::string outputReverseComplement ="";

  //opens the input file for reading
  myfileIN.open(input, ios::in);
  //opens the output file "dnaoutput.txt" for writting and clears out anything in
  //the file before new stuff is written to the file
  myfileOUT.open("dnaoutput.txt", ios::out | ios::trunc);

  //checks if the input and output file is open
  if (myfileIN.is_open() && myfileOUT.is_open()){
    //for loop to go through each line of the file
    for(std::string line; (std::getline(myfileIN, line, '\n')); ) {
      myfileOUT << "Sequence: " << line << '\n';
      //send each line through complement() to get complement of the inputted sequence
      outputComplement = dna->complement(line);
      myfileOUT << "Complement: " << outputComplement << '\n';

      //send each line through reverseComplement() to get complement of the inputted sequence
      outputReverseComplement = dna->reverseComplement(line);
      //writes translation to output file
      myfileOUT << "Reverse Complement: " << outputReverseComplement << '\n';
      myfileOUT << '\n';
      //resets string for next line
      outputComplement = "";
      outputReverseComplement = "";
    }
  }
  //closes both files after done using them
  myfileIN.close();
  myfileOUT.close();

  delete dna;

}
