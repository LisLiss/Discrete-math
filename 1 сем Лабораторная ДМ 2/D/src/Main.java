import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("lzw.in"));
        String s = in.nextLine(), help = "";
        StringBuilder ans = new StringBuilder();
        ArrayList<String> num = new ArrayList<>();
        for (int i = 0; i < 26; i++) {
            char x = 'a';
            x += i;
            num.add(Character.toString(x));
        }
        for (int i = 0; i < s.length(); i++) {
            int j = 0;
            help += s.charAt(i);
            while (j < num.size() && !help.equals(num.get(j))) {
                j++;
            }
            if (j == num.size()) {
                int k = 0;
                String help1 = help.substring(0, help.length() - 1);
                while (!help1.equals(num.get(k))) {
                    k++;
                }
                ans.append(Integer.toString(k)).append(" ");
                num.add(help);
                help = Character.toString(s.charAt(i));
            }
        }
        int j = 0;
        while (j < num.size() && !help.equals(num.get(j))) {
            j++;
        }
        ans.append(Integer.toString(j));
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("lzw.out")));
        out.write(new String(ans));
        in.close();
        out.close();

    }
}