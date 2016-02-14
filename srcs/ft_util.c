/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/15 00:21:11 by nle-bret          #+#    #+#             */
/*   Updated: 2016/02/15 00:21:13 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char		*ft_get_name(t_app *app, int id)
{
	char	*name;
	char	*tmp_id;
	char	*tmp_id2;
	char	*tmp_id3;

	if ((name = ft_strdup(app->n[id])) == NULL)
		ft_error("Malloc name\n");
	if (name[0])
	{
		name[0] -= 32;
		tmp_id = ft_strdup(" [");
		tmp_id2 = ft_strjoin(tmp_id, ft_itoa(id));
		ft_strdel(&tmp_id);
		tmp_id3 = ft_strjoin(tmp_id2, "]");
		ft_strdel(&tmp_id2);
		name = ft_strjoin(name, tmp_id3);
		ft_strdel(&tmp_id3);
	}
	return (name);
}

void		ft_rand_color(t_scene *scn)
{
	int		t;

	t = 100;
	scn->cs[0] = ft_get_color(0, 0, 0, 0);
	scn->cs[1] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[2] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[3] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
	scn->cs[4] = ft_get_color(rand() % t, rand() % t, rand() % t, 0);
}

void		ft_destroy_win(t_app *app)
{
	int		i;
	int		find;

	i = 0;
	find = 0;
	app->id_win[app->c] = 0;
	i = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
			find = 1;
		i++;
	}
	mlx_destroy_window(app->mlx, app->scn[app->c]->win);
	i = 0;
	while (i < NB_FRACTAL)
	{
		if (app->id_win[i])
			app->c = i;
		i++;
	}
	if (!find)
		exit(1);
}