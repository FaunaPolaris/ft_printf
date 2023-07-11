/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:05:19 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 16:20:12 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	fp_flag_len(va_list args, char type)
{
	size_t		output;

	output = 1;
	if (type == 'i' || type == 'd')
		output = fp_strlen(fp_itoa(va_arg(args, int)));
	else if (type == 's')
		output = fp_strlen(va_arg(args, char *));
	else if (type == 'c')
		return (output);
	else if (type == 'x')
		output = fp_strlen(fp_itoa_base(va_arg(args, int), 16));
	else if (type == 'X')
		output = fp_strlen(fp_itoa_base(va_arg(args, int), 16));
	else if (type == 'u')
		output = fp_strlen(fp_itoa_base(va_arg(args, int), 10));
	else if (type == 'p')
		output = (size_t)fp_plen(va_arg(args, void *));
	return (output);
}

int	fp_flag_width(char *flags)
{
	int		i;
	int		width;
	char	*temp;

	i = 2;
	while (fp_isdigit(flags[i]))
		i++;
	temp = fp_strndup(&flags[2], i);
	width = fp_atoi(temp);
	free(temp);
	return (width);
}

int	fp_fill_left(char *flags, va_list args, char fill)
{
	int		width;
	int		characters;
	int		i;

	i = 0;
	width = 0;
	while (fp_isdigit(flags[i]))
		i++;
	characters = fp_convert(flags[i], args);
	width = fp_flag_width(flags);
	while (characters < width)
	{
		fp_putchar_fd(fill, 1);
		characters++;
	}
	return (characters);
}

int	fp_fill_right(char *flags, va_list args, char fill)
{
	va_list		temp;
	int		i;
	int		width;
	size_t	len;

	i = 0;
	va_copy(temp, args);
	while (!fp_isalpha(flags[i]))
		i++;
	len = fp_flag_len(temp, flags[i]);
	va_end(temp);
	width = fp_flag_width(flags);
	if ((int)len > width)
	{
		fp_convert(flags[i], args);
		return ((int)len);
	}
	while ((int)len < width)
	{
		fp_putchar_fd(fill, 1);
		len++;
	}
	fp_convert(flags[i], args);
	return (len);
}

