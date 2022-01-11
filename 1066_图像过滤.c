#include <iostream>   //尽量使用C语言输入  c++可能会导致超时 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int main(int argc, char** argv) {
	int row,col;
	int a,b;
	int last;
	scanf("%d%d%d%d%d",&row,&col,&a,&b,&last);
	
	int tmp;
	for(int i=0;i<row;i++) {
		for(int j=0;j<col;j++) {
			scanf("%d",&tmp);
			if(j!=0) cout<<" ";
			if(tmp>=a&&tmp<=b) printf("%03d",last);
			else printf("%03d",tmp);
		}
		cout<<endl;
	}
	
	return 0;
}
