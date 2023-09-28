#ifndef ILI9341_SPRITE_H
#define ILI9341_SPRITE_H

#include "ILI9341_STM32_Driver.h"
#include "ILI9341_STM32_GFX.h"

typedef struct sprite_s
{
    /* data */
    const uint16_t *bitmap; // bitmap RGB565
    uint16_t width;         // ความกว้างของ sprite
    uint16_t height;        // ความสูงของ sprite
    uint16_t x;             // ตำแหน่งปัจจุบันในแกน x ของ sprite
    uint16_t y;             // ตำแหน่งปัจจุบันในแกน y ของ sprite
} Sprite;

void ILI9341_Draw_Sprite(const uint16_t *SPRITE, uint16_t WIDTH, uint16_t HEIGHT, uint16_t X, uint16_t Y);

#endif