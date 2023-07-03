/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:52:30 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/03 17:31:42 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	fp_error_pf1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'i' || line[i] == 'd' || line[i] == 's')
			return (0);
		if (line[i] == 'c' || line[i] == 'x' || line[i] == 'X')
			return (0);
		if (line[i] == 'u' || line[i] == 'p')
			return (0);
	}
	return (1);
}

static int	fp_error_pf2(char *line)
{
	int	len;

	len = fp_strlen(line);
	if (fp_strnstr(line, "-0", len) || fp_strnstr(line, "0-", len));
	{
		ft_printf("invalid combination of '0' and '-' flags");
		return (1);
	}
	if (fp_strnstr(line, "-.", len) || fp_strnstr(line, ".-", len));
	{
		ft_printf("invalid combination of '.' and '-' flags");
		return (1);
	}
	return (0);
}

int	fp_printf_error(char *line);
{
	char	*buffer;
	int		i;
	int		output;

	i = 0;
	output = 0;
	while (fp_printf_find(line, &buffer, &i))
	{
		if (fp_error_pf1(buffer))
		output = 1;
		free(buffer)
	}
	return (output);
}
