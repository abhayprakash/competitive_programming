using System;
using System.Collections;
public class Test
{
    public static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        int n, k;
        string s;
        while (t!=0)
        {
            string[] tokens = Console.ReadLine().Split();
            n = int.Parse(tokens[0]);
            k = int.Parse(tokens[1]);
            s = Console.ReadLine();

            ArrayList pos1 = new ArrayList();
            ArrayList pos0 = new ArrayList();
            for(int i=0; i<n; i++)
            {
                if(s[i] == '1')
                    pos1.Add(i);
                else
                    pos0.Add(i);
            }
            string ans = "";
            int dg = (n-k)/2;
            int sh = n-k-dg;
            while(dg < pos0.Count && sh < pos1.Count)
            {
                if(int.Parse(pos1[sh].ToString()) < int.Parse(pos0[dg].ToString()))
                {
                    ans += "1";
                    sh++;
                }
                else
                {
                    ans += "0";
                    dg++;
                }
            }
            while(dg < pos0.Count)
            {
                ans += "0";
                dg++;
            }
            while(sh < pos1.Count)
            {
                ans += "1";
                sh++;
            }
            int index = ans.Length - k;
            for (int i = index; i < ans.Length; i++)
                Console.Write(ans[i]);
            Console.WriteLine();
            t--;
        }
    }
}
