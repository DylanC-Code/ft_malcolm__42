/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 21:42:26 by dylan             #+#    #+#             */
/*   Updated: 2025/11/08 09:16:43 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYTE_UTILS_H
# define BYTE_UTILS_H

# include <stdint.h>

static inline uint16_t	get_u16(const void *ptr)
{
	uint16_t	res;

	res = 0;
	ft_memcpy(&res, ptr, sizeof(uint16_t));
	return (res);
}

static inline uint32_t	get_u32(const void *ptr)
{
	uint32_t	res;

	res = 0;
	ft_memcpy(&res, ptr, sizeof(uint32_t));
	return (res);
}

static inline uint8_t	get_u8(const void *ptr)
{
	uint8_t	res;

	res = *(uint8_t *)(ptr);
	return (res);
}

#endif
