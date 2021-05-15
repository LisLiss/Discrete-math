import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new File("huffman.in"));
        int n = in.nextInt();
        ArrayList<Long> s1 = new ArrayList<>(), s2 = new ArrayList<>();
        long inf = 2000000000001L;
        for (int i = 0; i < n; i++) {
            s1.add(in.nextLong());
            s2.add(inf);
        }
        Collections.sort(s1);
        s1.add(inf);
        s1.add(inf);
        s2.add(inf);
        s2.add(inf);
        int is1 = 0, is2 = 0;
        long a1, a2, b1, b2, ans = 0;
        for (int k = 0; k < n - 1; k++) {
            a1 = s1.get(is1);
            a2 = s1.get(is1 + 1);
            b1 = s2.get(is2);
            b2 = s2.get(is2 + 1);
            if (a2 <= b1) {
                s2.set(k, a1 + a2);
                is1 += 2;
            } else {
                if (a1 <= b2) {
                    s2.set(k, a1 + b1);
                    is1++;
                    is2++;
                } else {
                    s2.set(k, b1 + b2);
                    is2 += 2;
                }
            }
            ans += s2.get(k);
        }
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("huffman.out")));
        out.write(Long.toString(ans));
        in.close();
        out.close();
    }
}
