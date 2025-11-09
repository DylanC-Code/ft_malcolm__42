/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:54:47 by dylan             #+#    #+#             */
/*   Updated: 2025/11/09 18:16:39 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/mac_address.h"
#include "libft.h"
#include <stdio.h>

void	print_mac(const t_mac *mac)
{
	printf("%02x:%02x:%02x:%02x:%02x:%02x", mac->bytes[0], mac->bytes[1],
		mac->bytes[2], mac->bytes[3], mac->bytes[4], mac->bytes[5]);
}

/// @brief Compare two MAC addresses
/// @param mac1
/// @param mac2
/// @return true if equal, false otherwise
bool	mac_equal(const t_mac *restrict mac1, const t_mac *restrict mac2)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (mac1->bytes[i] != mac2->bytes[i])
			return (false);
	return (true);
}

char	*mac_to_string(const t_mac *mac)
{
	char	str[18];

	sprintf(str, "%02x:%02x:%02x:%02x:%02x:%02x", mac->bytes[0], mac->bytes[1],
		mac->bytes[2], mac->bytes[3], mac->bytes[4], mac->bytes[5]);
	return (ft_strdup(str));
}

bool	is_multicast_mac(const t_mac *mac)
{
	return (mac->bytes[0] & 0x01);
}

bool	is_broadcast_mac(const t_mac *mac)
{
	return (mac->bytes[0] == 0xff && mac->bytes[1] == 0xff
		&& mac->bytes[2] == 0xff && mac->bytes[3] == 0xff
		&& mac->bytes[4] == 0xff && mac->bytes[5] == 0xff);
}
