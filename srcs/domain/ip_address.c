/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 10:35:17 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:04:39 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/ip_address.h"
#include <stdio.h>

void	print_ip(const in_addr_t ip)
{
	unsigned char	bytes[4];

	bytes[0] = ip & 0xff;
	bytes[1] = (ip >> 8) & 0xff;
	bytes[2] = (ip >> 16) & 0xff;
	bytes[3] = (ip >> 24) & 0xff;
	printf("%u.%u.%u.%u", bytes[0], bytes[1], bytes[2], bytes[3]);
}

bool	ip_equal(const in_addr_t ip1, const in_addr_t ip2)
{
	return (ip1 == ip2);
}
