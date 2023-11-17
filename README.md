# dolphintests
A small suite of tests for the libft project at 42 written in C.

## Usage
No installation needed. 
Just download the repo and copy it in your libft project folder. Compile your library first, 
then cd into the dolphintest folder and run `make`. The output should be similar to this one below:

```c
make      
cc -Wall -Wextra -Werror    part1_tests.c  -lm -lbsd ../libft.a -o part1_tests
cc -Wall -Wextra -Werror    part2_tests.c  -lm -lbsd ../libft.a -o part2_tests
sh ./runtests.sh
Running unit tests:
----
RUNNING: ./part1_tests
ALL TESTS PASSED
Tests run: 23
part1_tests PASS
----
RUNNING: ./part2_tests
ALL TESTS PASSED
Tests run: 11
part2_tests PASS
```
Or if you want to test the bonus functions run `make bonus` instead. But this assumes that you compiled already 
your library with the bonus functions and that your library name is libft_bonus.a.
example:
```c
make bonus
cc -Wall -Wextra -Werror    zbonus_tests.c  -lm -lbsd ../libft_bonus.a -o zbonus_tests
sh ./runtests.sh
Running unit tests:
----
RUNNING: ./part1_tests
ALL TESTS PASSED
Tests run: 23
part1_tests PASS
----
RUNNING: ./part2_tests
ALL TESTS PASSED
Tests run: 11
part2_tests PASS
----
RUNNING: ./zbonus_tests
ALL TESTS PASSED
Tests run: 9
zbonus_tests PASS
```

## Acknoledgements
I took inspiration from the debugging and test tools found in Zed Shaw "learn C the hard way" book and tutorial! Thank you Zed!

## Bugs and suggestions
They are always welcome. Please file under issues. :)

