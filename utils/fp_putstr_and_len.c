/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_putstr_and_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:30:46 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/23 17:35:57 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	fp_putstr_and_len(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len])
	{
		fp_putchar_fd(s[len], fd);
		len++;
	}
	return (len);
}
