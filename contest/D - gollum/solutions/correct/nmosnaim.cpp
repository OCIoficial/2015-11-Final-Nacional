#include <iostream>
#include <vector>
using namespace std;

vector <long long> G;
int iact;

void buscar(long long x){
    if (G[iact]>=x) return;
    iact++;
    buscar(x);
    return;
}

int main(){
    long long n;
    cin >> n;
    if (n<=3){
        if (n==3) cout << 2 << endl;
        else cout << n << endl;
        return 0;
    }
    G.clear();
    G.push_back(0);
    G.push_back(1);
    G.push_back(3);
    int i = 3;
    iact=1;
    while (true){
        buscar(i);
        G.push_back(G[i-1] + iact);
        if (G[i]>=n){
            cout << i << endl;
            return 0;
        }
        i++;
    }
    return 0;
}
