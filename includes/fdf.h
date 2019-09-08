/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstripeb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:09:22 by tstripeb          #+#    #+#             */
/*   Updated: 2019/09/08 19:00:57 by tstripeb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct	s_base
{
	int			fd;
	int			lines;
	int			chars;
	char		*filename;
	int			**map;
}				t_base;

int				ft_write_in_base(t_base *base);
int				ft_line_char_mal(t_base *base, char *line);
int				ft_line_char(t_base *base, char *line);
void			ft_freetime(char **tmp, int counter);

#endif
