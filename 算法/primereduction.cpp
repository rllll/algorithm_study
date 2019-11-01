#include<iostream>

using namespace std;

void reverse(int& num) {
	int ans = 0;
	while (num != 0) {
		ans = ans * 10 + num % 10;
		num = num / 10;
	}
	num = ans;
}
bool isprime(int& ans, int num) {
	ans = 1;
	if (num == 1) return true;    //使1能结束循环，1本身不是素数
	if (num == 2) return true;
	int max = sqrt(num) + 1;
	for (int i = 2;i < max;i++) {
		if (num % i == 0) {
			ans = i;
			return false;
		}
	}
	return true;
}
int findstep(int num) {
	int step = 0;
	int ans = 0;
	int primal = 0;
	do {
		//cout << num << endl;
		primal = num;
		if (isprime(ans, num)) {
			reverse(num);
			if (isprime(ans, num) & (num < 10 | num >= primal)) {
				return step;
			}
			step++;
		}
		else {
			num = num / ans;
			reverse(num);
			step++;
		}
	} while (true);
}
void test(int num) {
	cout << "step:" << findstep(num) << endl;
}
void testexample() {
	test(1729);
	test(13);
	test(288);
	test(144);
	test(111);
	test(1111);
	test(1234);
}
int maxstep(int m, int n) {
	int maxstep = 0;
	int step = 0;
	for (int i = m;i <= n;i++) {
		step = findstep(i);
		if (step > maxstep)
			maxstep = step;
		if (maxstep > 1000)
			return -1;
	}
	return maxstep;
}
int main() {
	int m, n;
	cin >> m >> n;
	int ans = maxstep(m, n);
	if (ans == -1)
		cout << "Large";
	else
		cout << ans;
}