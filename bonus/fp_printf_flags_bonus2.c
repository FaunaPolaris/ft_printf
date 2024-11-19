/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_printf_flags_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:13:07 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 16:21:36 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	precision_zero(char *flags, va_list args)
{
	if (flags[2] == '0')
	{
		if (flags[3] == 's')
			va_arg(args, char *);
		else
			va_arg(args, int);
	}
	if (fp_isalpha(flags[2]))
	{
		if (flags[2] == 's')
			va_arg(args, char *);
		else
			va_arg(args, int);
	}
}

int	fp_precision(char *flags, va_list args)
{
	int		width;
	int		output;
	int		i;
	char	*temp;

	i = 0;
	if (flags[2] == '0' || fp_isalpha(flags[2]))
	{
		precision_zero(flags, args);
		return (0);
	}
	while (fp_isdigit(flags[i]))
		i++;
	width = fp_flag_width(flags);
	if (fp_strchr(&flags[i], 's'))
	{
		temp = fp_strndup(va_arg(args, char *), width);
		output = fp_putstr_and_len(temp, 1);
		free(temp);
	}
	else
		output = fp_fill_right(flags, args, '0');
	return (output);
}
