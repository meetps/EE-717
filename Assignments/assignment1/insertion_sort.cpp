#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<iomanip>
#include <time.h>

using namespace std;
 
timespec diff(timespec start, timespec end);
  
timespec diff(timespec start, timespec end)
{
	timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}

// Read data from inputfile, perform Insertion Sort and wirte back result & runtime(milliseconds) into outputfile
void insertionSort(string inputfile, string outputfile){
	
	// Read Data from inputfile
	ifstream infile(inputfile.c_str());
	
	int N;
	infile>>N; // N = size of Array
	
	int *inputArray;
	inputArray = new int[N];
	for(int i=0; i<N; i++){
		infile>>inputArray[i];
	}
	
	int key =0;
	int j =0;

	timespec time1, time2;
	// Record time before algorithm execution
	// clock_t start,end;
	// start = clock();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time1);
	
	for(int i =1; i < N; i++)
		{
			key = inputArray[i];
			j = i-1;
			while( j>=0 && inputArray[j] > key)
				{
					inputArray[j+1] = inputArray[j];
					j = j-1; 
				}
			inputArray[j+1] = key;
		}
	

	// Insertion Sort Algorithm
	/*
	
		INSERT YOUR ALGORITHM CODE HERE
		* Input Array = inputArray
		* Run Insertion Sort Algorithm on 'inputArray' and store the result in the same array
	
	*/
	
	// Record time after algorithm execution, and calculate time elapsed
	// end = clock();
	// float runtime = (end - start)/(CLOCKS_PER_SEC);
	// double runtime = (end - start)/(double)(CLOCKS_PER_SEC/1000); //Runt time of algorithm in "Milliseconds"
	
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &time2);
	

	// Write runtime & Result(Sorted Array) into outputfile
	ofstream outfile(outputfile.c_str());
	ofstream averaging("Average_Data_set.txt",ios::app);
	averaging << N <<","<<diff(time1,time2).tv_nsec << endl; 
	outfile<< diff(time1,time2).tv_nsec <<endl;
	// outfile<< std::setprecision(9) <<runtime<< " "<<start<< " " << end<<endl;
	for(int i=0; i<N; i++){
		outfile<<inputArray[i]<<endl;
	}

	delete(inputArray);
}


int main (void)
{
	insertionSort("worstoutput10000.txt","output10000.txt");
	return 0;
}



