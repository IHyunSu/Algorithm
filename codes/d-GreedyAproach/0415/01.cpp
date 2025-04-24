// MST: Prim's Algorithm
/* input case
5 7			<- size n, edge count k
1 2 1		<- vertex u,v and weight w
1 3 3
2 3 3
2 4 6
3 4 4
3 5 2
4 5 5
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#define INF 0xffff
using namespace std;

typedef vector<vector<int> > matrix_t;
typedef vector<pair<int, int> > set_of_edges;
typedef pair<int, int> edge_t;


void prim(int n, matrix_t& W, set_of_edges& F);
int main()
{
	set_of_edges F;
	int row, col;
	int n,m; 
	cin >> n >> m;
	matrix_t W(n+1,vector<int>(n+1,INF));

	while (m--)
	{
		cin >> row >> col;
		cin >> W[row][col];
		W[col][row] = W[row][col];
	}
	for (int i = 1; i <= n; i++)
		W[i][i] = 0;
	prim(n, W, F);

	for (edge_t e:F) {
		row = e.first; col = e.second;
		cout << row << " " << col << " " << W[row][col] << endl;
	}

	return 0;
}
void prim(int n, matrix_t& W, set_of_edges& F) {
	int vnear, min; 
	vector<int>nearest(n + 1), distance(n + 1);
	F.clear(); 
	for(int i=2;i<=n;i++)
	{
		nearest[i]=1;
		distance[i]=W[1][i];
	}
	for (int j = 1; j < n; j++)
	{
		for (int i = 2; i <= n; i++)
		{
			if (i != n)
				cout << nearest[i] << " ";
			else
				cout << nearest[i] << endl;
		}
		min = INF;
		for (int i = 2; i <= n; i++)
		{
			if (0 <= distance[i] && distance[i] < min)
			{
				min = distance[i];
				vnear = i;
			}
		}

		F.push_back(make_pair(vnear, nearest[vnear]));

		distance[vnear] = -1;
		for (int i = 2; i <= n; i++)
		{
			if (distance[i] > W[i][vnear])
			{
				distance[i] = W[i][vnear];
				nearest[i] = vnear;
			}
		}

	}
	for (int i = 2; i <= n; i++)
	{
		if (i != n)
			cout << nearest[i] << " ";
		else
			cout << nearest[i] << endl;
	}


}