/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2025 Andes Technology Corporation
 *
 * Authors:
 *   Alvin Chang <alvinga@andestech.com>
 */

#include <sbi/sbi_console.h>
#include <sbi/sbi_types.h>

void *__stack_chk_guard = (void *)0x95B5FF5AUL;

void __noreturn __stack_chk_fail(void)
{
	sbi_panic("Stack corruption detected\n");
}
