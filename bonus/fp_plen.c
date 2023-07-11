/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_plen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:30:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/27 11:34:50 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_plen(const void *ptr)
{
	int		output;
	int		bitsize;
	int		i;
	long long	efigy;

	output = 3;
	efigy = (long long)ptr;
	bitsize = (sizeof(void *) * 8);
	i = bitsize - 4;
	while (((efigy >> i) & 0xf) == 0)
		i -= 4;
	while (i > 0)
	{
		output += 1;
		i -= 4;
	}
	return (output);
}
