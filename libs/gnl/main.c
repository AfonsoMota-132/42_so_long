/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:32:45 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/05 10:39:46 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	i = 1;
	if (argc >= 2)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);	
			if (fd < 0)
			{
				printf("%s\n", "File does not exist.");
			}
			else
			{
				printf("%s\n", argv[i]);
				line = get_next_line(fd);
				while(line)
				{
					printf("%s", line);
					free(line);
					line = get_next_line(fd);
				}
			}
			printf("\n");
			free(line);
			close(fd);
			i++;
		}
	}
}
