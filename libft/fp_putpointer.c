/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:30:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/26 15:26:22 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_putpointer(const void *ptr)
{
	int		output;
	int		digit;
	int		bitsize;
	int		i;
	long long	efigy;

	output = 3;
	fp_putstr_fd("0x", 1);
	efigy = (long long)ptr;
	bitsize = (sizeof(void *) * 8);
	i = bitsize - 4;
	while (((efigy >> i) & 0xf) == 0)
		i -= 4;
	while (i > 0)
	{
		digit = (efigy >> i) & 0xf;
		if (digit < 10)
			fp_putchar_fd('0' + digit, 1);
		else if (digit > 10)
			fp_putchar_fd('a' + digit - 10, 1);
		output += 1;
		i -= 4;
	}
	fp_putstr_fd("a0", 1);
	return (output);
}
