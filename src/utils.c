/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:58:14 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/05 18:32:56 by fnacarel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	if (str)
	{
		while (*str)
		{
			str++;
			count++;
		}
	}
	return (count);
}

int		ft_put_address(unsigned long long nbr)
{
	int	chars_printed;

	chars_printed = 0;
	if (!nbr)
	{
		chars_printed += ft_putstr("(nil)");
		return (chars_printed);
	}
	chars_printed += ft_putstr("0x");
	chars_printed += ft_puthex(nbr, HEX_DIGITS_LOWCASE);
	return (chars_printed);
}

int		ft_puthex(unsigned long long nbr, char *base)
{
	int	len_base;
	int	chars_printed;

	chars_printed = 0;
	len_base = ft_strlen(base);
	if (nbr < len_base)
		chars_printed += ft_putchar(base[nbr]);
	else
	{
		chars_printed += ft_putnbr_base(nbr / len_base, base);
		chars_printed += ft_putnbr_base(nbr % len_base, base);
	}
	return (chars_printed);
}

int		ft_putnbr_base(long long nbr, char *base)
{
	int	len_base;
	int	chars_printed;

	chars_printed = 0;
	len_base = ft_strlen(base);
	if (nbr < 0)
	{
		nbr *= -1;
		chars_printed += ft_putchar('-');
	}
	if (nbr < len_base)
		chars_printed += ft_putchar(base[nbr]);
	else
	{
		chars_printed += ft_putnbr_base(nbr / len_base, base);
		chars_printed += ft_putnbr_base(nbr % len_base, base);
	}
	return (chars_printed);
}

int		ft_putstr(char *str)
{
	int	chars_printed;

	chars_printed = 0;
	if (str)
	{
		while (str[chars_printed])
		{
			write(1, &str[chars_printed], 1);
			chars_printed++;
		}
	}
	else
		chars_printed += ft_putstr("(null)");
	return (chars_printed);
}
