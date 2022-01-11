#include <iostream>
#include <cstring> 
using namespace std;
int main(int argc, char** argv) {
	int count;
	bool flag;
	int np,na,nt;
	int loc_p,loc_t;
	int pre,in,post;
	string str;
	
	cin>>count;
	for(int i=0;i<count;i++) {
		flag = true;
		np = na = nt = 0;
		loc_p = loc_t = 0;
		
		cin>>str;
		
		for(int j=0;j<str.length();j++) {
			switch(str[j]) {
				case 'P':np++;loc_p = j;break;
				case 'A':na++;break;
				case 'T':nt++;loc_t = j;break;
				default:flag = false;break;
			}
		}
		
		pre = loc_p;
		in = loc_t - loc_p - 1;
		post = str.length() - loc_t - 1;
		
		if((np==1)&&(nt==1)&&(flag)&&na&&(loc_p < loc_t)&&(pre*in==post)) {
			cout<<"YES"<<endl;
		}else {
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
