/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:01:31 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/27 15:47:32 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_putnbr_base(unsigned int nb, char *base_chars)
{
	unsigned int	base_size;

	base_size = (unsigned int)fp_strlen(base_chars);
	if ((nb / base_size) > 0)
		fp_putnbr_base(nb / base_size, base_chars);
	fp_putchar_fd(base_chars[nb % base_size], 1);
	return (fp_strlen(fp_itoa_base(nb, base_size)));
}
