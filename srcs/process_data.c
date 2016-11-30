/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 11:56:58 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/29 17:33:04 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool is_sharp_eligible(char c)
{
	return (c == 'o' || c == 'O' || c == 'x' || c == 'X');
}

void apply_sharp_flag(char **data, t_specifiers specifiers)
{
	char *tmp;

	tmp = *data;
	if (specifiers.identifier == 'o' || specifiers.identifier == 'O')
		*data = ft_strjoin("0", *data);
	else
		*data = ft_strjoin("0x", *data);
	free(tmp);
}

void apply_plus_space_flag(char **data, t_specifiers specifiers)
{
	char *tmp;

	tmp = *data;
	if (**data != '-')
	{
		if (specifiers.flags.plus)
			*data = ft_strjoin("+", *data);
		else
			*data = ft_strjoin(" ", *data);
		free(tmp);
	}
}

/* process the data from get_raw_data and apply flags, width and precision
	specified */

void	process_data(char **data, t_specifiers specifiers)
{
	int	len;

	if (specifiers.flags.sharp && is_sharp_eligible(specifiers.identifier))
		apply_sharp_flag(data, specifiers);
	if (specifiers.identifier == 'X')
		ft_strupcase(*data);
	if ((specifiers.flags.space || specifiers.flags.plus) &&
			is_signed_conv(specifiers.identifier))
		apply_plus_space_flag(data, specifiers);
	len = ft_strlen(*data);
}
