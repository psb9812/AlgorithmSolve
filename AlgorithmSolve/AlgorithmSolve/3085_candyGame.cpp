/*
백준 3085번
	 사탕 게임

풀이:
	문제를 딱 봤을 때 효율적인 방안도 잘 보이지 않고 그냥 구현 문제 같았다.
	모든 경우를 구해야 할 것 같아서 모든 상황의 시뮬레이션을 구현했다.
	다른 방법으로는 딱히 떠오르지 않았다.

	와다다 구현했더니 맞았다.
*/
#include <iostream>
using namespace std;

char board[50][50];
int n;
int maxCandy;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int GetMaxCandy()
{
	int tempMax = 0;

	for (int i = 0; i < n; i++)
	{
			int continuousCandyRow = 1;
			int continuousCandyColumn = 1;
		for (int j = 0; j < n - 1; j++)	
		{
			//행 중에서 가장 많은 캔디
			if (board[i][j] == board[i][j + 1])
			{
				continuousCandyRow++;
			}
			else
			{
				tempMax = max(tempMax, continuousCandyRow);
				continuousCandyRow = 1;
			}
			if (j + 1 == n - 1) //끝에 도달한 경우
			{
				tempMax = max(tempMax, continuousCandyRow);
			}

			//열 중에서 가장 많은 캔디
			if (board[j][i] == board[j + 1][i])
			{
				continuousCandyColumn++;
			}
			else
			{
				tempMax = max(tempMax, continuousCandyColumn);
				continuousCandyColumn = 1;
			}
			if (j + 1 == n - 1) //끝에 도달한 경우
			{
				tempMax = max(tempMax, continuousCandyColumn);
			}
		}
	}

	return tempMax;
}

int main()
{
	//입력 받은 보드 세팅
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	//시뮬레이션
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int curx = j + dx[d];
				int cury = i + dy[d];

				//예외 처리
				if (curx < 0 || cury < 0 || curx >= 50 || cury >= 50) 
					continue;
				if (board[i][j] == board[cury][curx])
					continue;

				//스왑
				int temp = board[i][j];
				board[i][j] = board[cury][curx];
				board[cury][curx] = temp;

				//현재 상태에서 최대 캔디 수 구하기
				maxCandy = max(maxCandy, GetMaxCandy());

				//복구
				temp = board[i][j];
				board[i][j] = board[cury][curx];
				board[cury][curx] = temp;
			}
		}
	}

	cout << maxCandy;

	return 0;
}