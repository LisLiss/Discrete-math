import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("mtf.in"));
        String s = in.nextLine();
        StringBuilder ans = new StringBuilder();
        ArrayList<Character> num = new ArrayList<>(), help = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            char x = 'a';
            x += i;
            num.add(x);
            help.add(x);
        }
        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            while (num.get(j) != s.charAt(i)) {
                j++;
            }
            ans.append(Integer.toString(j + 1)).append(" ");
            help.set(0, s.charAt(i));
            for (int k = 0; k < j; k++) {
                help.set(k + 1, num.get(k));
            }
            for (int k = 0; k < j + 1; k++) {
                num.set(k, help.get(k));
            }
        }
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("mtf.out")));
        out.write(new String(ans));
        in.close();
        out.close();

    }
}
