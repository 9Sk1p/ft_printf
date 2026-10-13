/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 14:05:51 by marvin            #+#    #+#             */
/*   Updated: 2026/10/13 14:05:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char format)
{
	int		len;
	char	*base;

	len = 0;
	if (format == 'X')
		base = "0123456789ABCDEF";
	else 
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_print_hex(n / 16, format);
	len += ft_print_char(base[n % 16]);
	return (len);
}