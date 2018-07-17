using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
	class Program
	{
		static void Main(string[] args)
		{
			int number1;
			int number2;
			int sum;
			Console.WriteLine("Enter First Integer:");
			number1 = Convert.ToInt32(Console.ReadLine());
			Console.WriteLine("Enter Second Integer:");
			number2 = Convert.ToInt32(Console.ReadLine());
			sum = number1 + number2;
			Console.WriteLine("Sum is {0}", sum);
			string str = Console.ReadLine();//从控制台读入输入
			string[] nums = str.Split(" ");//这里是以空格隔开
			int a = Convert.ToInt32(nums[0]);
			int b = Convert.ToInt32(nums[1]);
		}
	}
}