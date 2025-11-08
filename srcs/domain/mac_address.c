/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_address.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:54:47 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 14:40:23 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/mac_address.h"
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
	// __builtin_printf("Comparing MAC addresses: ");
	// print_mac(mac1);
	// __builtin_printf(" and ");
	// print_mac(mac2);
	// __builtin_printf("\n");
	while (++i < 6)
		if (mac1->bytes[i] != mac2->bytes[i])
			return (false);
	return (true);
}
