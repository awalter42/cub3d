/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ext.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeaufil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:01:53 by nbeaufil          #+#    #+#             */
/*   Updated: 2023/07/08 11:54:36 by nbeaufil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_in(int type, t_parse_info *info)
{
	if (type == 1 && info->no)
		return (1);
	if (type == 2 && info->so)
		return (1);
	if (type == 3 && info->we)
		return (1);
	if (type == 4 && info->ea)
		return (1);
	if (type == 5 && info->floor)
		return (1);
	if (type == 6 && info->sky)
		return (1);
	return (0);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	to_put;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		to_put = n % 10 + '0';
		write(fd, &to_put, 1);
	}
	else
	{
		to_put = n + '0';
		write(fd, &to_put, 1);
	}
}

int	check_info_validity(int type, char *path)
{
	int	fd;

	if (type < 5)
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
		{
			put_error(path, 3);
			return (put_error(": no such file or directory", 1));
		}
		close(fd);
	}
	else
	{
		if (-1 == check_color_validity(path))
		{
			put_error(path, 3);
			return (put_error(": invalid syntax", 1));
		}
	}
	return (0);
}
