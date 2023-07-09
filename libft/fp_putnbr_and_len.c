/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putnbr_and_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:03:41 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/09 14:36:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_putnbr_and_len(int n, int fd)
{
	char	*temp;
	int		output;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		fp_putchar_fd('-', fd);
	}
	if (n > 9)
	{
		fp_putnbr_and_len(n / 10, fd);
		fp_putnbr_and_len(n % 10, fd);
	}
	if (n <= 9)
		fp_putchar_fd(n + 48, fd);
	temp = fp_itoa(n);
	output = fp_strlen(temp);
	free(temp);
	return (output);
}
