/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:01:31 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/10 15:11:19 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_len(int nb, int output, int base)
{
	while ((nb / base) > 0)
	{
		nb /= base;
		output++;
	}
	return (output);
}

int	fp_putnbr_base(unsigned int nb, int base, int up)
{
	if ((nb / base) > 0)
		fp_putnbr_base(nb / base, base, up);
	nb %= base;
	if (nb < 10)
		fp_putchar_fd('0' + nb, 1);
	if (nb > 10 && up == 0)
		fp_putchar_fd('a' + nb - 10, 1);
	if (nb > 10 && up == 1)
		fp_putchar_fd('A' + nb - 10, 1);
	return (number_len(nb, 0, base));
}
