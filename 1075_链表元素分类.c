#include <iostream>
#include <vector> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct node {
	int data,next;
}list[100001];
vector<int> v[3];
int main(int argc, char** argv) {
	int n,k,start;
	scanf("%d %d %d",&start,&n,&k);
	
	int tmp;
	for(int i=0;i<n;i++) {
		scanf(" %d",&tmp);
		scanf("%d %d",&list[tmp].data,&list[tmp].next);
	}
	
	int p = start;
	while(p!=-1) {
		int data = list[p].data;
		if(data<0) v[0].push_back(p);
		else if(data>=0&&data<=k) v[1].push_back(p);
		else v[2].push_back(p);
		
		p = list[p].next;
	}
	
	int flag = 0;
	for(int i=0;i<3;i++) {
		for(int j=0;j<v[i].size();j++) {
			if(flag==0) {
				printf("%05d %d",v[i][j],list[v[i][j]].data);
				flag = 1;
			} else {
				printf(" %05d\n%05d %d",v[i][j],v[i][j],list[v[i][j]].data);
			}
		}
	}
	printf(" -1");
	return 0;
}
