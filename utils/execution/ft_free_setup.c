/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:19:46 by alfertah          #+#    #+#             */
/*   Updated: 2022/11/12 16:16:46 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_pipefd(t_state *state, int i)
{
	i--;
	while (i >= 0)
	{
		close(state->fds[i][1]);
		close(state->fds[i][0]);
		i--;
	}
	free(state->pids);
	ft_free_setup(state, -1);
}

void	ft_free_setup(t_state *state, int i)
{
	int	j;

	j = 0;
	if (i >= 0)
	{
		i--;
		while (i >= 0)
			free(state->fds[i--]);
		free(state->fds);
	}
	else if (i == -1)
	{
		while (j < state->pipes)
			free(state->fds[j++]);
		free(state->fds);
	}
	ft_free_exit(state, OUT_OF_MEM);
}
