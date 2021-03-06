// Crystal J.M. Crawford
// CISC192
// Programming Challenge 7: Binary String Search

//Things I want to improve
// y/n loop to see if ppl want to see each list (sorted & unsorted)
// y/n loop to see if they want to do another serach
// value control: error message for non string values

#include <iostream>
#include <string>
using namespace std;

void selectionSort(string [], int);
void showArray(string [], int);
int binarySearch(string [], int, string);

int main()
{
const int NUM_NAMES = 20;
string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
"Griffin, Jim", "Stamey, Marty", "Rose, Geri",
"Taylor, Terri", "Johnson, Jill",
"Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
"James, Jean", "Weaver, Jim", "Pore, Bob",
"Rutherford, Greg", "Javens, Renee",
"Harrison, Rose", "Setzer, Cathy",
"Pike, Gordon", "Holland, Beth" };
int results;
string fullName;

cout << endl << "This program takes a list of names, sorts them from A to Z, ";
cout << endl << "and allows you to serch for a name within the sorted list.";
cout << endl;

cout << endl << "Let's take a look at the unsorted values:" << endl;
showArray(names, NUM_NAMES);

cout << endl << "Now let's sort the list...";
selectionSort(names, NUM_NAMES);

cout << endl << endl << "1, 2, 3... voilà" << endl;

cout << endl << "The sorted values are:" << endl;
showArray(names, NUM_NAMES);

cout << "Now we can conduct a proper binary search.";
cout << endl << "Please enter a name in the following format, ";
cout << endl << "Last, First: ";
getline(cin, fullName);

cout << endl << "Awesome! Let's see if it's in the list.." << endl << endl;

results = binarySearch(names, NUM_NAMES, fullName);

if (results == -1)
  cout << "Sorry, but that name could not be located in the list.";
else
{
  cout << "Yes! That name is in the list. It can be found " << results;
  cout << " spots down on the list.";
}

cout << endl;
cout << "Press [Enter]  key to end ... ";
cin.ignore(256, '\n');
cin.get();
return 0;
}

void selectionSort(string array[], int size)
{
  int startScan, minIndex;
  string minValue;

  for (startScan = 0; startScan < (size - 1); startScan++)
  {
    minIndex = startScan;
    minValue = array[startScan];

    for (int index = startScan + 1; index < size; index++)
    {
      if (array[index] < minValue)
      {
        minValue = array[index];
        minIndex = index;
      }
    }
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
  }
}

void showArray(string array[], int size)
{
  for (int count = 0; count < size; count++)
    cout << array[count] << endl;
  cout << endl;
}

int binarySearch(string array[], int size, string value)
{
  int first = 0,
      last = size - 1,
      middle,
      position = -1;
  bool found = false;

  while (!found && first <= last)
  {
      middle = (first + last) / 2;
      if (array[middle] == value)
      {
          found = true;
          position = middle;
      }
      else if (array[middle] > value)
          last = middle - 1;
      else
          first = middle + 1;
  }
  return position;
}
