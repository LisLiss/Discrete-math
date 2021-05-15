import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        long[] mas = new long[n];
        ArrayList<ArrayList<Integer>> byt = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            mas[i] = in.nextLong();
        }
        long s = in.nextLong();
        if (s == 0) {
            System.out.println("1&~1");
            return;
        }
        for (int i = 0; i < n; i++) {
            if (mas[i] == s) {
                System.out.println(i + 1);
                return;
            }
        }
        for (int i = 0; i < n; i++) {
            byt.add(new ArrayList<>());
        }
        for (int i = 0; i < n; i++) {
            String xx = Long.toString(mas[i], 2);
            for (int j = xx.length() - 1; j > -1; j--) {
                byt.get(i).add(Integer.parseInt(Character.toString(xx.charAt(j))));
            }
            for (int j = xx.length(); j < 40; j++) {
                byt.get(i).add(0);
            }
        }
        ArrayList<Integer> nums = new ArrayList<>();
        String xx = Long.toString(s, 2);
        for (int j = xx.length() - 1; j > -1; j--) {
            nums.add(Integer.parseInt(Character.toString(xx.charAt(j))));
        }
        for (int j = xx.length(); j < 40; j++) {
            nums.add(0);
        }

        for (int i = 0; i < 40; i++) {
            for (int j = i + 1; j < 40; j++) {
                int jj = 0;
                while ((jj < n) && (byt.get(jj).get(i) == byt.get(jj).get(j))) {
                    jj++;
                }
                if (jj == n) {
                    if (nums.get(i) == nums.get(j)) continue;
                    System.out.println("Impossible");
                    return;
                }
            }
        }
        boolean f = false;
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < 40; i++) {
            if (nums.get(i) == 0) continue;
            if (f) ans.append("|");
            for (int j = 0; j < n; j++) {
                if (j > 0) ans.append("&");
                if (byt.get(j).get(i) == 0) {
                    ans.append("~");
                }
                ans.append(Integer.toString(j + 1));
                f = true;
            }

        }
        System.out.println(ans);
    }
}
