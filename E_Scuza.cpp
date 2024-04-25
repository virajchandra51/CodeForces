#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		vector<long long> v(n);
		vector<long long> pre;
		pre.push_back(0);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			pre.push_back(pre.back() + v[i]);
		}
		for (int i = 1; i < n; i++)
			v[i] = max(v[i], v[i - 1]);
		for (int i = 0; i < q; i++)
		{
			long long x;
			cin >> x;
			int low = 0;
			int high = n - 1;
			int ans = -1;
			while (low <= high)
			{
				long long mid = (low + high) / 2;
				if (v[mid] <= x)
				{
					ans = mid;
					low = mid + 1;
				}
				else
					high = mid - 1;
			}
			if (ans != -1)
				cout << pre[ans + 1] << " ";
			else
				cout << 0 << " ";
		}
		cout << endl;
	}
}