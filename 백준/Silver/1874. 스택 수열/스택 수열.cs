using System;
using System.Collections.Generic;

public class Program
{
    public static void Main(string[] args)
    {
        using var read = new System.IO.StreamReader(Console.OpenStandardInput());
        using var print = new System.IO.StreamWriter(Console.OpenStandardOutput());

        int num = Convert.ToInt32(read.ReadLine());
        int[] input = new int[num];

        for (int i = 0; i < num; i++)
            input[i] = Convert.ToInt32(read.ReadLine());

        PushPop(input, print);
    }

    public static void PushPop(int[] input, System.IO.StreamWriter print)
    {
        int[] stack = new int[input.Length];
        int top = -1;
        List<char> result = new List<char>();

        int count = 1;
        for (int i = 0; i < input.Length; i++)
        {
            while (count <= input[i])
            {
                stack[++top] = count++;
                result.Add('+');
            }

            if (top < 0 || stack[top] != input[i])
            {
                print.WriteLine("NO");
                return;
            }
            else
            {
                top--;
                result.Add('-');
            }
        }

        foreach (char output in result)
        {
            print.WriteLine(output);
        }
    }
}
