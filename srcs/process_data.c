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

void apply_sharp_flag(char **data, char id)
{
	char *tmp;

	if (id == 'o' || id == 'O' || id == 'x' || id == 'X')
	{
		tmp = *data;
		if (id == 'o' || id == 'O')
			*data = ft_strjoin("0", *data);
		else
			*data = ft_strjoin("0x", *data);
		free(tmp);
	}
}

void apply_plus_space_flag(char **data, t_specifiers specifiers)
{
	char *tmp;

	if (is_signed_conv(specifiers.identifier) && **data != '-')
	{
		tmp = *data;
		if (specifiers.flags.plus)
			*data = ft_strjoin("+", *data);
		else
			*data = ft_strjoin(" ", *data);
		free(tmp);
	}
}

void apply_precision(char **data, t_specifiers specifiers)
{
	size_t	len;
	int		precision;
	char		*to_add;
	char		*tmp;

	len = ft_strlen(*data);
	precision = specifiers.precision;
	tmp = *data;
	if ((is_signed_conv(specifiers.identifier) ||
		is_unsigned_conv(specifiers.identifier)) && precision > len)
		{
			to_add = ft_strcnew(precision - len, '0');
			*data = ft_strjoin(to_add, *data);
			free(tmp);
			free(to_add);
		}
}

void apply_width(char **data, t_specifiers specifiers)
{
	size_t	len;
	int		width;
	char		*to_add;
	char		*tmp;

	len = ft_strlen(*data);
	width = specifiers.width;
	if (width > len)
	{
		tmp = *data;
		if (specifiers.flags.zero == 0 || specifiers.precision != 0)
			to_add = ft_strcnew(width - len, ' ');
		else
			to_add = ft_strcnew(width - len, '0');
		if (specifiers.flags.dash == 0)
			*data = ft_strjoin(to_add, *data);
		else
			*data = ft_strjoin(*data, to_add);
		free(tmp);
		free(to_add);
	}
}

/* process the data from get_raw_data and apply flags, width and precision
	specified */

void	process_data(char **data, t_specifiers specifiers)
{
	int	len;

	if (specifiers.identifier == 'n')
		return ;
	if (specifiers.flags.sharp)
		apply_sharp_flag(data, specifiers.identifier);
	if (specifiers.identifier == 'X')
		ft_strupcase(*data);
	if (specifiers.precision > 0)
		apply_precision(data, specifiers);
	if ((specifiers.flags.space || specifiers.flags.plus))
		apply_plus_space_flag(data, specifiers);
	if (specifiers.width > 0)
		apply_width(data, specifiers);
}
