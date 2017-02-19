using System;
using System.Collections.Generic;
//using System.Linq;
using System.Text;

namespace MRT11_NUNIT_Partial
{
    public class Game
    {
        private Boolean atLeft;
        private List<char> leftSide;
        private List<char> rightSide;
        private String error;
        public Game()
        {
            leftSide = new List<char> { 'M', 'D', 'D', 'F', 'S', 'S', 'G', 'C' };
            rightSide = new List<char> { };
            atLeft = true;
        }

        public void move(char a, char b)
        {
            Boolean c = check(a, b);
            if (!c)
            {
                return;
            }

            if (atLeft)
            {
                leftSide.Remove(a);
                leftSide.Remove(b);
                rightSide.Add(a);
                rightSide.Add(b);
                atLeft = false;
            }
            else
            {
                rightSide.Remove(a);
                rightSide.Remove(b);
                leftSide.Add(a);
                leftSide.Add(b);
                atLeft = true;
            }
        }

        public void move(char a)
        {
            Boolean c = check(a);
            if (!c)
            {
                return;
            }

            if (atLeft)
            {
                leftSide.Remove(a);
                rightSide.Add(a);
                atLeft = false;
            }
            else
            {
                rightSide.Remove(a);
                leftSide.Add(a);
                atLeft = true;
            }

        }

        public Boolean check(char a)
        {
            List<char> current;
            List<char> otherSide;

            if (atLeft)
            {
                current = leftSide;
                otherSide = rightSide;
            }
            else
            {
                current = rightSide;
                otherSide = leftSide;
            }

            if (!(a == 'M' || a == 'F' || a == 'G' ))
            {
                error = "only mom, father, and guard can use the raft";
                return false;
            }

            if(current.Contains(a))
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }

        public Boolean check(char a, char b)
        {
            List<char> current;
            List<char> otherSide;

            if (atLeft)
            {
                current = leftSide;
                otherSide = rightSide;
            }
            else
            {
                current = rightSide;
                otherSide = leftSide;
            }

            if (!(a == 'M' || a == 'F' || a == 'G' || b == 'M' || b == 'F' || b == 'G'))
            {
                error = "only mom, father, and guard can use the raft";
                return false;
            }

            if(current.Contains(a) && current.Contains(b))
            {
                return true;
            }
            else
            {
                return false;
            }

        }

        public Boolean win()
        {
            //write this
            return false;
        }

        public List<char> getLeft()
        {
            return leftSide;
        }

        public List<char> getRight()
        {
            return rightSide;
        }

        public String getError()
        {
            return error;
        }

        public Boolean isAtLeft()
        {
            return atLeft;
        }

    }
}
