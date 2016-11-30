/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 21:51:41 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/29 17:06:15 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* functions that get each kind of specifications through parsing */

void		get_flags(char const **format, t_specifiers *specifiers)
{
	while (is_flag(**format))
	{
		if (**format == '#')
			specifiers->flags.sharp = 1;
		if (**format == '0')
			specifiers->flags.zero = 1;
		if (**format == '-')
			specifiers->flags.dash = 1;
		if (**format == ' ')
			specifiers->flags.space = 1;
		if (**format == '+')
			specifiers->flags.plus = 1;
		(*format)++;
	}
}

void		get_width(char const **format, t_specifiers *specifiers, va_list ap)
{
	if (ft_isdigit(**format))
	{
		specifiers->width = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		(*format)++;
		specifiers->width = va_arg(ap, int);
		while (ft_isdigit(**format))
			(*format)++;
		if (**format == '$')
			(*format)++;
	}
}

void		get_precision(char const **format, t_specifiers *specifiers, va_list ap)
{
	(*format)++;
	if (ft_isdigit(**format))
	{
		specifiers->width = ft_atoi(++(*format));
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		(*format)++;
		specifiers->width = va_arg(ap, int);
		while (ft_isdigit(**format))
			(*format)++;
		if (**format == '$')
			(*format)++;
	}
}

void get_length_specifier(char const **format, t_specifiers *specifiers)
{
	while (is_length_specifier(**format))
	{
		if (**format == 'h')
			specifiers->length.h++;
		else if (**format == 'l')
			specifiers->length.l++;
		else if (**format == 'j')
			specifiers->length.j++;
		else if (**format == 'z')
			specifiers->length.z++;
		(*format)++;
	}
}

void		get_identifier(char const **format, t_specifiers *specifiers)
{
	if (**format == 'p')
	{
		specifiers->identifier = 'x';
		specifiers->flags.sharp = 1;
		specifiers->length.l = 1;
		(*format)++;
	}
	else if (is_identifier(**format))
	{
		specifiers->identifier = **format;
		(*format)++;
	}
}
