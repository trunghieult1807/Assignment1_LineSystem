/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dbLib.cpp
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#include "dbLib.h"

 /* TODO: You can implement methods, functions that support your data structures here.
  * */

int countComma(string a){
	int count = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ',') {
			count++;
		}
	}
	return count;
}

bool isNum(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] < 48 || a[i] > 57) {
			return false;
		}
	}
	return true;
}

int findComma(int n, string a) {
	int num = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ',') {
			num++;
		}
		if (num == n) {
			return i;
			break;
		}
	}
	return -1;
}

int findSpace(int n, string a) {
	int num = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ') {
			num++;
		}
		if (num == n) {
			return i;
			break;
		}
	}
	return -1;
}

int countSpace(string a) {
	int num = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ') {
			num++;
		}
	}
	return num;
}

bool isExist(string a) {
	for (int i = 0; i < a.length(); i++) {
		if (a[i] == '"') {
			return true;
			break;
		}
	}
	return false;
}


// Please add more or modify as needed
void TDataset::loadDataCity() {
	fstream inFile;
	string temp;
	int tempNum;
	string preTemp = "";
	string line;
	string empty = "";
	int emptyNum = 0;
	inFile.open("cities.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file cities.csv." << endl;
		exit(1);
	}
	getline(inFile, line);
	while (getline(inFile, line)) {
		istringstream tempLine(line);
		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			CityList.id.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			CityList.id.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			CityList.name.push_back(empty);
		}
		else {
			CityList.name.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			CityList.coords.push_back(empty);
		}
		else {
			CityList.coords.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			CityList.startYear.push_back(emptyNum);
		}
		else {
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
				CityList.startYear.push_back(tempNum);
			}
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			CityList.urlname.push_back(empty);
		}
		else {
			CityList.urlname.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			CityList.country.push_back(empty);
		}
		else {
			CityList.country.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, '.');
		if (preTemp == temp) {
			CityList.countryState.push_back(empty);
		}
		else {
			CityList.countryState.push_back(temp);
		}
		preTemp = temp;
	}
	inFile.close();
}

void TDataset::loadDataLine() {
	fstream inFile;
	string temp;
	int tempNum;
	string line;
	string empty = "";
	int emptyNum = 0;
	string preTemp;
	inFile.open("lines.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file lines.csv." << endl;
		exit(1);
	}
	getline(inFile, temp);
	while (getline(inFile, line)) {
		if (isExist(line) == true) {
			istringstream tempLine(line);
			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.id.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				LineList.id.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.cityId.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				LineList.cityId.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, '"');

			getline(tempLine, temp, '"');
			if (preTemp == temp) {
				LineList.name.push_back(empty);
			}
			else {
				LineList.name.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.urlname.push_back(empty);
			}
			else {
				LineList.urlname.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.color.push_back(empty);
			}
			else {
				LineList.color.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.systemId.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				LineList.systemId.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, '.');
			if (preTemp == temp) {
				LineList.transportModeId.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
					LineList.transportModeId.push_back(tempNum);
				}
			}
			preTemp = temp;
		}

		else {
			istringstream tempLine(line);
			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.id.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				LineList.id.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.cityId.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				LineList.cityId.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.name.push_back(empty);
			}
			else {
				LineList.name.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.urlname.push_back(empty);
			}
			else {
				LineList.urlname.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.color.push_back(empty);
			}
			else {
				LineList.color.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				LineList.systemId.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				LineList.systemId.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, '.');
			if (preTemp == temp) {
				LineList.transportModeId.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
					LineList.transportModeId.push_back(tempNum);
				}
			}
			preTemp = temp;
		}
	}
	inFile.close();
}

void TDataset::loadDataStationLine() {
	fstream inFile;
	string temp;
	string line;
	string empty = "";
	string preTemp;
	int emptyNum = 0;
	int tempNum;
	inFile.open("station_lines.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file station_lines.csv." << endl;
		exit(1);
	}
	getline(inFile, temp);
	while (getline(inFile, line)) {
		istringstream tempLine(line);
		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			StationLineList.id.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			StationLineList.id.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			StationLineList.stationId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			StationLineList.stationId.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			StationLineList.lineId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			StationLineList.lineId.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			StationLineList.cityId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			StationLineList.cityId.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			StationLineList.createdAt.push_back(empty);
		}
		else {
			StationLineList.createdAt.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, '.');
		if (preTemp == temp) {
			StationLineList.updatedAt.push_back(empty);
		}
		else {
			StationLineList.updatedAt.push_back(temp);
		}
		preTemp = temp;

	}
	inFile.close();
}

void TDataset::loadDataStation() {
	fstream inFile;
	string temp;
	string line;
	string empty = "";
	string preTemp = "";
	int emptyNum = 0;
	int tempNum;
	inFile.open("stations.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file stations.csv." << endl;
		exit(1);
	}
	getline(inFile, temp);
	while (getline(inFile, line)) {
		istringstream tempLine(line);
		if (isExist(line) == true) {
			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.id.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				StationList.id.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, '"');

			getline(tempLine, temp, '"');
			if (preTemp == temp) {
				StationList.name.push_back(empty);
			}
			else {
				StationList.name.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.geometry.push_back(empty);
			}
			else {
				StationList.geometry.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.buildStart.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
				}
				StationList.buildStart.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.opening.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
				}
				StationList.opening.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.closure.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
				}
				StationList.closure.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp);
			if (preTemp == temp) {
				StationList.cityId.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				StationList.cityId.push_back(tempNum);
			}
			preTemp = temp;
		}
		else {
			istringstream tempLine(line);
			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.id.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				StationList.id.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.name.push_back(empty);
			}
			else {
				StationList.name.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.geometry.push_back(empty);
			}
			else {
				StationList.geometry.push_back(temp);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.buildStart.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
				}
				StationList.buildStart.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.opening.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
				}
				StationList.opening.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp, ',');
			if (preTemp == temp) {
				StationList.closure.push_back(emptyNum);
			}
			else {
				if (temp == "") {
					tempNum = 0;
				}
				else {
					tempNum = stoi(temp);
				}
				StationList.closure.push_back(tempNum);
			}
			preTemp = temp;

			getline(tempLine, temp);
			if (preTemp == temp) {
				StationList.cityId.push_back(emptyNum);
			}
			else {
				tempNum = stoi(temp);
				StationList.cityId.push_back(tempNum);
			}
			preTemp = temp;
		}
	}
	inFile.close();
}

void TDataset::loadDataSystem() {
	fstream inFile;
	string temp;
	int tempNum;
	string line;
	string empty = "";
	int emptyNum = 0;
	string preTemp;
	inFile.open("systems.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file systems.csv." << endl;
		exit(1);
	}
	getline(inFile, temp);
	while (getline(inFile, line)) {
		istringstream tempLine(line);
		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			SystemList.id.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			SystemList.id.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			SystemList.cityId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			SystemList.cityId.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, '.');
		if (preTemp == temp) {
			SystemList.name.push_back(empty);
		}
		else {
			SystemList.name.push_back(temp);
		}
		preTemp = temp;
	}
	inFile.close();
}

void TDataset::loadDataTrackLine() {
	fstream inFile;
	string temp;
	int tempNum;
	string line;
	string empty = "";
	int emptyNum = 0;
	string preTemp;
	inFile.open("track_lines.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file track_lines.csv." << endl;
		exit(1);
	}
	getline(inFile, temp);
	while (getline(inFile, line)) {
		istringstream tempLine(line);
		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackLineList.id.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackLineList.id.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackLineList.sectionId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackLineList.sectionId.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackLineList.lineId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackLineList.lineId.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackLineList.createAt.push_back(empty);
		}
		else {
			TrackLineList.updateAt.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, '.');
		if (preTemp == temp) {
			TrackLineList.cityId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackLineList.cityId.push_back(tempNum);
		}
		preTemp = temp;
	}

	inFile.close();
}

void TDataset::loadDataTrack() {
	fstream inFile;
	string temp;
	int tempNum;
	string line;
	string empty = "";
	int emptyNum = 0;
	string preTemp;
	inFile.open("tracks.csv", ios::in);
	if (!inFile) {
		cerr << "Unable to open file tracks.csv." << endl;
		exit(1);
	}
	getline(inFile, temp);
	while (getline(inFile, line)) {
		istringstream tempLine(line);
		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackList.id.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackList.id.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, '"');

		getline(tempLine, temp, '"');
		if (preTemp == temp) {
			TrackList.geometry.push_back(empty);
		}
		else {
			TrackList.geometry.push_back(temp);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackList.buildStart.push_back(emptyNum);
		}
		else {
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
			}
			TrackList.buildStart.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackList.opening.push_back(emptyNum);
		}
		else {
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
			}
			TrackList.opening.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackList.closure.push_back(emptyNum);
		}
		else {
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
			}
			TrackList.closure.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, ',');
		if (preTemp == temp) {
			TrackList.length.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackList.length.push_back(tempNum);
		}
		preTemp = temp;

		getline(tempLine, temp, '.');
		if (preTemp == temp) {
			TrackList.cityId.push_back(emptyNum);
		}
		else {
			tempNum = stoi(temp);
			TrackList.cityId.push_back(tempNum);
		}
		preTemp = temp;
	}
	inFile.close();
}

//**************************************
//Implement Requirement

void TDataset::printCityList() {
	CityList.id.print();
}

int TDataset::totalLine() {
	return CityList.id.countElement() + LineList.id.countElement() + StationList.id.countElement() + StationLineList.id.countElement() + SystemList.id.countElement() + TrackList.id.countElement() + TrackLineList.id.countElement();
}

int TDataset::numLineByCity(string cityName) {
	int idx;
	if (CityList.name.isCityExist(cityName, idx) == -1) {
		return -1;
	}
	else {
		return LineList.cityId.countNumOfLineById(CityList.id.at(idx));
	}
}

int TDataset::findCityIdByName(string cityName) {
	int idx;
	if (CityList.name.find(cityName, idx) == false) {
		return -1;
	}
	else {
		return CityList.id.at(idx);
	}
}

int TDataset::findStationIdByStationName(string stationName) {
	int idx;
	if (StationList.name.find(stationName, idx) == false) {
		return -1;
	}
	else {
		return StationList.id.at(idx);
	}
}

int* TDataset::findListStationIdByCityName(string cityName, int& N) {
	int* listArray = NULL;
	vector<int> listIdxOfStationId;
	int size;
	N = 0;
	if (findCityIdByName(cityName) == -1) {
		return listArray;
	}
	else {
		StationList.cityId.findListStationIdByCityId(findCityIdByName(cityName), listIdxOfStationId, size);
		listArray = new int[size];
		for (int i = 0; i < size; i++) {
			listArray[i] = StationList.id.at(listIdxOfStationId.at(i));
			N++;
			//cout << listArray[i] << endl;
		}
		return listArray;
	}
}

int* TDataset::findListLineIdByCityName(string cityName, int& N) {
	int* listArray = NULL;
	vector<int> listIdxOfLineId;
	int size;
	N = 0;
	if (findCityIdByName(cityName) == -1) {
		return listArray;
	}
	else {
		LineList.cityId.findListLineIdByCityId(findCityIdByName(cityName), listIdxOfLineId, size);
		listArray = new int[size];
		for (int i = 0; i < size; i++) {
			listArray[i] = LineList.id.at(listIdxOfLineId.at(i));
			//cout << listArray[i] << endl;
			N++;
		}
		return listArray;
	}
}

string TDataset::findGeometryOfLineByLineId(int lineId) {
	int idx;
	if (StationList.id.find(lineId, idx) == false) {
		return "";
	}
	else {
		/*cout << endl;
		cout << StationList.geometry.at(idx).substr(6, StationList.geometry.at(idx).length() - 7);*/
		return StationList.geometry.at(idx).substr(6, StationList.geometry.at(idx).length() - 7);

	}
}

string TDataset::findGeometryOfTrackByTrackId(int trackId) {
	int idx;
	if (TrackList.id.find(trackId, idx) == false) {
		return "";
	}
	else {
		/*cout << endl;
		cout << TrackList.geometry.at(idx);*/
		return TrackList.geometry.at(idx);
	}
}

int TDataset::findPositionOfStationInTrack(int lineId, int trackId) {
	int idx = 0;
	string str1 = findGeometryOfLineByLineId(lineId);
	string str2 = findGeometryOfTrackByTrackId(trackId);
	string str = str2.substr(11, str2.length() - 12);
	int size = countSpace(str);
	string* temp = new string[size];
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			temp[i] = str.substr(0, findComma(1, str) - 1);
		}
		else if (i == size - 1) {
			temp[i] = str.substr(findComma(i, str) + 1, str.length() - findComma(i, str) - 1);
		}
		else {
			temp[i] = str.substr(findComma(i, str) + 1, findComma(i + 1, str) - findComma(i, str) - 1);
		}
		if (str1 == temp[i]) {
			idx = i + 1;
			break;
		}
	}
	if (idx != 0) {
		return idx;
	}
	else {
		return -1;
	}
}

int* TDataset::findListStationIdByLineId(int lineId, int& N) {
	int* listArray = NULL;
	vector<int> listIdxOfStationId;
	int size;
	N = 0;
	StationLineList.lineId.findListStationIdByLineId(lineId, listIdxOfStationId, size);
	listArray = new int[size];
	for (int i = 0; i < size; i++) {
		listArray[i] = StationLineList.stationId.at(listIdxOfStationId.at(i));
		N++;
	}
	return listArray;
}

bool TDataset::separateDescription(string& name, string& geometry, int& buildstart, int& opening, int& closure, string description) {
	int count = countComma(description);
	if (count == 0) {
		name = description.substr(0, description.length());
		geometry = "";
		buildstart = -1;
		opening = -1;
		closure = -1;
	}
	else if (count == 1) {
		name = description.substr(0, findComma(1, description));
		geometry = description.substr(findComma(1, description) + 1, description.length() - findComma(1, description) - 1);
		buildstart = -1;
		opening = -1;
		closure = -1;
	}
	else if (count == 2) {
		name = description.substr(0, findComma(1, description));
		geometry = description.substr(findComma(1, description) + 1, findComma(2, description) - findComma(1, description) - 1);
		if (isNum(description.substr(findComma(2, description) + 1, description.length() - findComma(2, description) - 1)) == true) {
			buildstart = stoi(description.substr(findComma(2, description) + 1, description.length() - findComma(2, description) - 1));
		}
		else {
			return false;
		}
		opening = -1;
		closure = -1;
	}
	else if (count == 3) {
		name = description.substr(0, findComma(1, description));
		geometry = description.substr(findComma(1, description) + 1, findComma(2, description) - findComma(1, description) - 1);
		if (isNum(description.substr(findComma(2, description) + 1, findComma(3, description) - findComma(2, description) - 1)) == true) {
			buildstart = stoi(description.substr(findComma(2, description) + 1, findComma(3, description) - findComma(2, description) - 1));
		}
		else {
			return false;
		}
		if (isNum(description.substr(findComma(3, description) + 1, description.length() - findComma(3, description) - 1)) == true) {
			opening = stoi(description.substr(findComma(3, description) + 1, description.length() - findComma(3, description) - 1));
		}
		else {
			return false;
		}
		closure = -1;
	}
	else if (count == 4) {
		name = description.substr(0, findComma(1, description));
		geometry = description.substr(findComma(1, description) + 1, findComma(2, description) - findComma(1, description) - 1);
		if (isNum(description.substr(findComma(2, description) + 1, findComma(3, description) - findComma(2, description) - 1)) == true) {
			buildstart = stoi(description.substr(findComma(2, description) + 1, findComma(3, description) - findComma(2, description) - 1));
		}
		else {
			return false;
		}
		if (isNum(description.substr(findComma(3, description) + 1, findComma(4, description) - findComma(3, description) - 1)) == true) {
			opening = stoi(description.substr(findComma(3, description) + 1, findComma(4, description) - findComma(3, description) - 1));
		}
		else {
			return false;	
		}
		if (isNum(description.substr(findComma(4, description) + 1, description.length() - findComma(4, description) - 1)) == true) {
			closure = stoi(description.substr(findComma(4, description) + 1, description.length() - findComma(4, description) - 1));
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	return true;
}

int TDataset::addNewStation(string description) {
	int max = StationList.id.findMaxId() + 1;
	string name;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int def = -1;
	if (separateDescription(name, geometry, buildstart, opening, closure, description) == false) {
		return -1;
	}
	else {
		separateDescription(name, geometry, buildstart, opening, closure, description);
		StationList.id.push_back(max);
		StationList.name.push_back(name);
		StationList.geometry.push_back(geometry);
		StationList.buildStart.push_back(buildstart);
		StationList.opening.push_back(opening);
		StationList.closure.push_back(closure);
		StationList.cityId.push_back(def);
		return max;
	}
}

bool TDataset::isStationInTrack(int stationId, vector<int>& idx, int& size) {
	size = 0;
	for (int i = 0; i < TrackList.id.getSize(); i++) {
		if (findPositionOfStationInTrack(stationId, TrackList.id.at(i)) != -1) {
			idx.push_back(i+1);
			size++;
		}
	}
	if (size != 0) {
		return true;
	}
	else return false;
}

bool TDataset::isStationInStationLine(int stationId, vector<int>& idx, int& size) {
	size = 0;
	for (int i = 0; i < StationLineList.id.getSize(); i++) {
		if (StationLineList.stationId.at(i) == stationId) {
			idx.push_back(i+1);
			size++;
		}
	}
	if (size != 0) {
		return true;
	}
	else return false;
}

void TDataset::deleteStationInTrack(int stationId, int& is) {
	vector<int> idx = {};
	int size = 0;
	is = -1;
	if (isStationInTrack(stationId, idx, size) == true) {
		for (int i = 0; i < size; i++) {
			TrackList.id.remove(idx.at(i));
			TrackList.geometry.remove(idx.at(i));
			TrackList.buildStart.remove(idx.at(i));
			TrackList.opening.remove(idx.at(i));
			TrackList.closure.remove(idx.at(i));
			TrackList.length.remove(idx.at(i));
			TrackList.cityId.remove(idx.at(i));
		}
		is = 0;
	}
}

void TDataset::deleteStationInStationLine(int stationId, int& is) {
	vector<int> idx = {};
	int size = 0;
	is = -1;
	if (isStationInStationLine(stationId, idx, size) == true) {
		for (int i = 0; i < size; i++) {
			StationLineList.id.remove(idx.at(i));
			StationLineList.stationId.remove(idx.at(i));
			StationLineList.lineId.remove(idx.at(i));
			StationLineList.cityId.remove(idx.at(i));
			StationLineList.createdAt.remove(idx.at(i));
			StationLineList.updatedAt.remove(idx.at(i));
		}
		is = 0;
	}
}

void TDataset::deleteStation(int stationId, int& is) {
	int idx;
	is = -1;
	if (StationList.id.find(stationId, idx) == true) {
		StationList.id.remove(idx);
		StationList.name.remove(idx);
		StationList.geometry.remove(idx);
		StationList.buildStart.remove(idx);
		StationList.opening.remove(idx);
		StationList.closure.remove(idx);
		StationList.cityId.remove(idx);
		is = 0;
	}
}

int TDataset::isDelete(int stationId) {
	int is1, is2, is3;
	deleteStation(stationId, is3);
	if (is3 == 0) {
		deleteStationInTrack(stationId, is1);
		deleteStationInStationLine(stationId, is2);
		return 0;
	}
	else return -1;
}

int TDataset::updateInfoOfStation(int stationId, string description) {
	string name;
	string geometry;
	int buildstart;
	int opening;
	int closure;
	int def = -1;
	if (separateDescription(name, geometry, buildstart, opening, closure, description) == false) {
		return -1;
	}
	else {
		int idx;
		StationList.id.find(stationId, idx);
		separateDescription(name, geometry, buildstart, opening, closure, description);
		StationList.name.at(idx) = name;
		StationList.geometry.at(idx) = geometry;
		StationList.buildStart.at(idx) = buildstart;
		StationList.opening.at(idx) = opening;
		StationList.closure.at(idx)= closure;
		return 0;
	}
}

int TDataset::separeteForLastReq(int& stationId, int& lineId, int& pos, string input) {
	string stationIdString, lineIdString, posString;
	if (countSpace(input) != 2) {
		return -1;
	}
	stationIdString = input.substr(0, findSpace(1, input));
	lineIdString = input.substr(findSpace(1, input) + 1, findSpace(2, input) - findSpace(1, input) - 1);
	posString = input.substr(findSpace(2, input) + 1, input.length() - findSpace(2, input) - 1);
	if (isNum(stationIdString) == true && isNum(lineIdString) == true && isNum(posString) == true) {
		stationId = stoi(stationIdString);
		lineId = stoi(lineIdString);
		pos = stoi(posString);
		/*cout << endl << endl << pos << endl;*/
		return 0;
	}
	else return -1;
}

int TDataset::insertStation(int*& arrayList, int& stationId, int& lineId, int& pos, string input) {
	int N;
	if (separeteForLastReq(stationId, lineId, pos, input) == 0) {
		int size;
		int def = -1;
		string defString = "";
		vector<int> listIdxOfStationId;
		arrayList = findListStationIdByLineId(lineId, N);
		arrayList = new int[1];
		if (pos > N) {
			return -1;
		}
		else if (pos = N) {
			arrayList = new int[1];
			arrayList[N] = stationId;
			StationLineList.lineId.findListStationIdByLineId(lineId, listIdxOfStationId, size);
			StationLineList.id.insert(listIdxOfStationId.at(size - 1) + 1, def);
			StationLineList.lineId.insert(listIdxOfStationId.at(size - 1) + 1, lineId);
			StationLineList.stationId.insert(listIdxOfStationId.at(size - 1) + 1, stationId);
			StationLineList.createdAt.insert(listIdxOfStationId.at(size - 1) + 1, defString);
			StationLineList.updatedAt.insert(listIdxOfStationId.at(size - 1) + 1, defString);
			StationLineList.cityId.insert(listIdxOfStationId.at(size - 1) + 1, def);
			return 0;
		}
		else if(pos >= 0 && pos < N) {
			for (int i = 0; i < N; i++) {
				if (arrayList[i] == stationId) {
					return -1;
				}
			}
			arrayList = new int[1];
			for (int i = N - 1; i >= pos; i--) {
				arrayList[i + 1] = arrayList[i];
				if (i == pos) {
					arrayList[i] = stationId;
					StationLineList.lineId.findListStationIdByLineId(lineId, listIdxOfStationId, size);
					StationLineList.id.insert(listIdxOfStationId.at(i) + 1, def);
					StationLineList.lineId.insert(listIdxOfStationId.at(i) + 1, lineId);
					StationLineList.stationId.insert(listIdxOfStationId.at(i) + 1, stationId);
					StationLineList.createdAt.insert(listIdxOfStationId.at(i) + 1, defString);
					StationLineList.updatedAt.insert(listIdxOfStationId.at(i) + 1, defString);
					StationLineList.cityId.insert(listIdxOfStationId.at(i) + 1, def);
					return 0;
				}
			}
		}
	}
	else return -1;
}
//******************************************

void LoadData(void*& pData) {
	pData = new TDataset();
	TDataset* pD = (TDataset*)pData;
	pD->loadDataCity();
	pD->loadDataLine();
	pD->loadDataStationLine();
	pD->loadDataStation();
	pD->loadDataSystem();
	pD->loadDataTrackLine();
	pD->loadDataTrack();
}

void ReleaseData(void*& pData) {}
