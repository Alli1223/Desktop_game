#Sprint One:

##Good:
* It works
* Got a grid system working
* Committed well, with good GitHub use
* Trello board was kept up to-date
* Better understanding of classes
* Good Tri-Programming use

##Bad:
* Not much communication out of class
* Didn't meet up often
* Over ambitious
* Needed a more concrete designs
* Could have made use of white-board to design the game
* Have not seen 4th member(Angus)
* Trello board wasn't used properly

#Sprint 2 
##Good:
* Used shared pointers
* Kept Trello board up to date  
* Found and fixed bugs
* More code commenting/improved readability
* Character collision (sort of) works
* Coding task 2 has helped nail down components/component design

##Bad:
* Git merge conflicts 
* Errors with error system
* No daily scrums
* Need to get more code done (together and separately)
* More communication  


#Sprint 3  
##Good:
* Code merged into the development branch without many conflicts
* Level making system in place
* Character can move around map by itself
* Kept the Trello board up to date
* We were organised 
* Some gameplay
* Better communication

##Bad:  
* Character gets stuck in bottom right corners
* Not much done in the holiday
* No communication in holiday

#Sprint 4
##Good:

##Bad:
___

#Weekly Report:
##Week One
This week’s coding was all done as a group with one person typing and the other two helping. At the end of this week we had program that would open a window and render the cells.

We had issues with rendering the cells on screen, after going through some of the live coding examples we managed to fix the issue and get a cell to render in the window.  
  
We also had a problem where everything was rendering in one location, we managed to fix this by multiplying the location values by the cell size.

##Week Two
This week was also mostly done as group, we added a base class for the character and created a grid class that creates a vector of cells.
We intended to make a vectors of pointers to cells but none of us fully understood pointers, so we avoided using them. We will overcome this by attempting to use smart pointers in the future.

##Week Three
We all researching shared pointer and refactored the grid class code now it creates pointers to cells instead of cells themselves. We also changed it to a 2D array so it is now a vector of vectors of shared pointers to cells. This refactoring should also make cell state checking easier later on.

The character now renders in the window on top of the grid and has basic controls to move up, down left and right however it can go off-screen which is an issue that needs sorting. There was also an inheritance issue but this was fixed by putting public in the class name.


##Week Four
When trying to access a cell in the grid we found an issue where the grid class was creating nullptrs instead of cells. We managed to fix this issue by using make_shared on a cell before adding it to a vector.

The issue where the character was able to move off-screen was also fixed by making the character only be able to have a X and Y value between 0 and the window width and height. The character also now checks the cell state before moving on to it

We also had some merge conflict issues but managed to resolve them using tortoise git's resolve tool.

##Easter:
There was little communication over so we weren't sure what each other was doing.

There were some issues with Character states and inheritance these were overcome by researching how inheritance works and fixing the code. There were also issue with forward declarations but looking back at the lecture notes helped to fix that.

The program is currently in separate branches so the Development branch just contains a program where the player can move the character around the screen. There is an oxygen branch that gives cells an oxygen value that can be added to and a character branch that uses a finite state machine to determine the character’s behaviour depending on the cell state and the player input.

##Week Five 
The character can now check if a cell is a room before moving. The cell state now changes when a cell is full of oxygen and there’s a mouse event class to record where the players mouse is in the window.

##Week Six
We now have a class that can read a map in from a text file and create a grid that has rooms based on that text file. There is an issue where the content from text file appears to be flipped and rotated but that issue hasn't been solved yet.

We merged a few branches in development and then master this week. There were a few merge conflicts but they were fixed with tortoise git. We've had to drop a few features because there's not much time left now. The priorities for the next sprint are to get the oxygen and level generation working, having more than one character and then a general tidy up of the code.

##Week Seven

##Week Eight


