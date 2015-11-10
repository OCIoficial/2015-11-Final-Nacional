#include<bits/stdc++.h>
using namespace std;

//-1, 0 o 1 segun el signo de x
int signo(int x) {return (x > 0) - (x < 0);}

//movimientos posibles del caballo
/*  .2.1.
    3...0
    ..*..
    4...7
    .5.6.  */
//           0  1  2  3   4  5  6  7
int dx[] = {+2,+1,-1,-2, -2,-1,+1,+2};
int dy[] = {-1,-2,-2,-1, +1,+2,+2,+1};

int main() {
    //leer entrada
    int p,xi,yi,xf,yf;
    cin>>p>>xi>>yi>>xf>>yf;

    //obtener respuesta
    int ans,x,y;
    switch (p) {
        case 1: //torre
            /*  (movimiento horizontal si es necesario) +
                (movimiento vertical si es necesario)   */
            ans = (xi != xf) + (yi != yf);
        break;
        case 2: //alfil
            /*  si las casillas tienen colores distintos
                    no se puede
                si las casillas son la misma
                    se puede en cero movimientos
                si estan alineadas en una diagonal
                    se puede en un movimiento
                en cualquier otro caso
                    siempre se puede en dos movimientos */
            if ((xi + yi)%2 != (xf + yf)%2)
                ans = -1;
            else if (xi == xf and yi == yf)
                ans = 0;
            else if (abs(xf - xi) == abs(yf - yi))
                ans = 1;
            else
                ans = 2;
        break;
        case 3: //reina
            /*  si las casillas son la misma
                    se puede en cero movimientos
                si estan alineadas ortogonal o diagonal
                    se puede en un movimiento
                en cualquier otro caso
                    siempre se puede en dos movimientos */
            if (xi == xf and yi == yf)
                ans = 0;
            else if (xi == xf or yi == yf //ortogonal
            or abs(xf - xi) == abs(yf - yi)) //diagonal
                ans = 1;
            else
                ans = 2;
        break;
        case 4: //rey
            /*  la forma mas eficiente de moverse usando
                un rey es primero acercase diagonalmente
                y luego moverse ortogonal en linea recta
                hasta llegar al destino.
                Se calculan los movimientos simulando */
            ans = 0;
            x = xi, y = yi;
            while (x != xf or y != yf) { //aun no llega?
                /*  notese que esta forma con signos es
                    equivalente al algoritmo de arriba */
                x += signo(xf - x);
                y += signo(yf - y);
                ++ans;
            }
        break;
        case 5: //caballo
            /*  se modela el tablero como un grafo en
                donde cada casilla es un nodo y cada
                movimiento posible es una arista.
                Luego la minima cantidad de movimientos
                esta dada por la distancia hasta la
                casilla final segun un BFS desde la
                casilla inicial */
            int inf = 1e9; //infinito
            //inicializacion BFS
            vector<vector<int> > dist(100,
                vector<int>(100,inf));
            queue<int> qx,qy;
            qx.push(xi); qy.push(yi);
            dist[xi][yi] = 0;
            //BFS
            while (not qx.empty()) {
                //u: casilla siendo procesada
                int ux = qx.front(), uy = qy.front();
                qx.pop(); qy.pop();
                //para cada movimiento posible...
                for (int d = 0; d < 8; ++d) {
                    //v: casilla luego del movimiento
                    int vx = ux + dx[d], vy = uy + dy[d];
                    //chequeo de casilla valida
                    if (vx < 0 or vx >= 100
                    or vy < 0 or vy >= 100)
                        continue;
                    //actualizacion de nodo v
                    if (dist[vx][vy] == inf) {
                        dist[vx][vy] = dist[ux][uy] + 1;
                        qx.push(vx); qy.push(vy);
                    }
                }
            }
            //obtener respuesta luego del BFS
            ans = dist[xf][yf];
        break;
    }

    //imprimir respuesta
    cout<<ans<<endl;

    return 0;
}
