#include<iostream>
using namespace std;

unsigned factorial (unsigned n)
{
    int fact = 1;
	// maxor[i] C 2
	for (unsigned j = 1; j <= n; j++)
	{
	  fact *= j;
	}

    return fact;
}

int main ()
{
    unsigned num;
    unsigned numsets;

    cout << "Number of elements in set:";
    cin >> num;

    numsets = 1 << num; // 2^N

    cout << "Total Numsets: " << numsets << endl;

    for (unsigned i = 1; i < numsets; i++) {
        int xor =0;
        for (unsigned j = 0; j < num; j++) {
            if (i & (1<<j)) {
                cout << j+1 << " ";
                xor^=(j+1);
            }
        }
        cout << "XOR" << xor << endl;
        cout << endl;
    }

    cout << "Factorial 2:" <<  factorial (2);
    return 0;
}

// 
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//int factorial (int n)
//{
//    int fact = 1;
//	// maxor[i] C 2
//	for (int j = 1; j <= n; j++)
//	{
//	  fact *= j;
//	}
//
//    return fact;
//}

//int main()
//{
//	int 	N;
//	int 	maxor[128] = { 0 };
//	char*	arr;
//
//	scanf("%d", &N);
//	arr = (char*)malloc(N*sizeof(char));
//
//
//	for (int i = 0; i<N; i++)
//	{
//		int num;
//		scanf("%d", &num);
//		arr[i] = (char)num;
//		//maxor[arr[i]]++;
//	}
//
//	int numsubsets =  1 << N; // 2^N
//
//	for (int i = 1; i < numsubsets; i++)
//	{
//		int xor = 0;
//		for (int j = 0; j < N; j++)
//		{
//			if (i & (1<<j))
//				xor^=arr[j];
//		}
//		maxor[xor]++;
//	}
//
//	int res = 0;
//	for (int i = 0; i < 128; i++)
//	{
//        printf("%d\n",maxor[i]);
//		// assuming the result how many 2 subsets be choosen
//		// whose maxor is same
//		if (maxor[i]>1)
//		{
//			int fact = 1;
//			// maxor[i] C 2
//			//for (int j = 1; j <= maxor[i] - 1; j++)
//			//{
//			//	fact *= j;
//			//}
//			int n = maxor[i];
//			fact = factorial(n) / (factorial(2) * factorial(n-2));
//
//			//fact = fact / 2;
//			res = res + fact;
//			//res += (maxor[i] * (maxor[i]-1))/2;
//			//res ++;
//		}
//	}
//
//	printf("%d", res%1000000007);
//
//	return 0;
//}


// g++ -std=c++11 -Wall -O3 -m64 -g3 -o ./bin/lin_release/main main.cpp
// g++ -std=c++11 -Wall -O0 -m64 -g3 -o ./bin/lin_debug/main -DDEBUG main.cpp
// cl -Ox /Z7 /W3 /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe
// cl -Od /Z7 /W3 /DDEBUG /DEBUG /Fo.\bin\win_debug\ main.cpp /link /out:bin\win_debug\main.exe
// cl -Ox /Z7 /W3 /EHsc /DEBUG /Fo.\bin\win_release\ main.cpp /link /out:bin\win_release\main.exe & .\bin\win_release\main.exe
// 
