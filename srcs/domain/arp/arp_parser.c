/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:40:41 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 17:11:23 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/arp/arp_parser.h"
#include "libft.h"

t_arp_parser_status	parse_arp_request(unsigned char *buff, size_t buff_size,
		t_arp_packet *dst)
{
	ft_memset(dst, 0, sizeof(t_arp_packet));
	(void)buff;
	(void)buff_size;
	return (ARP_PARSING_SUCCESS);
}
