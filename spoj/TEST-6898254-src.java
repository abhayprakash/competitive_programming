import java.util.Scanner;
class Main{
 
        public static void main(String args[])
        {
          Scanner input =  new Scanner (System.in);
          int a;
          a=input.nextInt();
          while(a!=42)
          {
           System.out.printf("%d\n",a);
           a=input.nextInt();
          }
        }
}