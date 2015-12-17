
#include "u8x8.h"
#include "u8g2.h"



extern uint8_t tga_is_transparent;

extern uint8_t tga_desc_fg_r;
extern uint8_t tga_desc_fg_g;
extern uint8_t tga_desc_fg_b;

extern uint8_t tga_desc_bg_r;
extern uint8_t tga_desc_bg_g;
extern uint8_t tga_desc_bg_b;

extern uint8_t tga_lcd_fg_r;
extern uint8_t tga_lcd_fg_g;
extern uint8_t tga_lcd_fg_b;

extern uint8_t tga_lcd_bg_r;
extern uint8_t tga_lcd_bg_g;
extern uint8_t tga_lcd_bg_b;

extern void tga_save_png(const char *name);

u8x8_t u8x8;
u8g2_t desc;

void ra(uint8_t tx, uint8_t ty, const char *s)
{
  int x,y, i, w;
  x = tx*8*3+64*3 + 6;
  y = ty*8*3+32*3 + 4*3;
  for( i = 0; i < 6; i++)
  {
    u8g2_DrawHVLine(&desc, x-2*i, y-i, 1+2*i, 1);
    u8g2_DrawHVLine(&desc, x-2*i-1, y-i, 1+2*i, 1);
  }
  u8g2_DrawHVLine(&desc, x-30, y-1, 28, 0);
  u8g2_DrawHVLine(&desc, x-30, y, 20, 0);
  u8g2_DrawHVLine(&desc, x-30, y+1, 28, 0);

  w = u8g2_GetStringWidth(&desc, s);
  u8g2_DrawString(&desc, x-34-w, y+u8g2_GetAscent(&desc)/2, s);
  
  
}


int main(void)
{
  /*
  tga_desc_fg_r = 100;
  tga_desc_fg_g = 118;
  tga_desc_fg_b = 135;
  */

  tga_desc_fg_r = 106;
  tga_desc_fg_g = 0;
  tga_desc_fg_b = 255;

  tga_desc_bg_r = 255;
  tga_desc_bg_g = 255;
  tga_desc_bg_b = 255;

  tga_lcd_fg_r = 0;
  tga_lcd_fg_g = 0;
  tga_lcd_fg_b = 0;

  tga_lcd_bg_r = 240;
  tga_lcd_bg_g = 163;
  tga_lcd_bg_b = 10;

  /*
  u8x8_Setup_TGA_DESC(&desc);
  u8x8_InitDisplay(&desc);  
  u8x8_SetPowerSave(&desc, 0);
  u8x8_ClearScreen(&desc);
  u8x8_SetFont(&desc, u8x8_font_amstrad_cpc_r);
  u8x8_DrawString(&desc, 0, 0, "Description");
*/

  u8g2_Setup_TGA_DESC(&desc, &u8g2_cb_r0);
  u8x8_InitDisplay(u8g2_GetU8x8(&desc));  
  u8x8_SetPowerSave(u8g2_GetU8x8(&desc), 0);
  u8x8_ClearScreen(u8g2_GetU8x8(&desc));


  u8x8_Setup_TGA_LCD(&u8x8);
  u8x8_InitDisplay(&u8x8);  
  u8x8_SetPowerSave(&u8x8, 0);
  u8x8_ClearScreen(&u8x8);
  u8x8_SetFont(&u8x8, u8x8_font_amstrad_cpc_r);
  u8x8_DrawString(&u8x8, 0, 0, "Hello World!");

  tga_is_transparent = 1;
  u8g2_FirstPage(&desc);
  do
  {
    u8g2_SetFont(&desc, u8g2_font_helvB18_tf);
    ra(0,0, "x=0, y=0");
  } while( u8g2_NextPage(&desc) );


  //tga_save("u8x8.tga");
  tga_save_png("u8x8.png");
  return 0;
}
