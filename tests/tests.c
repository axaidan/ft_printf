#include <stdio.h>

int	main(int ac, char *av[])
{
	int		width;
	float	f;
	int		i;
	int		precision;
	char	str[] = "str qui";
	char	*ptr;
	char	c;
	int		ret_lib;
	void	*p;
	unsigned int	hex;

	/*
	width = 8;
	c = 'c';
	precision = 10;
	i = -100;
	f = 1.2344;
	printf("tests with \'0\' ===> %.0d\n", 0);
	printf("i = |%05d|\n", i);
	printf("i = |%.5d|\n", i);
	printf("|%-03.5c|\n", c);
	printf("i = %*.*x\n", width, precision, i);
	printf("f = %*.*f\n", width, precision, f);
	printf("str = %20s", str);
	printf("str = %-20s", str);
	printf("str = %020s", str);


	printf("||\n");
	printf("long str with a backslash zero included here%c but goes on\n", '\0');
	ret_lib = printf("%c\a\b\t\v\f\r\n", 1);
	printf("ret_lib = %d\n", ret_lib);
	ptr = str;
	printf("%p\n", ptr);
	*/


	hex = 11902345; 
	printf("%%x\t|%-12.20x|\n", hex);
	printf("%%X\t|%-12.20X|\n", hex);
	printf("%%x\t|%020x|\t flag '0' width 20\n", hex);
	printf("%%X\t|%.20X|\t preci 20\n", hex);
	printf("%%X\t|%25.20X|\n", hex);
	printf("%%X\t|%025X|\n", hex);

	p = &hex;
	printf("\"|%p|, |%20p|, |%0.15p|, |%-25p|\"\n", p, p, p, p);
	printf("\"|%p|\n", p);
	printf("\"|%#lx|\n", (long)p);
	printf("\"|%#x|\n", (int)p);
	printf("size of long %d\n", sizeof(long));
	printf("size of int %d\n", sizeof(unsigned int));
	printf("u_int_max ==> %u\n", -1);
	printf("\"%%p ==> |%30p|\n", NULL);
	printf("\"%%s ==> |%30s|\n", NULL);
	printf("\"|%#lx|\n", (long)NULL);
	printf("\"30.2%s\"\n", (char*)NULL);

	return (0);
}
