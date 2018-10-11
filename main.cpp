#include <iostream>
#include "SyntaxCheck.h"

using namespace std;

int main(int argc, char **argv)
{
  if (argc > 1) // makes sure the user has entered at least 1 argument in the command line
  {
    SyntaxCheck str(argv[1]); //creates an object of SyntaxCheck type to check their file for missing delimeters via its properties

    str.addBracket(); //calls the method that checks for missing delimeters in SyntaxCheck
  }
  return 0;
}
