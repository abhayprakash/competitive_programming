using System;

class Program
{
    static void Main()
    {
        int t = int.Parse(Console.ReadLine());
        for (int i = 0; i < t; i++)
        {
            int n = int.Parse(Console.ReadLine());
            if ((n & 1) != 0)
            {
                Console.WriteLine(0);
                continue;
            }
            int N = n * (n >> 1);
            int answer = 0;
            double sqrt = Math.Floor(Math.Sqrt(N));
            for (int num = 1; num <= sqrt; num++)
            {
                if (N % num == 0)
                    answer++;
            }
            answer *= 2;
            if (N == sqrt * sqrt)
            {
                answer--;
            }
            Console.WriteLine(answer);
        }
    }
}
