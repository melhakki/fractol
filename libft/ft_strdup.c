/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 17:35:45 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/17 23:46:58 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*s;
	char	*st;
	int		i;

	s = (char *)str;
	i = 0;
	while (s[i])
		i++;
	st = (char *)malloc((i + 1) * sizeof(char));
	if (!st)
		return (NULL);
	i = 0;
	while (s[i])
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
}
