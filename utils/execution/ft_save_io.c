/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_io.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:40:54 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/10 01:32:25 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_reset_io(t_state *state)
{
	dup2(state->io[0], STDIN_FILENO);
	dup2(state->io[1], STDOUT_FILENO);
}

void	ft_save_io(t_state *state)
{
	state->io[0] = dup(STDIN_FILENO);
	state->io[1] = dup(STDOUT_FILENO);
}
