/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_address.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:53:07 by dylan             #+#    #+#             */
/*   Updated: 2025/11/10 11:59:08 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_ADDRESS_H
# define MAC_ADDRESS_H

# include <stdbool.h>
# include <stdint.h>

typedef struct s_mac
{
	uint8_t	bytes[6];
}			t_mac;

void		print_mac(const t_mac *mac);
bool		mac_equal(const t_mac *restrict mac1,
				const t_mac *restrict mac2) __attribute__((nonnull));
void		mac_to_string(const t_mac *mac, char dst[18]);
bool		is_multicast_mac(const t_mac *mac) __attribute__((nonnull));
bool		is_broadcast_mac(const t_mac *mac) __attribute__((nonnull));

#endif
