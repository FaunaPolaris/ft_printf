/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:06 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 16:21:17 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"

int		ft_printf(const char *line, ...);
int		fp_convert(char c, va_list args);
int		fp_putline(va_list args, char *line);
int		fp_printf_find(char *line, char **buffer, int *memory);
int		fp_fill_left(char *flags, va_list args, char fill);
int		fp_fill_right(char *flags, va_list args, char fill);
int		fp_precision(char *flags, va_list args);
int		fp_printf_error(char *line);
size_t		fp_find_len(char *line);
size_t		fp_flag_len(va_list args, char type);
int		fp_flag_width(char *flag);
#endif
