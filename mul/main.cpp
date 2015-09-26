#include <stdio.h>
#include <stdint.h>

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /D_CRT_SECURE_NO_WARNINGS /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

//template<typename T>
//T multiply (T pArg1, T pArg2)
//{
//    unsigned T arg1 = static_cast<unsigned T>(pArg1);
//    unsigned T arg2 = static_cast<unsigned T>(pArg2);
//    T res = 0;
//
//    if (arg1 > arg2) {
//        for (int c = 0; c < arg2; c++) {
//            res += arg1;
//        }
//    } else {
//        for (int c = 0; c < arg1; c++) {
//            res += arg2;
//        }
//    }
//
//    if (((pArg1 < 0)&&(pArg2 > 0)) || ((pArg1 > 0)&&(pArg2 < 0))) {        
//        res = -1 * res;        
//    }
//
//    return res;
//}


int32_t multiply (int32_t pArg1, int32_t pArg2)
{
    uint32_t arg1;
    uint32_t arg2;
    int sign = 1;

    if (pArg1 < 0) {
        arg1 = pArg1 * -1;
        sign*=-1;
    } else {
        arg1 = pArg1;
    }
    if (pArg2 < 0) {
        arg2 = pArg2 * -1;
        sign*=-1;
    } else {
        arg2 = pArg2;
    }

    int32_t res = 0;

    if (arg1 > arg2) {
        for (uint32_t c = 0; c < arg2; c++) {
            res += arg1;
        }
    } else {
        for (uint32_t c = 0; c < arg1; c++) {
            res += arg2;
        }
    }

    return res * sign;
}

int main ()
{
    int32_t x = -20;
    int32_t y = 10;
    y = multiply(x,y);
    printf("%d", y);
    //uint32_t a;
    //uint32_t b;
    //b = multiply<uint32_t>(a,b);
    //
    //uint64_t p;
    //uint64_t q;
    //q = multiply<uint64_t>(p,q);

    //int32_t x;
    //int32_t y;
    //y = multiply<int32_t>(x,y);

    //int64_t m;
    //int64_t n;
    //
    //n = multiply<int64_t>(m,n);
    return 0;
}
