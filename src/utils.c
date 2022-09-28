/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnacarel <fnacarel@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:58:14 by fnacarel          #+#    #+#             */
/*   Updated: 2022/09/28 09:55:59 by fnacarel         ###   ########.fr       */
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

void	ft_putnbr_base(long long nbr, char *base)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	if (has_repeated_chars(base))
		return ;
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr < len_base)
		write(1, &base[nbr % len_base], 1);
	else
	{
		ft_putnbr_base(nbr / len_base, base);
		ft_putnbr_base(nbr % len_base, base);
	}
}
