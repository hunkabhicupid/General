#include <iostream>
using namespace std;

void Process (unsigned int sols[], unsigned int num_sols)
{
	unsigned int num_hand = 0;
	unsigned int num_fist = 0;
	
	for (unsigned int i = 0; i < num_sols; i++)
	{
		unsigned int num_hand_temp = 0;
		unsigned int num_fist_temp = 0;
		unsigned int num_fist_add = 0;
		unsigned int sup = sols[i];
		// calculate handshakes
		while (sup)
		{
			num_hand_temp++;
			if (sup - 1 < i)
				num_fist_add++;

			sup = sols[sup-1];
		}
		if (sols[i]) {
			num_hand += num_hand_temp;

			// calculate fist bumps
			num_fist_temp = (num_sols - num_hand_temp - (i + 1)) + num_fist_add;
			num_fist += num_fist_temp;
		}
	}

	cout << num_hand << " " << num_fist << endl;
}

int main()
{
	unsigned int sols[100000];
    unsigned int num_tests;
    cin >> num_tests;
    
    for (unsigned int i = 0; i < num_tests; i++)
    {
    	unsigned int num_sol;
    	cin >> num_sol;
    	
    	for (unsigned int j =0; j < num_sol; j++)
    	{
    		cin >> sols[j];
    	}
    	
    	Process(sols, num_sol);
    }
    return 0;
}

