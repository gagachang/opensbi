#
# SPDX-License-Identifier: BSD-2-Clause
#
# Copyright (c) 2025 Andes Technology Corporation
#
# Authors:
#   Alvin Chang <alvinga@andestech.com>
#

libsbiutils-objs-$(CONFIG_STACK_PROTECTOR) += stack_protector/stack_protector.o

ifeq ($(CONFIG_STACK_PROTECTOR),y)
stack-protector-cflags-$(CONFIG_STACK_PROTECTOR) := -fstack-protector
stack-protector-cflags-$(CONFIG_STACK_PROTECTOR_STRONG) := -fstack-protector-strong
stack-protector-cflags-$(CONFIG_STACK_PROTECTOR_ALL) := -fstack-protector-all
else
stack-protector-cflags-y := -fno-stack-protector
endif
