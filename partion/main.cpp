#include <stdio.h>
#include <stdint.h>

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

#define NUM 12
int main ()
{
    int stream [NUM] = {2,1,0,2,0,1,2,1,2,1,0,0};
    int lo = 0;     // lo - first 1
    int mid = 0;    //  mid - first unknown
    int hi = NUM-1; // top - last unknown
    // Dutch National Flag or 2 way pationing
    for (int mid = 0; mid < NUM && mid <= hi; mid++) {
        switch(stream[mid]) {
        case 0:
            stream[mid] = stream[lo];
            stream[lo] = 0; lo++;
            break;
        case 1:            
            break;
        case 2:
            stream[mid] = stream[hi];
            stream[hi] = 2;
            hi--;
            mid--;
            break;
        default: 
            // BAD
            break;
        }
    }

    for (int i =0; i< NUM; i++) {
        printf("stream[%d] = %d\n", i, stream[i]);
    }
    
}
