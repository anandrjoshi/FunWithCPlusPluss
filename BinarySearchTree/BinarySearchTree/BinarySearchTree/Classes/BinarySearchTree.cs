using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BinarySearchTree.Classes
{
	public static class BinarySearchTree
	{
		public static Node<int> GenerateIntBST(List<int> inputs)
		{
			Node<int> rootNode = new Node<int>();
			rootNode.Value = inputs.First();

			for(int i = 1; i<inputs.Count; i++)
			{
				AddNode(rootNode, inputs.ElementAt(i));
			}
			return rootNode;
		}

		private static void AddNode(Node<int> node, int value)
		{
			if(node.Value >= value)
			{
				if (node.LeftNode != null)
				{
					AddNode(node.LeftNode, value);
				}
				else
				{
					Node<int> leftNode = new Node<int>();
					leftNode.Value = value;
					node.LeftNode = leftNode;
				}
			}
			else
			{
				if (node.RightNode != null)
				{
					AddNode(node.RightNode, value);
				}
				else
				{
					Node<int> rightNode = new Node<int>();
					rightNode.Value = value;
					node.RightNode = rightNode;
				}
			}
		}
	}
}
