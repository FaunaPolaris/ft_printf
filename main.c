#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	x, y;
	unsigned int u = 2147483648;
	void	*p = malloc(1);


	ft_printf("You:\n\n");
//	tests for i;
	x = ft_printf("%%i test:%i, %i, %i, %i\nWith flags:\n\n Precision:\n Inplicit zero:%.i, explicit zero:%.0i, higher:%.12i, lower:%.5i\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = ft_printf("zero padding:\n lower:%01i higher:%010i\nleft ajustment:\n lower:%-1i, higher:%-12i.\nfield width:\n lower%1i, higher:%12i\n",15, 0xf, 15, 0xf, 15, 0xf);
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for d;
	ft_printf("%%d test:%d, %d, %d, %d\nWith flags:\n\n Precision:\n Inplicit zero:%.d, explicit zero%.0d, higher:%.12d, lower:%.5d\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = ft_printf("zero padding:\n lower:%01d higher:%010d\nleft ajustment:\n lower:%-1d, higher:%-12d\n field width:\nlower:%1d, higher:%12d\n",15, 0xf, 15, 0xf, 15, 0xf);
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for s;
	x = ft_printf("%%s test:%s, %s, %s, %s\nWith flags:\n\n Precision:\n mandatory null:%.3s, no null:%.4s\n", "Fauna", "Polaris", "Pinheiro", "Leite", "da", "Rosa");
	y =ft_printf("left ajustment:\n lower:%-1s, higher:%-12s\nfield width:\n lower%1s, higher:%12s\n","Polaris", "Polaris", "Polaris", "Polaris");
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for c;
	x = ft_printf("%%c test:ASCII: %c, %c\nnon ASCII: %c, %c\n",'T', '4', -4, 157);
	y = ft_printf("non printables: %c, %c\n", '\n', '\0');
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for x;
	x = ft_printf("%%x test:%x, %x, %x, %x\nWith flags:\n\n Precision:\n Inplicit zero:%.x, explicit zero%.0x, higher:%.12x, lower:%.5x\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = ft_printf("zero padding:\n lower:%01x higher:%010x\nleft ajustment:\n lower:%-1x, higher:%-12x\nfield width:\n lower%1x, higher:%12x\nunsigned int: %x\n",15, 0xf, 15, 0xf, 15, 0xf, u);
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for X;
	x = ft_printf("%%X test:%X, %X, %X, %X\nWith flags:\n\n Precision:\n Inplicit zero:%.X, explicit zero%.0X, higher:%.12X, lower:%.5X\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = ft_printf("zero padding:\n lower:%01X higher:%010X\nleft ajustment:\n lower:%-1X, higher:%-12X\nfield width:\n lower%1X, higher:%12X\nunsigned int: %x\n",15, 0xf, 15, 0xf, 15, 0xf, u);
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for u;
	x = ft_printf("%%u test:%u, %u, %u, %u\nWith flags:\n\n Precision:\n Inplicit zero:%.u, explicit zero%.0u, higher:%.12u, lower:%.5u\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = ft_printf("zero padding:\n lower:%01u higher:%010u\nleft ajustment:\n lower:%-1u, higher:%-12u\nfield width:\n lower%1u, higher:%12u\nunsigned int: %x\n",15, 0xf, 15, 0xf, 15, 0xf, u);
	ft_printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for p;
	ft_printf("poiter in Hexadecimal: %p\n", p);


	printf("\n\n\nStd:\n\n");
//	tests for i;
	x = printf("%%i test:%i, %i, %i, %i\nWith flags:\n\n Precision:\n Inplicit zero:%.i, explicit zero:%.0i, higher:%.12i, lower:%.5i\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
		y = printf("zero padding:\n lower:%01i higher:%010i\nleft ajustment:\n lower:%-1i, higher:%-12i.\nfield width:\n lower%1i, higher:%12i\n",15, 0xf, 15, 0xf, 15, 0xf);
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for d;
	printf("%%d test:%d, %d, %d, %d\nWith flags:\n\n Precision:\n Inplicit zero:%.d, explicit zero%.0d, higher:%.12d, lower:%.5d\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = printf("zero padding:\n lower:%01d higher:%010d\nleft ajustment:\n lower:%-1d, higher:%-12d\n field width:\nlower:%1d, higher:%12d\n",15, 0xf, 15, 0xf, 15, 0xf);
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for s;
	x = printf("%%s test:%s, %s, %s, %s\nWith flags:\n\n Precision:\n mandatory null:%.3s, no null:%.4s\n", "Fauna", "Polaris", "Pinheiro", "Leite", "da", "Rosa");
	y = printf("left ajustment:\n lower:%-1s, higher:%-12s\nfield width:\n lower%1s, higher:%12s\n", "Polaris", "Polaris", "Polaris", "Polaris");
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for c;
	x = printf("%%c test:ASCII: %c, %c\nnon ASCII: %c, %c\n",'T', '4', -4, 157);
	y = printf("non printables: %c, %c\n", '\n', '\0');
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for x;
	x = printf("%%x test:%x, %x, %x, %x\nWith flags:\n\n Precision:\n Inplicit zero:%.x, explicit zero%.0x, higher:%.12x, lower:%.5x\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = printf("zero padding:\n lower:%01x higher:%010x\nleft ajustment:\n lower:%-1x, higher:%-12x\nfield width:\n lower%1x, higher:%12x\nunsigned int: %x\n",15, 0xf, 15, 0xf, 15, 0xf, u);
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for X;
	x = printf("%%X test:%X, %X, %X, %X\nWith flags:\n\n Precision:\n Inplicit zero:%.X, explicit zero%.0X, higher:%.12X, lower:%.5X\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = printf("zero padding:\n lower:%01X higher:%010X\nleft ajustment:\n lower:%-1X, higher:%-12X\nfield width:\n lower%1X, higher:%12X\nunsigned int: %x\n",15, 0xf, 15, 0xf, 15, 0xf, u);
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for u;
	x = printf("%%u test:%u, %u, %u, %u\nWith flags:\n\n Precision:\n Inplicit zero:%.u, explicit zero%.0u, higher:%.12u, lower:%.5u\n",15, INT_MIN, 0xf, INT_MAX, 0, 0, 12, 123456);
	y = printf("zero padding:\n lower:%01u higher:%010u\nleft ajustment:\n lower:%-1u, higher:%-12u\nfield width:\n lower%1u, higher:%12u\nunsigned int: %x\n",15, 0xf, 15, 0xf, 15, 0xf, u);
	printf("characters printed:%i\n", x + y);
	printf("\n\n");
//	tests for p;
	printf("poiter in Hexadecimal: %p\n", p);
	free(p);
	return (0);
}
