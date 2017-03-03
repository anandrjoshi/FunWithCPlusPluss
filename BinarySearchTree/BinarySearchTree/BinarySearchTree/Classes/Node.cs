using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree.Classes
{
	public class Node<T>
	{
		public Node<T> LeftNode { get; set; }
		public Node<T> RightNode { get; set; }
		public T Value { get; set; }
	}
}
