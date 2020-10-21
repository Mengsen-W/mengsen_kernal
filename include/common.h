/*
 * @Author: Mengsen.Wang
 * @Date: 2020-10-21 17:51:27
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-10-21 18:11:01
 * @Brief: read write to port
 */

#ifndef MENGSEN_COMMON_H_
#define MENGSEN_COMMON_H_

#include "types.h"

/**
 * @brief write to port one bit
 * @param port [uint16_t] port address
 * @param value [uint8_t] out bit
 */
inline void outb(uint16_t port, uint8_t value);

/**
 * @brief read to port one bit
 * @param port [uint16_t] port address
 * @return value [uint8_t] out bit
 */
inline uint8_t inb(uint16_t port);

/**
 * @brief read to port one word
 * @param port [uint16_t] port address
 * @return value [uint16_t] out bit
 */
inline uint16_t inw(uint16_t port);

#endif  // MENGSEN_COMMON_H_