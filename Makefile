CFLAGS=-Wall -Wextra -Werror

TEST_SRC= part1_tests.c part2_tests.c
TEST_SRC_BONUS+= bonus_tests.c
TESTS=$(patsubst %.c,%,$(TEST_SRC))
TESTS_BONUS=$(patsubst %.c,%,$(TEST_SRC_BONUS))

NAME=../libft.a
NAME_BONUS=../libft.a	

LDLIBS=-lm
UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	LDLIBS+=-lbsd
endif

# the target build
all: update tests 

update:
	@git pull

clean:
	@echo ""
	@echo "==================\ncleaning all test files and executables"
	rm -rf tmp $(TESTS) $(TESTS_BONUS)
	rm -f *.o
	rm -f tests.log
	rm -rf `find . -name "*.dSYM" -print`
	find  .  -name ".*~" -delete -print
	rm -Rf tmp
	rm -f a.out

fclean: clean
	@echo
	@echo "======Already f clean============\n"

re: fclean tests

bonus: update tests_bonus 

.PHONY: tests tests_bonus
tests: LDLIBS += $(NAME)
tests: $(TESTS)
	sh ./runtests.sh

tests_bonus: LDLIBS += $(NAME_BONUS)
tests_bonus: $(TESTS_BONUS)
	sh ./runtests.sh

#will not work on mac
valgrind:
	@echo
	@echo "==================\nLaunching valgrind..."
	VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)
