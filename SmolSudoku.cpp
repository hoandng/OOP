#include <bits/stdc++.h>

using namespace std;

int main() {
	int a[9];
	set<int> s;
	for(auto &x:a) cin >> x;
	for(auto x:a){
		if (x>=1 && x<=9)
			s.insert(x);
	}
	if(s.size()==9){
		cout<<"VALID";
	}
	else{
		cout << "INVALID";
	}
	return 0;
}

