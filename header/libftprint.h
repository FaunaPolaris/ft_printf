/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 19:38:31 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 19:41:56 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

int	ft_printf(const char * line, ...);
int	fp_convert(char c, va_list args);
int	fp_putchar_fd(char c, int fd);
int	fp_putnbr_and_len(int n, int fd);
int	fp_putnbr_base(unsigned int nb, int base, int up);
int	fp_putpointer(const void *ptr);
int	fp_putstr_and_len(char *s, int fd);


#endif
