/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleland <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 17:42:36 by oleland           #+#    #+#             */
/*   Updated: 2019/07/23 20:43:04 by oleland          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct		s_det
{
	int				at;
	char			c[4];
}					t_det;

typedef struct		s_line
{
	int				x;
	int				y;
	struct s_line	*next;
}					t_line;

typedef struct		s_sek
{
	int				x;
	int				y;
	int				len;
}					t_sek;

void				ft_putfile(char *av);
int					valid(char c);
t_line				*minx(void);
int					pointcheck(int x, int y, t_sek quad);
int					checksqr(t_sek quad);
t_line				*ft_create_elem(int x, int y);
void				ft_list_push_front(int x, int y);
t_sek				ft_kvadrik(t_sek kvadr);
void				the_end(t_sek sek);
void				second_end(t_sek sek);
void				real_end(t_sek sek);
int					ft_atoi(char *str);
int					check_at(void);
void				let_it_go(void);
void				ft_continue(int i, int fd, int ret, char *see);
t_sek				ft_square(void);
int					determinate(char *str, int i);
void				mitka_pidr(void);
void				sponge_bob(void);

t_line				*g_line;
t_line				*g_ly;
t_det				g_det;
int					g_size;
int					g_x;
int					g_y;
# define BUF 4096
#endif
