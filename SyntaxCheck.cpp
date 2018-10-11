#include "SyntaxCheck.h"
#include <iostream>

// research template classes
using namespace std;

SyntaxCheck::SyntaxCheck(string test)
{
  stack = new GenStack<char>(); //creates my stack object (referencing the template stack i made)
  // I'm still pretty iffy on reading from files but this helped: http://www.cplusplus.com/reference/fstream/ifstream/ifstream/
  ImportedCodeFile.open(test, ifstream::in); // opening this file to read the delimeters
}

SyntaxCheck::~SyntaxCheck()
{
  ImportedCodeFile.close(); // closes the file we are reading from (to save space via the destructor)
  delete stack;
  cout << "The syntax checker was destroyed." << endl;
}
void SyntaxCheck::addBracket()
{
  try
  {
    if (ImportedCodeFile)
    {
      lineCTR = 0;
      while (getline(ImportedCodeFile, line)) // loops through every line in the file to check for delimeters
      {
        lineCTR++; // counts the lines so that we are able to tell them the line that their error is on
        for (int m = 0; m < line.length(); m++) // loops through each LINE and checks the characters to find any matching delimeters
        {
          if (line[m] == '{') //these several if statements check for the opening delimeter, and if it is found, that same delimeters is pushed to the stack we created above
          {
            stack->push('{');
          }
          else if (line[m] == '[')
          {
            stack->push('[');
          }
          else if (line[m] == '(')
          {
            stack->push('(');
          }

          else if (line[m] == '}') // these next few if statements respond to if a closing delimeter is found
          {
            if (stack->peek() == '{') // fire we have to check on the stack to make sure the last opened delimeter matched the one we just found
            {
               stack->pop(); // if it is true, then the delimeter gets popped off the stack and we forget about it!
            }
            else
            {
                cout << "Line " << lineCTR << ": Expected ) or ]" << endl; // if we cannot find a matching delimeter, we will print out the line that the delimeter is unmatched at
                                                                           // for some reason if I printed the specific delimeter they were missing it would print the inverse of that so this
                                                                           // way there's no confusing about what is missing
                comp = true; // (see the bottom if statement to really get this) but I created a bool set to false to see if the code was perfect and if there are missing
                             //delimeters, the bool is true
                break;
            }
          }
          else if (line[m] == ']') // the above process is repeated for the other two types of brackets
          {
            if (stack->peek() == '[')
            {
               stack->pop();
            }
            else
            {
                cout << "Line " << lineCTR << ": Expected ) or }" << endl;
                comp = true;
                break;
            }
          }
          else if (line[m] == ')')
          {
            if (stack->peek() == '(')
            {
               stack->pop();
            }
            else
            {
                cout << "Line " << lineCTR << ": Expected ] or }"  << endl;
                comp = true;
                break;
            }
          }
        }
      }
    }
    else
    {
      cout << "Your file does not exist! " << endl;
    }
  }
  // read about catching exceptions at https://stackoverflow.com/questions/6755991/catching-stdexception-by-reference
  catch (exception& e)
  {
    cout << "Line " << lineCTR << ": Extra Bracket "<< endl; // exception handling if ther are too many delimeters in the user's code
  }
  // read more about fixing is a stack is empty or full at: https://stackoverflow.com/questions/20334158/fixing-the-size-isempty-isfull-and-exceptions-of-my-stack-in-java
  // (in addition to your lecture in class)
  if (comp == false) // Corey was helping me with this I don't know any other way to check if there are no unmathced delimeters other than a bool
                     // anywhere that we are missing a delimeter, I make the bool true so it wouldnt enter this area
  {
    if (stack->isEmpty()) // obviously if there's nothing on the stack that means every delimeter had a match and was popped off the stack !!
    {
       cout <<"Your code is fine! Nice syntax checking! (-:" << endl;
    }
    else
    {
      cout << "You have reached the end of the file. You are missing a bracket." << endl;
    }
  }
}
