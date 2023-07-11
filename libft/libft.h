/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:46 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/11 15:17:53 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		fp_atoi(const char *nptr);
char	*fp_itoa(int n);
char	*fp_itoa_base(unsigned int nb, int base);
int	fp_putchar_fd(char c, int fd);
int		fp_putnbr_base(unsigned int nb, int base, int up);
int		fp_putstr_and_len(char *s, int fd);
int		fp_putnbr_and_len(int n, int fd);
int		fp_putpointer(const void *ptr);
char	*fp_strchr(const char *s, int c);
size_t		fp_strlen(const char *s);
char 	*fp_strndup(const char *s, int size);
char	*fp_strnstr(const char *big, const char *little, size_t len);
int		fp_isalpha(int c);
int		fp_isdigit(int c);
void	*fp_memcpy(void *dest, const void *src, size_t n);
int		fp_plen(const void *ptr);

#endif
