/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/21 06:19:39 by melhakki          #+#    #+#             */
/*   Updated: 2018/10/21 06:55:25 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(void *a, void *b)
{
	unsigned char c;
	unsigned char *pa;
	unsigned char *pb;

	pa = (unsigned char *)a;
	pb = (unsigned char *)b;
	c = *pa;
	*pa = *pb;
	*pb = c;
}
