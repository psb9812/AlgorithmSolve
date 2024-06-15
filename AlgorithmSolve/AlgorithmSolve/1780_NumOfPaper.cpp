/*
���� 1780��
	������ ����

Ǯ��:
	�̹� ������ ���� �տ� ������ �뵿�����ϴ�.
	�ٲ� �κ��� 3���� 1�� �߶���� �Ѵٴ� ��.
	�� �κи� �� �ٲٸ� �ȴ�.

	�Ǽ��� ���� �ɰ� �� �ε��� ����� �߸��ߴ�.
	�� �ε���, ��迡�� ���� �̰Ű����ϴٰ� ������ �߻��Ѵ�.
	�� �κ��� �����Ƶ� �Ĳ��ϰ� Ȯ���ϴ� ������ �����߰ڴٰ� ������.
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
		if (paper[startY][startX] == -1)
			countOfMinusOne++;
		else if (paper[startY][startX] == 0)
			countOfZero++;
		else if (paper[startY][startX] == 1)
			countOfOne++;
		return;
	}

	//�ؾ� �ϸ� ��� ȣ��
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
	//�Է� �� ����
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