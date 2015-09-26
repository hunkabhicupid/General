#include <stdio.h>

// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe

// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe & .\bin\win_release\main.exe

#include <iostream>
#include <thread>
using namespace std;

#include <chrono>
using namespace std::chrono;

#include <ctime>

#include <stdint.h>

#define NUM_THREADS 4
#define BIG_NUM     (536870912 + (rand()%2))

void ThreadFunc (high_resolution_clock::time_point pWaitUntil, high_resolution_clock::time_point pTime)
{
    uint64_t i = 0;
    // all threads to start again
    this_thread::sleep_until(pWaitUntil);

    while (high_resolution_clock::now() < pTime) {
        i++;
    }

    cout << i << endl;
}

struct ABC {
	union {
		uint32_t x;
		struct {
				uint32_t a : 4;
				uint32_t b : 4;
				uint32_t c : 4;
				uint32_t d : 4;
		};
	};
};

void functest(uint64_t *p)
{
    uint32_t * x = (uint32_t *)p;
    uint32_t * y = ((uint32_t *)p) + 1;
}

int main ()
{
	ABC x;
	x.x = 0;
	x.a = 1;
	x.b = 2;
	x.c = 3;
	x.d = 4;

    uint64_t abc = 4294967295;
    functest (&abc);

    thread * t[NUM_THREADS];

    high_resolution_clock::time_point wait = high_resolution_clock::now() + milliseconds(200);

    for (int i =0; i < NUM_THREADS; i++) {
        t[i] = new thread (ThreadFunc, wait, wait + milliseconds(60000));
    }

    for (int i =0; i < NUM_THREADS; i++) {
        t[i]->join();
    }
    //thread t1(ThreadFunc, wait, wait + milliseconds(1000));
    //thread t2(ThreadFunc, wait, wait + milliseconds(1000));
    //thread t3(ThreadFunc, wait, wait + milliseconds(1000));
    //thread t4(ThreadFunc, wait, wait + milliseconds(1000));

    //t1.join();
    //t2.join();
    //t3.join();
    //t4.join();
    //
    // Launch N threads
    //for (i = 0; i < NUM_THREADS; i++) {
    //
    //}
    
    //int i = 0;
    //int c = 0;
    //srand(0);
    //duration<double, milli> time_span;
    //
    //high_resolution_clock::time_point hrcstart, hrcstop;
    //hrcstart    = high_resolution_clock::now();
    //for (int i = 0; i < BIG_NUM; i++) {
    //    c++;
    //}
    //hrcstop     = high_resolution_clock::now();
    //time_span = duration_cast<duration<double, milli>>(hrcstop - hrcstart);
    //cout << time_span.count() << endl;
    //
    //steady_clock::time_point stcstart, stcstop;    
    //stcstart    = steady_clock::now();
    //for (int i = 0; i < BIG_NUM; i++) {
    //    c++;
    //}
    //stcstop     = steady_clock::now();
    //time_span = duration_cast<duration<double, milli>>(stcstop - stcstart);
    //cout << time_span.count() << endl;
    //
    //system_clock::time_point scstart, scstop;    
    //scstart     = system_clock::now();
    //for (int i = 0; i < BIG_NUM; i++) {
    //    c++;
    //}
    //scstop      = system_clock::now();
    //time_span = duration_cast<duration<double, milli>>(scstop - scstart);
    //cout << time_span.count() << endl;
    //
    //cout << "IGNORE: " << c;

    return 0;
}
