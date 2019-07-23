/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 13:43:34 by oleland           #+#    #+#             */
/*   Updated: 2019/07/23 15:29:59 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putfile(char *av)
{
	int i;
	int fd;
	int ret;
	char see[BUF + 1];

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		write(1, "map error\n", 10);
		return ;
	}
	ret = read(fd, see, BUF);
	see[ret] = '\0';
	if (!ft_atoi(see))
		return ;
	while (see[i] && see[i] != '\n')
		i++;
	i++;
	ft_continue(i, fd, ret, see);
}

int		determinate(char *str, int i)
{
	while (str[i])
	{
		if (valid(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_read(void)
{
	int		i;
	int		ret;
	char	see[BUF + 1];

	i = 0;
	ret = read(0, see, BUF);
	see[ret] = '\0';
	if (!ft_atoi(see))
		return ;
	while (see [i] && see [i] != '\n')
		i++;
	i++;
	ft_continue(i, 0, ret, see);
}

void	sponge_bob(void)
{
	t_sek	sek;
	t_sek	seks;

	g_ly = g_line;
	sek = ft_square();
	seks = sek;
	while (seks.y < g_y - seks.len)
	{
		seks.x = 0;
		while (seks.x < g_size - seks.len)
		{
			if (checksqr(seks))
			{
				seks = ft_kvadrik(seks);
				if (seks.len > sek.len)
					sek = seks;
			}
			seks.x++;
		}
		seks.y++;
	}
	the_end(sek);
	let_it_go();
}

int		main(int argc, char **argv)
{
	int i;

	g_size = 0;
	if (argc > 1)
	{
		i = 1;
		while (i <argc)
		{
			ft_putfile(argv[i]);
			i++;
		}
	}
	else
		ft_read();
	return (0);
}
