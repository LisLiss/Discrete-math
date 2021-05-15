import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt(), k = in.nextInt();
        ArrayList<ArrayList<Integer>> num = new ArrayList<>();
        ArrayList<ArrayList<Integer>> zap = new ArrayList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        ArrayList<Boolean> edin = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            ans.add(-1);
        }
        for (int i = 0; i < k; i++) {
            num.add(new ArrayList<>());
            zap.add(new ArrayList<>());
            edin.add(false);
            for (int j = 0; j < n; j++) {
                num.get(i).add(in.nextInt());
                if (num.get(i).get(j) == -1) {
                    zap.get(i).add(-1);
                } else {
                    zap.get(i).add(-2);
                }
            }
        }
        boolean f = true;
        while (f) {
            f = false;
            for (int i = 0; i < k; i++) {
                if (edin.get(i)) {
                    continue;
                }
                int x = 0;
                int nn = 0;
                for (int j = 0; j < n; j++) {
                    if (zap.get(i).get(j) == -2) {
                        nn++;
                        x = j;
                    }
                }
                if (nn == 1) {
                    f = true;
                    ans.set(x, num.get(i).get(x));
                    for (int l = 0; l < k; l++) {
                        if (num.get(l).get(x) == 1) {
                            zap.get(l).set(x, ans.get(x));
                        } else {
                            if (num.get(l).get(x) == 0) {
                                if (ans.get(x) == 0) {
                                    zap.get(l).set(x, 1);
                                } else {
                                    zap.get(l).set(x, 0);
                                }
                            }
                        }
                    }
                    for (int l = 0; l < k; l++) {
                        boolean fEdin = false, fNul = false, fTwo = false;
                        for (int m = 0; m < n; m++) {
                            if (zap.get(l).get(m) == -1) {
                                continue;
                            }
                            if (zap.get(l).get(m) == 1) {
                                fEdin = true;
                            }
                            if (zap.get(l).get(m) == -2){
                                fTwo = true;
                            }
                            if (zap.get(l).get(m) == 0) {
                                fNul = true;
                            }
                        }
                        if (fEdin) {
                            edin.set(l, true);
                        }
                        if (fNul && !fEdin && !fTwo) {
                            System.out.println("YES");
                            return;
                        }
                    }

                }
            }
        }
        System.out.println("NO");
    }
}
