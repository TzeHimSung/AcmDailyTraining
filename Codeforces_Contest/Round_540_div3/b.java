import java.util.*;

public class Main {
    public static void main(String[] args) {
        final int maxn = 200010;
        Scanner cin = new Scanner(System.in);
        int n = cin.nextInt();
        int[] odd = new int[maxn];
        int[] even = new int[maxn];
        for (int i = 1; i <= n; i++) {
            int x = cin.nextInt();
            odd[i] = odd[i - 1];
            even[i] = even[i - 1];
            if (i % 2 == 0)
                odd[i] += x;
            else
                even[i] += x;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            if (odd[i - 1] + even[n] - even[i] == even[i - 1] + odd[n] - odd[i])
                ans++;
        System.out.println(ans);
        cin.close();
    }
}