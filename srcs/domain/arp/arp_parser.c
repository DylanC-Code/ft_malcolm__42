/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:40:41 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 23:03:47 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/arp/arp_parser.h"
#include "libft.h"
#include "shared/byte_utils.h"
#include <net/if_arp.h>
#include <netinet/if_ether.h>
#include <stddef.h>

static void	parse_arp_header(unsigned char *buff, struct arphdr *hdr)
{
	unsigned char	*arp_p;

	arp_p = buff + ETH_HLEN;
	hdr->ar_hrd = get_u16(arp_p + offsetof(struct arphdr, ar_hrd));
	hdr->ar_pro = get_u16(arp_p + offsetof(struct arphdr, ar_pro));
	hdr->ar_hln = get_u8(arp_p + offsetof(struct arphdr, ar_hln));
	hdr->ar_pln = get_u8(arp_p + offsetof(struct arphdr, ar_pln));
	hdr->ar_op = get_u16(arp_p + offsetof(struct arphdr, ar_op));
}

static void	parse_arp_addrs(unsigned char *buff, t_arp_packet *pkt)
{
	unsigned char	*arp_p;

	arp_p = buff + ETH_HLEN + 8;
	ft_memcpy(&pkt->src_mac, arp_p, 6);
	ft_memcpy(&pkt->src_ip, arp_p + 6, 4);
	ft_memcpy(&pkt->tgt_mac, arp_p + 12, 6);
	ft_memcpy(&pkt->tgt_ip, arp_p + 18, 4);
}

t_arp_parser_status	parse_arp_request(unsigned char *buff, size_t buff_size,
		t_arp_packet *dst)
{
	if (buff_size < ETH_HLEN + ARP_HLEN)
		return (ARP_REQUEST_TOO_SHORT);
	ft_memset(dst, 0, sizeof(t_arp_packet));
	parse_arp_header(buff, &dst->header);
	parse_arp_addrs(buff, dst);
	return (ARP_PARSING_SUCCESS);
}
