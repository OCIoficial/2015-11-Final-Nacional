import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class generad2 {
	public static void main(String[] args) throws FileNotFoundException {
		int M = 722261;
		long [] V = new long[M];
		Scanner in = new Scanner(System.in);
		V[0]=0; V[1]=1;
		long k,l,val,ant,act;
		// long[] x = {0,10,30,42,78,99,1000,10000,245003,987654,1000000,
    //             Long.parseLong("1000000000000000"), Long.parseLong("1000235400"),
    //             Long.parseLong("156449846423"), Long.parseLong("919987654003207"),
    //             Long.parseLong("12340090900870")};
		long[] x = {0,
                1, 2, 10, 15, 25,
                100, 200, 333, 999, 100000,
                800025030, 1007004500, 2000235400, Long.parseLong("5002041000"), Long.parseLong("10000000000")};
		String caso="";
		for (int i = 1; i <= 15; i++) {
			if(i <= 9){caso = "0"+i;}
			else {
				caso = ""+i;
			}
			PrintWriter PP = new PrintWriter(caso+".in");
			PP.println(x[i]);
			PP.close();
			// PrintWriter OO = new PrintWriter(caso+".sol");
			// k = 1;
			// l = 1;
			// val = x[i];
			// ant = 1;
			// while(true){
			// 	k++;
			// 	act = ant+l;
			// 	if( val >= ant && val < act){
			// 		OO.println(k-1); 
			// 		break;
			// 	}
			// 	ant = act;
			// 	if(k < V.length-1){V[(int)k]= act;}
			// 	if(V[(int) l+1]==k){l++;}
			// }
			// OO.close();
		}
	}
}
