import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.parseInt(in.nextLine());
        n = (int) Math.pow(2, n);
        ArrayList<String> table = new ArrayList<>();
        ArrayList<Integer> ans = new ArrayList<>();
        ArrayList<Integer> num = new ArrayList<>();
        String s;
        for (int i = 0; i < n; i++) {
            s = in.nextLine();
            String[] ss = s.split(" ");
            table.add(ss[0]);
            num.add(Integer.parseInt(ss[1]));
        }
        for (int i = n - 1; i > -1; i--) {
            ans.add(num.get(0));
            for (int j = 0; j<i; j++){
                num.set(j, (num.get(j)+num.get(j+1))%2);
            }
        }
        for (int i=0; i<n; i++){
            System.out.print(table.get(i));
            System.out.print(" ");
            System.out.println(ans.get(i));
        }
    }
}
