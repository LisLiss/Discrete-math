import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    private static boolean saveZero(String s) {
        return s.charAt(0) == '0';
    }

    private static boolean saveOne(String s) {
        return s.charAt(s.length() - 1) == '1';
    }

    private static boolean selfDual(String s) {
        if (s.length()==1) return false;
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i)=='0'){
                if (s.charAt(s.length() - i - 1)=='0'){
                    return false;
                }
            } else {
                if (s.charAt(s.length() - i - 1) == '1') {
                    return false;
                }
            }
        }
        return true;
    }

    private static boolean monotonic(String s) {
        int i = s.length() / 2;
        while (i > 0) {
            for (int k = 0; k < s.length(); k += 2 * i) {
                for (int j = k; j < k + i; j++) {
                    if (s.charAt(j) > s.charAt(j + i)) {
                        return false;
                    }
                }
            }
            i /= 2;
        }
        return true;
    }

    private static boolean linear(String s) {
        ArrayList<Integer> ans = new ArrayList<>(), num = new ArrayList<>();
        for (int i = 0; i < s.length(); i++) {
            num.add(Integer.parseInt(Character.toString(s.charAt(i))));
        }
        for (int i = s.length() - 1; i > -1; i--) {
            ans.add(num.get(0));
            for (int j = 0; j < i; j++) {
                num.set(j, (num.get(j) + num.get(j + 1)) % 2);
            }
        }

        for (int i = 0; i < ans.size(); i++) {
            if (Integer.bitCount(i) <= 1) continue;
            if (ans.get(i) == 1) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        //int n = Integer.parseInt(in.nextLine());
        String s;
        int k=0;
        int sizze=4;
        for (int iii=0; iii<Math.pow(2,sizze); iii++) {
            s=Integer.toBinaryString(k);
            if (s.length()<sizze){
                while (s.length()!=sizze){
                    s="0"+s;
                }
            }
            k++;
            boolean[] noInPost = {false, false, false, false, false};
          //  for (int i = 0; i < n; i++) {
               // s = in.nextLine();
               // String[] mas = s.split(" ");
               // s = mas[1];
                if (!saveZero(s)) {
                    noInPost[0] = true;
                }
                if (!saveOne(s)) {
                    noInPost[1] = true;
                }
                if (!selfDual(s)) {
                    noInPost[3] = true;
                }
                if (!monotonic(s)) {
                    noInPost[2] = true;
                }
                if (!linear(s)) {
                    noInPost[4] = true;
                }
           // }
            if (noInPost[0] && !noInPost[1] && noInPost[2] && noInPost[3] && noInPost[4]) {
                System.out.println(s);
                return;
            }
        }
    }
}
