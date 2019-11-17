/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhakki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:33:35 by melhakki          #+#    #+#             */
/*   Updated: 2019/11/16 23:38:46 by melhakki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_light_pixel(t_all start, int x, int y, int color)
{
	int		i;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HIGHT)
		return ;
	i = x * 4 + WIDTH * 4 * y;
	start.img_str[i] = color * 10;
	start.img_str[i + 1] = color / 3;
	start.img_str[i + 2] = color * 20;
}

void		init(t_all *this)
{
	this->c_x = REPERE_X(this->x);
	this->c_y = REPERE_Y(this->y);
	this->z_x = 0;
	this->z_y = 0;
	this->iter = 0;
}

void		mandelbrot(t_all *this)
{
	this->y = 0;
	while (this->y < HIGHT)
	{
		this->x = 0;
		while (this->x < WIDTH)
		{
			init(this);
			while (this->iter < this->iter_max && (this->z_x * this->z_x)
					+ (this->z_y * this->z_y) < 4)
			{
				this->tmp = this->z_x;
				this->z_x = (this->z_x * this->z_x) -
					(this->z_y * this->z_y) + this->c_x;
				this->z_y = 2 * this->tmp * this->z_y + this->c_y;
				this->iter++;
			}
			if (this->iter == this->iter_max)
				ft_light_pixel(*this, this->x, this->y, 0);
			else
				ft_light_pixel(*this, this->x, this->y,
						this->iter * this->color);
			this->x++;
		}
		this->y++;
	}
}

void		burning_ship(t_all *this)
{
	this->y = 0;
	while (this->y < HIGHT)
	{
		this->x = 0;
		while (this->x < WIDTH)
		{
			init(this);
			while (this->iter < this->iter_max && (this->z_x * this->z_x)
					+ (this->z_y * this->z_y) < 4)
			{
				this->tmp = this->z_x;
				this->z_x = fabs((this->z_x * this->z_x) -
						(this->z_y * this->z_y) + this->c_x);
				this->z_y = fabs(2 * this->tmp * this->z_y + this->c_y);
				this->iter++;
			}
			if (this->iter == this->iter_max)
				ft_light_pixel(*this, this->x, this->y, 0);
			else
				ft_light_pixel(*this, this->x, this->y,
						this->iter * this->color);
			this->x++;
		}
		this->y++;
	}
}

void		julia(t_all *this)
{
	this->y = -1;
	while (++this->y < HIGHT)
	{
		this->x = -1;
		while (++this->x < WIDTH)
		{
			this->z_x = REPERE_X(this->x);
			this->z_y = REPERE_Y(this->y);
			this->iter = 0;
			while (this->iter < this->iter_max && (this->z_x * this->z_x)
					+ (this->z_y * this->z_y) < 4)
			{
				this->tmp = this->z_x;
				this->z_x = (this->z_x * this->z_x) -
					(this->z_y * this->z_y) + this->c_x;
				this->z_y = 2 * this->tmp * this->z_y + this->c_y;
				this->iter++;
			}
			if (this->iter == this->iter_max)
				ft_light_pixel(*this, this->x, this->y, 0);
			else
				ft_light_pixel(*this, this->x, this->y,
						this->iter * this->color);
		}
	}
}
