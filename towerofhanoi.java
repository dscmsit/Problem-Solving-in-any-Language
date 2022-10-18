import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int src = scn.nextInt();
        int dest = scn.nextInt();
        int help = scn.nextInt();
        toh(n, src,  dest,  help);
        
    }

    public static void toh(int n, int src, int dest, int help){
        if(n==0){
            return;
        }
        toh(n-1,src,help,dest);
        System.out.println(n + "[" + src + " -> "+dest + "]");
        toh(n-1,help,dest,src);
        return;

        
    }

}
