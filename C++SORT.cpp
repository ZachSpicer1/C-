//============================================================================
// Name        :C++SORT.cpp
// Author      : Zachary Spicer
// Data Structures Final Exam
// Description :Program to calculate statistics comparing the Sort algorithm to the Shell Sort
// algorithm. Two lists of random integers (0-100) are generated. List One is passed is passed to the
// insertion sort function and List Two is passed to the shell sort function. The number of
// comparisons and the number of required moves to sort each of the lists are calculated and
// displayed to the user. This program requires no user input.
//============================================================================

#include <iostream>
#include "arrayListType.h"
using namespace std;

void dspLists(arrayListType<int> , arrayListType<int>);
// this function receives the lists from the main and then
// calls the print function from the header file and then listSize function
// to print and give the length of the lists
void dspStats(arrayListType<int> , arrayListType<int>);
// this function calls the insertionSort and shellSort functions to sort the lists
// and print the lists after they are sorted.

int main() {
	//print statements to print the headers
	cout << "                                                  ARRAY SORTING STATISTICS APPLICATION"<< endl;
	cout << "                                                           Data Structures"<< endl;
	cout << "                                                             Final Exam" <<endl;

	//Instantiate the lists with 50 index's
	arrayListType<int> list1 (50);
	arrayListType<int> list2 (50);

	//call the fill array function to fill the lists with random integers
	list1.fillArray(list1);
	list2.fillArray(list2);

	// call the display lists functions to print the lists and there lengths
	dspLists(list1, list2);
	cout << endl;
	// call the displayStats function to sort the list, print the number of comparisons and
	// swaps between the two sorting method, then print the lists.
	dspStats(list1, list2);

	//end of program print statement
	cout<<"\nEnd of Program."<<endl;
	cout<<"Final Exam Complete.";

	return 0;
}

void dspLists(arrayListType<int> list1, arrayListType<int> list2)
{
	cout<<"RANDOM INTERGERS FOR INSERTION SORT";
	cout << "\nList 1 Unsorted ---> ";
	list1.print();
	cout << "list size ---------> " << list1.listSize();;

	cout<< "\n\nRANDOM INTERGERS FOR SHELL SORT";
	cout << endl;
	cout << "List 2 Unsorted ---> ";
	list2.print();
	cout << "List 2 size -------> " << list2.listSize(); ;

	cout<<"\n\n***************************************"<<endl;
	cout<<"*    COMPARISON SUMMARY STATISTICS    *"<<endl;
	cout<<"***************************************"<<endl;
}

void dspStats(arrayListType<int> list1,arrayListType<int> list2)
{
	cout << "INSERTION SORT" << endl;
	list1.insertionSort();
	cout << "List 1 Sorted ------> ";
	list1.print();

	cout << "\n\nSHELL SORT" << endl;
	list2.shellSort();
	cout << "List 2 Sorted ------> ";
	list2.print();
}
