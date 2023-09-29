#include "ILI9341_Sprite.h"

void ILI9341_Draw_Sprite(const uint16_t *SPRITE, uint16_t WIDTH, uint16_t HEIGHT, uint16_t X, uint16_t Y)
{
    // วาด bitmap จากกึ่งกลาง
    uint16_t half_height = (HEIGHT % 2) ? ((HEIGHT / 2) + 1) : (HEIGHT / 2);
    uint16_t half_width = (WIDTH % 2) ? ((WIDTH / 2) + 1) : (WIDTH / 2);

    uint16_t pixel = (half_height * WIDTH) - 1; // index ของ bitmap 1-D array
    uint16_t size = WIDTH * HEIGHT;

    // วาดท่อนบน
    for (uint16_t y = 0; y < half_height; y++)
    {
        for (uint16_t x = WIDTH - half_width; x > 0; x--)
        {
            ILI9341_Draw_Pixel(Y - y, X + x, SPRITE[pixel--]);
        }
        for (uint16_t x = 0; x < half_width; x++)
        {
            ILI9341_Draw_Pixel(Y - y, X - x, SPRITE[pixel--]);
        }
    }
    pixel = (half_height * WIDTH);
    // วาดท่อนล่าง
    for (uint16_t y = 1; y < HEIGHT - half_height; y++)
    {
        for (uint16_t x = half_width - 1; x >= 0; x--)
        {
            ILI9341_Draw_Pixel(Y + y, X - x, SPRITE[pixel++]);
        }
        for (uint16_t x = 1; x <= WIDTH - half_width; x++)
        {
            ILI9341_Draw_Pixel(Y + y, X + x, SPRITE[pixel++]);
        }
    }
}