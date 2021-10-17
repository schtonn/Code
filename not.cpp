#include "bits/stdc++.h"
using namespace std;
int n,q,c[7];
int main(){
	cin>>n;
	string s;
	cin>>s;
	cin>>q;
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		memset(c,0,sizeof(c));
		n=s.length();
		l=min(l,n);
		r=min(r,n);
		l--;
		r--;
		for(int j=l;j<=r;j++){
			c[s[j]-'a']++;
		}
		s.erase(l,r-l+1);
		int p=l;
		for(int j=0;j<7;j++){
			s.insert(p,c[j]/2,j+'a');
			p+=c[j]/2;
		}
		for(int j=0;j<7;j++){
			if(c[j]&1){
				s.insert(p,1,j+'a');
				p++;
				break;
			}
		}
		for(int j=6;j>=0;j--){
			s.insert(p,c[j]/2,j+'a');
			p+=c[j]/2;
		}
	}
	cout<<s<<endl;
	return 0;
}