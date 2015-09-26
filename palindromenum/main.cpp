#include<iostream>
using namespace std;
#include <vector>

bool  IsPallindrome (const unsigned int pNum)
{
    unsigned int num  = pNum;
    vector<unsigned int> arr;    
    while (num) {
        arr.push_back(num%10);
        num = num / 10;
    };

    for (unsigned int i = 0, j = arr.size()-1;  i <= arr.size() / 2; i++, j--) {
        if (arr[i] != arr[j]) {
            return false;
        }
    }

    //vector<unsigned int>::iterator i = arr.begin();
    //vector<unsigned int>::reverse_iterator j = arr.rbegin();
    //
    //for (; i != arr.end(); i++, j++) {
    //    if (*i != *j) {
    //        return false;
    //    }
    //}
    // 

    return true;
}

int main ()
{
    unsigned int num = 0;
    cout<< "Num:";
    cin >> num;

    cout << (IsPallindrome(num) ? "Yes it is a pallindrome" : "No it is not a pallindrome");
    return 0;
}



// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// 
