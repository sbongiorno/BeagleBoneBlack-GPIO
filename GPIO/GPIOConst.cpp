/*
 * Copyright (c) 2013 Mateusz Kaczanowski
 * www.mkaczanowski.com
 *
 * Original BBIO Author Adafruit
 * Modified for BeagleBoneBlack-GPIO Mateusz Kaczanowski
 *
 * This file incorporates work covered by the following copyright and
 * permission notice, all modified code adopts the original license:

 * Copyright (c) 2013 Adafruit

 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:

 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.

 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "./GPIOConst.h"
#include <stdio.h>
#include <string.h>


namespace GPIO {

/**
 * Values of the edge
 */
const char *GPIOConst::strEdge[] = { "none", "rising", "falling", "both" };

/**
 * GPIOConst singleton instance
 */
GPIOConst* GPIOConst::instance = NULL;

/**
 * Table of values for pins.
 * Table generated based on https://raw.github.com/jadonk/bonescript/master/node_modules/bonescript/bone.js
 */
pins_t GPIOConst::pinTable[] = {
    { "USR0", "USR0", 53, -1, -1, 1 },
    { "USR1", "USR1", 54, -1, -1, 1 },
    { "USR2", "USR2", 55, -1, -1, 1 },
    { "USR3", "USR3", 56, -1, -1, 1 },
    { "DGND", "P8_1", 0, -1, -1, -1 },
    { "DGND", "P8_2", 0, -1, -1, -1 },
    { "GPIO1_6", "P8_3", 38, -1, -1, 1 },
    { "GPIO1_7", "P8_4", 39, -1, -1, 1 },
    { "GPIO1_2", "P8_5", 34, -1, -1, 1 },
    { "GPIO1_3", "P8_6", 35, -1, -1, 1 },
    { "TIMER4", "P8_7", 66, -1, -1, 0 },
    { "TIMER7", "P8_8", 67, -1, -1, 0 },
    { "TIMER5", "P8_9", 69, -1, -1, 0 },
    { "TIMER6", "P8_10", 68, -1, -1, 0 },
    { "GPIO1_13", "P8_11", 45, -1, -1, 0 },
    { "GPIO1_12", "P8_12", 44, -1, -1, 0 },
    { "EHRPWM2B", "P8_13", 23, 4, -1, 0 },
    { "GPIO0_26", "P8_14", 26, -1, -1, 0 },
    { "GPIO1_15", "P8_15", 47, -1, -1, 0 },
    { "GPIO1_14", "P8_16", 46, -1, -1, 0 },
    { "GPIO0_27", "P8_17", 27, -1, -1, 0 },
    { "GPIO2_1", "P8_18", 65, -1, -1, 0 },
    { "EHRPWM2A", "P8_19", 22, 4, -1, 0 },
    { "GPIO1_31", "P8_20", 63, -1, -1, 1 },
    { "GPIO1_30", "P8_21", 62, -1, -1, 1 },
    { "GPIO1_5", "P8_22", 37, -1, -1, 1 },
    { "GPIO1_4", "P8_23", 36, -1, -1, 1 },
    { "GPIO1_1", "P8_24", 33, -1, -1, 1 },
    { "GPIO1_0", "P8_25", 32, -1, -1, 1 },
    { "GPIO1_29", "P8_26", 61, -1, -1, 0 },
    { "GPIO2_22", "P8_27", 86, -1, -1, 1 },
    { "GPIO2_24", "P8_28", 88, -1, -1, 1 },
    { "GPIO2_23", "P8_29", 87, -1, -1, 1 },
    { "GPIO2_25", "P8_30", 89, -1, -1, 1 },
    { "UART5_CTSN", "P8_31", 10, -1, -1, 1 },
    { "UART5_RTSN", "P8_32", 11, -1, -1, 1 },
    { "UART4_RTSN", "P8_33", 9, -1, -1, 1 },
    { "UART3_RTSN", "P8_34", 81, 2, -1, 1 },
    { "UART4_CTSN", "P8_35", 8, -1, -1, 1 },
    { "UART3_CTSN", "P8_36", 80, 2, -1, 1 },
    { "UART5_TXD", "P8_37", 78, -1, -1, 1 },
    { "UART5_RXD", "P8_38", 79, -1, -1, 1 },
    { "GPIO2_12", "P8_39", 76, -1, -1, 1 },
    { "GPIO2_13", "P8_40", 77, -1, -1, 1 },
    { "GPIO2_10", "P8_41", 74, -1, -1, 1 },
    { "GPIO2_11", "P8_42", 75, -1, -1, 1 },
    { "GPIO2_8", "P8_43", 72, -1, -1, 1 },
    { "GPIO2_9", "P8_44", 73, -1, -1, 1 },
    { "GPIO2_6", "P8_45", 70, 3, -1, 1 },
    { "GPIO2_7", "P8_46", 71, 3, -1, 1 },
    { "DGND", "P9_1", 0, -1, -1, -1 },
    { "DGND", "P9_2", 0, -1, -1, -1 },
    { "VDD_3V3", "P9_3", 0, -1, -1, -1 },
    { "VDD_3V3", "P9_4", 0, -1, -1, -1 },
    { "VDD_5V", "P9_5", 0, -1, -1, -1 },
    { "VDD_5V", "P9_6", 0, -1, -1, -1 },
    { "SYS_5V", "P9_7", 0, -1, -1, -1 },
    { "SYS_5V", "P9_8", 0, -1, -1, -1 },
    { "PWR_BUT", "P9_9", 0, -1, -1, -1 },
    {"SYS_RESETn", "P9_10", 0, -1, -1, -1 },
    { "UART4_RXD", "P9_11", 30, -1, -1, 0 },
    { "GPIO1_28", "P9_12", 60, -1, -1, 0 },
    { "UART4_TXD", "P9_13", 31, -1, -1, 0 },
    { "EHRPWM1A", "P9_14", 50, 6, -1, 0 },
    { "GPIO1_16", "P9_15", 48, -1, -1, 0 },
    { "EHRPWM1B", "P9_16", 51, 6, -1, 0 },
    { "I2C1_SCL", "P9_17", 5, -1, -1, 0 },
    { "I2C1_SDA", "P9_18", 4, -1, -1, 0 },
    { "I2C2_SCL", "P9_19", 13, -1, -1, 1 },
    { "I2C2_SDA", "P9_20", 12, -1, -1, 1 },
    { "UART2_TXD", "P9_21", 3, 3, -1, 0 },
    { "UART2_RXD", "P9_22", 2, 3, -1, 0 },
    { "GPIO1_17", "P9_23", 49, -1, -1, 0 },
    { "UART1_TXD", "P9_24", 15, -1, -1, 0 },
    { "GPIO3_21", "P9_25", 117, -1, -1, 1 },
    { "UART1_RXD", "P9_26", 14, -1, -1, 0 },
    { "GPIO3_19", "P9_27", 115, -1, -1, 0 },
    { "SPI1_CS0", "P9_28", 113, 4, -1, 1 },
    { "SPI1_D0", "P9_29", 111, 1, -1, 1 },
    { "SPI1_D1", "P9_30", 112, -1, -1, 0 },
    { "SPI1_SCLK", "P9_31", 110, 1, -1, 1 },
    { "VDD_ADC", "P9_32", 0, -1, -1, -1 },
    { "AIN4", "P9_33", 0, -1, 4, -1 },
    { "GNDA_ADC", "P9_34", 0, -1, -1, -1 },
    { "AIN6", "P9_35", 0, -1, 6, -1 },
    { "AIN5", "P9_36", 0, -1, 5, -1 },
    { "AIN2", "P9_37", 0, -1, 2, -1 },
    { "AIN3", "P9_38", 0, -1, 3, -1 },
    { "AIN0", "P9_39", 0, -1, 0, -1 },
    { "AIN1", "P9_40", 0, -1, 1, -1 },
    { "CLKOUT2", "P9_41", 20, -1, -1, 0 },
    { "GPIO0_7", "P9_42", 7, 0, -1, 0 },
    { "DGND", "P9_43", 0, -1, -1, -1 },
    { "DGND", "P9_44", 0, -1, -1, -1 },
    { "DGND", "P9_45", 0, -1, -1, -1 },
    { "DGND", "P9_46", 0, -1, -1, -1 },
    { "EXPIO0_0", "D2_P0", 456, -1, -1},
    { "EXPIO0_1", "D2_P1", 457, -1, -1},
    { "EXPIO0_2", "D2_P2", 458, -1, -1},
    { "EXPIO0_3", "D2_P3", 459, -1, -1},
    { "EXPIO0_4", "D2_P4", 460, -1, -1},
    { "EXPIO0_5", "D2_P5", 461, -1, -1},
    { "EXPIO0_6", "D2_P6", 462, -1, -1},
    { "EXPIO0_7", "D2_P7", 463, -1, -1},
    { "GPIO_J10", "D2_P8", 464, -1, -1},
    { "ETH_LED", "D2_P9", 465, -1, -1},
    { "SPI2_CS", "D2_P10", 466, -1, -1},
    { "CS2_1", "D2_P11", 467, -1, -1},
    { "CS2_2", "D2_P12", 468, -1, -1},
    { "NOT_BUZZ_EN", "D2_P13", 469, -1, -1},
    { "24V_ES_ENABLE", "D2_P14", 470, -1, -1},
    { "D2_P15", "D2_P15", 471, -1, -1},
    { "PWR_FAIL", "D12_P0", 472, -1, -1},
    { "BATT_STAT", "D12_P1", 473, -1, -1},
    { "GPIO_RTC", "D12_P2", 474, -1, -1},
    { "24V_ES", "D12_P3", 475, -1, -1},
    { "CHRG_STAT", "D12_P4", 476, -1, -1},
    { "HIZ_DET", "D12_P5", 477, -1, -1},
    { "D12_P6", "D12_P6", 478, -1, -1},
    { "D12_P7", "D12_P7", 479, -1, -1},
    { "MUX_0", "D8_P0", 480, -1, -1},
    { "MUX_1", "D8_P1", 481, -1, -1},
    { "MUX_2", "D8_P2", 482, -1, -1},
    { "MUX_3", "D8_P3", 483, -1, -1},
    { "MUX_4", "D8_P4", 484, -1, -1},
    { "MUX_5", "D8_P5", 485, -1, -1},
    { "MUX_6", "D8_P6", 486, -1, -1},
    { "MUX_7", "D8_P7", 487, -1, -1},
    { "HKIN1_0", "HK1_0", 488, -1, -1},
    { "HKIN1_1", "HK1_1", 489, -1, -1},
    { "HKIN1_2", "HK1_2", 490, -1, -1},
    { "HKIN1_3", "HK1_3", 491, -1, -1},
    { "HKIN1_4", "HK1_4", 492, -1, -1},
    { "HKIN1_5", "HK1_5", 493, -1, -1},
    { "HKIN1_6", "HK1_6", 494, -1, -1},
    { "HKIN1_7", "HK1_7", 495, -1, -1},
    { "HKOUT1_0", "HK2_0", 496, -1, -1},
    { "HKOUT1_1", "HK2_1", 497, -1, -1},
    { "HKOUT1_2", "HK2_2", 498, -1, -1},
    { "HKOUT1_3", "HK2_3", 499, -1, -1},
    { "HKOUT1_4", "HK2_4", 500, -1, -1},
    { "HKOUT1_5", "HK2_5", 501, -1, -1},
    { "HKOUT1_6", "HK2_6", 502, -1, -1},
    { "HKOUT1_7", "HK2_7", 503, -1, -1},
    { "SSR1_P0", "SSR1_0", 504, -1, -1},
    { "SSR1_P1", "SSR1_1", 505, -1, -1},
    { "SSR1_P2", "SSR1_2", 506, -1, -1},
    { "SSR1_P3", "SSR1_3", 507, -1, -1},
    { "SSR1_P4", "SSR1_4", 508, -1, -1},
    { "SSR1_P5", "SSR1_5", 509, -1, -1},
    { "SSR1_P6", "SSR1_6", 510, -1, -1},
    { "SSR1_P7", "SSR1_7", 511, -1, -1},
    { NULL, NULL, 0 }
};

/**
 * Returns the GPIOConst instance
 */
GPIOConst* GPIOConst::getInstance() {
  if (instance == NULL) {
    instance = new GPIOConst();
  }

  return instance;
}

/**
 * Constructor
 */
GPIOConst::GPIOConst() {
}

/**
 * Destructor
 */
GPIOConst::~GPIOConst() {
}

/**
 * Get gpio pin number by key i.e "P8_10"
 */
int GPIOConst::getGpioByKey(const char *key) {
  pins_t *p;
  for (p = pinTable; p->key != NULL; ++p) {
    if (strcmp(p->key, key) == 0) {
      return p->gpio;
    }
  }

  return 0;
}

/**
 * Get gpio number by name i.e "GPIO0_7"
 */
int GPIOConst::getGpioByName(const char *name) {
  pins_t *p;
  for (p = pinTable; p->name != NULL; ++p) {
    if (strcmp(p->name, name) == 0) {
      return p->gpio;
    }
  }

  return 0;
}

/**
 * Get GPIO name by pin number
 */
const char* GPIOConst::getGpioNameByPin(unsigned int pin) {
  pins_t *p;

  for (p = pinTable; p->name != NULL; ++p) {
    if (p->gpio == pin) {
      return p->name;
    }
  }

  return "";
}

/**
 * Get GPIO key by pin number
 */
const char* GPIOConst::getGpioKeyByPin(unsigned int pin) {
  pins_t *p;

  for (p = pinTable; p->name != NULL; ++p) {
    if (p->gpio == pin) {
      return p->key;
    }
  }

  return "";
}

/**
 * Get edge value by index [0, 3]
 */
const char* GPIOConst::getEdgeValueByIndex(unsigned int index) {
  return strEdge[index];
}

/**
 * Get edge index by edge name
 */
int GPIOConst::getEdgeIndexByValue(const char* value) {
  for (int i = 0; i < static_cast<int>(sizeof(strEdge)); i++) {
    if (strcmp(strEdge[i], value) == 0)
      return i;
  }

  return -1;
}

/**
 * Is the pin allocated by default
 * refering to https://github.com/derekmolloy/boneDeviceTree/tree/master/docs
 */
int GPIOConst::isPinAllocatedByDefault(unsigned int pin) {
  pins_t *p;

  for (p = pinTable; p->name != NULL; ++p) {
    if (p->gpio == pin) {
      return p->isAllocatedByDefault;
    }
  }

  return 0;
}
} /* namespace GPIO */
