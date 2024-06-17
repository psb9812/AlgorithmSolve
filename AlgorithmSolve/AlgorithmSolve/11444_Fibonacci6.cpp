/*
���� 11444��
	�Ǻ���ġ �� 6

Ǯ��:

*/

#include <iostream>
#include <map>
using namespace std;

using ull = unsigned long long;
ull n;
const ull mod = 1000000007;
ull countOfCall;
std::map < ull, ull > memo;

ull Fibo(ull n)
{
	//cout << ++countOfCall << '\n';
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;

	//�޸������̼ǿ� �����Ͱ� ���� ���
	if (memo.find(n) == memo.end())
	{
		//Ȧ��
		if (n % 2 == 1)
		{
			ull left = Fibo(n / 2 + 1);
			ull right = Fibo(n / 2);
			ull ret = (left * left + right * right) % mod;
			memo[n] =  ret;
			return ret;
		}
		else
		{
			ull half = Fibo(n / 2);
			ull right = Fibo(n / 2 - 1);
			ull left = half + right;
			ull ret =(left * half + half * right) % mod;
			memo[n] = ret;
			return ret;
		}
	}
	else
	{
		return memo[n];
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	cout << Fibo(n);
}