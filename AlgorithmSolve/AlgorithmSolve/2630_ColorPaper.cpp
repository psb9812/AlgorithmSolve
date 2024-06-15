/*
���� 2630��
	������ �����

Ǯ��:
	������ ���� ���� ���� �ݺ��Ǵ� ���¶� ��ͷ� Ǯ��߰ڴٴ� ������ �����.
	��û�� ���̵�� ���� ������ ������ ����� �����ؼ� Ǯ����.

	Ǯ�� ���� �˾Ҵµ� ��� 7�� ���� Ǯ���� ��������.
	7�� �� �ڵ尡 �� ����� �� �ؼ� ������ ������ �� ����̾���.
*/

#include <iostream>
using namespace std;
int n;
int paper[128][128];
int countOfBlue = 0;
int countOfWhite = 0;

bool divisionCheck(int startX, int startY, int N)
{
	//���� �ؾ� ���� �ƴ��� �Ǵ�
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
	//���� �ʾƵ� �Ǹ� �Ķ� �������� �Ͼ� �������� �Ǵ� �� ��� Ż��
	if (!divisionCheck(startX, startY, N))
	{
		if (paper[startY][startX] == 1)
			countOfBlue++;
		else if (paper[startY][startX] == 0)
			countOfWhite++;
		return;
	}

	//�ؾ� �ϸ� ��� ȣ��
	division(startX, startY, N / 2);				//1��и�
	division(startX + N / 2, startY, N / 2);		//2��и�
	division(startX + N / 2, startY + N / 2, N / 2);//3��и�
	division(startX, startY + N / 2, N / 2);		//4��и�
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	//�Է� �� ����
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