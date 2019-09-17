/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : processData.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : Implementation of main features in the assignment
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "processData.h"

 /* TODO: You can implement methods, functions that support your data structures here.
  * */
using namespace std;

void Initialization() {
	// If you use global variables, please initialize them explicitly in this function.
	/*TCity CityList;
	TLine LineList;
	TStationLine StationLineList;
	TStation StationList;
	TSystem SystemList;
	TTrackLine TrackLineList;
	TTrack TrackList;*/
}

void Finalization() {
	// Release your data before exiting
}

void ProcessRequest(const char* pRequest, void* pData, void*& pOutput, int& N) {
	// TODO: Implement this function for processing a request
	// NOTE: You can add other functions to support this main process.
	//       pData is a pointer to a data structure that manages the dataset
	//       pOutput is a pointer reference. It is set to nullptr and student must allocate data for it in order to save the required output
	//       N is the size of output, must be a non-negative number
	
	
	TDataset* pD = (TDataset*)pData;
	/*switch (*pRequest) {
	case 'CL':
	{
		pD->
	}
	}*/
	cout << pD->countElements();
	//pD->printCityList();

}

