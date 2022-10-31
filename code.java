import java.util.*;
public class code{
    public static boolean IsAnagram(String str1, String str2){
        int n1 = str1.length();
        int n2 = str2.length();
        if(n1!=n2){
            return false;
        }
        char temp1[] = str1.toCharArray();
        char temp2[] = str2.toCharArray();
        Arrays.sort(temp1);
        Arrays.sort(temp2);
        return Arrays.equals(temp1, temp2);
    }
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String str1 = sc.next();
        System.out.print("Enter the anagram: ");
        String str2 = sc.next();
        str1 = str1.toLowerCase();
        str2 = str2.toLowerCase();
        if(IsAnagram(str1,str2)){
            System.out.println("Yes, it is a anagram");
        }
        else{
            System.out.println("No, it is not a anagram");
        }
        sc.close();
    }
}