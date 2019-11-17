/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:49:43 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 06:50:37 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char *str, int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		while (str[i] && i < (int)ft_strlen(str) + n)
			ft_putchar(str[i++]);
	}
	else
	{
		while (str[i] && i < n)
			ft_putchar(str[i++]);
	}
}
