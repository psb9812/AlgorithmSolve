/*
백준 1992번
	쿼드 트리

풀이:
	문제를 읽다가 방금 풀었던 2630 색종이 만들기와 동일한 문제임을 알았다.
	역시 재귀로 풀면 된다.
	입력 방식과 출력 방식만 다르게 하고 1->2->4->3 사분면 순서대로 잘 분할 정복해서 출력하면 풀 수 있는 문제이다.
*/

#include <iostream>
using namespace std;
int n;
string board[64];


bool divisionCheck(int startX, int startY, int N)
{
	//분할 해야 할지 아닐지 판단
	for (int i = startY; i < startY + N; i++)
	{
		for (int j = startX; j < startX + N; j++)
		{
			if (board[startY][startX] != board[i][j])
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
		if (board[startY][startX] == '0')
			cout << '0';
		else if (board[startY][startX] == '1')
			cout << '1';
		return;
	}

	//해야 하면 재귀 호출
	cout << '(';
	division(startX, startY, N / 2);				//1사분면
	division(startX + N / 2, startY, N / 2);		//2사분면
	division(startX, startY + N / 2, N / 2);		//4사분면
	division(startX + N / 2, startY + N / 2, N / 2);//3사분면
	cout << ')';
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
		cin >> board[i];
	}

	division(0, 0, n);
}