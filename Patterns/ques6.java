// 12345
// 1234
// 123
// 12
// 1

import java.util.*;
public class Main
{
    public static void pattern(int n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n-i;j++)
            System.out.print(j+1);
            System.out.println("");
        }
    }
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		pattern(n);
	}
}