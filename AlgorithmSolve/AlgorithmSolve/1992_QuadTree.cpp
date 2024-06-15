/*
���� 1992��
	���� Ʈ��

Ǯ��:
	������ �дٰ� ��� Ǯ���� 2630 ������ ������ ������ �������� �˾Ҵ�.
	���� ��ͷ� Ǯ�� �ȴ�.
	�Է� ��İ� ��� ��ĸ� �ٸ��� �ϰ� 1->2->4->3 ��и� ������� �� ���� �����ؼ� ����ϸ� Ǯ �� �ִ� �����̴�.
*/

#include <iostream>
using namespace std;
int n;
string board[64];


bool divisionCheck(int startX, int startY, int N)
{
	//���� �ؾ� ���� �ƴ��� �Ǵ�
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
	//���� �ʾƵ� �Ǹ� �Ķ� �������� �Ͼ� �������� �Ǵ� �� ��� Ż��
	if (!divisionCheck(startX, startY, N))
	{
		if (board[startY][startX] == '0')
			cout << '0';
		else if (board[startY][startX] == '1')
			cout << '1';
		return;
	}

	//�ؾ� �ϸ� ��� ȣ��
	cout << '(';
	division(startX, startY, N / 2);				//1��и�
	division(startX + N / 2, startY, N / 2);		//2��и�
	division(startX, startY + N / 2, N / 2);		//4��и�
	division(startX + N / 2, startY + N / 2, N / 2);//3��и�
	cout << ')';
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
		cin >> board[i];
	}

	division(0, 0, n);
}