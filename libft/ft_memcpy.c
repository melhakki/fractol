/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:14:07 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 06:53:43 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char	*s;
	char	*c;
	size_t	i;

	s = (char *)dest;
	c = (char *)source;
	i = 0;
	while (i < n)
	{
		s[i] = c[i];
		i++;
	}
	return (dest);
}
