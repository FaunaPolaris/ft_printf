/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:15:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/23 18:28:19 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	print_convert(char *line, va_list args)
{
	int	i;

	i = 0;
	if (line[i] == 'i' || line[i] == 'd')
	{
		ft_putnbr_fd(va_arg(args, int), 1);
		i++;
	}
	else if (line[i] == 's')
		i = fp_putstr_and_len(va_arg(args, char *), 1);
	return (i);
}

static int	print_str(va_list args, char *line)
{
	int	i;
	int	output;

	i = 0;
	output = 0;
	while (line[i])
	{
		if (line[i] == '%')
		{
			i++;
			//if (flag(&line))
			//	output += handle_flags();
			//else
			output += print_convert(&line[i], args);
			i++;
		}
		else
		{
			ft_putchar_fd(line[i], 1);
			output++;
		}
	}
	return (output);
}

int	ft_printf(const char *line, ...)
{
	va_list	args;
	int	output;

	va_start(args, line);
	output = print_str(args, (char *)line);
	va_end(args);
	return (output);
}
