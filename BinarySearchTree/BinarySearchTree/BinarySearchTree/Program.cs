using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using BinarySearchTree.Classes;

namespace BinarySearchTree
{
	class Program
	{
		static void Main(string[] args)
		{
			List<int> inputs = new List<int> { 7, 3, 1, 9 };
			Node<int> rootNode = BinarySearchTree.Classes.BinarySearchTree.GenerateIntBST(inputs);

			Console.ReadKey();
		}
	}
}
