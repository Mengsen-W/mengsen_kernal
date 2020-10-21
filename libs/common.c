/*
 * @Author: Mengsen.Wang
 * @Date: 2020-10-21 17:52:57
 * @Last Modified by: Mengsen.Wang
 * @Last Modified time: 2020-10-21 18:11:43
 */

#include "common.h"

void outb(uint16_t port, uint8_t value) {
  asm volatile("outb %1, %0" : : "dN"(port), "a"(value));
}

uint8_t inb(uint16_t port) {
  uint8_t ret;

  asm volatile("inb %1, %0" : "=a"(ret) : "dN"(port));

  return ret;
}

uint16_t inw(uint16_t port) {
  uint16_t ret;

  asm volatile("inw %1, %0" : "=a"(ret) : "dN"(port));

  return ret;
}