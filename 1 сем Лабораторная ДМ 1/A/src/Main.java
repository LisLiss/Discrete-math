import com.sun.org.apache.xpath.internal.operations.Bool;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static ArrayList<Boolean> was;
    private static ArrayList<ArrayList<Boolean>> graf;
    private static ArrayList<Integer> ord;
    private static ArrayList<Integer> numComp;
    private static ArrayList<ArrayList<Boolean>> grafRev;
    private static int n;
    private static void dfs(int v) {
        was.set(v, true);
        for (int i = 0; i < 2 * n; i++) {
            if (!graf.get(v).get(i)) {
                continue;
            }
            if (!was.get(i)) {
                dfs(i);
            }
        }
        ord.add(v);
    }

    private static void dfstwo(int v, int c) {
        numComp.set(v, c);
        for (int i = 0; i < 2 * n; i++) {
            if (!grafRev.get(v).get(i)) {
                continue;
            }
            if (numComp.get(i) == -1) {
                dfstwo(i, c);
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int m = in.nextInt();
        graf = new ArrayList<>();
        grafRev = new ArrayList<>();
        for (int i = 0; i < 2 * n; i++) {
            graf.add(new ArrayList<>());
            grafRev.add(new ArrayList<>());
            for (int j = 0; j < 2 * n; j++) {
                graf.get(i).add(false);
                grafRev.get(i).add(false);
            }
        }
        int x;
        int y;
        for (int i = 0; i < m; i++) {
            x = in.nextInt();
            y = in.nextInt();
            if (x < 0) {
                if (y > 0) {
                    //x<0 y>0
                    //+x = y
                    //-y = -x
                    graf.get(-x - 1).set(y - 1, true);
                    graf.get(y + n - 1).set(-x + n - 1, true);
                    grafRev.get(y - 1).set(-x - 1, true);
                    grafRev.get(-x + n - 1).set(y + n - 1, true);
                } else {
                    //x<0 y<0
                    //+x = -y
                    //+y = -x
                    graf.get(-x - 1).set(-y + n - 1, true);
                    graf.get(-y - 1).set(-x + n - 1, true);
                    grafRev.get(-y + n - 1).set(-x - 1, true);
                    grafRev.get(-x + n - 1).set(-y - 1, true);
                }
            } else {
                if (y > 0) {
                    //x>0 y>0
                    //-x = +y
                    //-y = +x
                    graf.get(x + n - 1).set(y - 1, true);
                    graf.get(y + n - 1).set(x - 1, true);
                    grafRev.get(y - 1).set(x + n - 1, true);
                    grafRev.get(x - 1).set(y + n - 1, true);
                } else {
                    //x>0 y<0
                    //-x = -y
                    //+y = x
                    graf.get(x + n - 1).set(-y + n - 1, true);
                    graf.get(-y - 1).set(x - 1, true);
                    grafRev.get(-y + n - 1).set(x + n - 1, true);
                    grafRev.get(x - 1).set(-y - 1, true);
                }
            }
        }

        numComp = new ArrayList<>();
        ord = new ArrayList<>();
        was = new ArrayList<>();
        for (int i = 0; i < 2 * n; i++) {
            numComp.add(-1);
            was.add(false);
        }
        for (int i = 0; i < 2 * n; i++) {
            if (!was.get(i)) {
                dfs(i);
            }
        }

        int c = 0;
        for (int i = 0; i < 2 * n; i++) {
            if (numComp.get(ord.get(2 * n - i - 1)) == -1) {
                dfstwo(ord.get(2 * n - i - 1), c++);
            }
        }
        for (int i = 0; i < n; i++) {
            if (numComp.get(i)==numComp.get(i + n)) {
                System.out.println("YES");
                return;
            }
        }
        System.out.println("NO");
    }
}
