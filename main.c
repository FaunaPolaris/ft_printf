#include "libft.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	x; 
//	char	*str = "Fauna Polaris";
//	void	*p = malloc(1);
//	unsigned int y = 2147483648;

/*	ft_printf("my output:\n\n");
	x = ft_printf("string: %s", str);
	ft_printf("\ncharacters printed: %i", x);
	x = ft_printf("\npointer: %p", p);
	ft_printf("\ncharacters printed: %i", x);
	x = ft_printf("\nint max: %i", INT_MAX);
	ft_printf("\ncharacters printed: %i", x);
	x = ft_printf("\nint min: %i", INT_MIN);
	ft_printf("\ncharacters printed: %i", x);
	x = ft_printf("\nunsigned int: %u", y);
	ft_printf("\ncharacters printed: %i", x);
	x = ft_printf("\nflag %%%%: %%");
	ft_printf("\ncharacters printed: %i", x);
	
	ft_printf("\n\nstd output:\n\n");
	x = printf("string: %s", str);
	printf("\ncharacters printed: %i", x);
	x = printf("\npointer: %p", p);
	printf("\ncharacters printed: %i", x);
	x = printf("\nint max: %i", INT_MAX);
	printf("\ncharacters printed: %i", x);
	x = printf("\nint min: %i", INT_MIN);
	printf("\ncharacters printed: %i", x);
	x = printf("\nunsigned int: %u", y);
	printf("\ncharacters printed: %i", x);
	x = printf("\nflag %%%%: %%");
	printf("\ncharacters printed: %i", x);
*/
	x = ft_printf("\n%-3s\n", "Fauna");
	ft_printf("\ncharacters printed: %i", x);
	x = printf("\n%-3s\n", "Fauna");
	printf("\ncharacters printed: %i", x);
	x = ft_printf("%");
	ft_printf("\ncharacters printed: %i", x);
	return (0);
}
