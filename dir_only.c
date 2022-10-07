/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_only.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfertah <alfertah@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 11:38:47 by alfertah          #+#    #+#             */
/*   Updated: 2022/10/06 22:27:00 by alfertah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void *getCurrentDir(void)
{
    char *currWorkDir, *token;
    char *directory;
    size_t length;

    currWorkDir = getcwd(NULL, 0 );
    token = strrchr(currWorkDir, '/');

    if( currWorkDir == NULL ){
        printf("Error"); /* You decide here */
        exit(1);
    }

    if (token == NULL) {
        printf("Error"); /* You decide here */
        exit(1);
    }

    length = strlen(token);
    directory = malloc(length);
    memcpy(directory, token+1, length);

    return directory;
}