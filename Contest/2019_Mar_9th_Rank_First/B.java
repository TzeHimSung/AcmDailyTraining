import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class B {
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int t = cin.nextInt();
        for (int cnt = 1; cnt <= t; cnt++) {
            BigInteger a = cin.nextBigInteger();
            BigInteger b = cin.nextBigInteger();
            BigInteger c = cin.nextBigInteger();
            BigInteger d = cin.nextBigInteger();
            BigInteger e = a.add(b.add(c.add(d)));
            System.out.println(e);
        }
    }
}