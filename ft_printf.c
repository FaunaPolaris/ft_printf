/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 16:15:23 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/26 18:57:18 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*fp_cflag(char *line)
{
	int		i;
	char	*output;

	i = 0;
	if (ft_isalpha(line[i]))
		return (NULL);
	while (!(ft_isalpha(line[i])))
		i++;
	output = fp_strndup(line, i + 1);
	return (output);
}

int	fp_hflag(char *flags, va_list args)
{
	int		output;
	int	i;

	i = 0;
	if (!flags)
		return (0);
//	if (flags[i] == '0')
	else if (ft_isdigit(line[i]))
		output = fp_rightj(&flags[i + 1], args);
	else if (flags[i] == '-')
		output = fp_leftj(&flags[i + 1], args);
//	else if (flags[i] == '.')
	else if (flags [i] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	else
		output = fp_convert(&flags[i], args);
	return (output);
}

int	fp_convert(char *line, va_list args)
{
	int	i;

	i = 0;
	if (line[i] == 'i' || line[i] == 'd')
		i = fp_putnbr_and_len(va_arg(args, int), 1);
	else if (line[i] == 's')
		i = fp_putstr_and_len(va_arg(args, char *), 1);
	else if (line[i] == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (line[i] == 'x')
		i = fp_putnbr_base(va_arg(args, int), "0123456789abcdef");
	else if (line[i] == 'X')
		i = fp_putnbr_base(va_arg(args, int), "0123456789ABCDEF");
	else if (line[i] == 'u')
		i = fp_putnbr_un(va_arg(args, int));
	else if (line[i] == 'p')
		i = fp_putpointer(va_arg(args, void*));
	return (i);
}

int	fp_putline(va_list args, char *line)
{
	int	i;
	int	characters;

	i = 0;
	characters = 0;
	while (line[i])
	{
		if (line[i] == '%')
		{
			i++;
			if (!fp_cflag(&line[i]))
			{
				characters += fp_convert(&line[i], args);
				i++;
			}
			else
			{
				characters += fp_hflag(fp_cflag(&line[i]), args);
				i += ft_strlen(fp_cflag(&line[i]));
			}
		}
		else
		{
			ft_putchar_fd(line[i], 1);
			characters++;
			i++;
		}
	}
	return (characters);
}

int	ft_printf(const char *line, ...)
{
	va_list	args;
	int	characters;

	va_start(args, line);
	characters = fp_putline(args, (char *)line);
	va_end(args);
	return (characters);
}
