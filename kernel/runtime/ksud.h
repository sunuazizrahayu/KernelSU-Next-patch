#ifndef __KSU_H_KSUD
#define __KSU_H_KSUD

#include <asm/syscall.h>

#define KSUD_PATH "/data/adb/ksud"

/*
 * Mirror of struct user_arg_ptr from fs/exec.c (not exported on 4.9).
 * Used by the manual-hook bridge (core/init.c) and sulog/event.c.
 */
#ifndef KSU_USER_ARG_PTR_DEFINED
#define KSU_USER_ARG_PTR_DEFINED
struct user_arg_ptr {
#ifdef CONFIG_COMPAT
	bool is_compat;
#endif
	union {
		const char __user *const __user *native;
#ifdef CONFIG_COMPAT
		const compat_uptr_t __user *compat;
#endif
	} ptr;
};
#endif /* KSU_USER_ARG_PTR_DEFINED */

void ksu_ksud_init();
void ksu_ksud_exit();

void ksu_execve_hook_ksud(const struct pt_regs *regs);
void ksu_execveat_hook_ksud(const struct pt_regs *regs);
void ksu_stop_input_hook_runtime(void);

#endif
