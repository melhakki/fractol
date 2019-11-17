/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 00:45:55 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 03:00:24 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*a;
	char	*b;
	int		i;
	size_t	len;

	a = (char *)haystack;
	b = (char *)needle;
	if (ft_strlen(b) == 0)
		return (a);
	len = ft_strlen(b);
	i = 0;
	while (a[i])
	{
		if (ft_strncmp(&a[i], b, len) == 0)
			return ((char *)&a[i]);
		i++;
	}
	return (NULL);
}
