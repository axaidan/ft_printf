#include "libft.h"

int main(void)
{
	int	ret_lib;
	int	ret_ft_;
//	ft_printf("%12038123c%c%c %d%120983s\n", 'a', 'b', 'c', 440, " blabla");
//	ft_printf("bla bla bla |%*.*d|\n", 20, 10, -100);	
//	ft_printf("bla bla bla |%*.*d| et un autre |%5.*d|\n", 15, 10, -100, 4, -2);	
	ret_ft_ = ft_printf("bla bla bla |%*.*d| et un autre |%5.*d| et un 3eme |%0*i|\n", 15, 10, -100, 4, -2, 3, -120987);	
	ret_lib = printf("bla bla bla |%*.*d| et un autre |%5.*d| et un 3eme |%0*i|\n", 15, 10, -100, 4, -2, 3, -120987);	
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n", ret_lib);
	ret_ft_ = ft_printf("");
	ret_lib = printf("");
	printf("ret_ft_\t=\t%4d\n", ret_ft_);
	printf("ret_lib\t=\t%4d\n", ret_lib);
//	printf("bla bla bla |%5d|\n", 100);
	return (0);
}
