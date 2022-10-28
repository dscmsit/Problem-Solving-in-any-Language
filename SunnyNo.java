import java.util.*;
public class SunnyNo {

	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		System.out.print("Enter Number: ");
		int N=sc.nextInt();
	
		int m=(N+1);
		int n=m/4;
		int s=0;
		for(int i=1;i<n;i++)
		{
			if((m/i)==i)
			{	System.out.print(N+ " is Sunny Number");
				s=1;
				break;
			}
		}
		if(s==0){
			System.out.print(N+ " is not Sunny Number");
		}
		

	}
}