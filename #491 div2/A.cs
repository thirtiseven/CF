using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1 {
	class program {
		static void Main(string[] args) {
			string str = Console.ReadLine();//从控制台读入输入
			string[] nums = str.Split(new string[]{ " " }, StringSplitOptions.None);//这里是以空格隔开
			int a = Convert.ToInt32(nums[0]);
			int b = Convert.ToInt32(nums[1]);
			int c = Convert.ToInt32(nums[2]);
			int d = Convert.ToInt32(nums[3]);
			int cnt = a-c+b;
			if (d-cnt<=0||a+b<c||a<c||b<c) {
				Console.WriteLine(-1);
			}
			else Console.WriteLine(d-cnt);
		}
	}
}