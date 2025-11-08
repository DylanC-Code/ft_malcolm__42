/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_serializer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:50:15 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 22:00:39 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/ip_address.h"
#include "infrastructure/net/arp_serializer.h"
#include "libft.h"
#include "shared/byte_utils.h"
#include <net/ethernet.h>

static void	serialize_eth_header(const t_arp_frame *frame,
		unsigned char dst[128])
{
	unsigned char	*eth_p;
	uint16_t		tmp16;

	eth_p = dst;
	ft_memcpy(eth_p, frame->tgt_mac.bytes, sizeof(frame->tgt_mac.bytes));
	eth_p += sizeof(frame->tgt_mac.bytes);
	ft_memcpy(eth_p, frame->src_mac.bytes, sizeof(frame->src_mac.bytes));
	eth_p += sizeof(frame->src_mac.bytes);
	tmp16 = htons(ETH_P_ARP);
	ft_memcpy(eth_p, &tmp16, sizeof(uint16_t));
}

static void	serialize_arp_header(const t_arp_frame *frame,
		unsigned char dst[128])
{
	unsigned char	*arp_p;
	uint16_t		tmp16;

	arp_p = dst + ETH_HLEN;
	tmp16 = htons(frame->header_arp.ar_hrd);
	ft_memcpy(arp_p, &tmp16, sizeof(tmp16));
	arp_p += 2;
	tmp16 = htons(frame->header_arp.ar_pro);
	ft_memcpy(arp_p, &tmp16, sizeof(tmp16));
	arp_p += 2;
	*arp_p++ = frame->header_arp.ar_hln;
	*arp_p++ = frame->header_arp.ar_pln;
	tmp16 = htons(frame->header_arp.ar_op);
	ft_memcpy(arp_p, &tmp16, sizeof(tmp16));
}

static void	serialize_arp_addrs(const t_arp_frame *frame,
		unsigned char dst[128])
{
	unsigned char	*arp_p;

	arp_p = dst + ETH_HLEN + 8;
	ft_memcpy(arp_p, &frame->src_mac.bytes, ETH_ALEN);
	arp_p += ETH_ALEN;
	ft_memcpy(arp_p, &frame->src_ip, IP4LEN);
	arp_p += IP4LEN;
	ft_memcpy(arp_p, &frame->tgt_mac.bytes, ETH_ALEN);
	arp_p += ETH_ALEN;
	ft_memcpy(arp_p, &frame->tgt_ip, IP4LEN);
}

void	serialize_arp_frame(const t_arp_frame *frame, unsigned char dst[128])
{
	ft_memset(dst, 0, 128);
	serialize_eth_header(frame, dst);
	serialize_arp_header(frame, dst);
	serialize_arp_addrs(frame, dst);
}
