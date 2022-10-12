/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:25:13 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/10 22:23:43 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_state *state)
{
	if (!state->pwd || errno == ENOENT)
		state->pwd = getcwd(NULL, PATH_MAX);
	printf("%s\n", state->pwd);
	state->status = 0;
}
