#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 1000000
#define SIZE 8
#define EDGES 16

int matrix[SIZE][SIZE] = {
	//	1   2   3   4   5   6   7  8
		{0, 2,  0,  8,  2,  0,  0, 0}, // 1
		{2, 0,  3,  10, 5,  0,  0, 0}, // 2
		{0, 3,  0,  0,  12, 0,  0, 7}, // 3
		{8, 10, 0,  0,  14, 3,  1, 0}, // 4
		{2, 5,  12, 14, 0,  11, 4, 8}, // 5
		{0, 0,  0,  3,  11, 0,  6, 0}, // 6
		{0, 0,  0,  1,  4,  6,  0, 9}, // 7
		{0, 0,  7,  0,  8,  0,  9, 0}  // 8
};

const int list[16][3] = {
	{1,4,7},
	{2,1,5},
	{2,1,2},
	{3,2,3},
	{3,4,6},
	{4,7,5},
	{5,2,5},
	{6,6,7},
	{7,3,8},
	{8,5,8},
	{8,1,4},
	{9,7,8},
	{10,2,4},
	{11,5,6},
	{12,3,5},
	{14,4,5}
};

int visited[SIZE];
int sum = 0;
int edgecounter = 0;

void Prima()
{
	memset(visited, false, sizeof(visited));
	visited[0] = true;

	int rows;
	int columns;

	int min;
	while (edgecounter < SIZE - 1)
	{
		min = INF;
		rows = 0;
		columns = 0;

		for (int i = 0; i < SIZE; i++)
		{
			if (visited[i])
			{
				for (int j = 0; j < SIZE; j++)
				{
					if ((!visited[j]) && (matrix[i][j]))
					{
						if (min > matrix[i][j])
						{
							min = matrix[i][j];
							rows = i;
							columns = j;
						}
					}
				}
			}
		}
		cout << rows + 1 << " -> " << columns + 1 << " : " << matrix[rows][columns];
		sum += matrix[rows][columns];
		cout << endl;
		visited[columns] = true;
		edgecounter++;
	}
	cout << "Weight of graph: ";
	cout << sum << endl;
}

bool lines[SIZE];
bool edges[EDGES];
void Kruskal()
{
	for (int i = 0; i < SIZE; i++)
		lines[i] = false;

	int start;
	start = list[0][1];

	edges[start - 1] = true;
	int cyclenumber = EDGES - SIZE + 1;

	for (int i = 0; i < SIZE - 2; i++)
	{
		for (int j = 0; j < EDGES; j++)
		{
			list[j][1] - 1;
			list[j][2] - 1;

			if (cyclenumber)
			{
				if ((lines[list[j][i] - 1]) && (!lines[list[j][2] - 1]) ||
					(!lines[list[j][1] - 1]) && (lines[list[j][2] - 1]) ||
					(!lines[list[j][1] - 1]) && (!lines[list[j][2] - 1]) ||
					(lines[list[j][1] - 1]) && (lines[list[j][2] - 1]) && !edgecounter)
				{
					if ((lines[list[j][1] - 1]) && (lines[list[j][2] - 1]) || (visited[SIZE]) && (!edgecounter))
					{
						edgecounter++;
						cout << list[j][1] << " -> " << list[j][2] << endl;
						continue;
					}

					lines[list[j][1] - 1] = true;
					lines[list[j][2] - 1] = true;
					cout << list[j][1] << " -> " << list[j][2] << endl;
				}
				cyclenumber--;
			}
		}
	}
}

void main()
{
	cout << "Prima's algorithm: " << endl;
	Prima();
	cout << endl;
	cout << "Kruskal's algorithm: " << endl;
	Kruskal();
}