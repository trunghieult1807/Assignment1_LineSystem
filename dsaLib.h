/* Created by Nguyen Duc Dung on 2019-09-03.
 * =========================================================================================
 * Name        : dsaLib.h
 * Author      : Duc Dung Nguyen
 * Email       : nddung@hcmut.edu.vn
 * Copyright   : Faculty of Computer Science and Engineering - HCMUT
 * Description : The data structure library for Assignment 1
 * Course      : Data Structure and Algorithms - Fall 2019
 * =========================================================================================
 */

#ifndef DSA191_A1_DSALIB_H
#define DSA191_A1_DSALIB_H
#include <string>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class DSAException {
	int     _error;
	string  _text;
public:

	DSAException() : _error(0), _text("Success") {}
	DSAException(int err) : _error(err), _text("Unknown Error") {}
	DSAException(int err, const char* text) : _error(err), _text(text) {}

	int getError() { return _error; }
	string& getErrorText() { return _text; }
};

template <class T>
struct L1Item {
	T data;
	L1Item<T>* pNext;
	L1Item() : pNext(NULL) {}
	L1Item(T& a) : data(a), pNext(NULL) {}
};

template <class T>
class L1List {
private:
	L1Item<T>* _pHead;// The head pointer of linked list
	L1Item<T>* _pTail;
	size_t      _size;// number of elements in this list

public:
	L1List() : _pHead(NULL), _pTail(NULL), _size(0) {}
	~L1List() {}

	void    clean();
	bool    isEmpty() {
		return _pHead == NULL;
	}
	size_t  getSize() {
		return _size;
	}

	T& at(int idx) {
		if (idx < 0 || idx > _size) {
			throw new DSAException(-1, "The index is out of range! \n");
		}
		else {
			L1Item<T>* _pTemp = new L1Item<T>;
			_pTemp = _pHead;
			if (idx == 0) {
				_pTemp = _pHead;
			}
			else {
				for (int i = 1; i <= idx; i++) {
					_pTemp = _pTemp->pNext;
				}
			}
			return _pTemp->data;
		}
	}
	// give the reference to the element i-th in the list

	T& operator[](int idx);// give the reference to the element i-th in the list

	bool    find(T& a, int& idx);// find an element similar to a in the list. Set the found index to idx, set idx to -1 if failed. Return true if success.

	int     insert(int i, T& a);// insert an element into the list at location i. Return 0 if success, -1 otherwise

	int     remove(int i);// remove an element at position i in the list. Return 0 if success, -1 otherwise.

	int     push_back(T& a);// insert to the end of the list

	int     insertHead(T& a);// insert to the beginning of the list

	int     removeHead();// remove the beginning element of the list

	int     removeLast();// remove the last element of the list

	void    reverse();

	void    traverse(void (*op)(T&)) {
		// TODO: Your code goes here
		if (_size == 0) {
			return;
		}
		else {
			L1Item<T>* _pTemp = _pHead;
			while (_pTemp != NULL) {
				cout << _pTemp->data << endl;
				_pTemp = _pTemp->pNext;
			}
		}
	}
	
	void    traverse(void (*op)(T&, void*), void* pParam) {
		// TODO: Your code goes here
	}
	//****************************************
	//Implement requirement
	void print() {
		L1Item<T>* _pTemp = _pHead;
		while (_pTemp != NULL) {
			cout << _pTemp->data <<endl;
			_pTemp = _pTemp->pNext;
		}
	}

	int countElement() {
		int n = 0;
		L1Item<T>* _pTemp = _pHead;
		while (_pTemp != NULL) {
			n++;
			_pTemp = _pTemp->pNext;
		}
		return n;
	}

	int isCityExist(string cityName, int& idx) {
		L1Item<T>* _pTemp = _pHead;
		int i = 0;
		while (_pTemp != NULL) {
			if (_pTemp->data == cityName) {
				idx = i;
				return 0;
				break;
			}
			_pTemp = _pTemp->pNext;
			i++;
		}
		return -1;
	}

	int countNumOfLineById(int id) {
		L1Item<T>* _pTemp = _pHead;
		int count = 0;
		while (_pTemp != NULL) {
			if (_pTemp->data == id) {
				count++;
			}
			_pTemp = _pTemp->pNext;
		}
		return count;
	}

	int findListStationIdByCityId(int cityId, vector<int>& listIdxOfStationId, int& size) {
		int idx = 0;
		size = 0;
		L1Item<T>* _pTemp = _pHead;
		while (_pTemp != NULL) {
			if (_pTemp->data == cityId) {
				listIdxOfStationId.push_back(idx);
				size++;
			}
			idx++;
			_pTemp = _pTemp->pNext;
		}
		return 0;
	}

	int findListLineIdByCityId(int cityId, vector<int>& listIdxOfLineId, int& size) {
		int idx = 0;
		size = 0;
		L1Item<T>* _pTemp = _pHead;
		while (_pTemp != NULL) {
			if (_pTemp->data == cityId) {
				listIdxOfLineId.push_back(idx);
				size++;
			}
			idx++;
			_pTemp = _pTemp->pNext;
		}
		return 0;
	}

	int findListStationIdByLineId(int lineId, vector<int>& listIdxOfStationId, int& size) {
		int idx = 0;
		size = 0;
		L1Item<T>* _pTemp = _pHead;
		while (_pTemp != NULL) {
			if (_pTemp->data == lineId) {
				listIdxOfStationId.push_back(idx);
				size++;
			}
			idx++;
			_pTemp = _pTemp->pNext;
		}
		return 0;
	}

	//****************************************
};

/// Insert item to the end of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::push_back(T& a) {
	L1Item<T>* _pLast = new L1Item<T>(a);
	if (_pHead == NULL) {
		_pHead = _pLast;
		_pTail = _pLast;
		_pLast = NULL;
		_size++;
	}
	else {
		_size++;
		_pTail->pNext = _pLast;
		_pTail = _pLast;
		
	}
	return 0;
}

/// Insert item to the front of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insertHead(T& a) {
	L1Item<T>* _pFirst = new L1Item<T>;
	if (_pHead == NULL) {
		_pHead == _pFirst;
	}
	else {
		_pFirst->pNext = _pHead;
		_pFirst->data = a;
		_size++;
	}
	return 0;
}

/// Remove the first item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeHead() {
	if (_pHead == NULL) {
		throw new DSAException(-1, "The linked list is initially empty! \n");
	}
	else {
		_size--;
		L1Item<T>* _pTemp = _pHead;
		_pHead = _pHead->pNext;
		delete _pTemp;
		return 0;
	}
}

/// Remove the last item of the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::removeLast() {
	if (_size == 0) {
		throw new DSAException(-1, "The linked list is initially empty! \n");
	}
	else if (_pHead->pNext == NULL) {
		_size--;
		delete _pTail;
		_pHead = _pTail = NULL;
		return 0;
	}
	else {
		L1Item<T>* _pTemp = new L1Item<T>;
		L1Item<T>* _pLast = _pTail;
		_pTemp = _pHead;
		while (_pTemp->pNext != NULL) {
			_pTemp = _pTemp->pNext;
		}
		_pTail = _pTemp;
		delete _pLast;//delete last node
		_size--;
		return 0;
	}
}

/// Remove an element at position i in the list
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::remove(int i) {
	if (i < 0 || i > _size - 1) {
		throw new DSAException(-1, "The index is out of range! \n");
	}
	else {
		int index = 0;
		L1Item<T>* _p;
		while (index < i) {
			index++;

		}
		_size--;
	}
	return 0;
}

/// Insert an element into the list at location i
/// Return 0 if success, -1 otherwise
template <class T>
int L1List<T>::insert(int i, T& a) {
	if (i < 0 || i > _size - 1) {
		throw new DSAException(-1, "The index is out of range! \n");
	}
	else {
		L1Item<T>* _pCurr = _pHead;
		int index = 0;
		while (index < i - 1) {
			index++;
			_pCurr = _pCurr->pNext;
		}
		_pCurr->pNext = new L1Item<T>(a, _pCurr->pNext);
		_size++;
	}
	return 0;

};

/// Find an element similar to a in the list
/// Set the found index to idx, set idx to - 1 if failed
/// Return true if success, else return false
template <class T>
bool L1List<T>::find(T& a, int& idx) {
	L1Item<T>* _pTemp = new L1Item<T>;
	_pTemp = _pHead;
	idx = 0;
	while (_pTemp->data != a) {
		if (_pTemp->pNext == NULL) {
			idx = -1;
			return false;
		}
		idx++;
		_pTemp = _pTemp->pNext;
	}
	return true;
};


#endif //DSA191_A1_DSALIB_H
