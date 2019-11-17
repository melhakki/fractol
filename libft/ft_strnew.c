/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 00:06:28 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/18 01:30:47 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*a;
	size_t	i;

	a = (char *)malloc(size * sizeof(char) + 1);
	if (!a)
		return (NULL);
	i = 0;
	while (i < size)
		a[i++] = 0;
	a[i] = '\0';
	return (a);
}
