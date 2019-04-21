import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer cin = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
        PrintWriter cout = new PrintWriter(new OutputStreamWriter(System.out));
        while (cin.nextToken() != StreamTokenizer.TT_EOF) {
            // //a+b
            // int a,b;
            // a=(int)cin.nval; cin.nextToken();
            // b=(int)cin.nval;
            // cout.println(a+b);

            // String a+b
            String a, b;
            a = cin.sval;
            cin.nextToken();
            b = cin.sval;
            cout.println(a + b);

            // String x, y;
            // switch (cin.ttype) {
            // case StreamTokenizer.TT_WORD:
            // x = cin.sval;
            // break;
            // case StreamTokenizer.TT_NUMBER:

            // }
        }
        cout.flush(); // don't forget!
        cout.close();
    }
}