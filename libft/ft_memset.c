/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 14:42:24 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 06:52:04 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*cur;

	i = 0;
	if (n == 0)
		return (str);
	cur = (unsigned char *)str;
	while (i < n)
	{
		cur[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
