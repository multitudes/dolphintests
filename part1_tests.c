#include "dbg.h"
#include "../libft.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <bsd/string.h>


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

char *test_ft_isascii()
{
	my_assert(ft_isascii(0) == 1, "Output shd be one");
	my_assert(ft_isascii(127) == 1, "Output shd be one");
	my_assert(ft_isdigit(255) == 0, "Output shd be zero");
	my_assert(ft_isascii(128) == 0, "Output shd be zero");
	return NULL;
}

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

char *test_ft_strlen()
{
	my_assert(strlen("hello") == 5, "Output shd be 5");
	my_assert(strlen("") == 0, "Output shd be 0");
	my_assert(strlen("hello world") == 11, "Output shd be 11");
	return NULL;
}

//void	*ft_memset(void *b, int c, size_t len);
char *test_ft_memset()
{
//	my_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char b[6] = "hello";
	ft_memset((void *)b, 55, 5);
	my_assert(ft_strncmp(b, "77777", 5) == 0, "Output shd be 0");
	
	debug("==== %s \n", (char *)b);
	return NULL;
}

char *test_ft_bzero()
{
	//	my_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
	char b[6] = "hello";
	ft_bzero((void *)b, 4);
	for (int i = 0; i < 4; i++)
	{
		my_assert(b[i] == 0, "Output shd be 0");
	}
	my_assert(b[4] == 'o', "Output shd be o");
	return NULL;
}

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

// it is like the previous but strings can overlap
// tested with overlapping strings
char *test_ft_memmove()
{
	//	my_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
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

/*
 size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
 */
char *test_ft_strlcpy()
{
	//	my_assert(ft_memset("hello", 55, 5) == 5, "Output shd be 5");
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
	
	// char src[] = "coucou";
	// char dest[10]; memset(dest, 'A', 10);
	// /* 1 */  my_assert(ft_strlcpy(dest, src, 0) == strlen(src) && dest[0] == 'A'); 
	// /* 2 */  my_assert(ft_strlcpy(dest, src, 1) == strlen(src) && dest[0] == 0 && dest[1] == 'A'); 
	// /* 3 */  my_assert(ft_strlcpy(dest, src, 2) == strlen(src) && dest[0] == 'c' && dest[1] == 0  && dest[2] == 'A'); 
	// /* 4 */  my_assert(strlcpy(dest, src, -1) == strlen(src) && !strcmp(src, dest) && dest[strlen(src) + 1] == 'A');  memset(dest, 'A', 10);
	// /* 5 */  my_assert(ft_strlcpy(dest, src, 6) == strlen(src) && !memcmp(src, dest, 5) && dest[5] == 0);  memset(dest, 'A', 10);
	// /* 6 */  my_assert(ft_strlcpy(dest, src, 7) == strlen(src) && !memcmp(src, dest, 7));  memset(dest, 'A', 10);
	// /* 7 */  my_assert(ft_strlcpy(dest, src, 8) == strlen(src) && !memcmp(src, dest, 7));  memset(dest, 'A', 10);
	// /* 8 */  my_assert(ft_strlcpy(dest, "", 42) == 0 && !memcmp("", dest, 1));  memset(dest, 0, 10);
	// /* 9 */  my_assert(ft_strlcpy(dest, "1", 0) == 1 && dest[0] == 0);  memset(dest, 'A', 10);
	
	return NULL;
}

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

char *test_ft_toupper()
{
	for (int c = 0; c<=255; c++)
	{
		if (c >= 97 && c <= 122)
		{
			my_assert(ft_toupper(c) == c - 32, "wrong output");
			debug("====after ft_toupper c is %c",(char)ft_toupper(c));
		}
		else
		{
			my_assert(ft_toupper(c) == c, "wrong output");
			debug("====after ft_toupper c is %c",(char)c);
		}
	}
	return NULL;
}

char *test_ft_tolower()
{
	for (int c = 0; c<=255; c++)
	{
		if (c >= 65 && c <= 90)
		{
			my_assert(ft_tolower(c) == c + 32, "wrong output");
			debug("====after ft_toupper c is %c",(char)ft_toupper(c));
		}
		else
		{
			my_assert(ft_tolower(c) == c, "wrong output");
			debug("====after ft_toupper c is %c",(char)c);
		}
	}
	return NULL;
}

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
	
	char s1[] = "tripouille";
	/* 1 */  my_assert(ft_strchr(s1, 't') == s1, "wrong output");  
	/* 2 */  my_assert(ft_strchr(s1, 'l') == s1 + 7, "wrong output");  
	/* 3 */  my_assert(ft_strchr(s1, 'z') == 0, "wrong output");  
	/* 4 */  my_assert(ft_strchr(s1, 0) == s1 + strlen(s1), "wrong output");  
	/* 5 */  my_assert(ft_strchr(s1, 't' + 256) == s1, "wrong output");  
	return NULL;
}

char *test_ft_strrchr()
{
	int c = 88; // X
	char s[14] = "hello";
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
	
	char s1[] = "tripouille";
	char s2[] = "ltripouiel";
	char s3[] = "";
	/* 1 */  my_assert(ft_strrchr(s1, 't') == s1, "wrong output");  
	/* 2 */  my_assert(ft_strrchr(s1, 'l') == s1 + 8, "wrong output");  
	/* 3 */  my_assert(ft_strrchr(s2, 'l') == s2 + 9, "wrong output");  
	/* 4 */  my_assert(ft_strrchr(s1, 'z') == NULL, "wrong output");  
	/* 5 */  my_assert(ft_strrchr(s1, 0) == s1 + strlen(s1), "wrong output");  
	/* 6 */  my_assert(ft_strrchr(s1, 't' + 256) == s1, "wrong output");  
	char * empty = (char*)calloc(1, 1);
	/* 7 aperez-b */  my_assert(ft_strrchr(empty, 'V') == NULL, "wrong output"); free(empty);  
	/* 8 */  my_assert(ft_strrchr(s3, 0) == s3, "wrong output");  
	
	return NULL;
}

char *test_ft_strncmp()
{
	my_assert(ft_strncmp("hello", "hellA", 6) == 46, "Output shd be 46");
	my_assert(ft_strncmp("hello", "", 6) == 104, "Output shd be 104");
	my_assert(ft_strncmp("", "hellA", 6) == -104, "Output shd be -104");
	my_assert(ft_strncmp("", "", 6) == 0, "Output shd be 0");
	my_assert(ft_strncmp("www", "ww", 2) == 0, "Output shd be 0");
	my_assert(ft_strncmp("www", "w\b", 2) == 111, "Output shd be 111");
	
	/* 1 */ my_assert(ft_strncmp("t", "", 0) == 0, "wrong output");  
	/* 2 */ my_assert(ft_strncmp("1234", "1235", 3) == 0, "wrong output");  
	/* 3 */ my_assert(ft_strncmp("1234", "1235", 4) < 0, "wrong output");  
	/* 4 */ my_assert(ft_strncmp("1234", "1235", -1) < 0, "wrong output");  
	/* 5 */ my_assert(ft_strncmp("", "", 42) == 0, "wrong output");  
	/* 6 */ my_assert(ft_strncmp("Tripouille", "Tripouille", 42) == 0, "wrong output");  
	/* 7 */ my_assert(ft_strncmp("Tripouille", "tripouille", 42) < 0, "wrong output");  
	/* 8 */ my_assert(ft_strncmp("Tripouille", "TriPouille", 42) > 0, "wrong output");  
	/* 9 */ my_assert(ft_strncmp("Tripouille", "TripouillE", 42) > 0, "wrong output");  
	/* 10 */ my_assert(ft_strncmp("Tripouille", "TripouilleX", 42) < 0, "wrong output");  
	/* 11 */ my_assert(ft_strncmp("Tripouille", "Tripouill", 42) > 0, "wrong output");  
	/* 12 */ my_assert(ft_strncmp("", "1", 0) == 0, "wrong output");  
	/* 13 */ my_assert(ft_strncmp("1", "", 0) == 0, "wrong output");  
	/* 14 */ my_assert(ft_strncmp("", "1", 1) < 0, "wrong output");  
	/* 15 */ my_assert(ft_strncmp("1", "", 1) > 0, "wrong output");  
	/* 16 */ my_assert(ft_strncmp("", "", 1) == 0, "wrong output");
	
	return NULL;
}

//void	*ft_memchr(const void *s, int c, size_t n)
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
	/* 1 */ my_assert(ft_memchr(s2, 0, 0) == NULL, "wrong output");  
	/* 2 */ my_assert(ft_memchr(s2, 0, 1) == s2, "wrong output");  
	/* 3 */ my_assert(ft_memchr(s2, 2, 3) == s2 + 2, "wrong output");  
	/* 4 */ my_assert(ft_memchr(s2, 6, 6) == NULL, "wrong output");  
	/* 5 */ my_assert(ft_memchr(s2, 2 + 256, 3) == s2 + 2, "wrong output");   //Cast  my_assert
	
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

char *test_ft_calloc()
{
	debug("%lu ============ \n",SIZE_MAX );
	// 18446744073709551615UL
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

//ft_strdup(const char *s1)
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



//// for this one since it prints on the terminal I need
//// to redirect first to a file and then  my_assert that the output
//// is correct in reading the file again
//char *test_alphabet()
//{
//	// create the string that I am expected to see in output
//	char	alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
//	// this will read from file
//	char 	output[27] = {0};
//	
//	// prepare to write to a file
//	FILE *fp;
//	fp = freopen("tmp/alphabet.txt", "wr", stdout);
//	my_assert(fp != NULL, "failed to write alphabet to file!");
//	// the output of this will re redirected to the file now
//	ft_print_alphabet();
//	fclose(fp);
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	// now read from file to  my_assert
//	fp = fopen("tmp/alphabet.txt", "r");
//	my_assert(fp != NULL, "failed to read file!");
//	// assign the line found in fie to the var output
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	// this prints to the log
//	my_assert(strncmp(output, alphabet, 26) == 0, "Failed to print alphabet.");
//	debug("function output => %s",output);
//	
//	return NULL;
//}
//
//char *test_print_numbers()
//{
//	char	numbers[11] = "0123456789";
//	char 	output[11] = {0};
//	FILE *fp;
//	
//	fp = freopen("tmp/numbers.txt", "wr", stdout);
//	my_assert(fp != NULL, "failed to write numbers to file!");
//	
//	ft_print_numbers();
//	fclose(fp);
//	
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	
//	fp = fopen("tmp/numbers.txt", "r");
//	my_assert(fp != NULL, "failed to read file!");
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	my_assert(strncmp(output, numbers, 11) == 0, "Output is not as expected");
//	debug("function output => %s",output);
//	
//	return NULL;
//}
//
//char *test_is_negative()
//{
//	char	expect[4] = "NPP";
//	char 	output[4] = {0};
//	FILE *fp;
//	
//	fp = freopen("tmp/is_negative.txt", "wr", stdout);
//	my_assert(fp != NULL, "failed to write numbers to file!");
//	
//	ft_is_negative(-1);
//	ft_is_negative(1);
//	ft_is_negative(0);
//	fclose(fp);
//	
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	
//	fp = fopen("tmp/is_negative.txt", "r");
//	my_assert(fp != NULL, "failed to read file!");
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	my_assert(strncmp(expect, output, 4) == 0, "Output is not as expected");
//	debug("function output => %s",output);
//	
//	return NULL;
//}
//
//char *test_ft_ft()
//{
//	int nbr = 0;
//	ft_ft(&nbr);
//	my_assert( nbr == 42, "Output is not as expected");
//	nbr = -23423;
//	ft_ft(&nbr);
//	my_assert( nbr == 42, "Output is not as expected");
//
//	return NULL;
//}
//
//char *test_ft_swap()
//{
//	int a = 0;
//	int b = 42;
//	ft_swap(&a, &b);
//	my_assert( a == 42 && b == 0, "test 1 - Output is not as expected");
//	a = 0;
//	b = 0;
//	ft_swap(&a, &b);
//	my_assert( a == 0 && b == 0, "test 2 - Output is not as expected");
//	a = -42;
//	b = 42;
//	ft_swap(&a, &b);
//	my_assert( a == 42 && b == -42, "test 3 - Output is not as expected");
//	return NULL;
//}
//
//char *test_ft_mod()
//{
//	int a = 2;
//	int b = 42;
//	int div = 0;
//	int mod = 0;
//	ft_div_mod(a, b, &div, &mod);
//	my_assert( div == 0 && mod == 2, "test 1 - Output is not as expected");
//	a = 11;
//	b = 5;
//	ft_div_mod(a, b, &div, &mod);
//	my_assert( div == 2 && mod == 1, "test 2 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_iterative_factorial()
//{
//	my_assert( ft_iterative_factorial(2) == 2, "test 1 - Output is not as expected");
//	my_assert( ft_iterative_factorial(1) == 1, "test 2 - Output is not as expected");
//	my_assert( ft_iterative_factorial(0) == 1 , "test 3 - Output is not as expected");
//	my_assert( ft_iterative_factorial(-2) == 0, "test 4 - Output is not as expected");
//	my_assert( ft_iterative_factorial(-2) == 0, "test 5 - Output is not as expected");
//	my_assert( ft_iterative_factorial(13) == 0, "test 6 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_recursive_factorial()
//{
//	my_assert( ft_recursive_factorial(2) == 2, "test 1 - Output is not as expected");
//	my_assert( ft_recursive_factorial(1) == 1, "test 2 - Output is not as expected");
//	my_assert( ft_recursive_factorial(0) == 1 , "test 3 - Output is not as expected");
//	my_assert( ft_recursive_factorial(-2) == 0, "test 4 - Output is not as expected");
//	my_assert( ft_recursive_factorial(-2) == 0, "test 5 - Output is not as expected");
//	my_assert( ft_recursive_factorial(13) == 0, "test 6 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_sqrt()
//{
//	my_assert( ft_sqrt(2) == 0, "test 1 - Output is not as expected");
//	my_assert( ft_sqrt(1) == 1, "test 2 - Output is not as expected");
//	my_assert( ft_sqrt(0) == 0 , "test 3 - Output is not as expected");
//	my_assert( ft_sqrt(-2) == 0, "test 4 - Output is not as expected");
//	my_assert( ft_sqrt(4) == 2, "test 5 - Output is not as expected");
//	my_assert( ft_sqrt(9) == 3, "test 6 - Output is not as expected");
//	my_assert( ft_sqrt(2147395600) == 46340, "test 7 - Output is not as expected");
//	my_assert( ft_sqrt(INT_MAX) == 0, "test 8 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_ft_putstr()
//{
//	// create the string that I am expected to see in output
//	// will not take special chars like newline and no spaces because 
//	// the testing would get extremely complicated
//	char	str[27] = "HelloWorld";
//	// this will read from file
//	char 	output[27] = {0};
//	
//	// prepare to write to a file
//	FILE *fp;
//	fp = freopen("tmp/ft_putstr.txt", "wr", stdout);
//	my_assert(fp != NULL, "failed to write alphabet to file!");
//	// the output of this will re redirected to the file now
//	ft_putstr(str);
//	fclose(fp);
//	// resetting the normal behaviour for stdout
//	freopen ("/dev/tty", "a", stdout);
//	// now read from file to  my_assert
//	fp = fopen("tmp/ft_putstr.txt", "r");
//	my_assert(fp != NULL, "failed to read file!");
//	// assign the line found in fie to the var output
//	fscanf(fp, "%s", output);
//	fclose(fp);
//	// this prints to the log
//	debug("function output => %s",output);
//	my_assert(strncmp(output, str, 26) == 0, "Failed to print str.");
//	debug("function output => %s",output);
//	return NULL;
//}
//
//// will not account for non terminated strings!
//char *test_ft_strlen()
//{
//	my_assert( ft_strlen("") == 0, "test 1 - Output is not as expected");
//	my_assert( ft_strlen("1") == 1, "test 2 - Output is not as expected");
//	my_assert( ft_strlen("hello") == 5 , "test 3 - Output is not as expected");
//	return NULL;
//}
//
//// will not account for non terminated strings!
//char *test_ft_strcmp()
//{
//	int output = ft_strcmp("w", "w");
//	debug("function output => %d",output);
//	my_assert( output == 0, "test 1 - Output is not as expected");
//	output = ft_strcmp("12", "11");
//	debug("function output => %d",output);
//	my_assert( output == 1, "test 2 - Output is not as expected");
//	output = ft_strcmp("hello", "hellp");
//	debug("function output => %d",output);
//	my_assert( output == -1 , "test 3 - Output is not as expected");
//	return NULL;
//}
//
//// I skip the programs here for now...
//// I would need a shell script to  my_assert them
//
//// will not account for non terminated strings!
//char *test_ft_strdup()
//{
//	char *output = ft_strdup("hello world");
//	debug("function output => %s",output);
//	my_assert(ft_strcmp(output, "hello world") == 0, "test 1 - Output is not as expected");
//	
//	return NULL;
//}
//
//char *test_ft_range()
//{
//	int *range = ft_range(-1, 3);
//	debug("function output => %d %d", range[0], range[1]);
//	my_assert(range[0] == -1 && range[1] == 0, "test 1 - Output is not as expected");
//	my_assert(range[2] == 1 && range[3] == 2, "test 1 - Output is not as expected");
//	range = ft_range(-1, -1);
//	my_assert(range == NULL , "test 3 - Output is not as expected");
//	return NULL;
//}

char *all_tests()
{
	mu_suite_start();
	
	mu_run_test(test_ft_isalpha);
	mu_run_test(test_ft_isdigit);
	mu_run_test(test_ft_isalnum);
	mu_run_test(test_ft_isascii);
	mu_run_test(test_ft_isprint);
	mu_run_test(test_ft_strlen);
	mu_run_test(test_ft_memset);
	
	mu_run_test(test_ft_strncmp);
	mu_run_test(test_ft_bzero);
	mu_run_test(test_ft_memcpy);
	mu_run_test(test_ft_memmove);
	mu_run_test(test_ft_strlcpy);
	mu_run_test(test_ft_strlcat);
	mu_run_test(test_ft_toupper);
	mu_run_test(test_ft_tolower);
	mu_run_test(test_ft_strchr);
	mu_run_test(test_ft_strrchr);
	mu_run_test(test_ft_memchr);
	mu_run_test(test_ft_memcmp);
	mu_run_test(test_ft_strnstr);
	mu_run_test(test_ft_atoi);
	mu_run_test(test_ft_calloc);
	mu_run_test(test_ft_strdup);
	
	return NULL;
}

RUN_TESTS(all_tests);

