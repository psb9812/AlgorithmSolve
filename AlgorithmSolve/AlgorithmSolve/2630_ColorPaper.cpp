/*
백준 2630번
	색종이 만들기

풀이:
	문제를 보니 같은 꼴이 반복되는 형태라 재귀로 풀어야겠다는 생각이 들었다.
	엄청난 아이디어 없이 문제의 내용을 충실히 구현해서 풀었다.

	풀고 나서 알았는데 사실 7달 전에 풀었던 문제였다.
	7달 전 코드가 더 깔끔한 듯 해서 과거의 나에게 진 기분이었다.
*/

#include <iostream>
using namespace std;
int n;
int paper[128][128];
int countOfBlue = 0;
int countOfWhite = 0;

bool divisionCheck(int startX, int startY, int N)
{
	//분할 해야 할지 아닐지 판단
	for (int i = startY; i < startY + N; i++)
	{
		for (int j = startX; j < startX + N; j++)
		{
			if (paper[startY][startX] != paper[i][j])
			{
				return true;
			}
		}
	}
	return false;
}

void division(int startX, int startY, int N)
{
	//하지 않아도 되면 파랑 종이인지 하얀 종이인지 판단 후 재귀 탈출
	if (!divisionCheck(startX, startY, N))
	{
		if (paper[startY][startX] == 1)
			countOfBlue++;
		else if (paper[startY][startX] == 0)
			countOfWhite++;
		return;
	}

	//해야 하면 재귀 호출
	division(startX, startY, N / 2);				//1사분면
	division(startX + N / 2, startY, N / 2);		//2사분면
	division(startX + N / 2, startY + N / 2, N / 2);//3사분면
	division(startX, startY + N / 2, N / 2);		//4사분면
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	//입력 값 세팅
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> paper[i][j];
		}
	}

	division(0, 0, n);

	cout << countOfWhite << '\n' << countOfBlue;
}