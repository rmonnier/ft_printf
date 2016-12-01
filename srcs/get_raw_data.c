/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_raw_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:20:44 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/30 16:20:46 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* function that select a method to get the data */

t_bool	is_unsigned_conv(char c)
{
	return (c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
			c == 'b' || c == 'B');
}

t_bool	is_signed_conv(char c)
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
	else
		str = ft_strdup(&(specifiers.identifier));
	return (str);
}
