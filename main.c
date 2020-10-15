#include "libft.h"

int main(void)
{
	int	ret_lib;
	int	ret_ft_;
	ret_ft_ = ft_printf("bla bla bla |%*.*d| et un autre |%5.*d| et un 3eme |%0*i|\n", 15, 10, -100, 4, -2, 3, -120987);	
	ret_lib = printf("bla bla bla |%*.*d| et un autre |%5.*d| et un 3eme |%0*i|\n", 15, 10, -100, 4, -2, 3, -120987);	
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n", ret_lib);
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
	return (0);
}
