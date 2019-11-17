/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 22:53:59 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 06:54:53 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *source, int c, size_t n)
{
	char			*ds;
	unsigned char	*s;
	size_t			i;
	unsigned char	b;

	b = (unsigned char)c;
	ds = (char *)dest;
	s = (unsigned char *)source;
	i = 0;
	while (i < n)
	{
		ds[i] = s[i];
		if (s[i] == b)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
