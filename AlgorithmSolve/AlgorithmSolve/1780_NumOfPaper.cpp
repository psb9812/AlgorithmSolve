/*
백준 1780번
	종이의 개수

풀이:
	이번 문제도 역시 앞에 문제와 대동소이하다.
	바뀐 부분은 3분의 1씩 잘라줘야 한다는 점.
	그 부분만 잘 바꾸면 된다.

	실수한 점은 쪼갤 때 인덱스 계산을 잘못했다.
	늘 인덱스, 경계에서 대충 이거겠지하다가 문제가 발생한다.
	이 부분을 귀찮아도 꼼꼼하게 확인하는 습관을 가져야겠다고 느꼈다.
*/

#include <iostream>
using namespace std;
int n;
int paper[2187][2187];
int countOfMinusOne = 0;
int countOfZero = 0;
int countOfOne = 0;

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
		if (paper[startY][startX] == -1)
			countOfMinusOne++;
		else if (paper[startY][startX] == 0)
			countOfZero++;
		else if (paper[startY][startX] == 1)
			countOfOne++;
		return;
	}

	//해야 하면 재귀 호출
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			division(startX + (j * N/3), startY + (i * N/3), N / 3);
		}
	}
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

	cout << countOfMinusOne << '\n' << countOfZero << '\n' << countOfOne;
}