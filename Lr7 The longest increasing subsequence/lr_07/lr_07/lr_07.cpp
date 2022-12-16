#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

void findSequence(vector<int> const &sequence)
{
	int size = sequence.size();

	if (size == 0)
	{
		return;
	}

	vector<vector<int>> subsequence(size, vector<int>{});

	subsequence[0].push_back(sequence[0]);

	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if ((sequence[i] > sequence[j]) && (subsequence[j].size() > subsequence[i].size()))
			{
				subsequence[i] = subsequence[j];
			}
		}
		subsequence[i].push_back(sequence[i]);
	}

	int j = 0;
	cout << "The longest subsequence: ";
	for (int i = 0; i < size; i++)
	{
		if (subsequence[j].size() < subsequence[i].size())
		{
			j = i;
		}
	}

	int count = 0;
	for (int i : subsequence[j])
	{
		cout << i << " ";
		count++;
	}
	cout << endl;
	cout << "Max length of sequence: ";
	cout << count << endl;
	
}

void main()
{
	vector<int> sequence = { -5, 10, 6, 12, 3, 24, 7, 8 };
	findSequence(sequence);
}