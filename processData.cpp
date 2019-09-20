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
	//cout << pD->totalLine();//CL
	//cout << pD->numLineByCity("Santiago");//CL <cityName>
	//cout << pD->findCityIdByName("Santiago");//FC <cityName>
	//cout << pD->findStationIdByStationName("Keisei Tsudanuma");//FS <stationName>
	//pD->findListStationIdByCityName("Tokyo");//LSC <cityName>
	//pD->findListLineIdByCityName("Tokyo");//LLC <cityName>
	//pD->findListStationIdByLineId(571);//LSL <lineId>
	//pD->printCityList();
	string request = pRequest;
	if (request == "CL") {
		N = 1;
		int result = pD->totalLine();
		int* output = new int[N];
		output[0] = result;
		pOutput = output;
	}
	else if (request != "CL" && request.substr(0, 2) == "CL") {
		N = 1;
		string cityName = request.substr(3, request.length() - 3);
		int result = pD->numLineByCity(cityName);
		int* output = new int[N];
		output[0] = result;
		pOutput = output;
	}
	else if (request != "LSC" && request.substr(0, 3) == "LSC") {
		string cityName = request.substr(4, request.length() - 4);
		int* result = pD->findListStationIdByCityName(cityName, N);
		int* output = new int[N];
		output = result;
		pOutput = output;
	}
	else if (request != "LLC" && request.substr(0, 3) == "LLC") {
		string cityName = request.substr(4, request.length() - 4);
		int* result = pD->findListLineIdByCityName(cityName, N);
		int* output = new int[N];
		output = result;
		pOutput = output;
	}
	else if (request != "LSL" && request.substr(0, 3) == "LSL") {
		bool isNum = false;
		string lineId = request.substr(4, request.length() - 4);
		for (int i = 0; i < lineId.length(); i++) {
			if (lineId[i] < 48 || lineId[i] > 57) {
				isNum = false;
				break;
			}
			isNum = true;
		}
		if (isNum == true) {
			int lineIdNum = stoi(lineId);
			int* result = pD->findListStationIdByLineId(lineIdNum, N);
			int* output = new int[N];
			output = result;
			pOutput = output;
		}
	}
}

