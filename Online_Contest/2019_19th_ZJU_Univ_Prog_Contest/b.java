import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class Main {

    public static void main(String[] args) {
        Scanner cin=new Scanner(System.in);
        while (cin.hasNextInt())
        {
            int t=cin.nextInt();
            while (t-->0){
                BigInteger ans=BigInteger.ZERO;
                BigInteger x=cin.nextBigInteger();
                while (!x.equals(BigInteger.ONE)){
                    x=x.divide(BigInteger.valueOf(2));
                    ans=ans.add(x);
                }
                System.out.println(ans);
            }
        }
    }
}