import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner in = new Scanner(new File("bwt.in"));
        String s = in.nextLine();
        ArrayList <String> mas = new ArrayList<>();
        for (int i=0; i<s.length(); i++){
            StringBuilder x = new StringBuilder();
            for (int j=0; j<s.length(); j++){
                x.append(s.charAt((i+j)%s.length()));
            }
            mas.add(new String(x));
        }
        Collections.sort(mas);
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("bwt.out")));
        for (int i=0; i<s.length(); i++){
            out.write(mas.get(i).charAt(s.length()-1));
        }
        in.close();
        out.close();
    }
}
