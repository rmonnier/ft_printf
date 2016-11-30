/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_formater.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:07:02 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/30 11:25:26 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	is_unsigned_conv(char c)
{
	return (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
			c == 'b' || c == 'B');
}

static t_bool	is_signed_conv(char c)
{
	return (c == 'd' || c == 'D' || c == 'i');
}

char				*get_raw_data(va_list ap, t_specifiers specifiers)
{
	char *str;

	if (is_unsigned_conv(specifiers.identifier))
		str = unsigned_conv(ap, specifiers);
	else if (is_signed_conv(specifiers.identifier))
		str = signed_conv(ap, specifiers);
	return (str);
}
