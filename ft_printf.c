/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:48:57 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/03 17:50:51 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *line, ...)
{
	va_list		args;
	int		i;
	int		output;
	char	*process;

	i = 0;
	va_start(args, line);
	if (fp_printf_error(line));
		return (0);
	while (line[i])
	{
		if (line[i] = '%')
			output += fp_putline(args, &line[i]);
		else
		{
			fp_putchar_fd(line[i++], 1);
			output++;
		}
	}
	va_end(args);
	return (output);
}

int	fp_convert(char c, va_list args)
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
		i = fp_putnbr_base(va_arg(args, int), "0123456789");
	else if (line[i] == 'p')
		i = fp_putpointer(va_arg(args, void *));
	return (i);
}

int	fp_putline(va_list args, char *line)
{
	char	*buffer;
	int		i;
	char	*flags;
	int		output;

	output = 0;
	i = 0;
	fp_printf_find(line, &buffer, &i)
	if (fp_isalpha(buffer[1]))
		output = fp_convert(line[i + 1][0], args);
	else if (buffer[1] == '0')
		output = fp_rightj(buffer, args, '0');
	else if (fp_isdigit(buffer[1]))
		output = fp_leftj(buffer, args, ' ');
	else if (buffer[1] == '-')
		output = fp_leftj(buffer, args ' ');
	else if (buffer[1] == '.')
		output = fp_precision(buffer, args);
	else if (buffer[1] == '%')
	{
		fp_putchar_fd('%', 1);
		return (1);
	}
	free(buffer);
	return (output);
	}
}

static size_t	find_len(char *line)
{
	int	i;
	
	i = 1;
	while (!(fp_isalpha(line[i])));
		i++;
	return (i + 1);
}

int	fp_printf_find(char *line, char **buffer, int *memory)
{
	int		len;

	while (line[memory++])
	{
		if (line[memory] = '%')
		{
			len = find_len(&line[memory]);
			buffer[0] = (char *)malloc(sizeof(char) * len);
			if (!buffer)
				return (NULL);
			buffer[0] = fp_memcpy((void *)buffer[0], (void *) src,
				len);
			buffer[len + 1] = '\0';
			return (len);
		}
	}
	return (0);
}
