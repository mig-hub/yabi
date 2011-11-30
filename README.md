YABI
====

Yet Another Brainfuck Interpreter (Wow that is fucking original man !!!)

First of all, I need to warn you.
This interpreter is not yet finished.
It currently cannot run any code with nested square brackets.

Intall it with GCC or another C compiler (yeah it exists):

    gcc -o yabi yabi.c

And then you can use the interpreter with STDIN:

    ./yabi

Or give it a file:

    ./yabi test.bf

You can also use it with a shebang but make sure your shebang line does not contain any commands listed below because they will be interpreted.
You'll most likely have only dots `.` which are armless at this stage but be careful. There is an example called test_shebang.

One last thing, there is now a another version that takes advantage of the GCC feature "label as value", so if you compile with GCC
use this one instead which is approximately 4 times faster. Even if to be honest, we never code something in brainfuck that takes so
much time that you could notice the difference `;-)`

    gcc -o yabi yabi-gcc.c

BRAINFUCK
=========

Brainfuck is a very simple language (maybe the simplest).
Imagine you have just a long array of boxes in which you can put numbers (eventually printed as chars).
Then you start on the first box and here are the 8 commands that the interpreter understands:

- + Increment the number in the current box
- - Decrement the number in the current box
- > Move the pointer to the next box
- < Move the pointer to the previous box
- , Read STDIN for one character and put it in the current box
- . Print the character of the current box
- [ All code until the matching square bracket is skiped if current box is 0
- ] Loop back to the matching square bracket if current box is NOT 0

Any other character is ignored.

If you wanna learn more about Brainfuck, [go here](http://en.wikipedia.org/wiki/Brainfuck)
