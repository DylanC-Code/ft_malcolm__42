/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arp_printer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 23:09:26 by dylan             #+#    #+#             */
/*   Updated: 2025/11/07 23:10:36 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARP_PRINTER_H
# define ARP_PRINTER_H

# include "domain/arp/arp_packet.h"

void	print_arp_packet(t_arp_packet *pkt);

#endif