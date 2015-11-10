#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int P, Xi, Yi, Xf, Yf;
vector <vector <int> > tablero;
queue <pair<int,int> > q;

void check(int x, int y, int a, int b){
    if (x<0 || x >99 || y<0 || y>99) return;
    if (tablero[x][y]==0){
        q.push(pair<int,int>(x,y));
        tablero[x][y]=tablero[a][b] + 1;
    }
    return;
}


int main(){
    cin >> P >> Xi >> Yi >> Xf >> Yf;
    tablero.assign(100,vector<int>(100,0));
    if (Xi==Xf && Yi==Yf){
        cout << 0 << endl;
        return 0;
    }
    if (P==1){ //TORRE
        if (Xi==Xf || Yi==Yf) cout << 1;
        else cout << 2;
        cout << endl;
        return 0;
    }
    if (P==2){//ALFIL
        int p = Xi%2==0 + Yi%2==0; //0 o 2 versus 1
        int q = Xf%2==0 + Yf%2==0;
        if (p%2!=q%2) cout << -1;
        else {
            if (abs(Yf-Yi)==abs(Xf-Xi)) cout << 1;
            else cout << 2;
        }
        cout << endl;
        return 0;
    }
    if (P==3){//REINA
        if (Xi==Xf || Yi==Yf || abs(Yf-Yi)==abs(Xf-Xi)) cout << 1;
        else cout << 2;
        cout << endl;
        return 0;
    }
    if (P==4){ // REY
        cout << max(abs(Xf-Xi),abs(Yf-Yi)) << endl;
    }
    if (P==5){ //CABALLO
        pair<int,int>F = pair<int,int>(Xf,Yf);
        q.push(pair<int,int>(Xi,Yi));
        while (!q.empty()){
            pair<int,int> act = q.front();
            q.pop();
            if (act==F){
                cout << tablero[act.first][act.second] << endl;
                return 0;
            }
            int x = act.first, y = act.second;
            check(x-2,y-1,x,y);
            check(x-2,y+1,x,y);
            check(x+2,y-1,x,y);
            check(x+2,y+1,x,y);
            check(x-1,y+2,x,y);
            check(x-1,y-2,x,y);
            check(x+1,y+2,x,y);
            check(x+1,y-2,x,y);
        }
    }
    return 0;
}
