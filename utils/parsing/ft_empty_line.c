/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:37:29 by olabrahm          #+#    #+#             */
/*   Updated: 2022/10/10 01:32:25 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isspace(char c)
{
	return (c == '\t' || c == ' ' || c == '\r'
		|| c == '\n' || c == '\f' || c == '\v');
}

int	ft_empty_line(char *str)
{
	int	i;

	i = -1;
	if (str[0] == 0)
		return (1);
	while (str[++i])
		if (!ft_isspace(str[i]) && str[i] != DELIMIT)
			return (0);
	add_history(str);
	return (1);
}
