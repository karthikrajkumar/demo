/*?????.cpp
 *Created on: 2012-11-16
 * Author: ??
 */
int apple(int n, int k) {
	int a[n + 1];//?i????????
	a[n] = n + k;//??????????n+k????????1?
	while (1) {
		for (int i = n; i > 1; i--) {
			if (a[i] % (n-1) != 0) {//????????%n-1??0
				a[n] += n;
				break;//?????????????????n
			}
			a[i - 1] = a[i] / (n - 1) * n + k;//???????????
			if (i == 2)//??????
				return a[1];//??????????????
		}
	}
}
int main() {
	int n, k;
	cin >> n >> k;
	cout << apple(n, k);
	return 0;
}