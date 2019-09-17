#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <sstream>
#include <math.h>

#include "dsaLib.h"
#include "dbLib.h"
#include "processData.h"

using namespace std;

int main() {
    Initialization();

    void*   pData = nullptr;
    void*   pOutput = nullptr;
    int     N;

    LoadData(pData);
    assert(pData != nullptr);
    cout << fixed << setprecision(8);
    string req;
    while (true) {
        req = "";
        getline(cin, req);
        if (cin.bad()) {
            cin.clear();
            cin.ignore(1024, '\n');
            continue;
        }
        if (req == "Exit") {
            break;
        }
        ProcessRequest(req.data(), pData, pOutput, N);
        PrintReqOutput<int>(req.data(), (int*)pOutput, N);
        delete [] (int*)pOutput;
        pOutput = nullptr;
    }

    ReleaseData(pData);
    Finalization();
    return 0;
}