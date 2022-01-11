#include <iostream>
#include <vector>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
bool cmp(int a,int b) {
	return a>b;
}
int main(int argc, char** argv) {
	int n,tmp;
	vector<int> a;
	
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>tmp;
		a.push_back(tmp);
	}
	sort(a.begin(),a.end(),cmp);
	int ans=0,p=0;
	while(ans<=n&&a[p]>p+1) {
		ans++;
		p++;
	}
	cout<<ans;
	return 0;
}
