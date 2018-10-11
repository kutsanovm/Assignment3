#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;
// defines the variables used throughout SyntaxCheck.cpp
class SyntaxCheck
{
  public:
    SyntaxCheck(string test);
    ~SyntaxCheck();
    void addBracket();
    GenStack<char> *stack;
    int lineCTR;
    ifstream ImportedCodeFile;
    bool comp = false;

  private:
    string line;
    string test;


};
