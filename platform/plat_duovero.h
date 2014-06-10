/* rfm12b-linux: linux kernel driver for the rfm12(b) RF module by HopeRF
*  Copyright (C) 2013 Georg Kaindl
*
*  This file is part of rfm12b-linux.
*
*  rfm12b-linux is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 2 of the License, or
*  (at your option) any later version.
*
*  rfm12b-linux is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with rfm12b-linux.  If not, see <http://www.gnu.org/licenses/>.
*/

#if !defined(__RFM12_PLAT_DUOVERO_H__)
#define __RFM12_PLAT_DUOVERO_H__

#include <linux/ioport.h>
#include <asm/io.h>

/*
   This file handles pinmuxing on Gumstix Duovero.

   If you want to change the default hardware settings for BBB/BB, this
   is the place to look.
*/

// the amount of RFM12 modules connected to the Duovero
// per default, we have settings for one board. if you want
// more boards, you need to add the necessary settings below
// as well.
#define NUM_RFM12_BOARDS         1

/*
*  default config for Duovero (one RFM12 module)
*  level shifter is not shown
*
*  Duovero               RFM12B
*  ---------------------------------
*  GND                   GND
*  VCC_1.8               VDD (+3.3V)
*  GPIO122               nIRQ
*  MCSPI1_MISO           SDO
*  MCSPI1_MOSI           SDI
*  MCSPI1_CLK            SCK
*  MCSPI1_CS             nSEL
*/

struct spi_rfm12_board_config board_configs[NUM_RFM12_BOARDS] = {
   {
      .irq_pin      = 122,   // gpio3_19

      .spi_bus      = 1,   // spi port on Duovero
      .spi_cs         = 1      // CS 1
   }
};

static int
spi_rfm12_init_pinmux_settings(void);
static int
spi_rfm12_cleanup_pinmux_settings(void);

static int
spi_rfm12_init_pinmux_settings(void)
{
   return 0;
}

static int
spi_rfm12_cleanup_pinmux_settings(void)
{
   return 0;
}

#endif // __RFM12_PLAT_DUOVERO_H__
