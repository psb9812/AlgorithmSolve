/*
백준 2740번
	행렬 곱셈

풀이:
	행렬을 배운적이 없어서
	인터넷에 행렬 인강을 보고 이해한 후 푼 문제

	생각보다 어렵진 않은 개념이었다.
	그저 구현하면 됨.
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

	//입력값 세팅
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
