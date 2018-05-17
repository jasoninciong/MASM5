/*****************************************************************
* AUTHOR     : Jason Inciong & Jesse Mazzella
* ASSIGNMENT : MASM5
* CLASS      : CS3B
* SECTION    : T/Th 3:30pm
* DUE DATE   : 5/17/18
******************************************************************
******************************************************************
* MASM5
* ________________________________________________________________
* This program compares the time between a C++ implemented bubble
* sort versus an assembly bubble sort.
******************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;

extern "C" {
	void bubbleSortASM(vector<long>&, int size);
}

void swap(int *xp, int *yp);
void bubbleSortCPP(vector<long>& arr, int n);
void outputToFile(vector<long>& arr, int size, string filename);

int main() {

	//FILE VARIABLES
	ifstream ifile;
	ofstream oFile;
	string   outFileCPP = "SortedDataCPP.dat";  //stores data from CPP bubblesort
	string   outFileASM = "SortedDataASM.dat";  //stores data from ASM bubblesort

	//VECTOR VARIABLES
	vector<long> randomNums;
	vector<long> randomNumsASM;
	float pushData;

	//TIME VARIABLES
	int     mins = 0;        //minutes
	int     secs = 0;        //seconds
	double  tempSecs = 0;    //used to calculate minutes and seconds
	clock_t startClock;
	clock_t endClock;


	cout << "              MASM5 SORTING WARS\n";

	//read data into vector
	ifile.open("masm5.dat", ios::binary);
	if(!ifile.is_open()){
		cout << "error: randoms numbers were not stored\n";
		return 0;
	}
	while(ifile >> pushData){
		randomNums.push_back(pushData);
	}

	/******************
	 * C++ BUBBLESORT *
	 ******************/
	//Sort the data
	cout << "Sorting via C++.......................\n";
	startClock = clock();
	bubbleSortCPP(randomNums, randomNums.size());
	endClock = clock();

	//get time data
	tempSecs = double(endClock-startClock)/CLOCKS_PER_SEC;
	mins = ((int)tempSecs%3600)/60;
	secs = ((int)tempSecs%60);
	cout << "Time: " << mins << ':'<< secs << endl << endl;
	ifile.close();

	//store data into "SortedDataCPP.dat"
	outputToFile(randomNums, randomNums.size(), outFileCPP);


	/***********************
	 * ASSEMBLY BUBBLESORT *
	 ***********************/

	//read data into vector
	ifile.open("masm5.dat", ios::binary);
	if(!ifile.is_open()){
		cout << "error: randoms numbers were not stored\n";
		return 0;
	}
	while(ifile >> pushData){
		randomNumsASM.push_back(pushData);
	}

	cout << "Sorting via Assembly..................\n";

	startClock = clock();
	bubbleSortASM((long *)&randomNums[0], randomNums.size());
	endClock = clock();

	//get time data
	tempSecs = double(endClock-startClock)/CLOCKS_PER_SEC;
	mins = ((int)tempSecs%3600)/60;
	secs = ((int)tempSecs%60);
	cout << "Time: " << mins << ':'<< secs << endl << endl;
	ifile.close();

	//store data into "SortedDataCPP.dat"
	outputToFile(randomNumsASM, randomNumsASM.size(), outFileASM);

	return 0;
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSortCPP(vector<long>& arr, int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(arr[j], arr[j+1]);
           swapped = true;
        }
     }

     // IF no two elements were swapped by inner loop, then break
     if (swapped == false)
        break;
   }
}

/* Function to print an array */
void outputToFile(vector<long>& arr, int size, string filename)
{
	ofstream oFile;

	oFile.open(filename);

    int i;
    for (i=0; i < size; i++)
    	oFile << arr[i] << endl;

    oFile.close();
}
