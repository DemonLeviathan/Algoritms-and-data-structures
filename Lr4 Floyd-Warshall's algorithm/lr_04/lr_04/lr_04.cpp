#include <iostream>
using namespace std;

void main()
{
	int matrix[6][6] = {
		{0,  28,   21,   59,   12, 27},  // 1
		{7,  0,    24,   1000, 21, 9},   // 2
		{9,  32,   0,    13,   11, 1000},// 3
		{8,  1000, 5,    0,    16, 1000},// 4
		{14, 13,   15,   10,   0,  22},  // 5
		{15, 18,   1000, 1000, 6,  0}    // 6
	};

	int way[6][6] = {
		{0, 2, 3, 4, 5, 6},
		{1, 0, 3, 4, 5, 6},
		{1, 2, 0, 4, 5, 6},
		{1, 2, 3, 0, 5, 6},
		{1, 2, 3, 4, 0, 6},
		{1, 2, 3, 4, 5, 0}
	};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int m = 0; m < 6; m++)
			{

				if ((matrix[j][i] + matrix[i][m]) < matrix[j][m])
				{
					way[j][m] = way[j][i];
				}
				matrix[j][m] = min(matrix[j][m], (matrix[j][i] + matrix[i][m]));

			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << way[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}