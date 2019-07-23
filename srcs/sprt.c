/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprt.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:16:14 by oleland           #+#    #+#             */
/*   Updated: 2019/07/23 15:11:52 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while ((9 <= str[i]) && (str[i] <=32))
		i++;
	while (('0' <= str[i]) && (str[i] <= '9'))
		result = result * 10 + str[i++] - '0';
	g_det.at = result;
	g_det.c[0] = str[i];
	g_det.c[1] = str[i + 1];
	g_det.c[2] = str[i + 2];
	if (!check_at())
	{
		let_it_go();
		return(0);
	}
	return (1);
}

int check_at(void)
{
	if (g_det.at < 1)
	{
		write(1, "map error\n", 10);
			return (0);
	}
	if (g_det.c[0] == g_det.c[1])
	{
		write(1, "map error\n", 10);
			return (0);
	}
	if (g_det.c[0] == g_det.c[2])
	{
		write(1, "map error\n", 10);
			return(0);
	}
	if (g_det.c[1] == g_det.c[2])
	{
		write(1, "map error\n", 10);
		return (0);
	}
	return (1);
}

void	let_it_go(void)
{
	g_det.at = 0;
	g_det.c[0] = '\0';
	g_det.c[1] = '\0';
	g_det.c[2] = '\0';
	g_x = 0;
	g_y = 0;
	g_size = 0;
	if (g_line)
	{
		g_ly = g_line;
		if (g_ly)
		{
			while (g_line->next)
			{
				g_ly = g_line;
				g_line = g_line->next;
				free(g_ly);
			}
			free(g_line);
			g_line = NULL;
		}
	}
}

void	ft_continue(int i, int fd, int ret, char *see)
{
	g_line = ft_create_elem(-1, -1);
	g_ly = g_line;
	while (ret)
	{
		if (!determinate(see, i))
		{
			write(1, "map error\n", 10);
			let_it_go();
			return ;
		}
		ret  = read(fd, see, BUF);
		see[ret] = '\0';
		i = 0;
	}
	sponge_bob();
}

t_sek	ft_square(void)
{
	t_sek	quadrini;

	quadrini.x = 0;
	quadrini.y = 0;
	quadrini.len = -1;
	while (checksqr(quadrini))
	{
		quadrini.len++;
	}
	return (quadrini);
}
