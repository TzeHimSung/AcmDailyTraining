import java.util.*;
import java.lang.*;
import java.math.BigInteger;

public class Main {
    static final int maxn = 2000;
    static int[] N = new int[maxn];
    static int[] p = new int[maxn];
    static int cnt = 0, num = 0, tot = 0;
    static PQ[] A = new PQ[maxn];
    static BigInteger Limit = BigInteger.ONE;

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        sha();
        int t = cin.nextInt();
        for (int cnt = 1; cnt <= t; cnt++) {
            BigInteger x = cin.nextBigInteger();
            while (Limit.multiply(BigInteger.valueOf(p[num + 1])).compareTo(x) < 0
                    || Limit.multiply(BigInteger.valueOf(p[num + 1])).compareTo(x) == 0) {
                num++;
                Limit.multiply(BigInteger.valueOf(p[num]));
            }
            for (int i = 0; i < maxn; i++)
                A[i] = new PQ();
            dfs(0, BigInteger.ONE, 0);
            for (int i = 2; i <= tot; i++) {
                BigInteger xx = lcm(A[i].b, A[1].b);
                A[1].a.multiply(xx.divide(A[1].b));
                A[1].a.add(xx.divide(A[i].b));
                A[1].b = xx;
                BigInteger y = gcd(A[1].a, A[1].b);
                A[1].a.divide(y);
                A[1].b.divide(y);
            }
            System.out.print(A[1].b);
            System.out.print(" / ");
            System.out.println(A[1].a);
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

    static void dfs(long now, BigInteger sum, int cur) {
        if (now > num)
            return;
        A[++tot].setA(BigInteger.ONE);
        A[tot].setB(sum);
        for (int i = cur + 1; i <= num; i++) {
            if (sum.multiply(BigInteger.valueOf(p[i])).compareTo(Limit) > 0)
                continue;
            dfs(now + 1, sum.multiply(BigInteger.valueOf(p[i])), i);
        }
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