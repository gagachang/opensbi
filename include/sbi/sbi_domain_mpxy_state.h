/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Intel Corporation.
 * Copyright (c) 2024-2025 Andes Technology Corporation.
 */

#ifndef __SBI_DOMAIN_MPXY_STATE_H__
#define __SBI_DOMAIN_MPXY_STATE_H__

#include <sbi/sbi_types.h>

struct sbi_domain;
struct mpxy_state;

/**
 * Get per-domain MPXY state pointer for a given domain and HART index
 * @param dom pointer to domain
 * @param hartindex the HART index
 *
 * @return per-domain MPXY state pointer for given HART index
 */
struct mpxy_state *sbi_domain_get_mpxy_state(struct sbi_domain *dom,
					     u32 hartindex);

/**
 * Set per-domain MPXY state pointer for a given domain and HART index
 * @param dom pointer to domain
 * @param hartindex the HART index
 * @param ms pointer to MPXY state
 */
void sbi_domain_set_mpxy_state(struct sbi_domain *dom, u32 hartindex,
			       struct mpxy_state *ms);

/** Macro to obtain the current hart's MPXY state pointer */
#define sbi_domain_mpxy_state_thishart_ptr()			\
	sbi_domain_get_mpxy_state(sbi_domain_thishart_ptr(),	\
				  current_hartindex())

/**
 * Initialize domain MPXY state support
 *
 * @return 0 on success and negative error code on failure
 */
int sbi_domain_mpxy_state_init(void);

/* Deinitialize domain MPXY state support */
void sbi_domain_mpxy_state_deinit(void);

#endif
