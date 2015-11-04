#include <iostream>
using namespace std;

static int n,p,a,b;

int main(){
	int res;
	cin >> n >> p;
	cin >> a >> b;
	int ra=(n+a-1)/a;
	int rb=(n+b-1)/b;
	if (ra==rb) cout << p << endl;
	else{
		if (ra<rb) cout << 0 << endl;
		else cout << 1 << endl;
	}
	return 0;
}