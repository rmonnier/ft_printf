/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:39:04 by rmonnier          #+#    #+#             */
/*   Updated: 2016/12/01 18:39:06 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* data conversion for c, C, s, S */

static char		*get_arg_c(va_list ap)
{
	char	arg;
	char	*output;

	arg = (char)va_arg(ap, int);
	output = ft_strndup(&arg, 1);
	return (output);
}

static char		*get_arg_s(va_list ap)
{
	char	*arg;
	char	*output;

	arg = (char*)va_arg(ap, char*);
	output = ft_strdup(arg);
	return (output);
}

static char		*get_arg_lc(va_list ap)
{
	wint_t	arg;
	char		*output;

	arg = (wint_t)va_arg(ap, wint_t);
	output = ft_unicode_encoder(arg);
	return (output);
}

static char		*get_arg_ls(va_list ap)
{
	wchar_t	*arg;
	char		*output;

	arg = (wchar_t*)va_arg(ap, wchar_t*);
	output = ft_unicode_string_encoder(arg);
	return (output);
}

char  	*characters_conv(va_list ap, t_specifiers specifiers)
{
	unsigned long long arg;
	int					base;
	char					*output;

	if (specifiers.identifier == 'C' ||
				(specifiers.identifier == 'c' && specifiers.length.l == 1))
		output = get_arg_ls(ap);
	else if (specifiers.identifier == 'S' ||
				(specifiers.identifier == 's' && specifiers.length.l == 1))
		output = get_arg_ls(ap);
	else if (specifiers.identifier == 'c')
		output = get_arg_c(ap);
	else if (specifiers.identifier == 's')
		output = get_arg_s(ap);
	return (output);
}
