/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:58:14 by fnacarel          #+#    #+#             */
/*   Updated: 2022/10/04 17:26:02 by fnacarel         ###   ########.fr       */
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

int		ft_put_address(unsigned long int nbr)
{
	int	chars_printed;

	chars_printed = 0;
	if (!nbr)
	{
		chars_printed += ft_putstr("(nil)");
		return (chars_printed);
	}
	chars_printed += ft_putstr("0x");
	chars_printed += ft_putnbr_base(nbr, HEX_DIGITS_LOWCASE);
	return (chars_printed);
}

int		has_repeated_chars(char *str)
{
	size_t	len_str;
	size_t	i;
	size_t	j;

	i = 0;
	len_str = ft_strlen(str);
	if (str && len_str)
	{
		while (i < len_str)
		{
			j = (i + 1);
			while (j < len_str)
			{
				if (str[i] == str[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

int		ft_putnbr_base(long long nbr, char *base)
{
	int	len_base;
	int	chars_printed;

	chars_printed = 0;
	len_base = ft_strlen(base);
	if (has_repeated_chars(base))
		return (0);
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
	return (chars_printed);
}
