import java.util.Scanner;
import java.math.BigInteger;
class Main{
        public static void main(String args[])
        {
                Scanner sc = new Scanner(System.in);
                BigInteger a,b,c,e,d;
                String s="2";
                d=new BigInteger(s);
                for(int i=0;i<10;i++){
                a=sc.nextBigInteger();
                b=sc.nextBigInteger();
                c=a.add(b);
                e=a.subtract(b);
                System.out.println(c.divide(d).toString());
                System.out.println(e.divide(d).toString());
                }
        }
}