/*
백준 10830번


풀이:
	행렬에 관한 지식이 전무했던 나...
	지수법칙이 행렬에도 적용됨을 혼자 추론하고.. 삽질하고 있었다...
	일단 지수가 너무 크니까 수행 횟수를 줄일 방법이 필요했다.

	지수법칙이 적용되므로 분할해서 계산을 해주었다.

	그래서 얼추 논리가 맞게 잘 짜서 제출했는데 계속 틀리게 나왔다...
	한참을 뒤져본 결과.. 다른 부분은 수가 크므로 자료형을 ulonglong으로 했는데...
	지수를 받는 exponents 매개변수를 int로 해놔서 그랬던 거였다...................................

	자괴감이 들었던 문제...

	아무튼 다 풀고나서 다른 사람들의 풀이를 보니 다들 너무 깔끔하게 푸신다... 고수분들...
	행렬끼리의 곱은 그냥 3중 for문으로 많이 구현하셨는데 내가 한 재귀보다 훨씬 깔끔하고 성능도 좋아보였다.

	아무튼 큰 수가 나오는 문제는 모든 변수들의 타입을 조심해야겠고.(매개변수 조심)
	수행 횟수를 줄일 때 분할 정복을 활용할 수 있음을 다시 한 번 느낀다.
*/

#include <iostream>
#include <vector>
using namespace std;
int N;
unsigned long long B;

using Matrix = std::vector<std::vector<unsigned long long>>;

void matrixMul(Matrix& result, const Matrix& left, const Matrix& right, int LRow, int RColumn)
{
	if (RColumn == N)
		return;

	for (int i = 0; i < N; i++)
	{
		result[LRow][RColumn] += left[LRow][i] * right[i][RColumn];
	}

	if (LRow == N - 1)
	{
		LRow = -1;
		RColumn++;
	}
	matrixMul(result, left, right, LRow + 1, RColumn);
}

Matrix matrixSquare(Matrix& matrix, unsigned long long exponents)
{
	if (exponents == 1)
		return matrix;

	Matrix result(5, std::vector<unsigned long long>(5));

	if (exponents % 2 == 0)
	{
		Matrix squareMatrix(matrixSquare(matrix, exponents / 2));
		matrixMul(result, squareMatrix, squareMatrix, 0, 0);
	}
	else
	{
		exponents -= 1;
		Matrix squareMatrix(matrixSquare(matrix, exponents / 2));
		Matrix left(5, std::vector<unsigned long long>(5));
		matrixMul(left, squareMatrix, squareMatrix, 0, 0);
		//홀수인 경우이므로 한 번 더 곱해준다.
		matrixMul(result, left, matrix, 0, 0);
	}

	//나머지 연산 처리
	for (int k = 0; k < N; k++)
	{
		for (int q = 0; q < N; q++)
		{
			result[k][q] %= 1000;
		}
	}

	return result;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	Matrix inputMatrix(5, std::vector<unsigned long long>(5));

	//입력 값 세팅
	cin >> N >> B;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> inputMatrix[i][j];
		}
	}

	Matrix answer(5, std::vector<unsigned long long>(5));
	answer = matrixSquare(inputMatrix, B);


	//나머지 연산 처리
	for (int k = 0; k < N; k++)
	{
		for (int q = 0; q < N; q++)
		{
			answer[k][q] %= 1000;
		}
	}

	//정답 출력
	for (int k = 0; k < N; k++)
	{
		for (int q = 0; q < N; q++)
		{
			cout << answer[k][q] << ' ';
		}
		cout << '\n';
	}

}