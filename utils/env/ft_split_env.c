/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 09:54:46 by olabrahm          #+#    #+#             */
/*   Updated: 2022/11/14 00:41:18 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_env_validname(char *name)
{
	int	i;

	i = 0;
	if (ft_isdigit(name[i]))
		return (0);
	while (name[i])
	{
		if (!ft_isalnum(name[i]) && name[i] != '_')
		{
			if (!name[i + 1] && name[i] == '+' && i > 0)
				return (1);
			return (0);
		}
		i++;
	}
	return (1);
}

static char	*ft_extract_name(char *str, char c)
{
	unsigned int	i;
	unsigned int	key_len;
	char			*name;

	i = 0;
	key_len = 0;
	name = ft_strdup("");
	if (!name)
		return (NULL);
	while (str[i] && str[i] != c)
	{
		name = ft_charjoin(name, str[i++]);
		if (!name)
			return (NULL);
		key_len++;
	}
	name[key_len] = '\0';
	if (ft_strlen(name) == 0)
	{
		free(name);
		return (NULL);
	}
	return (name);
}

static char	*ft_extract_value(char *str, char c, unsigned int i)
{
	unsigned int	value_len;
	char			*value;

	value_len = 0;
	value = ft_strdup("");
	if (str[i] == c)
		i++;
	if (!str[i])
		return (value);
	while (str[i])
	{
		value = ft_charjoin(value, str[i++]);
		if (!value)
			return (NULL);
		value_len++;
	}
	value[value_len] = '\0';
	return (value);
}

static char	**ft_free(void *ptr1, void *ptr2, void *ptr3)
{
	free(ptr1);
	free(ptr2);
	free(ptr3);
	return (NULL);
}

char	**ft_split_env(char *str, char c)
{
	unsigned int	i;
	char			**new_val;
	char			*name;
	char			*value;

	i = 0;
	if (!str || !str[0] || str[0] == c)
		return (NULL);
	new_val = (char **) malloc(sizeof(char *) * 3);
	if (!new_val)
		return (NULL);
	name = ft_extract_name(str, c);
	if (!name || !ft_env_validname(name))
		return (ft_free((void *) new_val, (void *) name, NULL));
	value = ft_extract_value(str, c, (unsigned int) ft_strlen(name));
	if (!value)
		return (ft_free((void *) new_val, (void *) name, NULL));
	new_val[i++] = name;
	new_val[i++] = value;
	new_val[i] = NULL;
	return (new_val);
}
