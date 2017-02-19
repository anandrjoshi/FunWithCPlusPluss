using System;
using System.Collections.Generic;
using NUnit.Framework;
using System.Linq;
using System.Text;

namespace MRT11_NUNIT_Partial
{
    [TestFixture]
    public class GameTest
    {
        private Game Game1;

        [SetUp]
        protected void setUp()
        {
            Game1 = new Game();
            Game1.move('G', 'C');
        }

        [Test]
        public void moveTest()
        {
            Game1 = new Game();
            Game1.move('G', 'C');
            List<char> temp = Game1.getLeft();
            List<char> temp2 = Game1.getRight();
            Assert.IsTrue(!temp.Contains('G'));
            Assert.IsTrue(!temp.Contains('C'));
            Assert.IsTrue(temp2.Contains('G'));
            Assert.IsTrue(temp2.Contains('C'));
        }

        [Test]
        public void checkTest()
        {
           //write this
            Assert.Fail();
        }

        [Test]
        public void winTest()
        {
            Game1 = new Game();
            Game1.move('G', 'C');   //->
            Game1.move('G');        //<-
            Game1.move('G', 'D');   //->
            Game1.move('G', 'C');   //<-
            Game1.move('M', 'D');   //->
            Game1.move('M');        //<-
            Game1.move('M', 'F');   //->
            Game1.move('F');        //<-
            Game1.move('G', 'C');   //->
            Game1.move('M');        //<-
            Game1.move('M', 'F');   //->
            Game1.move('F');        //<-
            Game1.move('F', 'S');   //->
            Game1.move('G', 'C');   //<-
            Game1.move('G', 'S');   //->
            Game1.move('G');        //<-
            Game1.move('G', 'C');   //->
            Assert.IsTrue(Game1.win());
        }

        [Test]
        public void getLeftTest()
        {
            Game1 = new Game();
            Game1.move('G', 'C');
            List<char> temp = Game1.getLeft();
            Assert.IsFalse(temp.Contains('G'));
            Assert.IsFalse(temp.Contains('C'));
        }

        [Test]
        public void getRightTest()
        {
            Game1 = new Game();
            Game1.move('G', 'C');
            List<char> temp = Game1.getRight();
            Assert.IsTrue(temp.Contains('G'));
            Assert.IsTrue(temp.Contains('C'));

        }

        [Test]
        public void getErrorTest()
        {
            Game1 = new Game();
            Game1.move('D', 'S');
            String temp = Game1.getError();
            String target = "only mom, father, and guard can use the raft";
            Assert.IsTrue(temp.Equals(target));
        }
    }

}
