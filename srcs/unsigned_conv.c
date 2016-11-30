/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 22:52:07 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/29 23:16:38 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* data conversion for o, O, u, U, x, X, b, B */

static unsigned long long get_arg(va_list ap, char id, t_length length)
{
	unsigned long long output;

	if (length.l >= 2)
		output = (unsigned long long)va_arg(ap, unsigned long long);
	else if (length.l == 1 || id == 'U' || id == 'O' || id == 'B')
		output = (unsigned long long)va_arg(ap, unsigned long);
	else if (length.h >= 2)
		output = (unsigned long long)va_arg(ap, unsigned int);
	else if (length.h == 1)
		output = (unsigned long long)va_arg(ap, unsigned int);
	else
		output = (unsigned long long)va_arg(ap, unsigned int);
	return (output);
}

char  							*unsigned_conv(va_list ap, t_specifiers specifiers)
{
	unsigned long long arg;
	int					base;
	char					*output;

	arg = get_arg(ap, specifiers.identifier, specifiers.length);
	base = get_conv_base(specifiers.identifier);
	output = ft_itoa_base_llu(arg, base);
	return (output);
}
