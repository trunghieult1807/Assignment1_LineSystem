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
	//string temp2;
	int size;
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

	/*while (getline(inFile, temp)) {
		size = temp.length();
		temp2 = temp.substr(0, findComma(1, temp));
		StationList.id.push_back(temp2);
		temp2 = temp.substr(findComma(1, temp) + 1, findComma(2, temp) - findComma(1, temp) - 1);
		StationList.name.push_back(temp2);
		temp2 = temp.substr(findComma(2, temp) + 1, findComma(3, temp) - findComma(2, temp) - 1);
		StationList.geometry.push_back(temp2);
		temp2 = temp.substr(findComma(3, temp) + 1, findComma(4, temp) - findComma(3, temp) - 1);
		StationList.buildStart.push_back(temp2);
		temp2 = temp.substr(findComma(4, temp) + 1, findComma(5, temp) - findComma(4, temp) - 1);
		StationList.opening.push_back(temp2);
		temp2 = temp.substr(findComma(5, temp) + 1, findComma(6, temp) - findComma(5, temp) - 1);
		StationList.closure.push_back(temp2);
		temp2 = temp.substr(findComma(6, temp) + 1, size - findComma(6, temp));
		StationList.cityId.push_back(temp2);
	}*/

	/*while (!inFile.eof()) {
		if () {

		}
		else {
			getline(inFile, temp, ',');
			tempNum = stoi(temp);
			StationList.id.push_back(tempNum);
			getline(inFile, temp, ',');
			StationList.name.push_back(temp);
			getline(inFile, temp, ',');
			StationList.geometry.push_back(temp);
			getline(inFile, temp, ',');
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
			}
			StationList.buildStart.push_back(tempNum);
			getline(inFile, temp, ',');
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
			}
			StationList.opening.push_back(tempNum);
			getline(inFile, temp, ',');
			if (temp == "") {
				tempNum = 0;
			}
			else {
				tempNum = stoi(temp);
			}
			StationList.closure.push_back(tempNum);
			getline(inFile, temp, '\n');
			tempNum = stoi(temp);
			StationList.cityId.push_back(tempNum);
		}
	}*/

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

TCity TDataset::getCityList() {
	return CityList;
}

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
