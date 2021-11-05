# ASSIGNMENT4
fun with stacks

1. Sophie Pelton -- 2370862 -- spelton@chapman.edu -- CPSC350-01 -- Assignment 4
2. DNAComplement.h -- DNAComplement.cpp -- FileProcessor.h -- FileProcessor.cpp -- GenStack.cpp -- RPNCalc.h -- RPNCalc.cpp -- main.cpp -- Makefile -- REAME.md
3. no known compile errors. For DNAComplement.cpp, if the line from the file is in lower case, I cast it to upper case when I am checking the character and then when I write it to the file it is the upper case verion for A, T, C, and G. For the case of there being a character in the file line that is not A, T, G, or C, I append that charcater to the the complement string as is. 

4.references used: 

(1) https://ioecapsule.com/linked-list-template-implementation-of-doubly-linked-list-using-c/
(2) https://www.bestprog.net/en/2019/10/11/c-development-of-a-template-class-that-implements-a-stack-in-the-form-of-a-linked-list/
(3) https://stackoverflow.com/questions/44214288/c-friend-class-for-linked-list-node
(4) https://stackoverflow.com/questions/5029840/convert-char-to-int-in-c-and-c
(5) https://www.geeksforgeeks.org/converting-strings-numbers-cc/
(6) https://java2blog.com/check-if-string-is-number-cpp/#Using_stdisdigit_method_to_check_if_a_string_is_number

5. make realclean --> make all --> ./assignment4.exe ___
  
  there is a command line parameters, enter RPN or DNA. User input is prompted on the concole, for DNA you will have to input a file to read the DNA sequence from. For RPN you will have to input an equation that is in post fix notation with a space between each character (ex: a b + c * d - e / f %)
