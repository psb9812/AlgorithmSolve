/*
백준 11444번
	피보나치 수 6

풀이:
	문제에서 최대 백 경번째의 피보나치 수를 1초안에 구하라고 한다...
 	단순한 재귀로 피보나치 수를 구하는 방법은 무조건 시간 초과임을 직감!
  	분할 정복을 해야겠다고 생각했다.
   	분할을 어떻게 해야 하나하고 피보나치 수를 차례대로 적어가면서 고민하다가
    	유의미한 식을 발견했다.

	k <= n - 1
     	F(n) = F(n - k + 1) * F(n - k) + F(n - k) * F(n - k - 1)
      	여기서 k 를  n/2로 해서 절반씩 줄여나가면 O(logN)의 시간 복잡도로 처리할 수 있을 것 같았다.
       	바로 구현 후 제출했는데 시간초과가 났다.

 	중복 계산이 많았기 때문이다.
  	바로 map을 이용해서 메모이제이션으로 최적화 해주었더니 정답이었다.

   	문제 조건을 보고 어떻게 풀어야 하는지 추론한 뒤 수학적인 발견으로 문제를 풀 수 있었다.
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

	//메모이제이션에 데이터가 없는 경우
	if (memo.find(n) == memo.end())
	{
		//홀수
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
