/*
백준 10448번 
	유레카 이론

풀이:

	1초면 1억번 연산인데 이 문제는 들어오는 숫자의 범위가 1000이다.
	n*(n+1)/2가 1000정도가 되려면 n이 대략 45이하가 되어야 한다.

	45번을 3제곱해도 대략 90,000 정도이므로 부르트 포스로 무식하게 돌렸다.
*/

#include <iostream>
using namespace std;
int T;

int Tn(int num)
{
	return num * (num + 1) / 2;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	while (T--)
	{
		int inputNum;
		bool isEurekaNum = false;
		cin >> inputNum;

		for (int i = 1; i < 45; i++)
		{
			for (int j = 1; j < 45; j++)
			{
				for (int k = 1; k < 45; k++)
				{
					if (inputNum == Tn(i) + Tn(j) + Tn(k))
					{
						cout << 1 << "\n";
						isEurekaNum = true;
						break;
					}
				}
				if (isEurekaNum)
					break;
			}
			if (isEurekaNum)
				break;
		}

		if (!isEurekaNum)
			cout << 0 << "\n";
		
	}
}