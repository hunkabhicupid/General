// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe & .\bin\win_release\main.exe
// 
#include <cstdio>
#include <ctime>
#include <cstdint>
#include <ctime>

#include <iostream>
#include <thread>
using namespace std;

#include <chrono>
using namespace std::chrono;

#define NUM_THREADS 4
#define BIG_NUM     (536870912 + (rand()%2))

//#define LOOP
#define SLEEP

int main ()
{    
    int i = 0;
    int c = 0;
    srand(0);
    duration<double, milli> time_span;

    cout << "high_resolution_clock(ms)" << endl;
    high_resolution_clock::time_point hrcstart, hrcstop;
    hrcstart    = high_resolution_clock::now();
#ifdef LOOP
    for (int i = 0; i < BIG_NUM; i++) {
        c++;
    }
#elif defined(SLEEP)
    this_thread::sleep_for(2s);
#endif
    hrcstop     = high_resolution_clock::now();
    time_span = duration_cast<duration<double, milli>>(hrcstop - hrcstart);
    cout << time_span.count() << endl;

    cout << "steady_clock(ms)" << endl;
    steady_clock::time_point stcstart, stcstop;    
    stcstart    = steady_clock::now();
#ifdef LOOP
    for (int i = 0; i < BIG_NUM; i++) {
        c++;
    }
#elif defined(SLEEP)
    this_thread::sleep_for(2s);
#endif
    stcstop     = steady_clock::now();
    time_span = duration_cast<duration<double, milli>>(stcstop - stcstart);
    cout << time_span.count() << endl;

    cout << "system_clock(ms)" << endl;
    system_clock::time_point scstart, scstop;    
    scstart     = system_clock::now();
#ifdef LOOP
    for (int i = 0; i < BIG_NUM; i++) {
        c++;
    }
#elif defined(SLEEP)
    this_thread::sleep_for(2s);
#endif
    scstop      = system_clock::now();
    time_span = duration_cast<duration<double, milli>>(scstop - scstart);
    cout << time_span.count() << endl;

    cout << "clock_t(ms)" << endl;
    clock_t cstart, cstop;    
    cstart     = clock();
#ifdef LOOP
    for (int i = 0; i < BIG_NUM; i++) {
        c++;
    }
#elif defined(SLEEP)
    this_thread::sleep_for(2s);
#endif
    cstop      = clock();    
    cout << (((float)(cstop - cstart)*1000)/CLOCKS_PER_SEC) << endl;

    cout << "IGNORE: " << c;

    return 0;
}


//void ThreadFunc (high_resolution_clock::time_point pWaitUntil, high_resolution_clock::time_point pTime)
//{
//    uint64_t i = 0;
//    // all threads to start again
//    this_thread::sleep_until(pWaitUntil);
//
//    while (high_resolution_clock::now() < pTime) {
//        i++;
//    }
//
//    cout << i << endl;
//}
// 
// 
    //thread * t[NUM_THREADS];
    //
    //high_resolution_clock::time_point wait = high_resolution_clock::now() + milliseconds(200);
    //
    //for (int i =0; i < NUM_THREADS; i++) {
    //    t[i] = new thread (ThreadFunc, wait, wait + milliseconds(60000));
    //}
    //
    //for (int i =0; i < NUM_THREADS; i++) {
    //    t[i]->join();
    //}
