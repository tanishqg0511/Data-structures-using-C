// 1
// 12
// 123
// 1234
// 12345

import java.util.*;
public class Main
{
    public static void pattern(int n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i+1;j++)
            System.out.print(j);
            System.out.println("");
        }
    }
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		pattern(n);
	}
}
