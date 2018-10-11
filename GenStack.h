#include <iostream>
// the template clqss for the GenStack we made !!!
using namespace std;
// Jacob Anabi, stack overflow, my CS major friend at Carnegie Mellon and https://isocpp.org/wiki/faq/templates helped explain template classes.
template <class Tdough> // this must be placed before every method
class GenStack
{
	public:
		GenStack();
		GenStack(int maxSize);
		~GenStack();

		void push(Tdough d);
		Tdough pop(); // every char in this file gets changed to the name of the template class I made (Tdough)
		Tdough peek();

		bool isFull();
		bool isEmpty();

		int size;
		int top;

		Tdough *myArray;
		Tdough *newArr;
};


template <class Tdough>
GenStack<Tdough>::GenStack()
{
	// variables get initialized to default values
	myArray = new Tdough[10]; // i belive this is the default size for stacks
	size = 10;
	top = -1; // use this to see if stack is full or empty
}

template <class Tdough>
GenStack<Tdough>::GenStack(int maxSize)
{
	myArray = new Tdough[maxSize]; //creates the specific stack to our program
	size = maxSize;
	top = -1;
}

template <class Tdough>
GenStack<Tdough>::~GenStack()
{
	delete myArray; // destroys the memory that this array takes up
	//cout << "stack destroyed" << endl;
}

template <class Tdough>
void GenStack<Tdough>::push(Tdough d) // the construction of the push() method
{
	if (!this->isFull()) // if the array is NOT full
	{
		myArray[++top] = d; //add the element they want to push to the top of the array (which then gets increased)
	}
	else // if the array is full, we have to make a bigger one and point all the current info towards that new, bigger array
	{
		newArr = new Tdough[size+5];  // i incremented the size by 5
		for(int i =0; i<size;i++) // loops through the first array and moves all of its elements to the second arrauy
		{
			newArr[i] = myArray[i];
		}
		newArr=myArray;
		size+=5; // incrememts the size in the global scope of this class to 5 (bc we have a new array to work with)
	}
}

template <class Tdough>
Tdough GenStack<Tdough>::pop() //the construction of the pop() method
{
	if (!this->isEmpty())
	{
		return myArray[top--]; // if the array is NOT empty, take off the last element added and return it
	}
	else
	{
		throw std::invalid_argument("This stack is empty bud!"); // throws this error that the stack is empty so there is nothing left to pop off
	}
}

template <class Tdough>
Tdough GenStack<Tdough>::peek() //the construction of the peek() method
{
	if (!this->isEmpty())
	{
		return myArray[top]; // if the array is NOT empty, return the last element (without taking it off the array)
	}
	else
	{
			throw std::invalid_argument("This stack is empty bud!"); // throws this error that the stack is empty so there is nothing too peek at
	}
}

template <class Tdough>
bool GenStack<Tdough>::isFull() //if the array is full (the top/recent value is equal to the size-1), return a bool
{
	return (top == size-1);
}

template <class Tdough>
bool GenStack<Tdough>::isEmpty() //if the array is empty (the top value is left unchanged)
{
	return (top == -1);
}
