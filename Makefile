CFLAGS=-Wall -Wextra -Werror

NAME=../libft.a

LDLIBS=-lm -lbsd
	
# the target build
all: tests 

clean:
	@echo ""
	@echo "==================\ncleaning all test files and executables"
	rm -rf tmp $(TESTS) $(TESTS_BONUS)
	rm -f *.o
	rm -f tests/tests.log
	rm -rf `find . -name "*.dSYM" -print`
	find  .  -name ".*~" -delete -print
	rm -Rf tmp
	rm -f a.out

fclean: clean
	@echo
	@echo "==================\n"

re: fclean tests

NAME_BONUS=libft_bonus.a

TEST_SRC= part1_tests.c part2_tests.c
TEST_SRC_BONUS+= zbonus_tests.c
TESTS=$(patsubst %.c,%,$(TEST_SRC))
TESTS_BONUS=$(patsubst %.c,%,$(TEST_SRC_BONUS))

bonus: tests_bonus 


.PHONY: tests tests_bonus
tests: LDLIBS += $(NAME)
tests: $(TESTS)
	sh ./runtests.sh

tests_bonus: LDLIBS += $(NAME_BONUS)
tests_bonus: $(TESTS_BONUS)
	sh ./runtests.sh

#dont have valgrind on mac so need to test this on linux
valgrind:
	@echo
	@echo "==================\nLaunching valgrind..."
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
