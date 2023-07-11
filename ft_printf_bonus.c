/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 14:48:57 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 18:44:25 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	fp_find_len(char *line)
{
	int	i;
	
	i = 1;
	if (line[i] == '%' && line[i - 1] == '%')
		return (2);
	while (!(fp_isalpha(line[i])))
		i++;
	return (i + 1);
}

int	ft_printf(const char *line, ...)
{
	va_list		args;
	int		i;
	int		output;

	if (!line)
		return (-1);
	i = 0;
	output = 0;
	va_start(args, line);
	if (fp_printf_error((char *)line))
		return (0);
	while (line[i])
	{
		if (line[i] == '%')
		{
			output += fp_putline(args, (char *)&line[i]);
			i += fp_find_len((char *)&line[i]);
		}
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
	if (c == 'i' || c == 'd')
		i = fp_putnbr_and_len(va_arg(args, int), 1);
	else if (c == 's')
		i = fp_putstr_and_len(va_arg(args, char *), 1);
	else if (c == 'c')
	{
		fp_putchar_fd(va_arg(args, int), 1);
		return (1);
	}
	else if (c == 'x')
		i = fp_putnbr_base(va_arg(args, unsigned int), 16, 0);
	else if (c == 'X')
		i = fp_putnbr_base(va_arg(args, unsigned int), 16, 1);
	else if (c == 'u')
		i = fp_putnbr_base(va_arg(args, unsigned int), 10, 0);
	else if (c == 'p')
		i = fp_putpointer(va_arg(args, void *));
	return (i);
}

int	fp_putline(va_list args, char *line)
{
	char	*buffer;
	int		i;
	int		output;

	output = 0;
	i = 0;
	if (fp_printf_find(line, &buffer, &i))
	{
		if (fp_isalpha(buffer[1]))
			output = fp_convert(line[i], args);
		else if (buffer[1] == '0')
			output = fp_fill_right(buffer, args, '0');
		else if (fp_isdigit(buffer[1]))
			output = fp_fill_right(buffer, args, ' ');
		else if (buffer[1] == '-')
			output = fp_fill_right(buffer, args, ' ');
		else if (buffer[1] == '.')
			output = fp_precision(buffer, args);
		else if (buffer[1] == '%')
			output = fp_putchar_fd('%', 1);
		free(buffer);
	}
	return (output);
}


int	fp_printf_find(char *line, char **buffer, int *memory)
{
	int		len;

	while (line[memory[0]])
	{
		if (line[memory[0]] == '%')
		{
			len = fp_find_len(&line[memory[0]]);
			buffer[0] = (char *)malloc(sizeof(char) * (len + 1));
			if (!buffer[0])
				return (1);
			buffer[0] = fp_memcpy((void *)buffer[0], 
				(void *)line, len);
			buffer[0][len] = '\0';
			memory[0]++;
			return (len);
		}
		memory[0]++;
	}
	return (0);
}
