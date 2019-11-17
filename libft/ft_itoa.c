/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 06:08:51 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/20 23:53:39 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		ft_len(int n)
{
	long		size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size++);
}

char			*ft_itoa(int n)
{
	long		n_long;
	long		len;
	char		*str;

	len = ft_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	n_long = n;
	if (n_long < 0)
		n_long = -n_long;
	while (len >= 0)
	{
		str[len] = (n_long % 10) + '0';
		len--;
		n_long /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
