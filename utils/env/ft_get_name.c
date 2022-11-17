/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:29:23 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/16 23:20:23 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_quotes(char *value)
{
	unsigned int	i;
	int				count;

	i = 0;
	count = 0;
	while (value[i])
	{
		if (value[i] == '\"')
			count++;
		i++;
	}
	return (count);
}

char	*get_name(char *value)
{
	unsigned int	i;
	unsigned int	j;
	char			*output;
	int				quotes;

	if (!value || !ft_strlen(value))
		return (NULL);
	quotes = count_quotes(value);
	if (!quotes)
		return (ft_strdup(value));
	output = (char *) malloc((ft_strlen(value) + quotes) * sizeof(char));
	if (!output)
		return (NULL);
	i = 0;
	j = 0;
	while (value[i])
	{
		if (value[i] == '\"')
			output[j++] = '\\';
		output[j++] = value[i++];
	}
	output[j] = 0;
	return (output);
}
