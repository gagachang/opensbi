/*
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Intel Corporation.
 * Copyright (c) 2024-2025 Andes Technology Corporation.
 */

#include <sbi/sbi_domain.h>

struct domain_mpxy_state_priv {
	/** MPXY state for possible HARTs indexed by hartindex */
	struct mpxy_state *hartindex_to_mpxy_state_table[SBI_HARTMASK_MAX_BITS];
};

static struct sbi_domain_data dmspriv = {
	.data_size = sizeof(struct domain_mpxy_state_priv),
};

struct mpxy_state *sbi_domain_get_mpxy_state(struct sbi_domain *dom,
					     u32 hartindex)
{
	struct domain_mpxy_state_priv *dmsp =
		sbi_domain_data_ptr(dom, &dmspriv);

	return (dmsp && hartindex < SBI_HARTMASK_MAX_BITS) ?
		dmsp->hartindex_to_mpxy_state_table[hartindex] : NULL;
}

void sbi_domain_set_mpxy_state(struct sbi_domain *dom, u32 hartindex,
			       struct mpxy_state *ms)
{
	struct domain_mpxy_state_priv *dmsp =
		sbi_domain_data_ptr(dom, &dmspriv);

	if (dmsp && hartindex < SBI_HARTMASK_MAX_BITS)
		dmsp->hartindex_to_mpxy_state_table[hartindex] = ms;
}

int sbi_domain_mpxy_state_init(void)
{
	return sbi_domain_register_data(&dmspriv);
}

void sbi_domain_mpxy_state_deinit(void)
{
	sbi_domain_unregister_data(&dmspriv);
}
