#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{

    ifstream inpFile("i betastat 1", ios::in);
    ofstream outFile("output.csv", ios::out);

    if(!inpFile) {
        cerr << "Could not be opened." << endl;
        exit(EXIT_FAILURE);

    }
    string line, username, feature, pid, start;
    string host_uname, date;
    string sep1, sep2, sep3, day, mon, numday, time, yr;
    int n = 0, pos;

    if(!outFile) {
        cerr << "File could no be opened." << endl;
        exit(EXIT_FAILURE);
    }

    while(getline(inpFile, line)) {
        n++;
        if(n > 11 && n < 51) {
            inpFile >> username >> sep1 >> feature >> sep2 >> pid >> sep3 >> day >> mon >> numday >> time >> yr;
            pos = username.find('@');
            host_uname = username.replace(pos, 1, ",");
            date = day + " " + mon + " " + numday + " " + time + " " + yr;
            //cout << pos;
            //cout << host_uname << ',' << feature << ',' << date << endl;
            outFile << host_uname << ',' << feature << ',' << date << endl;
        }

    }

    inpFile.close();
    outFile.close();

    cout << "Data written in \'output.csv\'" << endl;

    return 0;
}
