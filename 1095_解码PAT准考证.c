#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct node {
	string t;
	int score;
};
bool cmp(const node &a,const node &b) {
	return a.score!=b.score?a.score>b.score:a.t<b.t;
}
int main(int argc, char** argv) {
	int n,k,num;
	string s;
	cin>>n>>k;
	vector<node> v(n);
	for(int i=0;i<n;i++) {
		cin>>v[i].t>>v[i].score;
	}
	for(int i=1;i<=k;i++) {
		cin>>num>>s;
		printf("Case %d: %d %s\n",i,num,s.c_str());
		vector<node> ans;
		int cnt=0,sum=0;
		if(num==1) {
			for(int j=0;j<n;j++) {
				if(v[j].t[0]==s[0]) ans.push_back(v[j]);
			}
		} else if(num==2) {
			for(int j=0;j<n;j++) {
				if(v[j].t.substr(1,3)==s) {
					cnt++;
					sum += v[j].score;
				}
			}
			if(cnt!=0) printf("%d %d\n",cnt,sum);
		} else if(num==3) {
			unordered_map<string,int> mp;
			for(int j=0;j<n;j++) {
				if(v[j].t.substr(4,6)==s) {
					mp[v[j].t.substr(1,3)]++;
				}
			}
			for(auto it:mp) ans.push_back({it.first,it.second});
		}
		sort(ans.begin(),ans.end(),cmp);
		for(int j=0;j<ans.size();j++) {
			printf("%s %d\n",ans[j].t.c_str(),ans[j].score);
		}
        if (((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt == 0)) printf("NA\n");
	} 
	
	return 0;
}
