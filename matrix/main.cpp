#include<iostream>
using namespace std;

int main ()
{
    unsigned order;

    cout << ("Order of square matrix");
    cin >> order;


    bool** rows = new bool*[order];

    for (unsigned i = 0; i < order; i++) {
        rows[i] = new bool[order];
        cout<< "Row" << i+1 << endl;
        for (unsigned j = 0; j < order; j++) {
            cout<< "Column" << j+1<< ":";
            cin >> rows[i][j];            
        }
    }
    cout << "MATRIX"<< endl << "{" << endl;
    for (unsigned i = 0; i < order; i++) {
        cout << "{";
        for (unsigned j = 0; j < order; j++) {
            cout<< rows[i][j] << ",";            
        }
        cout << "}" << endl;
    }
    cout << "}" << endl;


    for (unsigned i = 0; i < order; i++) {
        delete [] rows[i];
    }
    delete [] rows;
    return 0;
}

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// 
