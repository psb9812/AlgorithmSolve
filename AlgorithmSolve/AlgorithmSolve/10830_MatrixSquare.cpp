/*
���� 10830��


Ǯ��:
	��Ŀ� ���� ������ �����ߴ� ��...
	������Ģ�� ��Ŀ��� ������� ȥ�� �߷��ϰ�.. �����ϰ� �־���...
	�ϴ� ������ �ʹ� ũ�ϱ� ���� Ƚ���� ���� ����� �ʿ��ߴ�.

	������Ģ�� ����ǹǷ� �����ؼ� ����� ���־���.

	�׷��� ���� ���� �°� �� ¥�� �����ߴµ� ��� Ʋ���� ���Դ�...
	������ ������ ���.. �ٸ� �κ��� ���� ũ�Ƿ� �ڷ����� ulonglong���� �ߴµ�...
	������ �޴� exponents �Ű������� int�� �س��� �׷��� �ſ���...................................

	�ڱ����� ����� ����...

	�ƹ�ư �� Ǯ���� �ٸ� ������� Ǯ�̸� ���� �ٵ� �ʹ� ����ϰ� Ǫ�Ŵ�... ����е�...
	��ĳ����� ���� �׳� 3�� for������ ���� �����ϼ̴µ� ���� �� ��ͺ��� �ξ� ����ϰ� ���ɵ� ���ƺ�����.

	�ƹ�ư ū ���� ������ ������ ��� �������� Ÿ���� �����ؾ߰ڰ�.(�Ű����� ����)
	���� Ƚ���� ���� �� ���� ������ Ȱ���� �� ������ �ٽ� �� �� ������.
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
		//Ȧ���� ����̹Ƿ� �� �� �� �����ش�.
		matrixMul(result, left, matrix, 0, 0);
	}

	//������ ���� ó��
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

	//�Է� �� ����
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


	//������ ���� ó��
	for (int k = 0; k < N; k++)
	{
		for (int q = 0; q < N; q++)
		{
			answer[k][q] %= 1000;
		}
	}

	//���� ���
	for (int k = 0; k < N; k++)
	{
		for (int q = 0; q < N; q++)
		{
			cout << answer[k][q] << ' ';
		}
		cout << '\n';
	}

}