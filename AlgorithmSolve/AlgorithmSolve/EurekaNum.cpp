/*
���� 10448�� 
	����ī �̷�

Ǯ��:

	1�ʸ� 1��� �����ε� �� ������ ������ ������ ������ 1000�̴�.
	n*(n+1)/2�� 1000������ �Ƿ��� n�� �뷫 45���ϰ� �Ǿ�� �Ѵ�.

	45���� 3�����ص� �뷫 90,000 �����̹Ƿ� �θ�Ʈ ������ �����ϰ� ���ȴ�.
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