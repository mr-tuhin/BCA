import java.lang.Math;
class  Armstrong
{
    public static void main(String args[])
    {
        int n,i,s=0, original,n1, c=0,r;


        n=Integer.parseInt(args[0]);
        n1=n;

        // lenth calculation
        while(n!=0)
        {
            r=n%10 ;
            c=c+1;
            n=n/10;
            
        }

        n=n1;
        // processing
        while(n!=0)
        {
            r=n%10;
            s= s+ (int) (Math.pow(r,c));
            n=n/10;
        }

        if(s==n1)
        {
            System.out.println("Armstrong");
        }
        else
        {
            System.out.println("Not Armstrong");
        }
    }
}