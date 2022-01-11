#include <iostream>
#include <vector>
#include <cmath>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int main(int argc, char** argv) {
	int n,m;  //n个学生   m个题目 
	scanf("%d %d",&n,&m);
	
	int hash[] = {1,2,4,8,16};
	int optnum,truenum;
	char c;
	vector<int> fullscore(m),trueopt(m);
	vector<vector<int> > cnt(m,vector<int>(5));
	for(int i=0;i<m;i++) {
		scanf("%d %d %d",&fullscore[i],&optnum,&truenum);
		for(int j=0;j<truenum;j++) {
			scanf(" %c",&c);
			trueopt[i] += hash[c-'a'];
		}
	} 
	
	int tmp;
	int opt[1001][101]={0};
	for(int i=0;i<n;i++) {   //very important
		double grade=0;
		for(int j=0;j<m;j++) {
			getchar();
			scanf("(%d",&tmp);
			for(int k=0;k<tmp;k++) {
				scanf(" %c)",&c);
				opt[i][j] += hash[c-'a'];
			}
			int el = opt[i][j] ^ trueopt[j];
			if(el) {
				if((opt[i][j] | trueopt[j])==trueopt[j]) {
					grade += fullscore[j] * 1.0 / 2;
				}
				for(int k=0;k<5;k++) {
					if(el & hash[k]) cnt[j][k]++;
				}
			} else {
				grade += fullscore[j];
			}
		}
		printf("%.1f\n",grade);
	}
	
	int maxcnt = 0;
	for(int i=0;i<m;i++) {
		for(int j=0;j<5;j++) {
			maxcnt = maxcnt>cnt[i][j]?maxcnt:cnt[i][j];
		}
	}
	
	if(maxcnt==0) {
		printf("Too simple\n");
	} else {
		for(int i=0;i<m;i++) {
			for(int j=0;j<cnt[i].size();j++) {
				if(maxcnt==cnt[i][j]) {
					printf("%d %d-%c\n",maxcnt,i+1,'a'+j);
				}
			}
		}
	}
	
	return 0;
}
