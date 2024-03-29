/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DBLIB_H
#define DSA191_A1_DBLIB_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>
#include <cstdlib>
#include <vector>
#include "dsaLib.h"

 /* TODO: Please design your data structure carefully so that you can work with the given dataset
  *       in this assignment. The below structures are just some suggestions.
  */
struct TCity {
	// The structure to store city information
	L1List<int> id;
	L1List<string> name;
	L1List<string> coords;
	L1List<int> startYear;
	L1List<string> urlname;
	L1List<string> country;
	L1List<string> countryState;
};

struct TLine {
	// The structure to store line information
	L1List<int> id;
	L1List<int> cityId;
	L1List<string> name;
	L1List<string> urlname;
	L1List<string> color;
	L1List<int> systemId;
	L1List<int> transportModeId;
};

struct TTrack {
	// The structure to store track information
	L1List<int> id;
	L1List<string> geometry;
	L1List<int> buildStart;
	L1List<int> opening;
	L1List<int> closure;
	L1List<int> length;
	L1List<int> cityId;
};

struct TTrackLine {
	L1List<int> id;
	L1List<int> sectionId;
	L1List<int> lineId;
	L1List<string> createAt;
	L1List<string> updateAt;
	L1List<int> cityId;
};

struct TSystem {
	L1List<int> id;
	L1List<int> cityId;
	L1List<string> name;
};

struct TStation {
	L1List<int> id;
	L1List<string> name;
	L1List<string> geometry;
	L1List<int> buildStart;
	L1List<int> opening;
	L1List<int> closure;
	L1List<int> cityId;
};

struct TStationLine {
	L1List<int> id;
	L1List<int> stationId;
	L1List<int> lineId;
	L1List<int> cityId;
	L1List<string> createdAt;
	L1List<string> updatedAt;
};

class TDataset {
	// This class can be a container that help you manage your tables

	TCity CityList;
	TLine LineList;
	TTrack TrackList;
	TTrackLine TrackLineList;
	TSystem SystemList;
	TStation StationList;
	TStationLine StationLineList;
public:
	TCity getCityList();
	void loadDataCity();
	void loadDataLine();
	void loadDataStationLine();
	void loadDataStation();
	void loadDataSystem();
	void loadDataTrackLine();
	void loadDataTrack();
	void printCityList();
	int totalLine();
	int numLineByCity(string cityName);
	int findCityIdByName(string cityName);
	int findStationIdByStationName(string stationName);
	int* findListStationIdByCityName(string cityName, int& size);
	int* findListLineIdByCityName(string cityName, int& size);
	int* findListStationIdByLineId(int lineId, int& size);
	string findGeometryOfLineByLineId(int id);  
	string findGeometryOfTrackByTrackId(int id);
	int findPositionOfStationInTrack(int lineId, int trackId);
	int addNewStation(string description);
	bool separateDescription(string& name, string& geometry, int& buildstart, int& opening, int& closure, string description);
	bool isStationInTrack(int stationid, vector<int>& idx, int& size);
	bool isStationInStationLine(int stationId, vector<int>& idx, int& size);
	void deleteStationInTrack(int stationId, int& is);
	void deleteStationInStationLine(int stationId, int& is);
	void deleteStation(int stationId, int& is);
	int isDelete(int stationId);
	int updateInfoOfStation(int stationId, string description);
	int separeteForLastReq(int& stationId, int& lineId, int& pos, string input);
	int insertStation(int*& arrayList, int& stationId, int& lineId, int& pos, string input);
};

void LoadData(void*& pData);

void ReleaseData(void*&);

#endif //DSA191_A1_DBLIB_H
