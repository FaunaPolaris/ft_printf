/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:16:35 by fpolaris          #+#    #+#             */
/*   Updated: 2023/05/22 11:57:27 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	neg(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	recurse(int n, int len, char *news)
{
	news[len] = neg(n % 10) + 48;
	if (n > 9 || n < -9)
		recurse(n / 10, len - 1, news);
}

char	*fp_itoa(int n)
{
	int		len;
	int		temp;
	char	*news;

	temp = n;
	len = 1;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		len++;
	}
	if (n < 0)
		len++;
	news = (char *)malloc(sizeof(char) * (len + 1));
	if (!news)
		return (NULL);
	if (n < 0)
		news[0] = '-';
	recurse(n, len - 1, news);
	news[len] = '\0';
	return (news);
}
