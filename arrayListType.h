//***********************************************************************************
// Author: D.S. Malik
// Modified by: Zachary Spicer
// Modified date: 5/3/2018
// Modifications: added and implemented the functions InsertionSort, ShellSort,intervalInsertionSort
// and fillArray.
//
// Class description: This class defines and specifies the member functions 
// that implement the basic properties for working with array-based lists.
//***********************************************************************************

#ifndef H_arrayListType
#define H_arrayListType

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <time.h>

using namespace std;

template <class elemType>
class arrayListType
{

// ---------- CLASS DEFINITION ----------

    public:
        const arrayListType<elemType>& operator= (const arrayListType<elemType> &);
        // Overloads the assignment operator
        bool isEmpty();
        // Function to determine whether the list is empty
        // Postcondition: Returns true if the list is empty; 
        //                otherwise, returns false.
        bool isFull();
        // Function to determine whether the list is full.
        // Postcondition: Returns true if the list is full; 
        //                otherwise, returns false.
        int listSize();
        // Function to determine the number of elements in the list
        // Postcondition: Returns the value of length.
        int maxListSize();
        // Function to determine the size of the list.
        // Postcondition: Returns the value of maxSize.
        void print() const;
        // Function to output the elements of the list
        // Postcondition: Elements of the list are output on the 
        //                standard output device.
        bool isItemAtEqual(int location, const elemType &item);
        // Function to determine whether the item is the same 
        // as the item in the list at the position specified by
        // Postcondition: Returns true if the list[location] 
        //                is the same as the item; otherwise, 
        //                returns false.
        void insertAt(int location, const elemType &insertItem);
        // Function to insert an item in the list at the 
        // position specified by location. The item to be inserted 
        // is passed as a parameter to the function.
        // Postcondition: Starting at location, the elements of the
        //                list are shifted down, list[location] = insertItem;,
        //                and length++;. If the list is full or location is
        //                out of range, an appropriate message is displayed.
        void insertEnd(const elemType &insertItem);
        // Function to insert an item at the end of the list. 
        // The parameter insertItem specifies the item to be inserted.
        //Postcondition: list[length] = insertItem; and length++;
        //               If the list is full, an appropriate message is 
        //               displayed.
        void removeAt(int location);
        // Function to remove the item from the list at the 
        // position specified by location 
        // Postcondition: The list element at list[location] is 
        //                removed and length is decremented by 1. If location is 
        //                out of range,an appropriate message is displayed.
        void retrieveAt(int location, elemType &retItem);
        // Function to retrieve the element from the list at the  
        // position specified by location. 
        // Postcondition: retItem = list[location] 
        //                If location is out of range, an appropriate message 
        //                is displayed.
        void replaceAt(int location, const elemType &repItem);
        // Function to replace the elements in the list at the 
        // position specified by location. The item to be replaced 
        // is specified by the parameter repItem.
        // Postcondition: list[location] = repItem 
        //                If location is out of range, an appropriate message 
        //                is displayed.
        void clearList();
        // Function to remove all the elements from the list. 
        // After this operation, the size of the list is zero.
        // Postcondition: length = 0;
        int seqSearch(const elemType& item);
        // Function to search the list for a given item. 
        // Postcondition: If the item is found, returns the 
        //                location in the array where the item is found; otherwise, 
        //                returns -1.
        void insert(const elemType &insertItem);
        // Function to insert the item specified by the parameter 
        // insertItem at the end of the list. However, first the
        // list is searched to see whether the item to be inserted 
        // is already in the list. 
        // Postcondition: list[length] = insertItem and length++
        //                If the item is already in the list or the list
        //                is full, an appropriate message is displayed.
        void remove(const elemType &removeItem);
        // Function to remove an item from the list. The parameter 
        // removeItem specifies the item to be removed.
        // Postcondition: If removeItem is found in the list,
        //                it is removed from the list and length is 
        //                decremented by one.
        arrayListType(int size = 100);
        // Constructor
        // Creates an array of the size specified by the 
        // parameter size. The default array size is 100.
        // Postcondition: The list points to the array, length = 0, 
        //                and maxSize = size
        arrayListType(const arrayListType<elemType> &otherList); 
        // Copy constructor
        ~arrayListType();
        // Destructor
        // Deallocates the memory occupied by the array.
        

        void insertionSort();
        // function that compares index's of a list one after the other and swaps them if certain
        // conditions are met. in this instance int j is the value behind int i, and the function compares them
        // and swaps them if the j is greater then i and j is greater then or equal to 0
        // includes the comp and swap counters to count the number of comparisons and swaps of the integers
        // Postcondition: The List is is sorted and prints the comparisons
        void shellSort();
        // function to initialize inc based on the size of list. Then a do while loop that passes inc and begin
        // to the intervalInsertionSort function which will sort the list. it divides inc by three and loops again until inc is 0.
        // includes the numComp and numMoves variables to count the number of comparisons and the number of moves
        //Postcondition: The List is sorted and prints the comparisons
        void intervalInsertionSort (int begin, int inc, int &numComp, int &numMoves);
        // Initialize the location variable then for loop until first(equals the first integer in the list + the gap) is greater then
        // the length of the list, adding the gap to the first variable every time. then increment the comparison as we are comparing the
        // first to the length and then add if statement to compare two indexs in the list, first and the one next to first. initialize temp to the index of first in the list
        // and assign temp to first. then a do while loop to run until loc is greater then inc - 1 and the index of loc - inc is greater then temp. the loop will set the index of first to first
        // - inc, remove an instance of inc from loc, then increment the moves and comparison variables. when the loop finishes set the loc index to temp.
        // includes the numComp and numMoves variables to count the number of comparisons and the number of moves
        // Postcondition: The index's of j and j-inc are swapped in the list when the conditions are true;
        void fillArray (arrayListType<int> &myList);
        // function to fill the list with random integers ranging from 0 to 100
        // postcondition: the list is filled with random integers.

     protected:
        elemType *list;        // Array to hold the list elements
        int length;            // Variable to store the length of the list
        int maxSize;           // Variable to store the maximum size of the list
};

// ---------- CLASS IMPLEMENTATION ----------

template <class elemType>
void arrayListType<elemType>::insertionSort()
{
 int i, key, j;
 int swap = 0;
 int comp = 0;

 for (i = 1; i < length; i++)
 {
	 key = list[i];
	 j = i-1;
	 comp ++;
	 while (j >= 0 && list[j] > key)
	 {
		list[j+1] = list[j];
		j=j-1;
		comp++;
		swap++;
	 }
	 list[j+1] = key;
 }
  cout << "Comparisons --------> " << comp << endl;
  cout << "Number of Moves ----> " << swap << endl;
}

template <class elemType>
void arrayListType<elemType>::shellSort()
{
int inc;
int numComp = 0;
int numMoves = 0;
for (inc = 1; inc < (length - 1) / 9; inc = 3 * inc + 1)
{
}
do
{
	for (int begin = 0; begin < inc; begin++)
	{
		intervalInsertionSort(begin, inc, numComp, numMoves);
	}
	inc = inc / 3;
}
while (inc > 0);
cout << "Comparisons --------> " << numComp << endl;
cout << "Number of Moves ----> " << numMoves << endl;
} //end shellSort

template <class elemType>
void arrayListType<elemType>::intervalInsertionSort(int begin, int inc, int &numComp, int &numMoves)
{
	int loc;
	for(int first = begin+inc; first < length; first += inc)
	{
		numComp++;
		if ( list[first] < list[first - 1])
		{
			int temp = list[first];
			loc = first;
			do{
			list[first] = list[first-inc];
			loc -= inc;
			numComp++;
			numMoves++;
			}
			while(loc>inc-1 && list[loc-inc] > temp);
			list[loc] = temp;
		}
	}
}

template <class elemType>
void arrayListType<elemType>::fillArray(arrayListType<int> &myList)
{
	for (int i = 0; i < maxSize; i++)
	{
		int randNum = ((rand() + time(0)) % 100);
		insertEnd(randNum);
	}
}




template <class elemType>
bool arrayListType<elemType>::isEmpty()
{
    return (length == 0);
} // end isEmpty

template <class elemType>
bool arrayListType<elemType>::isFull()
{
    return (length == maxSize);
} // end isFull

template <class elemType>
int arrayListType<elemType>::listSize()
{
    return length;
} // end listSize

template <class elemType>
int arrayListType<elemType>::maxListSize()
{
    return maxSize;
} // end maxListSize

template <class elemType>
void arrayListType<elemType>::print() const
{
    for (int i = 0; i < length; i++)
        cout << list[i] << " ";

    cout << endl;
} // end print

template <class elemType>
bool arrayListType<elemType>::isItemAtEqual
                            (int location, const elemType &item)
{
    return(list[location] == item);
} // end isItemAtEqual

template <class elemType>
void arrayListType<elemType>::insertAt
                  (int location, const elemType &insertItem)
{
    if (location < 0 || location >= maxSize)
        cerr << "The position of the item to be inserted "
             << "is out of range" << endl;
    else
        if (length >= maxSize)            //list is full
            cerr << "Cannot insert in a full list" << endl;
        else
        {
            for (int i = length; i > location; i--)
                 list[i] = list[i - 1];   //move the elements down

            list[location] = insertItem;  //insert the item at the 
                                          //specified position

            length++;     //increment the length
    }
} //end insertAt

template <class elemType>
void arrayListType<elemType>::insertEnd(const elemType &insertItem)
{

    if (length >= maxSize)  //the list is full
        cerr << "Cannot insert in a full list" << endl;
    else
    {
         list[length] = insertItem;   //insert the item at the end
         length++;                    //increment the length
    }
} //end insertEnd

template <class elemType>
void arrayListType<elemType>::removeAt(int location)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be removed "
             << "is out of range" << endl;
    else
    {
        for (int i = location; i < length - 1; i++)
            list[i] = list[i+1];

        length--;
    }
} //end removeAt

template <class elemType>
void arrayListType<elemType>::retrieveAt
                             (int location, elemType &retItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be retrieved is "
             << "out of range." << endl;
    else
        retItem = list[location];
} //end retrieveAt


template <class elemType>
void arrayListType<elemType>::replaceAt
                          (int location, const elemType &repItem)
{
    if (location < 0 || location >= length)
        cerr << "The location of the item to be replaced is "
             << "out of range." << endl;
    else
        list[location] = repItem;

} //end replaceAt

template <class elemType>
void arrayListType<elemType>::clearList()
{
    length = 0;
} //end clearList

template <class elemType>
int arrayListType<elemType>::seqSearch(const elemType &item)
{
    int loc;
    bool found = false;

    for (loc = 0; loc < length; loc++)
        if (list[loc] == item)
        {
            found = true;
            break;
        }

    if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
void arrayListType<elemType>::insert(const elemType &insertItem)
{
    int loc;

    if (length == 0)   //list is empty
        list[length++] = insertItem;    //insert the item and 
                                        //increment the length
    else if (length == maxSize)
        cerr << "Cannot insert in a full list." << endl;
    else
    {
        loc = seqSearch(insertItem);

        if (loc == -1)                  //the item to be inserted 
                                        //does not exist in the list
            list[length++] = insertItem;
        else
            cerr << "the item to be inserted is already in "
                 << "the list. No duplicates are allowed." << endl;
    }
} //end insert

template<class elemType>
void arrayListType<elemType>::remove(const elemType &removeItem)
{
    int loc;

    if (length == 0)
        cerr << "Cannot delete from an empty list." << endl;
    else
    {
        loc = seqSearch(removeItem);

        if (loc != -1)
            removeAt(loc);
        else
            cout << "The item to be deleted is not in the list."
                 << endl;
    }
} //end remove

template <class elemType>
arrayListType<elemType>::arrayListType(int size)
{
    if (size < 0)
    {
        cerr << "The array size must be positive. Creating "
             << "an array of size 100. " << endl;

        maxSize = 100;
    }
    else
        maxSize = size;

    length = 0;

    list = new elemType[maxSize];
    assert(list != NULL);
} // end constructor with parameters

template <class elemType>
arrayListType<elemType>::~arrayListType()
{
    delete [] list;
} // end destructor

template <class elemType>
arrayListType<elemType>::arrayListType
                   (const arrayListType<elemType> &otherList)
{
    maxSize = otherList.maxSize;
    length = otherList.length;
    list = new elemType[maxSize]; //create the array
    assert(list != NULL);         //terminate if unable to allocate
                                  //memory space

    for (int j = 0; j < length; j++)  //copy otherList
        list [j] = otherList.list[j];
} //end copy constructor

template <class elemType>
const arrayListType<elemType>& arrayListType<elemType>::operator=
                      (const arrayListType<elemType> &otherList)
{
    if (this != &otherList)      //avoid self-assignment
    {
        delete [] list; 
        maxSize = otherList.maxSize; 
        length = otherList.length; 
 
        list = new elemType[maxSize];  //create the array
        assert(list != NULL);    //if unable to allocate memory 
                                 //space, terminate the program 
        for (int i = 0; i < length; i++)
            list[i] = otherList.list[i]; 
    }

    return *this; 
} // end operator overload

#endif
