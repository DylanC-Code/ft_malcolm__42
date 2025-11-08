/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mac_address.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:53:07 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 14:33:56 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAC_H
# define MAC_H

# include <stdbool.h>
# include <stdint.h>

typedef struct s_mac
{
	uint8_t	bytes[6];
}			t_mac;

void		print_mac(const t_mac *mac);
bool		mac_equal(const t_mac *restrict mac1,
				const t_mac *restrict mac2) __attribute__((nonnull));

#endif
