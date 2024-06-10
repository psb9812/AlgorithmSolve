/*
���� 2503��
	���� �߱�

Ǯ��:
	ȥ�� ��� ���� �ϴٰ�
	�ʹ� ���� �ɷ��� ���� �ô�.

	���ø��� ���� ���̵��� "���ڿ��� �ٲ㼭 ���ϰ� �ε����� �ڸ����� ���ϴ� ��"��
	"���� ������ ������ bool �迭�� ������ �� �� �̾Ƴ��� ���������� ���"�̾���.

	��� �� �� ì�� �� �־��� ��������.
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int T;

//������ �ִ� ���� 987�̹Ƿ� 987 + 1���� �迭�� �����.
bool possibleNums[988];

//100�� �ڸ� �����ϴ� �Լ�
int NumOf100(int num)
{
	return (num / 100);
}
//10�� �ڸ� �����ϴ� �Լ�
int NumOf10(int num)
{
	return (num % 100) / 10;
}
//1�� �ڸ� �����ϴ� �Լ�
int NumOf1(int num)
{
	return num % 10;
}

bool IsContainNum(int num, int contain)
{
	if (contain == NumOf100(num))
		return true;
	else if (contain == NumOf10(num))
		return true;
	else if (contain == NumOf1(num))
		return true;
	else
		return false;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//�⺻������ true�� �ʱ�ȭ
	memset(possibleNums, true, sizeof(possibleNums));

	cin >> T;


	//0�� ���ų� �ߺ����� �� �ε����� false�� �Ѵ�.
	for (int i = 123; i < 988; i++)
	{
		//0�� ���ִ� ���
		if (IsContainNum(i, 0))
		{
			possibleNums[i] = false;
			continue;
		}
		//�ߺ����� �� �ִ� ���.
		if (NumOf1(i) == NumOf10(i) || NumOf1(i) == NumOf100(i) || NumOf10(i) == NumOf100(i))
			possibleNums[i] = false;
	}

	while (T--)
	{
		int number, strike, ball;
		cin >> number >> strike >> ball;

		for (int i = 123; i < 988; i++)
		{
			int sCount = 0; int bCount = 0;

			if (possibleNums[i])
			{
				string compareNum1 = to_string(number);
				string compareNum2 = to_string(i);

				for (int a = 0; a < 3; a++) {
					for (int b = 0; b < 3; b++) {
						if (a == b && compareNum1[a] == compareNum2[b]) sCount++;
						if (a != b && compareNum1[a] == compareNum2[b]) bCount++;
					}
				}

				if (sCount != strike || bCount != ball) possibleNums[i] = false;
			}
		}
	}

	int ans = 0;
	for (int i = 123; i < 988; i++)
	{
		if (possibleNums[i])
			ans++;
	}

	cout << ans;
}