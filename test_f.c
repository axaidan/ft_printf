#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char *av[])
{
	int 	ret_ft_;
	int		ret_lib;
	double	d;
	int		preci;
	int		width;

	d = atof(av[1]);
	if (ac == 2)
	{
		preci = -1;
		width = 0;
		ret_lib = printf("lib\t=\t\"%f\"\n", d);
		ret_ft_ = ft_printf("ft_\t=\t\"%f\"\n", d);
		printf("ret_lib\t=\t%3d\nret_ft_\t=\t%3d\n\n", ret_lib, ret_ft_);
	}
	else if (ac == 3)
	{
		preci = -1;
		width = atoi(av[2]);
		ret_lib = printf("lib\t=\t\"%*f\"\n", width, d);
		ret_ft_ = ft_printf("ft_\t=\t\"%*f\"\n", width, d);
		printf("ret_lib\t=\t%3d\nret_ft_\t=\t%3d\n\n", ret_lib, ret_ft_);
	}
	else if (ac == 4)
	{
		preci = atoi(av[3]);
		width = atoi(av[2]);
		ret_lib = printf("lib\t=\t\"%*.*f\"\n", width, preci, d);
		ret_ft_ = ft_printf("ft_\t=\t\"%*.*f\"\n", width, preci, d);
		printf("ret_lib\t=\t%3d\nret_ft_\t=\t%3d\n\n", ret_lib, ret_ft_);
	}
}
