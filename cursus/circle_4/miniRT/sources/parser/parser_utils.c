/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyang <siyang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:58:47 by siyang            #+#    #+#             */
/*   Updated: 2023/06/12 16:16:06 by siyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_float(char **line)
{
	double res;

	while (**line == ' ')
		(*line)++;
	if (!validate_argument(*line))
		error_exit("Parsing Error", 1);
	res = ft_atof(*line);
	while ((**line >= '0' && **line <= '9') || **line == '.' || **line == '-')
		(*line)++;
	return (res);
}

t_color3	get_color(char **line)
{
	double	temp[3];
	double	value;
	int		i;

	while (**line == ' ')
		(*line)++;
	i = 0;
	while (i < 3)
	{
		if (!validate_argument(*line))
			error_exit("Parsing Error", 1);
		value = (double)ft_atoi(*line);
		if (value < 0 || value > 255)
			error_exit("Parsing Error", 1);
		temp[i] = value / 255.0;
		while (**line >= '0' && **line <= '9')
			(*line)++;
		if (**line == ',')
			(*line)++;
		i++;
	}
	return (color3(temp[0], temp[1], temp[2]));
}

int	get_fov(char **line)
{
	int res;

	while (**line == ' ')
		(*line)++;
	if (!validate_argument(*line))
		error_exit("Parsing Error", 1);
	res = ft_atoi(*line);
	if (res < 0 || res > 180)
		error_exit("Parsing Error", 1);
	while (**line >= '0' && **line <= '9')
		(*line)++;
	return (res);
}

t_point3	get_coordinate(char **line)
{
	t_point3	point;
	double		temp[3];
	int			i;

	while (**line == ' ')
		(*line)++;
	i = 0;
	while (i < 3)
	{
		if (!validate_argument(*line))
			error_exit("Parsing Error", 1);
		temp[i] = ft_atof(*line);
		while ((**line >= '0' && **line <= '9') || **line == '.' || **line == '-' || **line == '+')
			(*line)++;
		if (**line == ',')
			(*line)++;
		i++;
	}
	point.x = temp[0];
	point.y = temp[1];
	point.z = temp[2];
	return (point);
}

t_vec3	get_vector(char **line)
{
	t_vec3	vec;
	double	temp[3];
	int		i;

	while (**line == ' ')
		(*line)++;
	i = 0;
	while (i < 3)
	{
		if (!validate_argument(*line))
			error_exit("Parsing Error", 1);
		temp[i] = ft_atof(*line);
		if (temp[i] < -1.0 || temp[i] > 1.0)
			error_exit("Parsing Error", 1);
		while ((**line >= '0' && **line <= '9') || **line == '.' || **line == '-' || **line == '+')
			(*line)++;
		if (**line == ',')
			(*line)++;
		i++;
	}
	vec.x = temp[0];
	vec.y = temp[1];
	vec.z = temp[2];
	return (vec);
}

int	validate_argument(char *line)
{
	if (*line == '+')
		line++;
	else if (*line == '-')
		line++;
	if (!*line)
		return (0);
	while (*line)
	{
		if (*line == ',' || *line == ' ')
			break ;
		else if ((*line >= '0' && *line <= '9') || *line == '.' || *line == '\n')
			line++;
		else
			return (0);
	}
	return (1);
}

void validate_overlap(int id, int *check_overlap) // checking whether A, C, L appear only once or not
{
	if (id >= 4 && !check_overlap[id - 4])
		check_overlap[id - 4] = 1;
	else if (id >= 4 && check_overlap[id - 4])
		error_exit("Parsing Error", 1);
}
