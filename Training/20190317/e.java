import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class Main {
    static final int maxn = 200000;
    static int[] N = new int[maxn];
    static int[] p = new int[maxn];
    static int cnt = 0, num = 0, tot = 0;
    static PQ ans = new PQ();
    static BigInteger Limit = BigInteger.ONE;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        sha();
        int t = cin.nextInt();
        for (int _cnt = 1; _cnt <= t; _cnt++) {
            num = 0;
            tot = 0;
            Limit = BigInteger.ONE;
            BigInteger x = cin.nextBigInteger();
            ans.setA(BigInteger.ONE);
            while (Limit.multiply(BigInteger.valueOf(p[num + 1])).compareTo(x) < 0
                    || Limit.multiply(BigInteger.valueOf(p[num + 1])).compareTo(x) == 0) {
                num++;
                ans.a = ans.a.multiply(BigInteger.valueOf(p[num] + 1));
                Limit = Limit.multiply(BigInteger.valueOf(p[num]));
            }
            ans.b = Limit;
            BigInteger y = gcd(ans.a, ans.b);
            ans.a = ans.a.divide(y);
            ans.b = ans.b.divide(y);
            System.out.print(ans.b);
            System.out.print("/");
            System.out.println(ans.a);
        }
    }

    static void sha() {
        N[1] = 1;
        for (int i = 2; i <= maxn - 1; i++) {
            if (N[i] == 0)
                p[++cnt] = i;
            for (int j = 1; j <= cnt; j++) {
                if (i * p[j] >= maxn)
                    break;
                N[i * p[j]] = 1;
                if (i % p[j] == 0)
                    break;
            }
        }
    }

    static BigInteger gcd(BigInteger a, BigInteger b) {
        if (a.mod(b).equals(BigInteger.ZERO))
            return b;
        else
            return gcd(b, a.mod(b));
    }

    static BigInteger lcm(BigInteger a, BigInteger b) {
        return a.multiply(b).divide(gcd(a, b));
    }
}

class PQ {
    BigInteger a, b;

    void setA(BigInteger x) {
        a = x;
    }

    void setB(BigInteger x) {
        b = x;
    }

    PQ() {
        a = BigInteger.ZERO;
        b = BigInteger.ZERO;
    }
}