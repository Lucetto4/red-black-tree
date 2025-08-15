# red-black-tree
Overview
This project implements a Red-Black Tree in C++ supporting insertion, duplicate counting, printing, and automatic balancing through rotations and recoloring. This is maintained through the rules of a Red-Black Tree, which are:
Nodes are either red or black
The root is always black
Red nodes aren’t allowed to have red children
Every path from a node to its descendant null leaves must have the same number of black nodes
All leaves are consideRed-Black nodes

How It Works
The project starts with a simple loop asking the user to enter the number one if they are ready to begin, and runs the loop until they select yes.  It does this through simple Cin or Cout lines.  After the user has prompted the project to start, another loop is run until the end of the project. This Loop, like the previous one, uses simple cin or cout commands to prompt the user to make a few choices.  The user will type the numbers 1 through 5 after being shown a menu, and based on their selection, different things will happen. The options consist of insertion duplication, counting, printing, deleting (which I didn’t get to), or terminating the loop.
The insertion process was by far the hardest it starts off by doing a standard BST insert just based on value,  and it first checks if a number is already present in the tree. If it is, then instead of adding it again,  the node's duplicate counter is incremented by one. If it is not a duplicate, however, it then calls the function insert fix, which gaver me quite a bit of trouble writing,  and it handles rotations and recoloring.  It does this in three cases. In case one, if the uncle to the node insert fix is called on is red, it recolors its parent and Uncle black. Then it sets the grandparent to red and moves up the tree to repeat. In case two, which is described to have a triangle shape (the new node and the parent are on opposite sides), it calls a single rotation on the parent. In case three, referred to as a line shape, which is when the new node and parent are on the same side, it calls a single rotation on the grandparent. It then always ensures the root is black after the fix. 

Testing
Light testing after completion yielded very good results in different locations, and I didn't find any errors. Below you can see the tests I ran and the outputs I received. 
Insert: 10, 5, 1  
Output: R:1 B:5 R:10
Insert: 15, 10, 5, 1, 6  
Output: R:1 B:5 R:6 B:10 B:15
Insert: 20, 15, 10  
Output: R:10 B:15 R:20
Insert: 10 10 10 
Output calling getValCount gave me 3.

Challenges & Fixes
I had many, many challenges and fixes to do. The main issue was working through logic. Every time I thought I was reasoning properly, I would make mistakes. Very many times, I would find myself having put a lot of time into writing a function and realizing I did it wrong after I finished. Nearly every function took multiple tries, and insert and rotations gave me the most trouble. The main fixes I remember having to implement are handling a case where a grandparent would be no to avoid crashes,  fixing case to rotation updates by properly reassigning pointers, and ensuring the route is always black at the end of balancing. While there were many more mistakes and fixes I had to make, these were the main ones I remember. The main thing I struggled with was deletion, and out of fear, I was running low on time and maybe wouldn't get to submission on time. I wrote deletion out of my project. The option is still in the menu; I removed my starting Logic for it in the function. Had I started this assignment earlier, I would have done deletion, but I suspect it would have been much harder compared to everything else. I underestimated how difficult this assignment would be, but even without deletion, I'm still quite proud of what I learned and how I was able to reason through the logic.

How To Run:
From the terminal in the project folder run: g++ -std=c++11 main.cpp redBlackTree.cpp -o rbt
Once compiled run: ./rbt
From there you will be prompted to enter 1 to start and a menu will appear giving you further instructions

Screenshots
https://drive.google.com/drive/folders/1BOSwdEiVlq8ShNNN_dTDX3tCsMjpdntr

Follow Up
While I spent quite some time on this assignment and ended up with a working Red-Black Tree(minus deletion), I'm still nowhere near confident enough to completely make one of these by myself without having to use online resources. I have been taught about Red-Black Trees previously before but this assignment was way harder than I remembered them to be.  While I understand their basic concepts and how they work,  at least in my opinion, the logic is extraordinarily hard, and I would need a lot more time to feel as if I had mastery over the Red-Black Tree. Even so, I think this assignment has greatly increased my understanding of them, as well as my ability to handle logic in general.  It allowed me to work through problems and ways of thinking that I don't normally do, and while that was a struggle, I found it challenging in a good way.

