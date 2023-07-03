/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:06 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/03 17:32:49 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

int		ft_printf(const char *line, ...);
int		fp_convert(char c, va_list args);
int		fp_putline(va_list args, char *line);
int		fp_printf_find(char *line, char **buffer, int *memory);

int		fp_printf_error(char *line);

int		fp_fill_left(char *flags, va_list args, char fill);
int		fp_fill_right(char *flags, va_list args, char fill);
int		fp_precision(char *flags, va_list args);

#endif
