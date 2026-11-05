#ifndef __KSU_H_SUCOMPAT
#define __KSU_H_SUCOMPAT
#include <asm/ptrace.h>
#include <linux/types.h>
struct filename;

extern bool ksu_su_compat_enabled;

void ksu_sucompat_init(void);
void ksu_sucompat_exit(void);

// Handler functions for manual-hook (4.9 plain-args ABI) integration
int ksu_handle_faccessat(int *dfd, const char __user **filename_user,
			 int *mode, int *flags);
int ksu_handle_stat(int *dfd, const char __user **filename_user, int *flags);
int ksu_handle_execveat_sucompat(int *fd, struct filename **filename_ptr,
				 void *argv, void *envp, int *flags);

#ifndef KSU_MANUAL_HOOK
long ksu_handle_faccessat_sucompat(int orig_nr, struct pt_regs *regs);
long ksu_handle_stat_sucompat(int orig_nr, struct pt_regs *regs);
long ksu_handle_execve_sucompat(const char __user **filename_user, int orig_nr,
				struct pt_regs *regs);
#endif

#endif
