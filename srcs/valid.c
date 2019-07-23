/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:42:20 by oleland           #+#    #+#             */
/*   Updated: 2019/07/23 17:52:37 by etristan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		valid(char c)
{
	if (c == g_det.c[0] || c == g_det.c[1] || c == '\n' || c == '\0')
	{
		if (c == g_det.c[1])
			ft_list_push_front(g_x, g_y);
		if (c == '\n')
		{
			if (g_size == 0)
				g_size = g_x;
			else if (g_size != g_x)
				return (0);
			g_x = -1;
			g_y++;
		}
	}
	else
		return (0);
	if (g_y > g_det.at)
		return (0);
	g_x++;
	return (1);
}

t_line	*minx(void)
{
	t_line	*r_line;

	g_ly = g_line;
	r_line = g_line;
	while (g_ly)
	{
		if (r_line->x < g_ly->x)
			r_line = g_ly;
		g_ly = g_ly->next;
	}
	return (r_line);
}

int		pointcheck(int x, int y, t_sek quad)
{
	if (quad.x + 1 + quad.len >= g_size)
		return (1);
	if (g_det.at <= quad.y + 1 + quad.len)
		return (1);
	if (x >= quad.x)
	{
		if (x <= (quad.x + quad.len + 1))
		{
			if (y >= quad.y)
			{
				if (y <= (quad.y + quad.len + 1))
					return (1);
			}
		}
	}
	return (0);
}

int		checksqr(t_sek quad)
{
	t_line *li;

	while (g_ly->y < quad.y && g_ly->next)
		g_ly = g_ly->next;
	li = g_ly;
	while (li)
	{
		if (pointcheck(li->x, li->y, quad))
			return (0);
		li = li->next;
	}
	return (1);
}
