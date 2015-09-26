#include<iostream>
using namespace std;

// (10^k-1)/9   => 1, 11, 111, 1111
// (10*x)+3     => 3, 13, 23, 33, 43
// for a given (10*x)+3, find (10^k-1)/9 divisible with lowest k
// num * Y = (10^k-1)/9 
int main ()
{
    unsigned n;
    cout << "Num:";
    cin >> n;
    //int count=1, rem=1; 
    //while(rem)
    //{
    //    cout <<rem<<endl;
    //    rem= (rem*10+1)%n; count++;
    //} 
    //while(count--){ cout<<"1";}

    //cout << (pow(10, n) - 1)/9;

    unsigned i = 1;
    for (;;i++) {
        if ((unsigned)((pow(10, i)-1)/9)%n == 0) 
            break;
    }

    cout<<(((pow(10, i)-1)/9));

    return 0;
}

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// 
