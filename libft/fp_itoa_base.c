/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 19:14:21 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/27 08:36:27 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recurse(unsigned int nb, int base, char **output, int a)
{
	if (nb / base > 0)
		recurse(nb / base, base, output, a - 1);
	nb %= base;
	if (nb < 10)
		output[0][a] = '0' + nb;
	if (nb > 10)
		output[0][a] = 'a' + nb - 10;
}

char	*fp_itoa_base(unsigned int nb, int base)
{
	char	*output;
	int	a;
	unsigned int	temp;

	temp = nb;
	a = 1;
	while (temp >= (unsigned int)base)
	{
		temp /= base;
		a++;
	}
	output = (char *)malloc((a + 1) * sizeof(char));
	recurse(nb, base, &output, a - 1);
	return (output);
}
