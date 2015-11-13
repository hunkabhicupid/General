#include <cmath>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void mark_multiples (unsigned int * parr, unsigned int num, unsigned int limit)
{
	int i = 2;
	
	while (i*num <= limit)
	{
		parr[i*num] = 1;
		i++;
	}
}

void GetListOfPrimes (vector<unsigned int>& vec, unsigned int X, unsigned int Y)
{
	unsigned int y = (unsigned int)sqrt(Y);
	unsigned int x = 3;
	unsigned int * parr = (unsigned int *)malloc(sizeof(unsigned int)*y);
	memset(parr, 0, sizeof(unsigned int)*y);
	vec.push_back(2);
		
	for (unsigned int i = x; i <= y; i+=2)
	{
		if (parr[i] == 0) {
			vec.push_back(i);
			mark_multiples(parr, i, y);
		}
	}
	free(parr);
}
bool IsEligible (const unsigned int num, vector<unsigned int>& vec)
{
	unsigned int i = 2;
	
	vector<unsigned int>::const_iterator it;
	for (it = vec.cbegin(); it != vec.cend(); it++) {
		if (num %(*it * *it) == 0){
			return false;
		}
	}
	return true;
}

void ProcessRange (unsigned int X, unsigned int Y)
{
	vector<unsigned int> vec;
	int count = 0;
	GetListOfPrimes(vec, X, Y);
	for (unsigned int i = X; i <=Y; i++)
	{
		if (IsEligible(i, vec))
			count++;
	}
	cout << count << endl;
}

int main()
{
    int numtests = 0;
    cin >> numtests;
    
    for (int i = 0; i < numtests; i++)
    {
    	unsigned int x,y;
    	cin >> x >> y;
    	ProcessRange(x,y);
    }
    return 0;
}
