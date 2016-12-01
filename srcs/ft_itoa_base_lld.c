/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonnier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:22:54 by rmonnier          #+#    #+#             */
/*   Updated: 2016/11/29 23:18:31 by rmonnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		convert_number_to_base_component(int number)
{
	char *base;

	base = "0123456789abcdef";
	return (base[number]);
}

static size_t	size_itoa(long long value, int base)
{
	size_t		i;

	i = 1;
	while ((value / base) != 0)
	{
		value = value / base;
		i++;
	}
	return (i);
}

static void		fill_str_itoa_base(long long value, int base, char *str, size_t i)
{
	str[i] = convert_number_to_base_component(-(value % base));
	if ((value / base) != 0)
		fill_str_itoa_base(value / base, base, str, i - 1);
}

char			*ft_itoa_base_lld(long long value, int base)
{
	char	*itoa;
	size_t	size;

	if (base < 2 || base > 16)
		return (NULL);
	size = size_itoa(value, base);
	if (value < 0 && base == 10)
		size++;
	if (!(itoa = (char*)ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (value < 0 && base == 10)
		itoa[0] = '-';
	else if (value > 0)
		value = -value;
	itoa[size] = '\0';
	fill_str_itoa_base(value, base, itoa, size - 1);
	return (itoa);
}
