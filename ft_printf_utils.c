/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:05:19 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/26 18:57:48 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fp_leftj(char *flags, va_list args)
{
	int	width;
	int	characters;
	int	i;

	i = 0;
	width = 0;
	while (ft_isdigit(flags[i]))
		i++;
	characters = fp_convert(&flags[i], args);
	width = ft_atoi(fp_strndup(flags, i));
	while (characters < width)
	{
		ft_putchar_fd(' ', 1);
		characters++;
	}
	return (characters);
}

int	fp_rightj(char *flags, va_list args)
{
	int	width;
	int	characters;
	int	i;

	i = 0;
	width = 0;
	while (ft_isdigit(flags[i]))
		i++;
	characters = fp_convert(&flags[i], args);
	width = ft_atoi(fp_strndup(flags, i));
	while (characters < width)
	{
		ft_putchar_fd(' ', 1);
		characters++;
	}
	return (characters);
}
