/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerrors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:59:29 by egomez-a          #+#    #+#             */
/*   Updated: 2023/04/19 15:47:21 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_entry_bonus(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: Bad argument. The input should follow: \n", 2);
		ft_putstr_fd("  ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
		ft_putstr_fd("  ./pipex \"here_doc\" <LIMITER> ", 1);
		ft_putstr_fd("<cmd> <cmd1> <cmdn> <file>\n", 1);
		exit(EXIT_SUCCESS);
	}
}

void	check_pid(pid_t pid)
{
	if (pid < 0)
	{
		perror("Fork error. Child not created");
		exit (errno);
	}	
}

void	filerror(char *string)
{
	perror(string);
	exit(errno);
}

void	check_pipe(int *fd)
{
	if (pipe(fd) < 0)
	{
		put_error("Pipe error. Pipe not created");
		exit (1);
	}	
}

void	put_error(const char *error)
{
	perror(error);
	exit (errno);
}
