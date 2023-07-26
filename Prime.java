class Prime
{
    public static void main(String args[])
    {
        int i,n,flag=0;
        n=Integer.parseInt(args[0]);
        for(i=2;i<n;i++)
        {
            if(n%i==0)
            {
               flag=1;
               break;
            }
            
        }
        if(flag==0)
        {
            System.out.println("prime");
        }
        else
        {
            System.out.println("not prime");
        }
    }
}