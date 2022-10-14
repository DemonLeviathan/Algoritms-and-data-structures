#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void main()
{
	queue<int> MatrixQueue;
	int matrix[10][10] = {
		{0, 1, 0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 1, 0, 0, 1, 0},
		{1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 1, 0, 0, 0, 1, 0},
		{0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 1, 0, 1, 0, 0, 0, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 1, 0}
	};

	// BFS
	int nodes[10];
	for (int i = 0; i < 10; i++)
		nodes[i] = 0;
	MatrixQueue.push(0);

	cout << "BFS: " << endl;
	while (!MatrixQueue.empty())
	{
		int node = MatrixQueue.front();
		MatrixQueue.pop();
		nodes[node] = 2;

		for (int j = 0; j < 10; j++)
		{
			if (matrix[node][j] == 1 && nodes[j] == 0)
			{
				MatrixQueue.push(j);
				nodes[j] = 1;
			}
		}
		cout << node + 1 << " ";
	}
	cout << endl;

	cout << "DFS:" << endl;
	stack<int> MatrixStack;
	for (int i = 0; i < 10; i++)
		nodes[i] = 0;
	MatrixStack.push(0);

	while (!MatrixStack.empty())
	{
		int node = MatrixStack.top();
		MatrixStack.pop();

		if (nodes[node] == 2) continue;
			nodes[node] = 2;

			for (int j = 9; j >= 0; j--)
			{
				if (matrix[node][j] == 1 && nodes[j] != 2)
				{ 
					MatrixStack.push(j);
					nodes[j] = 1;
				}
			}
			cout << node + 1 << " ";
	}

	// список рёбер
	int edge[22][2] = { {1, 2}, {2, 1}, {1, 5}, {5, 1}, {2, 7}, {7, 2}, {2, 8}, {8, 2}, {3, 8}, {8, 3}, {4, 6}, {6, 4}, 
		{4, 9}, {9, 4}, {5, 6}, {6, 5}, {6, 9}, {9, 6}, {7, 8}, {8, 7}, {9, 10}, {10, 9} };

	// список смежности
	int list[10][3] = { {2, 5}, {1, 7, 8}, {8}, {6, 9}, {1, 6}, {4, 5, 9}, {2, 8}, {2, 3, 7}, {4, 6, 10}, {9} };

	cout << endl << endl;
	cout << "list: " << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << " -> ";
		for (int j = 0; j < 3; j++)
		{
			if (list[i][j] != 0)
			cout << list[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}