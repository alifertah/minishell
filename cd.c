/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:51:06 by alfertah          #+#    #+#             */
/*   Updated: 2022/09/19 22:41:54 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_cd(char *cmd, int i)
{
    
            if(cmd[i+1])
            {
                chdir(&cmd[i+1]);
                printf("%s\n", getcwd(NULL, 0));
            }
            else
            {
                chdir(getenv("HOME"));
                printf("%s\n", getcwd(NULL, 0));
            }
}