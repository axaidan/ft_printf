#include "libft.h"

void	display_struct(t_substr substr)
{
	printf("=== DISPLAY STRUCT ===\n");
	printf("\ti\t=\t%d\n", substr.i);
	printf("\tc\t=\t%c\n", substr.c);
	printf("\tstr\t=\t%s\n", substr.str);
	printf("\tptr\t=\t%p\n", substr.ptr);
	printf("\twidth\t=\t%d\n", substr.width);
	printf("\tpreci\t=\t%d\n", substr.preci);
	printf("\tf_zero\t=\t%d\n", substr.f_zero);
	printf("\tf_minus\t=\t%d\n", substr.f_minus);
	printf("\tsub\t=\t%s\n", substr.sub);
}
