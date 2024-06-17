/*
���� 2740��
	��� ����

Ǯ��:
	����� ������� ���
	���ͳݿ� ��� �ΰ��� ���� ������ �� Ǭ ����

	�������� ����� ���� �����̾���.
	���� �����ϸ� ��.
*/

#include <iostream>
using namespace std;
int N, M, K;
int A[100][100];
int B[100][100];
int result[100][100];

void matrixMul(int LRow, int RColumn)
{
	if (RColumn == K)
		return;

	for (int i = 0; i < M; i++)
	{
		result[LRow][RColumn] += A[LRow][i] * B[i][RColumn];
	}

	if (LRow == N - 1)
	{
		LRow = -1;
		RColumn++;
	}
	matrixMul(LRow + 1, RColumn);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//�Է°� ����
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cin >> B[i][j];
		}
	}

	matrixMul(0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}