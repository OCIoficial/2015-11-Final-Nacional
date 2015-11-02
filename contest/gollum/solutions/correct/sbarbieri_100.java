import java.util.Scanner;

class sbarbieri_100 {
	//V[n] guarda el primer entero k tal que G(k)=n. Notar que V[n+1]=V[n]+G(n)
	//Dados los casos de prueba, se puede ver que el crecimiento de G(n) es lento,
  //pero no tanto como para guardar V[n] hasta poder calcular G(10^15).
	//Para ganarle a la restriccion en memoria, es posible guardar V[n] solo hasta
  // un valor mas chico, y avanzar con dos valores de ahi en adelante.
	//de esta manera k representa la iteracion sobre n, y l el valor actual de G(n)
  // (que crece muy lentamente)
	//los valores act y ant representan V[k] y V[k-1] respectivamente
	//para encontrar el valor de val, neceitamos que V[n+1] > val >= V[n], de este
  //modo G(val) = n.
	//Los casos de prueba del enunciado indican que G(10^15)=2240208500	y
  //G(2240208500)=722258
	//Asi sabemos que basta guardar valores en V hasta 722258.
	//Tecnicamente, k y l podrian ser ints (dado los valores de casos de prueba).
	//
	//Este problema fue inspirado por https://projecteuler.net/problem=341
	//
	//Sebastian Barbieri. 
	public static void main(String[] args) {
		long [] V = new long[722261];
		Scanner in = new Scanner(System.in);
		V[0]=0; V[1]=1;
		long k,l,val,ant,act;
		k = 1;
		l = 1;
		val = in.nextLong();
		ant = 1;
		while(true){
			k++;
			act = ant+l;
			if( val >= ant && val < act){
				System.out.println((k-1)); 
				break;
			}
			ant = act;
			if(k < V.length){V[(int)k]= act;}
			if(V[(int) l+1]==k){l++;}
		}
	}
}
