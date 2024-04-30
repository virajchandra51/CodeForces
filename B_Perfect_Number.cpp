#include <bits/stdc++.h>
using namespace std;

int cal(int num){
	int sum = 0;
	while (num>0){
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

int main(){
    int k;
	cin>>k;
	int ans = 1;
	while (k>0){
		ans++;
		if (cal(ans) == 10) k--;
	}
	cout<<ans<<endl;
}