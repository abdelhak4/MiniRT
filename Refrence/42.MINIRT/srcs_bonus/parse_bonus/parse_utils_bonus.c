/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-jao <mait-jao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:26:53 by mait-jao          #+#    #+#             */
/*   Updated: 2022/11/12 22:32:28 by mait-jao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incls/mini_rt.h"

int	get_int_len(char *line, int i)
{
	int	int_len;

	int_len = 0;
	if (ft_isdigit(line[i]))
	{
		while (ft_isdigit(line[i]))
		{
			i++;
			int_len++;
		}
	}
	else
		print_error_exit(get_scene(), "check digit");
	return (int_len);
}

int	get_float_len(char *line, int i)
{
	int	float_len;
	int	dot;

	dot = 0;
	float_len = 0;
	if (line[i] == '-')
	{
		i++;
		float_len++;
	}
	if (ft_isdigit(line[i]))
	{
		while (ft_isdigit(line[i]) || line[i] == '.')
		{
			if (line[i] == '.')
				dot++;
			i++;
			float_len++;
		}
	}
	else
		print_error_exit(get_scene(), "check float");
	if (dot > 1)
		print_error_exit(get_scene(), "check float");
	return (float_len);
}
