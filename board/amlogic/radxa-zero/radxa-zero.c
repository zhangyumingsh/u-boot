// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2021 Radxa Limited
 * Author: Jack Ma <jack@radxa.com>
 */

#include <common.h>
#include <dm.h>
#include <env.h>
#include <env_internal.h>
#include <init.h>
#include <net.h>
#include <asm/io.h>
#include <asm/arch/axg.h>
#include <asm/arch/sm.h>
#include <asm/arch/eth.h>
#include <asm/arch/mem.h>

int misc_init_r(void)
{
	env_set("serial#", "AMLG12ARADXA0");

	return 0;
}
