import java.util.*;
public class Automorphic{
    static boolean test(int num) {

        int square = num*num;
        while(num>0){
            if(num%10 != square%10){
                return false;
            }
            num/=10;
            square/=10;
        }
    return true;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Number to Check: ");
        int N = sc.nextInt();
        System.out.println(test(N) ? "Automorphic" : "Not Automorphic");
    }
}