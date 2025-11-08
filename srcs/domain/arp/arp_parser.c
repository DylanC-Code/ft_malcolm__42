/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:40:41 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 10:48:28 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/arp/arp_parser.h"
#include "domain/ip_address.h"
#include "infrastructure/shared.h"
#include "libft.h"
#include "shared/byte_utils.h"
#include <arpa/inet.h>
#include <net/if_arp.h>
#include <netinet/if_ether.h>
#include <netinet/in.h>
#include <stddef.h>

static t_arp_parser_status	parse_arp_header(unsigned char *buff,
		size_t buff_size, struct arphdr *hdr)
{
	unsigned char	*arp_p;

	if (buff_size < ETH_HLEN + ARP_HLEN)
		return (ARP_REQUEST_TOO_SHORT);
	arp_p = buff + ETH_HLEN;
	hdr->ar_hrd = ntohs(get_u16(arp_p + 0));
	hdr->ar_pro = ntohs(get_u16(arp_p + 2));
	hdr->ar_hln = get_u8(arp_p + 4);
	hdr->ar_pln = get_u8(arp_p + 5);
	hdr->ar_op = ntohs(get_u16(arp_p + 6));
	return (ARP_PARSING_SUCCESS);
}

static t_arp_parser_status	parse_arp_addrs(unsigned char *buff,
		t_arp_packet *pkt)
{
	unsigned char	*arp_p;

	arp_p = buff + ETH_HLEN + 8;
	if (pkt->header.ar_hln != 6 || pkt->header.ar_pln != 4)
		return (ARP_INVALID_LENGTHS);
	ft_memcpy(&pkt->src_mac, arp_p, 6);
	pkt->src_ip = ntohl(get_u32(arp_p + ETH_ALEN));
	ft_memcpy(&pkt->tgt_mac, arp_p + ETH_ALEN + IP4LEN, 6);
	pkt->tgt_ip = ntohl(get_u32(arp_p + ETH_ALEN + IP4LEN + ETH_ALEN));
	return (ARP_PARSING_SUCCESS);
}

static char	*arp_parse_strerror(t_arp_parser_status err)
{
	if (err == ARP_PARSING_SUCCESS)
		return ("arp packet ok");
	else if (err == ARP_REQUEST_TOO_SHORT)
		return ("arp packet too short to contain full arp header");
	else if (err == ARP_INVALID_LENGTHS)
		return ("arp packet has invalid hardware or protocol address lengths");
	else if (err == ARP_INVALID_IP)
		return ("arp packet contains invalid ip addresses");
	else
		return ("arp parsing unknown error");
}

bool	parse_arp_request(unsigned char *buff, size_t buff_size,
		t_arp_packet *dst)
{
	t_arp_parser_status	hdr_status;
	t_arp_parser_status	addrs_status;

	ft_memset(dst, 0, sizeof(t_arp_packet));
	hdr_status = parse_arp_header(buff, buff_size, &dst->header);
	if (hdr_status != ARP_PARSING_SUCCESS)
	{
		ft_error(arp_parse_strerror(hdr_status));
		return (false);
	}
	addrs_status = parse_arp_addrs(buff, dst);
	if (addrs_status != ARP_PARSING_SUCCESS)
	{
		ft_error(arp_parse_strerror(addrs_status));
		return (false);
	}
	return (true);
}
