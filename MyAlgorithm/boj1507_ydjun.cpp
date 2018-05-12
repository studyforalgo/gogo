#include <stdio.h>

int map[21][21];
bool eliminate[21][21];
int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &map[i][j]);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (map[i][j] > map[i][k] + map[k][j])
					return printf("-1\n"), 0;
				if (i == j || j == k || k == i) continue;
				if (map[i][j] == map[i][k] + map[k][j])
					eliminate[i][j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			if (!eliminate[i][j])ans += map[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}