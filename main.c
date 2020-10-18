#include "libft.h"

int main(void)
{
	int	ret_lib;
	int	ret_ft_;
	char	*p_null;

	/*
	 * INT AND UNSIGNED INT
	 */
	ret_ft_ = ft_printf("bla bla bla |%*.*d| et un autre |%5.*d| et un 3eme |%0*i|\n", 15, 10, -100, 4, -2, 3, -120987);	
	ret_lib = printf("bla bla bla |%*.*d| et un autre |%5.*d| et un 3eme |%0*i|\n", 15, 10, -100, 4, -2, 3, -120987);	
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"\"\n");
	ret_lib = printf("\"\"\n");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"%d\"\n", -2147483648);
	ret_lib = printf("\"%d\"\n", -2147483647 -1);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"%d\"\n", -100);
	ret_lib = printf("\"%d\"\n", -100);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"%u %u %u %u\"\n", -100, 1, 0, -10);
	ret_lib = printf("\"%u %u %u %u\"\n", -100, 1, 0, -10);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"%9.2d %0u %.u %-12.1d blabla %-10d\"\n", -100, 1, 0, -10, 42);
	ret_lib = printf("\"%9.2d %0u %.u %-12.1d blabla %-10d\"\n", -100, 1, 0, -10, 42);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	/*
	 * CHARS 
	 */
	ret_ft_ = ft_printf("\"|%c| |%c| |%c|\"\n", 'i', 'a', '9');
	ret_lib = printf("\"|%c| |%c| |%c|\"\n", 'i', 'a', '9');
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"|%3c| |%-10c| |%-1c|\"\n", 'i', 'o', '0');
	ret_lib = printf("\"|%3c| |%-10c| |%-1c|\"\n", 'i', 'o', '0');
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"bla bla bla |%*c| |%-*c|\"\n", 4, '#', 12, '1');
	ret_lib = printf("\"bla bla bla |%*c| |%-*c|\"\n", 4, '#', 12, '1');
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	ret_ft_ = ft_printf("\"bla bla bla |%*c| |%-*c|\"\n", 4, '#', 12, '1');
	ret_lib = printf("\"bla bla bla |%*c| |%-*c|\"\n", 4, '#', 12, '1');
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	/*
	 * STRS
	 */
	ret_ft_ = ft_printf("\"%s\"\n", "lalalalala");
	ret_lib = printf("\"%s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%30s\"\n", "lalalalala");
	ret_lib = printf("\"%30s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%30.5s\"\n", "lalalalala");
	ret_lib = printf("\"%30.5s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%-30s\"\n", "lalalalala");
	ret_lib = printf("\"%-30s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%-30.5s\"\n", "lalalalala");
	ret_lib = printf("\"%-30.5s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%-2.6s\"\n", "lalalalala");
	ret_lib = printf("\"%-2.6s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%-2.s\"\n", "lalalalala");
	ret_lib = printf("\"%-2.s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%-2.s %*.*s %1.s %*.2s %.si\"\n", "lalalalala", 8, 1, "bebe", "yo", 4, "c'est", "cool");
	ret_lib = printf("\"%-2.s %*.*s %1.s %*.2s %.si\"\n", "lalalalala", 8, 1, "bebe", "yo", 4, "c'est", "cool");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	p_null = NULL;
	//ret_lib = printf("\"%.5s\"\n", p_null);
	//ret_ft_ = ft_printf("\"%.5s\"\n", p_null);
	ret_lib = printf("\"%-*.6s\"\n", -20, NULL);
	ret_ft_ = ft_printf("\"%-*.6s\"\n", -20, NULL);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
	 /*

	 // HEX
	ret_ft_ = ft_printf("\"%3.x %10.3X |%-15.8X| %x %10.12x\"\n", 1209873, 129387, 12390871, 478, 347896);
	ret_lib = printf("\"%3.x %10.3X |%-15.8X| %x %10.12x\"\n", 1209873, 129387, 12390871, 478, 347896);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"bla bla bla%x %-13X\"\n", 0, -123);
	ret_lib = printf("\"bla bla bla%x %-13X\"\n", 0, -123);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%s\"\n", "lalalalala");
	ret_lib = printf("\"%s\"\n", "lalalalala");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	// PTR
	ret_ft_ = ft_printf("\"%p\"\n", &ret_ft_);
	ret_lib = printf("\"%p\"\n", &ret_ft_);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);

	ret_ft_ = ft_printf("\"%p\"\n", NULL);
	ret_lib = printf("\"%p\"\n", NULL);
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n\n", ret_lib);
*/

	return (0);
}
