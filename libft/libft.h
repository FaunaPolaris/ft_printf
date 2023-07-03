/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:08:46 by fpolaris          #+#    #+#             */
/*   Updated: 2023/07/03 18:13:45 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		fp_atoi(const char *nptr);
char	*fp_itoa(int n);
char	*fp_itoa(unsigned int nb, int base);
void	fp_putchar_fd(char c, int fd);
int		fp_putnbr_base(unsigned int nb, char *base_chars);
int		fp_putstr-and_len(char *s, int fd);
int		fp_
