vector<int> primefactors(int a)
{
    vector<int> primefactors;
    for(int i=1;i<=a;++i)
        if(a%i==0&&isprime(i))
        {
            primefactors.push_back(i);
            a=a/i;i=1;
        }
    return primefactors;
}
int main()
{
int a=5,b=2500;
cout<<"GCD = "<<gcd(a,b)<<endl;
cout<<"LCM = "<<lcm(a,b)<<endl;
if(!isprime(b)) out<<"not prime"<<endl;
vector <int> p =
primefactors(b);
for(int i=0;i<p.size();++i)
out<<p[i]<<endl;
return 0;
}
