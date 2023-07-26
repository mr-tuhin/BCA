class AddSeries
{
    public static void main(String args[])
    {
        int i,s=0,n;
        n=Integer.parseInt(args[0]);
        for(i=1; i<= n;i++)
        {
            if(i%2!=0)
            {
                s=s+i;
            }
        }
        
            System.out.println(s);
    }
}