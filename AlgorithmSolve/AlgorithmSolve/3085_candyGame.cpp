/*
���� 3085��
	 ���� ����

Ǯ��:
	������ �� ���� �� ȿ������ ��ȵ� �� ������ �ʰ� �׳� ���� ���� ���Ҵ�.
	��� ��츦 ���ؾ� �� �� ���Ƽ� ��� ��Ȳ�� �ùķ��̼��� �����ߴ�.
	�ٸ� ������δ� ���� �������� �ʾҴ�.

	�ʹٴ� �����ߴ��� �¾Ҵ�.
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
			//�� �߿��� ���� ���� ĵ��
			if (board[i][j] == board[i][j + 1])
			{
				continuousCandyRow++;
			}
			else
			{
				tempMax = max(tempMax, continuousCandyRow);
				continuousCandyRow = 1;
			}
			if (j + 1 == n - 1) //���� ������ ���
			{
				tempMax = max(tempMax, continuousCandyRow);
			}

			//�� �߿��� ���� ���� ĵ��
			if (board[j][i] == board[j + 1][i])
			{
				continuousCandyColumn++;
			}
			else
			{
				tempMax = max(tempMax, continuousCandyColumn);
				continuousCandyColumn = 1;
			}
			if (j + 1 == n - 1) //���� ������ ���
			{
				tempMax = max(tempMax, continuousCandyColumn);
			}
		}
	}

	return tempMax;
}

int main()
{
	//�Է� ���� ���� ����
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	//�ùķ��̼�
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int d = 0; d < 4; d++)
			{
				int curx = j + dx[d];
				int cury = i + dy[d];

				//���� ó��
				if (curx < 0 || cury < 0 || curx >= 50 || cury >= 50) 
					continue;
				if (board[i][j] == board[cury][curx])
					continue;

				//����
				int temp = board[i][j];
				board[i][j] = board[cury][curx];
				board[cury][curx] = temp;

				//���� ���¿��� �ִ� ĵ�� �� ���ϱ�
				maxCandy = max(maxCandy, GetMaxCandy());

				//����
				temp = board[i][j];
				board[i][j] = board[cury][curx];
				board[cury][curx] = temp;
			}
		}
	}

	cout << maxCandy;

	return 0;
}