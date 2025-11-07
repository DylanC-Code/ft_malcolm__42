/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_packet.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:41:06 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 22:22:50 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_PACKET_H
# define ARP_PACKET_H

# define ARP_HLEN 28

# include "domain/mac.h"
# include <net/if_arp.h>
# include <netinet/in.h>

typedef struct s_arp_packet
{
	struct arphdr	header;
	t_mac			src_mac;
	t_mac			tgt_mac;
	in_addr_t		src_ip;
	in_addr_t		tgt_ip;
}					t_arp_packet;

#endif
