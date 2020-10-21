/*
 * @Author: Mengsen.Wang
 * @Date: 2020-10-19 19:02:54
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-10-19 19:04:07
 * @Description: entry
 */

#include "types.h"

int kern_entry() {
  uint8_t *input = (uint8_t *)0xB8000;
  uint8_t color = (0 << 4) | (15 & 0x0F);

  *input++ = 'H';
  *input++ = color;
  *input++ = 'e';
  *input++ = color;
  *input++ = 'l';
  *input++ = color;
  *input++ = 'l';
  *input++ = color;
  *input++ = 'o';
  *input++ = color;
  *input++ = ',';
  *input++ = color;
  *input++ = ' ';
  *input++ = color;
  *input++ = 'O';
  *input++ = color;
  *input++ = 'S';
  *input++ = color;
  *input++ = ' ';
  *input++ = color;
  *input++ = 'K';
  *input++ = color;
  *input++ = 'e';
  *input++ = color;
  *input++ = 'r';
  *input++ = color;
  *input++ = 'n';
  *input++ = color;
  *input++ = 'e';
  *input++ = color;
  *input++ = 'l';
  *input++ = color;
  *input++ = '!';
  *input++ = color;

  return 0;
}