#include "dolphin_tests.h"

/*
 Part two of the libft project asks to code some C utilities functions.
 */

/*
 Parameters of ft_substr:
 s:  The string from which to create the substring.
 start:  The start index of the substring in the
 string ’s’.
 len:  The maximum length of the substring.
 Allocates (with malloc(3)) and returns a substring
 from the string ’s’.
 The substring begins at index ’start’ and is of
 maximum size ’len’.
 ex hello len 5
 start is 4 -> o
 possible len is 1 5-4
 */
char *test_ft_substr()
{
	char test[20] = "hello world!";
	char *s = ft_substr(test, 6, 4);
	debug("==== %s \n",s) ;
	my_assert(ft_strncmp(s, "worl", 4) == 0, "Output shd be 0");
	free(s);

	s = ft_substr(test, 10, 4);
	debug("==== %s \n",s) ;
	my_assert(ft_strncmp(s, "d!", 2) == 0, "Output shd be 0");
	free(s);
	
	s = ft_substr("Betelgeuse", 0, 42000);
	my_assert(strcmp(s, "Betelgeuse") == 0, "Output shd be 0");
	free(s);  
		
	s = ft_substr("Betelgeuse", 1, 1);
	my_assert(strcmp(s, "e") == 0, "Output shd be 0");
	free(s);

	s = ft_substr("Betelgeuse", 100, 1);
	my_assert(strcmp(s, "") == 0, "Output shd be 0");
	free(s);  

	s = ft_substr("Betelgeuse", 0, 42000);
	my_assert(strcmp(s, "Betelgeuse") == 0, "Output shd be 0");
	free(s);  
	
	char *str = strdup("1"); 
	s = ft_substr(str, 42, 42000000);
	my_assert(strcmp(s, "") == 0, "Output shd be 0");
	free(s);   free(str);  

	str = strdup("0123456789");
	s = ft_substr(str, 9, 10);
	my_assert(strcmp(s, "9") == 0, "Output shd be 9");
	free(s);   free(str);  

	s = ft_substr("42", 0, 0);
	my_assert(strcmp(s, "") == 0, "Output shd be 0");
	free(s);  

	s = ft_substr("Life, the Universe and Everything.", 8, 14);
	my_assert(strcmp(s, "e Universe and") == 0, "Output shd be 0");
	free(s);    
	
	return NULL;
}

/*
 Parameters of ft_strjoin:
 s1:  The prefix string.
 s2:  The suffix string.
 ret The new string.
 NULL if the allocation fails.
 Allocates (with malloc(3)) and returns a new
 string, which is the result of the concatenation
 of ’s1’ and ’s2’.
 */
char *test_ft_strjoin()
{
	char test[20] = "Life, ";
	char test2[28] = "the Universe and Everything.";
	char *sub1 = ft_strjoin(test, test2);
	debug("==== %s \n",sub1) ;
	my_assert(ft_strncmp(sub1, "Life, the Universe and Everything.", 28) == 0, "Output shd be life...!");
	free(sub1);

	char test3[20] = "";
	char test4[28] = "the Universe and Everything.";
	char *sub2 = ft_strjoin(test3, test4);
	debug("==== %s \n",sub2) ;
	my_assert(ft_strncmp(sub2, "the Universe and Everything.", 15) == 0, "Output shd be the universe...!");
	free(sub2);

	char test5[20] = "";
	char test6[20] = "";
	char *sub3 = ft_strjoin(test5, test6);
	debug("==== %s \n",sub3) ;
	my_assert(ft_strncmp(sub3, "", 1) == 0, "Output shd be ''");
	free(sub3);

	char test7[20] = " hello";
	char test8[20] = "";
	char *sub4 = ft_strjoin(test7, test8);
	debug("==== %s \n",sub4) ;
	my_assert(ft_strncmp(sub4, " hello", 6) == 0, "Output shd be hello");
	free(sub4);
	return NULL;
}

/*
 Parameters of ft_strtrim:
 s1:  The string to be trimmed.
 set:  The reference set of characters to trim.
 Return value
 The trimmed string.
 NULL if the allocation fails.
 Description
 Allocates (with malloc(3)) and returns a copy of
 ’s1’ with the characters specified in ’set’ removed
 from the beginning and the end of the string.
 */
char *test_ft_strtrim()
{
	char *test = "hel-?lo ? ?!!? ?~~\t?~?~!-";
	char *set = " !-?~\t";
	char *res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "hel-?lo", 7) == 0, "Output shd be hel-?lo");
	free(res);

	test = "   --- hel-?lo";
	set = " -";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "hel-?lo", 7) == 0, "Output shd be hel-?lo");
	free(res);

	test = "hel-?lo    --- ";
	set = " -";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "hel-?lo", 7) == 0, "Output shd be hel-?lo");
	free(res);

	test = "  ---  - hel-?lo    --- ";
	set = " -";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "hel-?lo", 7) == 0, "Output shd be hel-?lo");
	free(res);

	test = "  ---  - -    --- ";
	set = " -";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "", 0) == 0, "Output shd be nothing");
	free(res);

	test = "";
	set = "abc";
	res = ft_strtrim(test, set);
	debug("==== shd be empty |%s|\n",res) ;
	my_assert(ft_strncmp(res, "", 0) == 0, "Output shd be nothing");
	free(res);

	test = "abc";
	set = "";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "abc", 3) == 0, "Output shd be abc");
	free(res);

	test = "";
	set = "";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "", 0) == 0, "Output shd be abc");
	free(res);

	test = "abc";
	set = "cba";
	res = ft_strtrim(test, set);
	debug("==== %s \n",res) ;
	my_assert(ft_strncmp(res, "", 0) == 0, "Output shd be abc");
	free(res);

	return NULL;
}

// function to free the memory in ft_split
void freesplit(char **arr)
{
	for (int i = 0; arr[i] != NULL; ++i)
		free(arr[i]);
	free(arr);
}

/*
 Parameters of ft_split:
 s:  The string to be split.
 c:  The delimiter character.
 Return value
 The array of new strings resulting from the split.
 NULL if the allocation fails.
 Allocates (with malloc(3)) and returns an array
 of strings obtained by splitting ’s’ using the
 character ’c’ as a delimiter.  The array must end
 with a NULL pointer.
 allowed are malloc, free
 */
char *test_ft_split()
{
	char test[46] = "---hello-and-thanks for-all-the--fish---";
	char **res = ft_split(test, '-');
	debug("==== %s \n",res[0]);
	debug("==== %s \n",res[1]);
	debug("==== %s \n",res[2]);
	debug("==== %s \n",res[3]);
	debug("==== %s \n",res[4]);
	debug("==== %s \n",res[5]);
	debug("==== %s \n",res[5]);
	my_assert(ft_strncmp(res[0], "hello", 5) == 0, "Output shd be hello");
	my_assert(ft_strncmp(res[1], "and", 3) == 0, "Output shd be hello");
	my_assert(ft_strncmp(res[2], "thanks for", 10) == 0, "Output shd be hello");
	my_assert(ft_strncmp(res[3], "all", 3) == 0, "Output shd be all");
	my_assert(ft_strncmp(res[4], "the", 3) == 0, "Output shd be the");
	my_assert(ft_strncmp(res[5], "fish", 4) == 0, "Output shd be fish");
	my_assert(ft_strncmp(res[6], NULL, 0) == 0, "Output shd be null");
	freesplit(res); 

	char test2[45] = "---hello-and-thanks for-all-the-fish---";
	char **res2 = ft_split(test2, ' ');
	debug("==== %s \n",res2[0]);
	debug("==== %s \n",res2[1]);
	my_assert(ft_strncmp(res2[0], "---hello-and-thanks", 10) == 0, "Output shd be ---hello-and-thanks");
	my_assert(ft_strncmp(res2[1], "for-all-the-fish", 10) == 0, "Output shd be for-all-the-fish");
	freesplit(res2); 
	
	char test3[45] = "---hello-and-thanks for-all-the-fish---";
	char **res3 = ft_split(test3, '!');
	debug("==== %s \n",res3[0]);
	my_assert(ft_strncmp(res3[0], test3, 20) == 0, "Output shd be hello-and-thanks for-all-the-fish");
	freesplit(res3); 

	char **res4 = ft_split("", '!');
	debug("==== %s \n",res4[0]);
	my_assert(ft_strncmp(res4[0], "", 0) == 0, "Output shd be empty");
	freesplit(res4); 

	char **res5 = ft_split("hello", 0);
	debug("==== %s \n",res5[0]);
	my_assert(ft_strncmp(res5[0], "hello", 5) == 0, "Output shd be hello");
	freesplit(res5); 
	
	return NULL;
}

/*
 Parameters of ft_itoa:
 n:  the integer to convert.
 Return value
 The string representing the integer.
 NULL if the allocation fails.
 Description
 Allocates (with malloc(3)) and returns a string
 representing the integer received as an argument.
 Negative numbers must be handled.
 
 this version of itoa needs to be freed
 */
char *test_ft_itoa()
{
	// int max is still 2147483647 on a 64 bit machine
	debug("====int max ==  %d",INT_MAX);
	
	char *test = ft_itoa(INT_MAX);
	debug("====ft_itoa( INT_MAX ) ==  %s",test);
	my_assert(ft_strncmp(test, "2147483647", 10) == 0, "Output shd be 0");	free(test);
	
	test = ft_itoa(-2147483648);
	debug("====ft_itoa( int min ) ==  %s",test);
	my_assert(ft_strncmp(test, "-2147483648", 11) == 0, "Output shd be 0");	free(test);
	
	test = ft_itoa(-1);
	debug("====ft_itoa( -1 ) ==  %s",test);
	my_assert(ft_strncmp(test, "-1", 2) == 0, "Output shd be 0");	free(test);
	
	test = ft_itoa(5);
	debug("====ft_itoa( 5 ) ==  %s",test);
	my_assert(ft_strncmp(test, "5", 1) == 0, "Output shd be 0");	free(test);
	
	test = ft_itoa(0);
	debug("====ft_itoa( 0 ) ==  %s",test);
	my_assert(ft_strncmp(test, "0", 1) == 0, "Output shd be 0");	free(test);

	return NULL;
}

/*
declare f as pointer to function (unsigned int, char) returning char
to be used in ft_strmapi below
 */
char f(unsigned int a, char c)
{
	char	e;
	
	e = 'e';
	if ((a % 2) || (c == 'a'))
		e = c;

	return e;
}

/*
 Parameters of ft_strmapi:
 s:  The string on which to iterate.
 f:  The function to apply to each character.
 Return value
 The string created from the successive applications
 of ’f’.
 Returns NULL if the allocation fails.
 Applies the function ’f’ to each character of the
 string ’s’, and passing its index as first argument
 to create a new string (with malloc(3)) resulting
 from successive applications of ’f’.
 this version uses malloc and the result needs to be freed
 */
char *test_ft_strmapi()
{
	char s[40] = "hello-and-thanks for-all-the-fish";
	char *test = ft_strmapi(s, f);

	debug("====test ==  %s",test);
	my_assert(ft_strncmp(test, "eeele-ane-ehanesefereaeleteeefese", 30) == 0, "Output shd be 0");free(test);
	
	char s2[40] = "";
	test = ft_strmapi(s2, f);
	debug("====test ==  %s",test);
	my_assert(ft_strncmp(test, "", 1) == 0, "Output shd be 0");free(test);

	char s3[4] = "eh";
	test = ft_strmapi(s3, f);
	debug("====test ==  %s",test);
	my_assert(ft_strncmp(test, "eh", 2) == 0, "Output shd be 0");free(test);

	return NULL;
}

/*
declaring f as pointer to function (unsigned int, char) returning char
To use below in ft_striteri
 */
void f2(unsigned int a, char* c)
{
	if ((a % 2) || (*c == 'a'))
		 ; // do nothing
	else
		*c = 'e';
}

/*
 Parameters
 s:  The string on which to iterate.
 f:  The function to apply to each character.
 Description
 Applies the function ’f’ on each character of
 the string passed as argument, passing its index
 as first argument.  Each character is passed by
 address to ’f’ to be modified if necessary.
 */
char *test_ft_striteri()
{
	char s[40] = "hello-and-thanks for-all-the-fish";
	ft_striteri(s, f2);
	debug("====test ==  %s",s);
	my_assert(ft_strncmp(s, "eeele-ane-ehanesefereaeleteeefese", 30) == 0, "Output shd be 0");
	
	char s2[40] = "";
	ft_striteri(s2, f2);
	debug("====test ==  %s",s2);
	my_assert(ft_strncmp(s2, "", 1) == 0, "Output shd be 0");

	char s3[4] = "eh";
	ft_striteri(s3, f2);
	debug("====test ==  %s",s3);
	my_assert(ft_strncmp(s3, "eh", 2) == 0, "Output shd be 0");

	return NULL;
}

/*
 this test will print to the log file (stderr -> 2)
 
 Parameters of ft_putchar_fd:
 c:  The character to output.
 fd:  The file descriptor on which to write.
 Outputs the character ’c’ to the given file
 descriptor.
 allowed functions: write
 */
char *test_ft_putchar_fd()
{
	ft_putchar_fd('t', 2);
	ft_putchar_fd('h', 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('n', 2);
	ft_putchar_fd('k', 2);
	ft_putchar_fd('s', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('f', 2);
	ft_putchar_fd('o', 2);
	ft_putchar_fd('r', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('a', 2);
	ft_putchar_fd('l', 2);
	ft_putchar_fd('l', 2);
	ft_putchar_fd(' ', 2);
	ft_putchar_fd('t', 2);
	ft_putchar_fd('h', 2);
	ft_putchar_fd('e', 2);
	ft_putchar_fd('-', 2);
	ft_putchar_fd('f', 2);
	ft_putchar_fd('i', 2);
	ft_putchar_fd('s', 2);
	ft_putchar_fd('h', 2);
	
	return NULL;
}

/*
 this test will print to the log file (stderr -> 2)
 
 Parameters of ft_putstr_fd:
 s:  The string to output.
 fd:  The file descriptor on which to write.
 Outputs the string ’s’ to the given file
 descriptor.
 */
char *test_ft_putstr_fd()
{
	ft_putstr_fd("hello-and-thanks for-all-the-fish", 2);
	ft_putstr_fd("2147483648", 2);
	
	return NULL;
}

/*
 this test will print to the log file (stderr -> 2)
 
 Parameters of ft_putendl_fd:
 s:  The string to output.
 fd:  The file descriptor on which to write.
 Outputs the string ’s’ to the given file descriptor
 followed by a newline.
 */
char *test_ft_putendl_fd()
{
	ft_putendl_fd("2147483648", 2);
	ft_putendl_fd("hello-and-thanks for-all-the-fish", 2);

	ft_putendl_fd("", 2);
	ft_putendl_fd("1", 2);
	
	return NULL;
}

/*
 this test will print to the log file (stderr -> 2)
 
 Parameters of ft_putnbr_fd:
 Outputs the integer ’n’ to the given file
 descriptor.
 */
char *test_ft_putnbr_fd()
{
	ft_putnbr_fd(-2147483648, 2);
	ft_putnbr_fd(2147483647, 2);
	ft_putnbr_fd(0, 2);
	ft_putnbr_fd(1, 2);
	ft_putnbr_fd(-1, 2);
	
	return NULL;
}

char *all_tests()
{
	suite_start();
	
	run_test(test_ft_substr);
	run_test(test_ft_strjoin);
	run_test(test_ft_strtrim);
	run_test(test_ft_split);
	run_test(test_ft_itoa);
	run_test(test_ft_strmapi);
	run_test(test_ft_striteri);
	run_test(test_ft_putchar_fd);
	run_test(test_ft_putstr_fd);
	run_test(test_ft_putendl_fd);
	run_test(test_ft_putnbr_fd);
	
	return NULL;
}

RUN_TESTS(all_tests);

