/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:06 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/26 18:29:11 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *line, ...);
int		fp_putline(va_list args, char *line);
int		fp_convert(char *line, va_list args);
int		fp_hflag(char *flags, va_list args);
int		fp_leftj(char *flags, va_list args);
char	*fp_cflag(char *line);

#endif
