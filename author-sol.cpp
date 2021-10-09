#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, h;
		cin >> n >> h;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// find the maximum element in the sequence
		int mx = *max_element(a.begin(), a.end());
		auto Check = [&](int k) {
			// this function checks if the chosen 'k' value can make it possible to eat bananas
			// in less than or equal to 'h' hours
			int hours = 0;
			for (int i = 0; i < n; i++) {
				hours += ((a[i] + k - 1) / k);
			}
			return (hours <= h);
		};
		int low = 1;
		int high = mx;
		int ans = mx;
		// perform binary search from 1 to 'mx' (inclusive)
		while (low <= high) {
			// check every 'mid' element if it passes the condition in the Check() function
			// if yes, then limit the search to 'mid - 1' (because there might be other possible lower
			// values that can achieve the required condition)
			// otherwise, increase the range of the binary search ('mid' + 1)
			int mid = (low + high) / 2;
			if (Check(mid)) {
				ans = min(ans, mid);
				high = mid - 1;
			} else {
				low = mid + 1;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
