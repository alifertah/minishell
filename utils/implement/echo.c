/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:23:13 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/12 01:10:14 by alfertah         ###   ########.fr       */
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

int find_only(char *cmd)
{
    int i;
    i = 1;
    while (cmd[i])
    {
        if (cmd[i] != 'n')
            return 1;
        i++;
    }
    return 0;
}

void	ft_print_n(t_cmd *cmd)
{
	int i;

	i = 1;

	while(cmd->args[i])
	{
		printf("%s ", cmd->args[i]);
		if(!cmd->args[i + 1])
		{
			printf("\n");
		}
		i++;
	}
}

void	ft_echo(t_state *state, t_cmd *current_cmd)
{
	int	i;
	int t;

	t = 0;
	i = 1;
	if(current_cmd->num_of_args == 1)
	{
		printf("\n");
		state->status = 0;
	}
	if (current_cmd->num_of_args >= 2)
	{
		if (current_cmd->args[i][0] == '-')
		{
			while(current_cmd->args[i])
			{
				if(find_only(current_cmd->args[i]))
					break;
				t = 1;
				i++;
			}
			if(current_cmd->args[i])
				ft_print(current_cmd->args, i);
		}
		else
			ft_print_n(current_cmd);
	}
	state->status = 0;
}
