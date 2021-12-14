/*
 *  linux/drivers/cpufreq/cpufreq_mrfixedfreq18.c
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/cpufreq.h>
#include <linux/init.h>
#include <linux/module.h>

static int cpufreq_governor_mrfixedfreq18(struct cpufreq_policy *policy,
					unsigned int event)
{
	switch (event) {
	case CPUFREQ_GOV_START:
	case CPUFREQ_GOV_LIMITS:
		pr_debug("setting to %u kHz because of event %u\n",
						1800000, event);
		__cpufreq_driver_target(policy, 1800000,
						CPUFREQ_RELATION_H);
		break;
	default:
		break;
	}
	return 0;
}

#ifdef CONFIG_CPU_FREQ_GOV_MRFIXEDFREQ18_MODULE
static
#endif
struct cpufreq_governor cpufreq_gov_mrfixedfreq18 = {
	.name		= "mrfixedfreq18",
	.governor	= cpufreq_governor_mrfixedfreq18,
	.owner		= THIS_MODULE,
};

static int __init cpufreq_gov_mrfixedfreq18_init(void)
{
	return cpufreq_register_governor(&cpufreq_gov_mrfixedfreq18);
}

static void __exit cpufreq_gov_mrfixedfreq18_exit(void)
{
	cpufreq_unregister_governor(&cpufreq_gov_mrfixedfreq18);
}

MODULE_AUTHOR("Mr. Fix It");
MODULE_DESCRIPTION("CPUfreq policy governor 'mrfixedfreq18'");
MODULE_LICENSE("GPL");

fs_initcall(cpufreq_gov_mrfixedfreq18_init);
module_exit(cpufreq_gov_mrfixedfreq18_exit);
