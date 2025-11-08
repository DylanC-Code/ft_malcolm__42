/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_frame.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:41:06 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 15:45:59 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_FRAME_H
# define ARP_FRAME_H

# define ARP_HLEN 28

# include "domain/mac_address.h"
# include <net/if_arp.h>
# include <netinet/in.h>

typedef struct s_arp_frame
{
	struct arphdr	header_arp;
	t_mac			src_mac;
	t_mac			tgt_mac;
	in_addr_t		src_ip;
	in_addr_t		tgt_ip;
}					t_arp_frame;

#endif
