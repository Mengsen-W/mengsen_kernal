/*
 * @Author: Mengsen.Wang
 * @Date: 2020-10-21 17:52:32
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-10-21 18:16:55
 * @Brief: comsole operation
 */

#ifndef MENGSEN_CONSOLE_H_
#define MENGSEN_CONSOLE_H_

#include "types.h"

/**
 * @brief RCB color
 */
typedef enum real_color {
  rc_black = 0,
  rc_blue = 1,
  rc_green = 2,
  rc_cyan = 3,
  rc_red = 4,
  rc_magenta = 5,
  rc_brown = 6,
  rc_light_grey = 7,
  rc_dark_grey = 8,
  rc_light_blue = 9,
  rc_light_green = 10,
  rc_light_cyan = 11,
  rc_light_red = 12,
  rc_light_magenta = 13,
  rc_light_brown = 14,  // yellow
  rc_white = 15
} real_color_t;

/**
 * @brief clean console
 */
void console_clear();

/**
 * @brief out console one char with color
 * @param c [char] output char
 * @param back [real_color_t] background color
 * @param fore [real_color_t] foreground color
 */
void console_putc_color(char c, real_color_t back, real_color_t fore);

/**
 * @brief out console string that is white character with black background and
 * '\0' in end
 * @param cstr [char *] output string
 */
void console_write(char *cstr);

/**
 * @brief out console string colorful and '\0' in end
 * @param cstr [char *] output string
 * @param back [real_color_t] background color
 * @param fore [real_color_t] foreground color
 */
void console_write_color(char *cstr, real_color_t back, real_color_t fore);

/**
 * @brief out console hexadecimal integers colorful
 * @param n [uint32_t] output integers
 * @param back [real_color_t] background color
 * @param fore [real_color_t] foreground color
 */
void console_write_hex(uint32_t n, real_color_t back, real_color_t fore);

/**
 * @brief out console Decimal integer colorful
 * @param n [uint32_t] output integer
 * @param back [real_color_t] background color
 * @param fore [real_color_t] foreground color
 */
void console_write_dec(uint32_t n, real_color_t back, real_color_t fore);

#endif  // MENGSEN_CONSOLE_H_