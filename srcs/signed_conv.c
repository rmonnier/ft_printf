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

/* data conversion for d, D, i */

static long long get_arg(va_list ap, char id, t_length length)
{
	unsigned long long output;

	if (length.l >= 2)
		output = (long long)va_arg(ap, long long);
	else if (length.l == 1 || id == 'U' || id == 'O' || id == 'B')
		output = (long long)va_arg(ap, long);
	else if (length.h >= 2)
		output = (long long)va_arg(ap, int);
	else if (length.h == 1)
		output = (long long)va_arg(ap, int);
	else
		output = (long long)va_arg(ap, int);
	return (output);
}

char  				*signed_conv(va_list ap, t_specifiers specifiers)
{
	long long	arg;
	int			base;
	char			*output;

	arg = get_arg(ap, specifiers.identifier, specifiers.length);
	base = get_conv_base(specifiers.identifier);
	output = ft_itoa_base_lld(arg, base);
	return (output);
}
