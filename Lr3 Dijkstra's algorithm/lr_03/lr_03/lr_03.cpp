#include <iostream>
#include <queue>
using namespace std;

void main()
{
	queue<int> Queue;
	int matrix[9][9] = {
		//   A   B   C   D   E   F   G   H   I
			{0,  7,  10, 0,  0,  0,  0,  0,  0}, // A
			{7,  0,  0,  0,  0,  9,  27, 0,  0}, // B
			{10, 0,  0,  0,  31, 8,  0,  0,  0}, // C
			{0,  0,  0,  0,  32, 0,  0,  17, 21},// D
			{0,  0,  31, 32, 0,  0,  0,  0,  0}, // E
			{0,  9,  8,  0,  0,  0,  0,  11, 0}, // F
			{0,  27, 0,  0,  0,  0,  0,  0,  15},// G
			{0,  0,  0,  17, 0,  11, 0,  0,  15},// H
			{0,  0,  0,  21, 0,  0,  15, 15, 0}  // I
	};

	int tmp;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			tmp = matrix[i][j];
			tmp = matrix[j][i];
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	int mindistance[9];
	int visited[9];

	for (int i = 0; i < 9; i++)
	{
		mindistance[i] = 1000;
		visited[i] = 1;
	}

	int startpoint = 0;
	mindistance[startpoint] = 0;
	int minvalue, min;

	do
	{
		minvalue = 1000;
		min = 1000;

		for (int i = 0; i < 9; i++)
		{
			if ((visited[i] == 1) && (mindistance[i] < min))
			{
				min = mindistance[i];
				minvalue = i;
			}
		}

		if (minvalue != 1000)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (matrix[minvalue][i] > 0)
					{
						tmp = min + matrix[minvalue][i];
						if (tmp < mindistance[i])
						{
							mindistance[i] = tmp;
						}
					}
				}
				visited[minvalue] = 0;
			}
		}
	} while (minvalue < 1000);


	cout << "The shortest distances to nodes from A: " << endl;
	for (int i = 0; i < 9; i++)
	{ 
		cout << mindistance[i] << "  ";
	}
	cout << endl;

	/*int checked[9];
	int last = 7;
	checked[0] = last + 1;
	int pre = 1;
	int weight = mindistance[last];

	while (last != startpoint)
	{
		for (int i = 0; i < 9; i++)
		{
			if (matrix[i][last] != 0)
			{
				int way = weight - matrix[i][last];

				if (way == mindistance[i])
				{
					weight = way;
					last = i;
					checked[pre] = i + 1;
					pre++;
				}
			}
		}
	}
	for (int i = pre - 1; i >= 0; i--)
		cout << checked[i] << " ";
	cout << endl;*/

}