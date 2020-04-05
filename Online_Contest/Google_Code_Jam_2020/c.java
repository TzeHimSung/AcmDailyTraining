import java.util.*;
import java.io.*;
import java.lang.Math;

public class Solution {
	public static void main (String[] args) {
		Scanner cin = new Scanner(new BufferedReader(new InputStreamReader(System.cin)));
		int T = cin.nextInt();
		for (int __case = 1; __case <= T; __case++) {
            System.out.print("Case #" + __case + ": ");
			boolean flag = false;
			int n = cin.nextInt();
			int totActivity = 0;
			int[][] timelist = new int[1440][2];
			int[][] answerKey = new int[n][2];
			int[][] activity = new int[n][3];
			for (int i = 0; i < n; i++) {
				activity[i][0] = cin.nextInt();
				activity[i][1] = cin.nextInt();
				activity[i][2] = totActivity++;
			}
			Arrays.sort(activity, new java.util.Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return Integer.compare(a[0], b[0]);
				}
			});
			for (int i = 0; i < n; i++) {
				boolean cOK = true, jOK = true;
				for (int k = activity[i][0]; k < activity[i][1]; k++) {
					if (timelist[k][0] == 1) {
						cOK = false;
					}
				}
				if (cOK) {
					for (int k = activity[i][0]; k < activity[i][1]; k++) {
						timelist[k][0] = 1;
					}
					answerKey[i] = new int[] {activity[i][2], 1};
				} else {
					for (int k = activity[i][0]; k < activity[i][1]; k++) {
						if (timelist[k][1] == 1) {
							jOK = false;
						}
					}
					if (jOK) {
						for (int k = activity[i][0]; k < activity[i][1]; k++) {
							timelist[k][1] = 1;
						}
						answerKey[i] = new int[] {activity[i][2], 2};
					} else {
						flag = true;
					}
				}
			}
			String answer = "";
			if (flag) {
				answer = "IMPOSSIBLE";
			} else {
				Arrays.sort(answerKey, new java.util.Comparator<int[]>() {
					public int compare(int[] a, int[] b) {
						return Integer.compare(a[0], b[0]);
					}
				});
				for (int i = 0; i < answerKey.length; i++) {
					if (answerKey[i][1] == 1) {
						answer += "C";
					} else if (answerKey[i][1] == 2) {
						answer += "J";
					}
				}
			}
			System.out.println(answer);
		}
	}
}