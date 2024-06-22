/*
¹éÁØ 1699¹ø
	Á¦°ö¼öÀÇ ÇÕ

Ç®ÀÌ:

*/

#include <iostream>
#include <cmath>
using namespace std;

int D[100001];
int n;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	D[0] = 0;
	D[1] = 1;

	for (int k = 2; k <= n; k++)
	{
		D[k] = k;
		for (int j = 1; j * j <= k; j++)
		{
			D[k] = min(D[k] , 1 + D[k - (j * j)]);
		}
	}

	cout << D[n];
}
