/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-a <egomez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:42:20 by egomez-a          #+#    #+#             */
/*   Updated: 2023/04/19 15:47:41 by egomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execute(char *argv, char **envp, t_pipex *pipex)
{
	char	*pathcmd;
	int		i;
	char	**command;

	i = -1;
	command = ft_split(argv, ' ');
	pathcmd = test_path(command[0], pipex);
	if (!pathcmd)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		perror(" Error");
		exit(EXIT_FAILURE);
	}
	if (execve(pathcmd, command, envp) == -1)
		perror("**  Error: command not found\n");
}

char	*test_path(char *command, t_pipex *pipex)
{
	int		i;
	char	*cmd_path_ok;

	i = 0;
	while (i < pipex->len)
	{
		if (command[0] == '/')
			cmd_path_ok = ft_strdup(command);
		else
			cmd_path_ok = ft_strjoin(pipex->path[i], command);
		if (access(cmd_path_ok, F_OK) == 0)
			return (cmd_path_ok);
		free(cmd_path_ok);
		i++;
	}
	i = -1;
	while (pipex->path[++i])
		free(pipex->path[i]);
	free(pipex->path);
	return (0);
}

void	start_pipe(char *argv, char **envp, t_pipex *pipex)
{
	pid_t	pid;
	int		fd[2];

	pipe(fd);
	check_pipe(fd);
	pid = fork();
	if (pid == -1)
		put_error("Error. Fork not created\n");
	if (pid == 0)
	{
		close(fd[FD_READ_END]);
		dup2(fd[FD_WRITE_END], STDOUT_FILENO);
		printf("Try to execute %s\n", argv);
		execute(argv, envp, pipex);
	}
	else
	{
		close(fd[FD_WRITE_END]);
		dup2(fd[FD_READ_END], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex		pipex;
	int			ncom;

	check_entry_bonus(argc);
	pipex.path = env_variable(envp);
	pipex.len = path_lenght(&pipex);
	ncom = 2;
	pipex.fd_in = ft_openfile(argv[1], 1);
	pipex.fd_out = ft_openfile(argv[argc - 1], 2);
	dup2(pipex.fd_in, STDIN_FILENO);
	while (ncom < argc - 2)
		start_pipe (argv[ncom++], envp, &pipex);
	dup2(pipex.fd_out, STDOUT_FILENO);
	execute(argv[argc - 2], envp, &pipex);
	filerror("Error. \n");
}
