/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openfile_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 09:48:42 by egomez-a          #+#    #+#             */
/*   Updated: 2023/04/19 15:47:38 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_openfile(char *arg, int control)
{
	int	fd;

	fd = 0;
	if (control == 1)
	{
		fd = open(arg, O_RDONLY, 0777);
		if (fd < 0)
		{
			write(2, "Pipex: execve failed: No such file or directory\n", ft_strlen("Pipex: execve failed: No such file or directory\n"));
			exit (0);
		}
	}
	else if (control == 2)
	{
		fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd < 0)
		{
			write(2, "Pipex: execve failed: No such file or directory\n", ft_strlen("Pipex: execve failed: No such file or directory\n"));
			exit (0);
		}
	}
	return (fd);
}
