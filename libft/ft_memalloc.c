/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 21:42:53 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/18 23:48:58 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*a;
	size_t			i;

	a = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (!a)
	{
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		a[i++] = 0;
	}
	return (a);
}
