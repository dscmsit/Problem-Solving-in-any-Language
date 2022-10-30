class mirrorReflection {
    public int mirrorReflection(int p, int q) {
        if (q==0) return 0;
        int lcm = (p*q)/gcd(p, q);
        int m = lcm/p;
        int n = lcm/q;
        if(m%2==0 && n%2==1) return 0;
        if(m%2==1 && n%2==1) return 1;
        if(m%2==1 && n%2==0) return 2;
        return 0;
    }
    
    public int gcd(int a,int b)
    {
        if (a==b) return a;
        if (a<=0) return b;
        if (b<=0) return a;
        
        if (a<b)
        {
            return gcd(b-a,a);
        }
        else
        {
            return gcd(a-b,b);
        }
    }
}