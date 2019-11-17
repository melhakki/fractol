/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 21:59:27 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 00:35:30 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	lendest;
	size_t	lensrc;
	int		j;

	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	j = 0;
	i = ft_strlen(dest);
	if (n <= lendest)
		return (lensrc + n);
	while (src[j] && i < n - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (lendest + lensrc);
}
