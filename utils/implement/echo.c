/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:23:13 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/27 19:28:13 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_print(char **array, int starting_from)
{
	int	i;

	i = starting_from;
	while (array[i])
	{
		if (i != starting_from)
			printf(" ");
		printf("%s", array[i++]);
	}
}

int	find_only(char *cmd)
{
	int		i;

	i = 1;
	while (cmd[i])
	{
		if (cmd[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_print_nl(t_cmd *cmd)
{
	int	i;

	i = 1;
	while (cmd->args[i])
	{
		printf("%s ", cmd->args[i]);
		i++;
	}
	printf("\n");
}

void	ft_echo(t_state *state, t_cmd *current_cmd)
{
	int	i;

	i = 1;
	if (current_cmd->num_of_args == 1)
		printf("\n");
	if (current_cmd->num_of_args >= 2)
	{
		if (current_cmd->args[1] && current_cmd->args[1][0] == '-'
			&& !find_only(current_cmd->args[1] + 1))
			ft_print(current_cmd->args, 2);
		else
			ft_print_nl(current_cmd);
	}
	state->status = 0;
}
