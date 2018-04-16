#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1000000000;


typedef pair<int, int> P;

vector<P> cityNode[1001];
struct COMP {
	bool operator()(P e1, P e2)
	{
		return e1.second > e2.second; //낮은 순으로 뽑는다.
	}
};
int main()
{
	int n, m;//도시의 개수, 버스의 개수

	scanf("%d %d", &n, &m);
	int from, to, busFee;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &from, &to, &busFee);
		cityNode[from].push_back(P(to, busFee));
	}

	int start, end;
	scanf("%d %d", &start, &end);

	int dist[1001];
	for (int i = 0; i < 1001; i++)
	{
		dist[i] = INF;
	}

	int visited[1001] = { 0, };
	priority_queue<P, vector<P>, COMP> pq;

	dist[start] = 0;
	pq.push(P(start, 0));
	while (!pq.empty())
	{
		int currNode;
		currNode = pq.top().first;
		pq.pop();

		if (visited[currNode] == 1) continue;

		visited[currNode] = 1;
		for (int i = 0; i < cityNode[currNode].size(); i++)
		{
			int next = cityNode[currNode][i].first;
			int acost = cityNode[currNode][i].second;

			if (dist[next] > dist[currNode] + acost)
			{
				dist[next] = dist[currNode] + acost;
				pq.push(P(next, dist[next]));
			}
		}

	}

	printf("%d\n", dist[end]);
	return 0;
}