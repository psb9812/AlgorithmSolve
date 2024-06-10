/*
백준 2503번
	숫자 야구

풀이:
	혼자 고민 많이 하다가
	너무 오래 걸려서 답을 봤다.

	떠올리지 못한 아이디어는 "문자열로 바꿔서 편하게 인덱스로 자리수를 구하는 것"과
	"수의 범위가 작으니 bool 배열로 가능한 수 쫙 뽑아놓고 지워나가는 방식"이었다.

	배울 걸 잘 챙길 수 있었던 문제였다.
*/

#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
int T;

//가능한 최대 수는 987이므로 987 + 1개의 배열을 만든다.
bool possibleNums[988];

//100의 자리 리턴하는 함수
int NumOf100(int num)
{
	return (num / 100);
}
//10의 자리 리턴하는 함수
int NumOf10(int num)
{
	return (num % 100) / 10;
}
//1의 자리 리턴하는 함수
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

	//기본적으로 true로 초기화
	memset(possibleNums, true, sizeof(possibleNums));

	cin >> T;


	//0이 들어가거나 중복수가 들어간 인덱스를 false로 한다.
	for (int i = 123; i < 988; i++)
	{
		//0이 들어가있는 경우
		if (IsContainNum(i, 0))
		{
			possibleNums[i] = false;
			continue;
		}
		//중복수가 들어가 있는 경우.
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