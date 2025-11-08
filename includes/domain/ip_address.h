/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_address.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:47:13 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 12:00:45 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IP_ADDRESS_H
# define IP_ADDRESS_H

# define IP4LEN 4

# include <netinet/in.h>
# include <stdbool.h>

bool	ip_equal(const in_addr_t ip1, const in_addr_t ip2);

#endif
