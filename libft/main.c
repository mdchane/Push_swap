#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <ctype.h>

void	f1(char *c)
{
	write(1, c, 1);
}
void	f2(unsigned int i, char *c)
{
	printf("(i: %d = %c) //", i, *c);
}
char	f3(char c) 
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
char	f4(unsigned int i, char c) 
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c + (i%2));
}

int		main()
{
	char str1[7] = "salut";
	char str2[7] = "coucou";

//ft_strlen
	printf("ft_strlen : %ld\n", ft_strlen(str1));
	printf("strlen : %ld\n", strlen(str1));
	printf("--------------------------------\n");
//ft_strcpy
	printf("ft_strcpy : %s\n", ft_strcpy(str1, str2));
	char str1b[7] = "salut";
	printf("strcpy : %s\n", strcpy(str1b, str2));
	printf("--------------------------------\n");

//ft_strncpy
	char str3[10] = "saluttoi";
	char str4[7] = "coucou";
	printf("ft_strncpy : %s\n", ft_strncpy(str3, str4, 4));
	char str3b[10] = "saluttoi";
	printf("strncpy : %s\n", strncpy(str3b, str4, 4));
	printf("--------------------------------\n");

//ft_strstr
	char *str5 = "bc";
	char *str6 = "abcdef";
	printf("ft_strstr(%s, %s) : %s\n", str5, str6, ft_strstr(str5, str6));
	printf("strstr(%s, %s) : %s\n", str5, str6, strstr(str5, str6));
	printf("--------------------------------\n");

//ft_strnstr
	printf("ft_strnstr(%s, %s, %d) : %s\n", str5, str6, 2, ft_strnstr(str5, str6, 2));
	printf("strnstr(%s, %s, %d) : %s\n", str5, str6, 2, strnstr(str5, str6, 2));
	printf("--------------------------------\n");

//ft_strcmp

	printf("ft_strcmp(%s, %s) : %d\n", str5, str6, ft_strcmp(str5, str6));
	printf("strcmp(%s, %s) : %d\n", str5, str6, strcmp(str5, str6));
	printf("--------------------------------\n");

//ft_strncmp

	printf("ft_strncmp(%s, %s) : %d\n", str5, str6, ft_strncmp(str5, str6, 2));
	printf("strncmp(%s, %s) : %d\n", str5, str6, strncmp(str5, str6, 2));
	printf("--------------------------------\n");

	//ft_strcat

	char s7[12] = "salut";
	char s7b[12] = "salut";
	printf("ft_strcat(%s, %s) : %s\n", s7, s7b, ft_strcat(s7, s7b));
	char s7c[6] = "salut";
	printf("strcat(%s, %s) : %s\n", s7b, s7c, strcat(s7b, s7c));
	printf("--------------------------------\n");

	//ft_strncat

	char s8[30] = "coucou";
	char s8b[30] = "coucou";
	printf("ft_strncat(%s, %s, 3) : %s\n", s8, s8b, ft_strncat(s8, s8b, 3));
	char s8c[7] = "coucou";
	printf("strncat(%s, %s, 3) : %s\n", s8b, s8c, strncat(s8b, s8c, 3));
	printf("--------------------------------\n");

	//ft_strlcat
	char s9[10] = "salut";
	char s9b[4] = "toi";
	char s9c[10] = "salut";
	char s9d[4] = "toi";
	printf("ft_strlcat(%s, %s, 10) : %ld\n", s9, s9b, ft_strlcat(s9, s9b, 10));
	printf("str appendé par ft_strlcat : %s\n", s9);
	printf("strlcat(%s, %s, 10) : %ld\n", s9c, s9d, strlcat(s9c, s9d, 10));
	printf("str appendé par strlcat : %s\n", s9c);
	printf("--------------------------------\n");

	//ft_strdup
	printf("ft_strdup(s10, %s) : %s\n", s9b, ft_strdup(s9b));
	printf("strdup(s10b, %s) : %s\n", s9b, ft_strdup(s9b));
	printf("--------------------------------\n");


	//ft_strchr
	char *s10 = "salut";
	char c = 'l';
	printf("ft_strchr(%s, %d) : %p\n", s10, c, ft_strchr(s10, c));
	printf("strchr(%s, %d) : %p\n", s10, c, strchr(s10, c));
	printf("--------------------------------\n");

	//ft_strrchr
	printf("ft_strlcat(%s, %s) : %ld\n", s9, s9b, ft_strlcat(s9, s9b, 10));
	printf("str appendé par strlcat : %s\n", s9);
	printf("strlcat(%s, %s) : %ld\n", s9, s9b, ft_strlcat(s9, s9b, 10));
	printf("str appendé par strlcat : %s\n", s9);
	printf("--------------------------------\n");

	//ft_strdup
	printf("ft_strdup(s10, %s) : %s\n", s9b, ft_strdup(s9b));
	printf("strdup(s10b, %s) : %s\n", s9b, ft_strdup(s9b));
	printf("--------------------------------\n");


	//ft_strchr
	printf("ft_strchr(%s, %d) : %p\n", s10, c, ft_strchr(s10, c));
	printf("strchr(%s, %d) : %p\n", s10, c, strchr(s10, c));
	printf("--------------------------------\n");

	//ft_strrchr
	char *s10b = "salutl";
	char d = 'l';
	printf("ft_strchr(%s, %c) : %p\n", s10b, d, ft_strchr(s10b, d));
	printf("ft_strrchr(%s, %c) : %p\n", s10b, d, ft_strrchr(s10b, d));
	printf("strrchr(%s, %c) : %p\n", s10b, d, strrchr(s10b, d));
	printf("--------------------------------\n");

	//memset
	char	p[7] = "memset";
	int		cm = '*';
	size_t	n = 2;
	printf("p : %s\n", p);
	memset(p, cm, n);
	printf("memset(p, %c, %ld) : %s\n", cm, n, p);
	ft_memset(p, 's', n);
	printf("ft_memset(p, %c, %ld) : %s\n", 's', n, p);
	printf("--------------------------------\n");

	//bzero
	char	p1[6] = "bzero";
	size_t	n1 = 3;
	printf("p1 : %s\n", p1);
	bzero(p1, n1);
	printf("bzero(p1, n1): %s\n", p1);
	char	p2[6] = "bzero";
	printf("p2 : %s\n", p2);
	ft_bzero(p2, n1);
	printf("ft_bzero(p2, n1): %s\n", p2);
	printf("--------------------------------\n");

	//memcpy
	char	p3[5] = "damn";
	char	p4[5] = "helo";
	size_t	n2 = 3;
	printf("p3 : %s & p4 : %s\n", p3, p4);
	ft_memcpy(p4, p3, n2);
	printf("ft_memcpy(p4, p3,  %ld) => p3 : %s & p4 : %s\n", n2, p3, p4);
	printf("--------------------------------\n");

	//memccpy
	char	det[] = "saluttoi";
	char	*dest = det;
	char	*src = det;

	memcpy(dest + 3, dest, 3);
	printf("memcpy : %s\n", dest);
	ft_memcpy(src + 3, src, 3);
	printf("ft_memcpy %s\n", src);
	printf("--------------------------------\n");

	char	det1[] = "saluttoi";
	char	*dest1 = det1;
	char	*src1 = det1;

	memmove(dest1 + 3, dest1, 3);
	printf("memmove %s\n", dest1);
	ft_memmove(src1 + 3, src1, 3);
	printf("ft_memmove %s\n", src1);
	printf("--------------------------------\n");

	//memchr
	char	p5[] = "lafac";
	c = 'c';
	n = 5;
	printf("memchr(%s, %c, %ld) : %p\n", p5, c, n, memchr(p5, c, n));
	printf("ft_memchr(%s, %c, %ld) : %p\n", p5, c, n, ft_memchr(p5, c, n));
	printf("--------------------------------\n");

	//memcmp
	char	p6[] = "ladac";
	printf("memcmp(%s, %s, %ld) : %d\n", p5, p6, n, memcmp(p5, p6, n));
	printf("ft_memcmp(%s, %s, %ld) : %d\n", p5, p6, n, ft_memcmp(p5, p6, n));
	printf("--------------------------------\n");

	//atoi
	char	p7[] = "-98986";
	printf("atoi(%s) = %d\n", p7, atoi(p7));
	printf("ft_atoi(%s) = %d\n", p7, ft_atoi(p7));

	//isalpha
	int		i = 'Z';
	printf("ft_isalpha(%c) : %d\n", i, ft_isalpha(i));
	printf("ft_isdigit(%c) : %d\n", i, ft_isdigit(i));
	printf("ft_isalnum(%c) : %d\n", i, ft_isalnum(i));
	printf("ft_isprint(%c) : %d\n", i, ft_isprint(i));
	printf("ft_isascii(%c) : %d\n", i, ft_isascii(i));

	int		i2 = 'j';
	printf("ft_tolower(%c) : %c\n", i, ft_tolower(i));
	printf("ft_toupper(%c) : %c\n", i2, ft_toupper(i2));
	printf("--------------------------------\n");

	//memalloc
	void	*ptr = NULL;
	printf("ptr : %p\n", ptr);
	ptr = ft_memalloc(0);
	printf("after memalloc\n");
	printf("ptr : %p : %s\n", ptr, ptr);
	printf("--------------------------------\n");

	//memdell
	void	**ptr1 = &ptr;
	printf("ptr1 : %p & *ptr1 : %p\n", ptr1, *ptr1);
	ft_memdel(ptr1);
	printf("after memdell\n");
	printf("ptr1 : %p & *ptr1 : %p\n", ptr1, *ptr1);
	printf("--------------------------------\n");

	//strnew
	char	t[] = "hello";
	char	*t1 = t;
	printf("t1: adr %p,  %s\n", t, t1);
	t1 = ft_strnew(2);
	printf("t1 = ft_strnew(2)\n");
	printf("t1: adr %p,  %s\n", t1, t1);
	ft_strdel(&t1);
	printf("ft_strdel(&t1)\n");
	printf("t1 :adr %p,  %s\n", t1, t1);
	printf("--------------------------------\n");

	//strclr
	char	t2[] = "hello";
	printf("t2 : %s\n", t2);
	ft_strclr(t2);
	printf("ft_strclr(t2)\n");
	printf("t2 : %s\n", t2);
	printf("--------------------------------\n");

	//striter
	char	t3[] = "SaLUt CommENt";
	printf("t3 : %s\n", t3);
	printf("ft_striter(t3, &f1)\n");
	ft_striter(t3, &f1);
	printf("\n--------------------------------\n");

	//striteri
	printf("t3 : %s\n", t3);
	printf("ft_striteri(t3, &f2)\n");
	ft_striteri(t3, &f2);
	printf("\n--------------------------------\n");

//strmap
	printf("t3 : %s\n", t3);
	printf("ft_strmap(t3, &ft_toupper) : %s\n", ft_strmap(t3, &f3));
	printf("\n--------------------------------\n");
//strmapi
	printf("t3 : %s\n", t3);
	printf("ft_strmap(t3, &ft_toupper) : %s\n", ft_strmapi(t3, &f4));
	printf("\n--------------------------------\n");

//strequ
	char	t4[] = "salut";
	char	t5[] = "salu";
	size_t	n6 = 3;

	printf("t4 : %s et t5 : %s\n", t4, t5);
	printf("strequ : %d\n", ft_strequ(t4, t5));
	printf("strenqu with n = %ld: %d\n", n6,  ft_strnequ(t4, t5, n6));
	printf("\n--------------------------------\n");


//ft_strsub
	char	t6[10] = "salut toi";
	printf("t6 = %s\n", t6);
	printf("ft_strsub(t6, 3, 2) = %s\n", ft_strsub(t6, 3, 2));
	printf("\n--------------------------------\n");

//ft_strjoin
	char	t7[7] = "coucou";
	printf("t7 = %s\n", t7);
	printf("ft_strjoin t6 & t7 = %s\n", ft_strjoin(t6, t7));
	printf("\n--------------------------------\n");

//ft_strtrim
	char	t8[] = "       hello world     ";
	printf("t8 = $%s$\nAfter ft_strtrim = $%s$\n", t8, ft_strtrim(t8));
	printf("\n--------------------------------\n");

//ft_strsplit
	int		k=0;
	char	**tab;
	tab = ft_strsplit("*salut*les***etudiants*", '*');
	while (tab[k])
	{
		printf("tab[%d] = %s\n", k, tab[i]);
		k++;
	}
	printf("\n--------------------------------\n");
//ft_itoa
	printf("itoa = %s\n", ft_itoa(-2147483648));
	printf("\n--------------------------------\n");

//ft_putnbr
	ft_putnbr(14464);

	return (0);
}
