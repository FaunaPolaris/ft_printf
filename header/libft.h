/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:17:06 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 19:42:35 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int			ft_printf(const char *line, ...);
int			fp_convert(char c, va_list args);
int			fp_putline(va_list args, char *line);
int			fp_printf_find(char *line, char **buffer, int *memory);
int			fp_fill_left(char *flags, va_list args, char fill);
int			fp_fill_right(char *flags, va_list args, char fill);
int			fp_precision(char *flags, va_list args);
int			fp_printf_error(char *line);
size_t		fp_find_len(char *line);
size_t		fp_flag_len(va_list args, char type);
int			fp_flag_width(char *flag);
int			fp_atoi(const char *nprt);
int			fp_isalpha(int c);
int			fp_isdigit(int c);
char		*fp_itoa_base(unsigned int nb, int base);
char		*fp_itoa(int n);
void		*fp_memcpy(void *dest, const void *src, size_t n);
int			fp_plen(const void *ptr);
char		*fp_strchr(const char *s, int c);
size_t		fp_strlen(const char *s);
char		*fp_strndup(const char *s, int size);
char		*fp_strnstr(const char *big, const char *little, size_t len);
int			fp_putchar_fd(char c, int fd);
int			fp_putnbr_and_len(int n, int fd);
int			fp_putnbr_base(unsigned int nb, int base, int up);
int			fp_putpointer(const void *ptr);
int			fp_putstr_and_len(char *s, int fd);
size_t		fp_find_len(char *line);
int			fp_printf_find(char *line, char **buffer, int *memory);

#endif
