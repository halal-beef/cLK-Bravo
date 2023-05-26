/*
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef __MSM7K_PLATFORM_MSM_GPIO_H_
#define __MSM7K_PLATFORM_MSM_GPIO_H_

#define GPIO1_REG(off) (MSM_GPIO1_BASE + 0x800 + (off))
#define GPIO2_REG(off) (MSM_GPIO2_BASE + 0xC00 + (off))

#define GPIO1_REG_R(off) (MSM_GPIOCFG1_BASE + 0x000 + (off))
#define GPIO2_REG_R(off) (MSM_GPIOCFG2_BASE + 0x400 + (off))

/* pin ownership */
#define GPIO_OWNER_0       GPIO1_REG_R(0x100)
#define GPIO_OWNER_1       GPIO2_REG_R(0x104)
#define GPIO_OWNER_2       GPIO1_REG_R(0x108)
#define GPIO_OWNER_3       GPIO1_REG_R(0x10c)
#define GPIO_OWNER_4       GPIO1_REG_R(0x110)
#define GPIO_OWNER_5       GPIO1_REG_R(0x114)

/* output value */
#define GPIO_OUT_0         GPIO1_REG(0x00)	/* gpio  15-0  */
#define GPIO_OUT_1         GPIO2_REG(0x00)	/* gpio  42-16 */
#define GPIO_OUT_2         GPIO1_REG(0x04)	/* gpio  67-43 */
#define GPIO_OUT_3         GPIO1_REG(0x08)	/* gpio  94-68 */
#define GPIO_OUT_4         GPIO1_REG(0x0C)	/* gpio 106-95 */
#define GPIO_OUT_5         GPIO1_REG(0x50)	/* gpio 107-121 */

/* same pin map as above, output enable */
#define GPIO_OE_0          GPIO1_REG(0x10)
#define GPIO_OE_1          GPIO2_REG(0x08)
#define GPIO_OE_2          GPIO1_REG(0x14)
#define GPIO_OE_3          GPIO1_REG(0x18)
#define GPIO_OE_4          GPIO1_REG(0x1C)
#define GPIO_OE_5          GPIO1_REG(0x54)

/* same pin map as above, input read */
#define GPIO_IN_0          GPIO1_REG(0x34)
#define GPIO_IN_1          GPIO2_REG(0x20)
#define GPIO_IN_2          GPIO1_REG(0x38)
#define GPIO_IN_3          GPIO1_REG(0x3C)
#define GPIO_IN_4          GPIO1_REG(0x40)
#define GPIO_IN_5          GPIO1_REG(0x44)

/* same pin map as above, 1=edge 0=level interrup */
#define GPIO_INT_EDGE_0    GPIO1_REG(0x60)
#define GPIO_INT_EDGE_1    GPIO2_REG(0x50)
#define GPIO_INT_EDGE_2    GPIO1_REG(0x64)
#define GPIO_INT_EDGE_3    GPIO1_REG(0x68)
#define GPIO_INT_EDGE_4    GPIO1_REG(0x6C)
#define GPIO_INT_EDGE_5    GPIO1_REG(0xC0)

/* same pin map as above, 1=positive 0=negative */
#define GPIO_INT_POS_0     GPIO1_REG(0x70)
#define GPIO_INT_POS_1     GPIO2_REG(0x58)
#define GPIO_INT_POS_2     GPIO1_REG(0x74)
#define GPIO_INT_POS_3     GPIO1_REG(0x78)
#define GPIO_INT_POS_4     GPIO1_REG(0x7C)
#define GPIO_INT_POS_5     GPIO1_REG(0xBC)

/* same pin map as above, interrupt enable */
#define GPIO_INT_EN_0      GPIO1_REG(0x80)
#define GPIO_INT_EN_1      GPIO2_REG(0x60)
#define GPIO_INT_EN_2      GPIO1_REG(0x84)
#define GPIO_INT_EN_3      GPIO1_REG(0x88)
#define GPIO_INT_EN_4      GPIO1_REG(0x8C)
#define GPIO_INT_EN_5      GPIO1_REG(0xB8)

/* same pin map as above, write 1 to clear interrupt */
#define GPIO_INT_CLEAR_0   GPIO1_REG(0x90)
#define GPIO_INT_CLEAR_1   GPIO2_REG(0x68)
#define GPIO_INT_CLEAR_2   GPIO1_REG(0x94)
#define GPIO_INT_CLEAR_3   GPIO1_REG(0x98)
#define GPIO_INT_CLEAR_4   GPIO1_REG(0x9C)
#define GPIO_INT_CLEAR_5   GPIO1_REG(0xB4)

/* same pin map as above, 1=interrupt pending */
#define GPIO_INT_STATUS_0  GPIO1_REG(0xA0)
#define GPIO_INT_STATUS_1  GPIO2_REG(0x70)
#define GPIO_INT_STATUS_2  GPIO1_REG(0xA4)
#define GPIO_INT_STATUS_3  GPIO1_REG(0xA8)
#define GPIO_INT_STATUS_4  GPIO1_REG(0xAC)
#define GPIO_INT_STATUS_5  GPIO1_REG(0xB0)

enum {
	MSM_GPIO_CFG_INPUT,
	MSM_GPIO_CFG_OUTPUT,
};

/* GPIO TLMM: Pullup/Pulldown */
enum {
	MSM_GPIO_CFG_NO_PULL,
	MSM_GPIO_CFG_PULL_DOWN,
	MSM_GPIO_CFG_KEEPER,
	MSM_GPIO_CFG_PULL_UP,
};

/* GPIO TLMM: Drive Strength */
enum {
	MSM_GPIO_CFG_2MA,
	MSM_GPIO_CFG_4MA,
	MSM_GPIO_CFG_6MA,
	MSM_GPIO_CFG_8MA,
	MSM_GPIO_CFG_10MA,
	MSM_GPIO_CFG_12MA,
	MSM_GPIO_CFG_14MA,
	MSM_GPIO_CFG_16MA,
};

enum {
	MSM_GPIO_CFG_ENABLE,
	MSM_GPIO_CFG_DISABLE,
};

enum {
	MSM_GPIO_OWNER_BASEBAND,
	MSM_GPIO_OWNER_ARM11,
};

#define MSM_GPIO_CFG(gpio, func, dir, pull, drvstr) \
	((((gpio) & 0x3FF) << 4)        |	  \
	 ((func) & 0xf)                  |	  \
	 (((dir) & 0x1) << 14)           |	  \
	 (((pull) & 0x3) << 15)          |	  \
	 (((drvstr) & 0xF) << 17))

#define MSM_GPIO_PIN(gpio_cfg)    (((gpio_cfg) >>  4) & 0x3ff)
#define MSM_GPIO_FUNC(gpio_cfg)   (((gpio_cfg) >>  0) & 0xf)
#define MSM_GPIO_DIR(gpio_cfg)    (((gpio_cfg) >> 14) & 0x1)
#define MSM_GPIO_PULL(gpio_cfg)   (((gpio_cfg) >> 15) & 0x3)
#define MSM_GPIO_DRVSTR(gpio_cfg) (((gpio_cfg) >> 17) & 0xf)

#define NR_MSM_GPIOS 121

void msm_gpio_config(unsigned config, unsigned disable);
void msm_gpio_set_owner(unsigned gpio, unsigned owner);
void msm_gpio_init(void);

#endif				//__MSM7K_PLATFORM_MSM_GPIO_H_