#include <linux/types.h>
// 4.9 manual-hook port: stubs for the KSU-Next v3.4.2 dynamic hook
// infrastructure (lsm_hook / syscall_hook_manager / arm64 syscall_hook /
// tp_marker) which is incompatible with the plain syscall ABI of 4.9.
#include <linux/errno.h>
struct ksu_lsm_hook;
#include "hook/setuid_hook.h"      // ksu_setuid_hook_init/exit
#include "hook/syscall_hook_manager.h" // ksu_avc_spoof_init/exit
#include "feature/sucompat.h"      // ksu_sucompat_init/exit
int ksu_lsm_hook(struct ksu_lsm_hook *hook) { return -ENOSYS; }
void ksu_lsm_unhook(struct ksu_lsm_hook *hook) { }
void ksu_lsm_hook_init(void) { }
void ksu_lsm_hook_exit(void) { }
void ksu_syscall_hook_init(void) { }
void ksu_syscall_hook_exit(void) { }
// 4.9 manual-hook port: the dynamic syscall hooks are inert, but the
// official init() also registers feature handlers and kernel umount:
//   setuid_hook_init  -> ksu_kernel_umount_init
//   sucompat_init     -> SU_COMPAT feature handler (manager badge)
//   avc_spoof_init    -> AVC_SPOOF feature handler
void __init ksu_syscall_hook_manager_init(void)
{
	ksu_setuid_hook_init();
	ksu_sucompat_init();
	ksu_avc_spoof_init();
}
void __exit ksu_syscall_hook_manager_exit(void)
{
	ksu_setuid_hook_exit();
	ksu_sucompat_exit();
	ksu_avc_spoof_exit();
}

#include "hook/tp_marker.h"
void ksu_clear_task_tracepoint_flag_if_needed(struct task_struct *t) { }