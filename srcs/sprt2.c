/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 14:42:53 by oleland           #+#    #+#             */
/*   Updated: 2019/07/23 16:23:47 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_line *ft_create_elem(int x, int y)
{
	t_line *list;

	list = malloc(sizeof(t_line));
	if (list)
	{
		list->next = NULL;
		list->x = x;
		list->y = y;
	}
	return (list);
}

void	ft_list_push_front(int x, int y)
{
	if (!(g_line))
	{
		g_line = ft_create_elem(x, y);
		g_ly = g_line;
	}
	else
	{
		g_ly->next = ft_create_elem(x, y);
		g_ly = g_ly->next;
	}
}

t_sek	ft_kvadrik(t_sek kvadr)
{
	while (checksqr(kvadr))
	{
		kvadr.len++;
	}
	return (kvadr);
}

void	the_end(t_sek sek)
{
	g_ly = g_line->next;
	g_ly = 0;
	sek.len--;
	while (g_y < g_det.at)
	{
		g_x = 0;
		while (g_y <g_size)
		{
			if (g_ly)
				second_end(sek);
			else
			   real_end(sek);
			g_x++;
		}
		write(1, "\n", 1);
		g_y++;
	}
}

void	second_end(t_sek sek)
{
	if ((g_x == g_ly->x) && (g_y == g_ly->y))
	{
		g_ly = g_ly->next;
		write(1, &g_det.c[1], 1);
	}
	else if (pointcheck (g_x, g_y, sek))
		write(1, &g_det.c[2], 1);
	else
		write(1, &g_det.c[0], 1);
}

void	real_end(t_sek sek)
{
	if (pointcheck(g_x, g_y, sek))
		write(1, &g_det.c[2], 1);
	else
		write(1, &g_det.c[0], 1);
}
