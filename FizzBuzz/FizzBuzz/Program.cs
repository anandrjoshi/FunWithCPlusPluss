using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FizzBuzz
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Enter value for n: ");
			int n = Convert.ToInt32(Console.ReadLine());

			if(n<0)
			{
				Console.WriteLine("Validation failed!");
			}
			else
			{ 
				IList<string> fizzBuzz = GenerateFizzBuzzSequence(n);

				foreach(string str in fizzBuzz)
				{
					Console.WriteLine(str);
				}
			}

			Console.ReadKey();
		}

		private static IList<string> GenerateFizzBuzzSequence(int n)
		{
			IList<string> fizzBuzz = new List<string>();
			
			for (int i = 0; i < n; i++)
			{
				if((i+1)%3 == 0 && (i+1)%5 == 0)
				{
					fizzBuzz.Add("FizzBuzz");
				}
				else if((i+1)%3 == 0)
				{
					fizzBuzz.Add("Fizz");
				}
				else if((i+1)%5 == 0)
				{
					fizzBuzz.Add("Buzz");
				}
				else
				{
					fizzBuzz.Add(Convert.ToString(i+1));
				}
			}

			return fizzBuzz;
		}
	}
}
