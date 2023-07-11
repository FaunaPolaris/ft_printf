/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fp_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpolaris <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:20:36 by fpolaris          #+#    #+#             */
/*   Updated: 2023/06/26 17:48:57 by fpolaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fp_strndup(const char *s, int size)
{
	size_t	i;
	char	*news;

	i = 0;
	news = (char *)malloc(sizeof(char) * (size + 1));
	if (!news)
		return (NULL);
	while (i < (size_t)size)
	{
		news[i] = s[i];
		i++;
	}
	news[size] = '\0';
	return (news);
}
