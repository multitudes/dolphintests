#include "dolphin_tests.h"

/*
 Part one of the libft project recreates standard C functions.
 The original ones can be found in the man pages
 */

// ft_isalpha should return 1 if the char is a alphabetical character
char *test_ft_isalpha()
{
	my_assert(ft_isalpha(65) == 1, "Output shd be one");
	my_assert(ft_isalpha(70) == 1, "Output shd be one");
	my_assert(ft_isalpha(90) == 1, "Output shd be one");
	my_assert(ft_isalpha(97) == 1, "Output shd be one");
	my_assert(ft_isalpha(100) == 1, "Output shd be one");
	my_assert(ft_isalpha(122) == 1, "Output shd be one");
	my_assert(ft_isalpha(255) == 0, "Output shd be zero");
	my_assert(ft_isalpha(123) == 0, "Output shd be zero");
	my_assert(ft_isalpha(10) == 0, "Output shd be zero");
	my_assert(ft_isalpha(0) == 0, "Output shd be zero");
	my_assert(ft_isalpha(89) == 1, "Output shd be Y");

	return NULL;
}

// ft_isdigit should return 1 if the char is a digit
char *test_ft_isdigit()
{
	my_assert(ft_isdigit(50) == 1, "Output shd be one");
	my_assert(ft_isdigit('0') == 1, "Output shd be one");
	my_assert(ft_isdigit('1') == 1, "Output shd be one");
	my_assert(ft_isdigit('9') == 1, "Output shd be one");
	my_assert(ft_isdigit(10) == 0, "Output shd be zero");
	my_assert(ft_isdigit('/') == 0, "Output shd be one");
	my_assert(ft_isdigit(':') == 0, "Output shd be one");
	my_assert(ft_isdigit('0'+1) == 1, "Output shd be one");
	my_assert(ft_isdigit('9'+2) == 0, "Output shd be zero");
	my_assert(ft_isdigit(255) == 0, "Output shd be zero");
	
	return NULL;
}
// ft_isalnum should return 1 if the char is alphanumeric
char *test_ft_isalnum()
{
	my_assert(ft_isalnum(48) == 1, "Output shd be one");
	my_assert(ft_isalnum(57) == 1, "Output shd be one");
	my_assert(ft_isalnum('0') == 1, "Output shd be one");
	my_assert(ft_isalnum('1') == 1, "Output shd be one");
	my_assert(ft_isalnum(65) == 1, "Output shd be one");
	my_assert(ft_isalnum(66) == 1, "Output shd be one");
	my_assert(ft_isalnum(97) == 1, "Output shd be one");
	my_assert(ft_isalnum(122) == 1, "Output shd be one");
	my_assert(ft_isalnum('z' + 1) == 0, "Output shd be zero");
	my_assert(ft_isalnum(47) == 0, "Output shd be zero");
	my_assert(ft_isalnum(123) == 0, "Output shd be zero");
	my_assert(ft_isalnum(255) == 0, "Output shd be zero");
	
	return NULL;
}

// ft_isascii should return 1 if the char is in the ascii table
char *test_ft_isascii()
{
	my_assert(ft_isascii(0) == 1, "Output shd be one");
	my_assert(ft_isascii(127) == 1, "Output shd be one");
	my_assert(ft_isdigit(255) == 0, "Output shd be zero");
	my_assert(ft_isascii(128) == 0, "Output shd be zero");
	
	return NULL;
}

// ft_isprint should return 1 if the char is in the ascii table
char *test_ft_isprint()
{
	my_assert(ft_isprint(32) == 1, "Output shd be one");
	my_assert(ft_isprint(126) == 1, "Output shd be one");
	my_assert(ft_isprint(50) == 1, "Output shd be one");

	my_assert(ft_isprint(31) == 0, "Output shd be zero");
	my_assert(ft_isprint(127) == 0, "Output shd be zero");
	my_assert(ft_isprint(255) == 0, "Output shd be zero");

	return NULL;
}

// ft_strlen returns the length of the string
char *test_ft_strlen()
{
	my_assert(strlen("hello") == 5, "Output shd be 5");
	my_assert(strlen("") == 0, "Output shd be 0");
	my_assert(strlen("hello world") == 11, "Output shd be 11");
	return NULL;
}

// ft_memset parameters are a pointer to a memory location which will be
// overwritten with a char (passed as a second param) n times (third param)
char *test_ft_memset()
{
	char b[6] = "hello";
	char b2[6] = "hello";
	ft_memset((void *)b, 55, sizeof(b));
	my_assert(ft_strncmp(b, "77777", 5) == 0, "Output shd be 0");
	
	debug("====ft_memset returns: %s \n", (char *)b);
	debug("====memset returns: %s \n", (char *)memset((void *)b2, 55, sizeof(b2)));
	// error 'memset' will always overflow;
	// debug("====memset returns: %s \n", (char *)memset((void *)b2, 55, 8));
	return NULL;
}

// ft_bzero is like ft_memset but writes zeroes.
char *test_ft_bzero()
{
	char b[6] = "hello";
	ft_bzero((void *)b, 4);
	for (int i = 0; i < 4; i++)
	{
		my_assert(b[i] == 0, "Output shd be 0");
	}
	my_assert(b[4] == 'o', "Output shd be o");
	return NULL;
}

// ft_memcpy copies n chars from source to dest
// doesnt check for overlapping
char *test_ft_memcpy()
{
	char dst[6] = "hello";
	char src[6] = "world";
	size_t n = 5;
	ft_memcpy((void *)dst, (void *)src, n);
	my_assert(ft_strncmp(dst, "world", n) == 0, "Output shd be 0");
	
	debug("====memcpy should be %s \n",(char *)memcpy((void *)dst, (void *)src, n));

	return NULL;
}

// ft_memmove it is like the previous ft_memcpy but strings can overlap safely
// tested with overlapping strings
char *test_ft_memmove()
{
	char dst[11] = "helloworld";
	char *src = (dst+3);
	char dst2[11] = "helloworld";
	char *src2 = (dst2+3);
	size_t n = 6;
	debug("====memmove gives be %s \n",(char *)memmove((void *)dst, (void *)src, n));
	debug("====after memmove dst is %s and src %s \n",dst, src);

	ft_memmove((void *)dst2, (void *)src2, n);
	debug("====ft_memmove gives be %s \n",dst2);

	my_assert(ft_strncmp(dst, "loworlorld", n) == 0, "Output shd be 0");

	return NULL;
}

// the signature is
//ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
char *test_ft_strlcpy()
{
	char dst[6] = "hello";
	char src[6] = "world";
	size_t n = 6;
	int res = ft_strlcpy(dst, src, n);
	debug("====ft_strlcpy gives be %d \n",res);
	debug("====after ft strlcpy dst is %s and src %s \n",dst, src);
	my_assert(res == 5, "Output shd be 5");
	char dst2[6] = "hello";
	char src2[6] = "world";
	size_t n2 = 6;
	int res2 = strlcpy(dst2, src2, n2);
	debug("====strlcpy gives be %d \n",res2);
	debug("====after strlcpy dst is %s and src %s \n",dst2, src2);
	my_assert(res2 == 5, "Output shd be 5");

	char dst3[6] = "hello";
	char src3[6] = "world";
	size_t n3 = 0;
	int res3 = ft_strlcpy(dst3, src3, n3);
	debug("====ft_strlcpy gives  %d \n",res3);
	my_assert(res3 == 5, "Output shd be 5");
	char dst4[6] = "hello";
	char src4[6] = "world";
	size_t n4 = 0;
	int res4 = strlcpy(dst4, src4, n4);
	debug("====strlcpy gives  %d \n",res4);
	debug("====after strlcpy dst is %s and src %s \n",dst4, src4);
	my_assert(res4 == 5, "Output shd be 5");
	
	char dst5[6] = "hello";
	char src5[6] = "world";
	size_t n5 = 3;
	int res5 = ft_strlcpy(dst5, src5, n5);
	debug("====ft_strlcpy with len 3 gives be %d \n",res5);
	my_assert(res3 == 5, "Output shd be still 5 like src length even with dstlen 3");
	char dst6[6] = "hello";
	char src6[6] = "world";
	size_t n6 = 3;
	int res6 = strlcpy(dst6, src6, n6);
	debug("====strlcpy with len 3 gives %d! \n",res6);
	debug("====after strlcpy dst is %s and src %s \n",dst6, src6);
	my_assert(res6 == 5, "Output shd be still 5 like src length even with dstlen 3");
	
	return NULL;
}

// signature is size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// check man page strlcat - this one is a bit more complicated to explain
char *test_ft_strlcat()
{
	char dst[20] = "ab";
	char src[20] = "bcdef";
	size_t n = 2;
	int res = ft_strlcat(dst, src, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst);
	my_assert(res == 7, "res = 7 because (n eq dstlen) ->return srclen +dstlen");
	my_assert(ft_strncmp(dst, "ab", n) == 0, "Output shd be 0");
	
	char dst2[20] = "ab";
	char src2[20] = "bcdef";
	n = 0;
	res = ft_strlcat(dst2, src2, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst2);
	my_assert(res == 5, "res = 5 because (n < destlen) ->return srclen + n");
	my_assert(ft_strncmp(dst2, "ab", 2) == 0, "Output shd be 0");
	int resa = ft_strlcat(dst2, src2, 5);
	debug("==== second ft_strlcat gives be %zu \n",(size_t)resa);
	debug("==== second ft_strlcat gives str %s \n",dst2);

	char dst3[20] = "ab";
	char src3[20] = "bcdef";
	n = 1;
	res = ft_strlcat(dst3, src3, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst3);
	my_assert(res == 6, "res = 6 because (n < destlen) ->return srclen + n");
	my_assert(ft_strncmp(dst3, "ab", 2) == 0, "Output shd be 0");
	
	char dst4[20] = "ab";
	char src4[20] = "bcdef";
	n = 3;
	res = ft_strlcat(dst4, src4, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst4);
	my_assert(res == 7, "res = 6 because (n < destlen) ->return srclen + n");
	my_assert(ft_strncmp(dst4, "ab", 2) == 0, "Output shd be 0");

	char dst5[20] = "ab";
	char src5[20] = "bcdef";
	n = 4;
	res = ft_strlcat(dst5, src5, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst5);
	my_assert(res == 7, "res = 6 because (n > destlen) ->return dstlen + srclen");
	my_assert(ft_strncmp(dst5, "abb", 3) == 0, "Output shd be 0");

	char dst6[20] = "";
	char src6[20] = "bcdef";
	n = 4;
	res = ft_strlcat(dst6, src6, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst6);
	my_assert(res == 5, "res = 5 because (n > destlen) ->return dstlen + srclen");
	my_assert(ft_strncmp(dst6, "bcd", 3) == 0, "Output shd be 0");

	char dst7[20] = "ab";
	char src7[20] = "bcdef";
	n = 10;
	res = ft_strlcat(dst7, src7, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst7);
	my_assert(res == 7, "res = 7 because (n > destlen) ->return dstlen + srclen");
	my_assert(ft_strncmp(dst7, "abbcdef", 7) == 0, "Output shd be 0");

	char dst8[20] = "ab";
	char src8[20] = "";
	n = 10;
	res = ft_strlcat(dst8, src8, n);
	debug("====ft_strlcat gives be %d \n",res);
	debug("====after ft_strlcat dst shd be ab => %s  \n",dst8);
	my_assert(res == 2, "res = 2 because (n > destlen) ->return dstlen + srclen");
	my_assert(ft_strncmp(dst8, "ab", 2) == 0, "Output shd be 0");

	return NULL;
}

// ft_toupper takes a char and outputs the upper char in the alphabet
char *test_ft_toupper()
{
	for (int c = 0; c<=255; c++)
	{
		if (c >= 97 && c <= 122)
		{
			my_assert(ft_toupper(c) == c - 32, "wrong output");
			// debug("====after ft_toupper c is %c",(char)ft_toupper(c));
		}
		else
		{
			my_assert(ft_toupper(c) == c, "wrong output");
			// debug("====after ft_toupper c is %c",(char)c);
		}
	}
	return NULL;
}

// ft_tolower takes a char and outputs the lower corr char in the alphabet
char *test_ft_tolower()
{
	for (int c = 0; c<=127; c++)
	{
		if (c >= 65 && c <= 90)
		{
			my_assert(ft_tolower(c) == c + 32, "wrong output");
			// debug("====after ft_toupper c is %c",(char)ft_toupper(c));
		}
		else
		{
			my_assert(ft_tolower(c) == c, "wrong output");
			// debug("====after ft_toupper c is %c",(char)c);
		}
	}
	return NULL;
}

// signature char	*ft_strchr(const char *s, int c)
/*
 The strchr() function locates the first occurrence of
 c (converted to a char) in the string pointed to by
 s.  The terminating null character is considered
 to be part of the string; therefore if c is ‘\0’, the
 functions locate the terminating ‘\0’.
 */
char *test_ft_strchr()
{
	int c = 88;
	char s[14] = "hello";
	char *res = ft_strchr(s, c);
	my_assert(res == NULL, "wrong output");
	my_assert(strchr(s,c) == NULL, "wrong output");
	c = 'e';
	char *res1 = ft_strchr(s, c);
	char *res2 = strchr(s, c);
	my_assert(ft_strncmp(res1, "ello", 4) == 0, "wrong output");
	my_assert(ft_strncmp(res2, "ello", 4) == 0, "wrong output");
	c = 'l';
	char *res3 = ft_strchr(s, c);
	char *res4 = strchr(s, c);
	my_assert(ft_strncmp(res3, "llo", 3) == 0, "wrong output");
	my_assert(ft_strncmp(res4, "llo", 3) == 0, "wrong output");
	
	char s1[] = "What happens if I press this button?";
	my_assert(ft_strchr(s1, 'W') == s1, "wrong output");  
	my_assert(ft_strchr(s1, 'p') == s1 + 7, "wrong output");  
	my_assert(ft_strchr(s1, 'z') == 0, "wrong output");  
	my_assert(ft_strchr(s1, 0) == s1 + strlen(s1), "wrong output");  
	my_assert(ft_strchr(s1, 'W' + 256) == s1, "wrong output");  
	
	return NULL;
}

/*
 The strrchr() function is identical to strchr(),
 except it locates the last occurrence of c.
 */
char *test_ft_strrchr()
{
	int c = 88; // X
	char *s = "hello";
	char *res = ft_strrchr(s, c);
	my_assert(res == NULL, "wrong output");
	my_assert(strrchr(s,c) == NULL, "wrong output");
	c = 'e';
	char *res1 = ft_strrchr(s, c);
	char *res2 = strrchr(s, c);
	my_assert(ft_strncmp(res1, "ello", 4) == 0, "wrong output");
	my_assert(ft_strncmp(res2, "ello", 4) == 0, "wrong output");
	c = 'l';
	char *res3 = ft_strrchr(s, c);
	char *res4 = strrchr(s, c);
	my_assert(ft_strncmp(res3, "lo", 2) == 0, "wrong output");
	my_assert(ft_strncmp(res4, "lo", 2) == 0, "wrong output");
	
	char *s1 = "What happens if I press this button?";
	char *s2 = "!Don't panic!";
	char *s3 = "";
	my_assert(ft_strrchr(s1, 'W') == s1, "wrong output");  
	my_assert(ft_strrchr(s1, 'p') == s1 + 18, "wrong output");  
	my_assert(ft_strrchr(s2, '!') == s2 + 12, "wrong output");  
	my_assert(ft_strrchr(s1, 'z') == NULL, "wrong output");  
	my_assert(ft_strrchr(s1, 0) == s1 + strlen(s1), "wrong output");  
	my_assert(ft_strrchr(s1, 'W' + 256) == s1, "wrong output");  
	char * empty = (char*)calloc(1, 1);
	my_assert(ft_strrchr(empty, 'V') == NULL, "wrong output"); free(empty);  
	my_assert(ft_strrchr(s3, 0) == s3, "wrong output");  
	
	return NULL;
}

/*
The strncmp() function compares not more than n characters.
Because strncmp() is designed for comparing strings rather than binary data,
characters that appear after a ‘\0’ character are not compared.
RETURN VALUES
The strcmp() and strncmp() functions return an integer greater than,
equal to, or less than 0, according as the string s1 is greater than,
equal to, or less than the string s2.
The comparison is done using unsigned characters, so that ‘\200’
is greater than ‘\0’.
*/
char *test_ft_strncmp()
{
	my_assert(ft_strncmp("hello", "hellA", 6) == 46, "Output shd be 46");
	my_assert(ft_strncmp("hello", "", 6) == 104, "Output shd be 104");
	my_assert(ft_strncmp("", "hellA", 6) == -104, "Output shd be -104");
	my_assert(ft_strncmp("", "", 6) == 0, "Output shd be 0");
	my_assert(ft_strncmp("www", "ww", 2) == 0, "Output shd be 0");
	my_assert(ft_strncmp("www", "w\b", 2) == 111, "Output shd be 111");
	
	my_assert(ft_strncmp("t", "", 0) == 0, "wrong output");  
	my_assert(ft_strncmp("1234", "1235", 3) == 0, "wrong output");  
	my_assert(ft_strncmp("1234", "1235", 4) < 0, "wrong output");  
	my_assert(ft_strncmp("1234", "1235", -1) < 0, "wrong output");  
	my_assert(ft_strncmp("", "", 42) == 0, "wrong output");  
	my_assert(ft_strncmp("What happens if I press this button?", "What happens if I press this button?", 42) == 0, "wrong output");  
	my_assert(ft_strncmp("What happens if I press this button?", "What happens if i press this button?", 42) < 0, "wrong output");  
	my_assert(ft_strncmp("What happens if I press this button?", "What happens if I press this button?", 42) == 0, "wrong output");  
	my_assert(ft_strncmp("What happens if I press this button?", "What happens if I press this button", 42) > 0, "wrong output");  
	my_assert(ft_strncmp("What happens if I press this button?", "What happens if I press this button?X", 42) < 0, "wrong output");  
	my_assert(ft_strncmp("What happens if I press this button?", "What happens if I press", 42) > 0, "wrong output");  
	my_assert(ft_strncmp("", "1", 0) == 0, "wrong output");  
	my_assert(ft_strncmp("1", "", 0) == 0, "wrong output");  
	my_assert(ft_strncmp("", "1", 1) < 0, "wrong output");  
	my_assert(ft_strncmp("1", "", 1) > 0, "wrong output");  
	my_assert(ft_strncmp("", "", 1) == 0, "wrong output");
	my_assert(ft_strncmp("test\200", "test\0", 5) > 0, "wrong output");
	my_assert(strncmp("test\200", "test\0", 5) > 0, "wrong output");
	
	return NULL;
}

//void	*ft_memchr(const void *s, int c, size_t n)
/*
 void *
 memchr(const void *s, int c, size_t n);
 DESCRIPTION
 The memchr() function locates the first occurrence of c
 (converted to an unsigned char) in string s.
 RETURN VALUES
 The memchr() function returns a pointer to the byte located, or NULL
 if no such byte exists within n bytes.
 */
char *test_ft_memchr()
{
	int c = 88;
	char s[14] = "hello";
	char *res = ft_memchr(s, c, 5);
	my_assert(res == NULL, "wrong output");
	my_assert(memchr(s,c, 5) == NULL, "wrong output");
	c = 'e';
	char *res1 = ft_memchr(s, c, 5);
	char *res2 = memchr(s, c, 5);
	my_assert(ft_strncmp(res1, "ello", 4) == 0, "wrong output");
	my_assert(ft_strncmp(res2, "ello", 4) == 0, "wrong output");
	c = 'l';
	char *res3 = ft_memchr(s, c, 5);
	char *res4 = memchr(s, c, 5);
	my_assert(ft_strncmp(res3, "llo", 3) == 0, "wrong output");
	my_assert(ft_strncmp(res4, "llo", 3) == 0, "wrong output");
	
	char s2[] = {0, 1, 2 ,3 ,4 ,5};
	my_assert(ft_memchr(s2, 0, 0) == NULL, "wrong output");  
	my_assert(ft_memchr(s2, 0, 1) == s2, "wrong output");  
	my_assert(ft_memchr(s2, 2, 3) == s2 + 2, "wrong output");  
	my_assert(ft_memchr(s2, 6, 6) == NULL, "wrong output");  
	my_assert(ft_memchr(s2, 2 + 256, 3) == s2 + 2, "wrong output");
	
	return NULL;
}

// similar than the strcmp but accepting unsigned chars
// It doesn't say it will return -1 or 1 or a difference between char values
// What it exactly returns is implementation dependent.
char *test_ft_memcmp()
{
	my_assert(ft_memcmp("hello", "hellA", 6) > 0, "Output shd be 46");
	debug("====memcmp( hell , hell , 6) ==  %d",memcmp("hell0", "hell", 6));
	my_assert(memcmp("hello", "hellA", 6) > 0, "Output shd be 46");
	my_assert(ft_memcmp("hello", "", 6) > 0, "Output shd be 104");
	my_assert(memcmp("hello", "", 6) > 0, "Output shd be 104");
	my_assert(ft_memcmp("", "hellA", 6) < 0, "Output shd be -104");
	my_assert(memcmp("", "hellA", 6) < 0, "Output shd be -104");
	my_assert(ft_memcmp("ù", "ù", 6) == 0, "Output shd be 0");
	my_assert(memcmp("ù", "ù", 6) == 0, "Output shd be 0");
	my_assert(ft_memcmp("www", "ww", 2) == 0, "Output shd be 0");
	my_assert(memcmp("www", "ww", 2) == 0, "Output shd be 0");
	my_assert(ft_memcmp("www", "w\b", 2) > 0, "Output shd be 111");
	my_assert(memcmp("www", "w\b", 2) > 0, "Output shd be 111");
	
	return NULL;
}

/*
 The strnstr() function locates the first occurrence of the null-terminated
 string needle in the string haystack, where not more than len characters
 are searched.  Characters that appear after a ‘\0’ character
 are not searched.  Since the strnstr() function is a FreeBSD specific API,
 it should only be used when portability is not a concern.
 If needle is an empty string, haystack is returned; if needle occurs nowhere
 in haystack, NULL is returned;
 otherwise a pointer to the first character of the first occurrence of needle
 is returned.
 */
char *test_ft_strnstr()
{
	char haystk[20] = "hello world";
	char needle[20] = "wo";
	size_t len = 11;
	char *res = ft_strnstr(haystk, needle, len);
	char *res1 = strnstr(haystk, needle, len);
	debug("====ft_strnstr gives %s \n",res);
	debug("====strnstr gives %s \n",res1);
	my_assert(ft_strncmp(res, "world", 5) == 0, "Output shd be 0");
	
	char haystk2[20] = "hello world";
	char needle2[20] = "wo";
	len = 6;
	char *res2 = ft_strnstr(haystk2, needle2, len);
	char *res3 = strnstr(haystk2, needle2, len);
	debug("====ft_strnstr gives be %s \n",res2);
	debug("====strnstr gives be %s \n",res3);
	my_assert(res2 == 0, "Output shd be NULL pointer");
	
	char haystk3[20] = "hello world";
	char needle3[20] = "wo";
	len = 0;
	char *res4 = ft_strnstr(haystk3, needle3, len);
	char *res5 = strnstr(haystk3, needle3, len);
	debug("====ft_strnstr gives %s \n",res4);
	debug("====strnstr gives %s \n",res5);
	my_assert(res4 == 0, "Output shd be NULL pointer");
	
	// return haystack
	char haystk4[20] = "hello world";
	char needle4[20] = "";
	len = 11;
	char *res6 = ft_strnstr(haystk4, needle4, len);
	char *res7 = strnstr(haystk4, needle4, len);
	debug("====ft_strnstr gives %s \n",res6);
	debug("====strnstr gives %s \n",res7);
	my_assert(ft_strncmp(res6, "hello world", 11) == 0, "Output shd be 0");
	
	// haystack too short
	char haystk5[20] = "hello";
	char needle5[20] = "wo";
	len = 11;
	char *res8 = ft_strnstr(haystk5, needle5, len);
	char *res9 = strnstr(haystk5, needle5, len);
	debug("====ft_strnstr gives %s \n",res8);
	debug("====strnstr gives %s \n",res9);
	my_assert(res8 == 0, "Output shd be NULL pointer");
	
	// len too short
	char haystk6[20] = "hello world";
	char needle6[20] = "o w";
	len = 6;
	char *res10 = ft_strnstr(haystk6, needle6, len);
	char *res11 = strnstr(haystk6, needle6, len);
	debug("====ft_strnstr gives %s \n",res10);
	debug("====strnstr gives %s \n",res11);
	my_assert(res10 == 0, "Output shd be NULL pointer");
	return NULL;
}

// int	ft_atoi(const char *str)
char *test_ft_atoi()
{
	// int max is still 2147483647 on a 64 bit machine
	debug("====int max ==  %d",INT_MAX);
	my_assert(ft_atoi("+0") == 0, "Output shd be 0");
	debug("====atoi( +0 ) ==  %d",atoi("+0"));
	my_assert(ft_atoi("-0") == 0, "Output shd be 0");
	debug("====atoi( -0 ) ==  %d",atoi("-0"));
	
	debug("====atoi(  \t++0) ==  %d",atoi("  \t++0"));
	my_assert(ft_atoi("  \t++0") == 0, "Output shd be 0");

	my_assert(ft_atoi("  \t\v\f\n\radd") == 0, "Output shd be 0");
	debug("====atoi( +0 ) ==  %d",atoi("  \t\v\f\n\radd"));
	my_assert(ft_atoi("2147483647") == 2147483647, "Output shd be int max");
	debug("====atoi( int max) ==  %d",atoi("2147483647"));

	debug("====atoi( int max) ==  %d",atoi("21474836488"));
	my_assert(ft_atoi("21474836488") == 8, "Output shd be overflow max");
	debug("====atoi( int min) ==  %d",atoi("-2147483648"));
	my_assert(ft_atoi("-2147483648") == -2147483648, "Output shd be int min");
	debug("====atoi( int min) ==  %d",atoi("-2"));
	my_assert(ft_atoi("-2") == -2, "Output shd be int min");
	return NULL;
}

// max size possible to be allocated should be no more than 18446744073709551615UL
// because this is the max value of an unsigned long on 64 bit machines
// and size_t is a UL.
// Apparently in such cases where calloc would return null, sometimes it actually returns
// a pointer but it should not be used.
// But think about that passing a neg number might try to allocate a
// few terabytes..
char *test_ft_calloc()
{
	debug("%lu ============ \n",SIZE_MAX );
	void *test = NULL;
	test = ft_calloc(1, 1);
	my_assert(test != NULL, "Output shd be not be null");
	free(test);
	
	void * p = ft_calloc(2, 2);
	char e[] = {0, 0, 0, 0};
	my_assert(memcmp(p, e, 4) == 0, "wrong output");
	free(p); 
	
	my_assert(ft_calloc(ULONG_MAX, ULONG_MAX) == NULL, "wrong output"); 
	
	p = ft_calloc(INT_MAX, INT_MAX);
	my_assert( p == NULL, "wrong output");
	p = ft_calloc(INT_MIN, INT_MIN);
	my_assert( p == NULL, "wrong output"); 

	p = ft_calloc(0, 0);
	my_assert(p != NULL, "wrong output"); free(p); 
	p = calloc(0, 0);
	my_assert(p != NULL, "wrong output"); free(p); 

	p = ft_calloc(0, 5);
	my_assert(p != NULL, "wrong output"); free(p); 
	p = ft_calloc(5, 0);
	my_assert(p != NULL, "wrong output"); free(p);
		p = calloc(0, 5);
	my_assert(p != NULL, "wrong output"); free(p); 
	p = calloc(5, 0);
	my_assert(p != NULL, "wrong output"); free(p);

	p = ft_calloc(0, -5);
	debug("--- pointer ft_calloc 0 -5 -> %p", p);
	my_assert(p != NULL, "wrong output");free(p); 
	
	my_assert(calloc(-5, -5) == NULL, "wrong output"); 
	my_assert(ft_calloc(-5, -5) == NULL, "wrong output"); 

	// I seem to get random output here from my mallocs... unsurprisingly!
	// so I think these tests are not reliable
	// p = ft_calloc(-5, 0);
	// debug("--- pointer ft calloc 0 -5 -> %p", p);
	// my_assert(p != NULL, "wrong output"); free(p);
	// p = calloc(-5, 0);
	// debug("--- pointer calloc 0 -5 -> %p", p);
	// my_assert(p != NULL, "wrong output"); free(p); 
	p = ft_calloc(3, -5);
	my_assert(p == NULL, "wrong output"); 
	debug("--- pointer ft calloc 3 -5 -> %p", p);
	p = calloc(3, -5);
	my_assert(p == NULL, "wrong output");
	debug("--- pointer calloc  3 -5  -> %p", p); 
	
	return NULL;
}

// signature ft_strdup(const char *s1)
// copies a string. Needs to be freed!
char *test_ft_strdup()
{
	char test[20] = "hello world!";
	char *dup1 = ft_strdup(test);
	char *dup2 = strdup(test);
	
	debug("==== %s \n",dup1) ;
	debug("==== %s \n",dup2) ;
	
	my_assert(ft_strncmp(test, dup1, 11) == 0, "Output shd be 0");
	
	free(dup1);
	free(dup2);

	return NULL;
}

char *all_tests()
{
	suite_start();
	
	run_test(test_ft_isalpha);
	run_test(test_ft_isdigit);
	run_test(test_ft_isalnum);
	run_test(test_ft_isascii);
	run_test(test_ft_isprint);
	run_test(test_ft_strlen);
	run_test(test_ft_memset);
	run_test(test_ft_strncmp);
	run_test(test_ft_bzero);
	run_test(test_ft_memcpy);
	run_test(test_ft_memmove);
	run_test(test_ft_strlcpy);
	run_test(test_ft_strlcat);
	run_test(test_ft_toupper);
	run_test(test_ft_tolower);
	run_test(test_ft_strchr);
	run_test(test_ft_strrchr);
	run_test(test_ft_memchr);
	run_test(test_ft_memcmp);
	run_test(test_ft_strnstr);
	run_test(test_ft_atoi);
	run_test(test_ft_calloc);
	run_test(test_ft_strdup);
	
	return NULL;
}

RUN_TESTS(all_tests);

