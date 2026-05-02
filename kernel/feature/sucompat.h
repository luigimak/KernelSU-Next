#ifndef __KSU_H_SUCOMPAT
#define __KSU_H_SUCOMPAT
#include <asm/ptrace.h>
#include <linux/types.h>
#include <linux/version.h>
#include <linux/fs.h>

extern struct static_key_true ksu_su_compat_enabled;

void ksu_sucompat_init(void);
void ksu_sucompat_exit(void);

// Handler functions
int ksu_handle_faccessat(int *dfd, const char __user **filename_user, int *mode, int *__unused_flags);
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
int ksu_handle_stat(int *dfd, struct filename **filename, int *flags);
#else
int ksu_handle_stat(int *dfd, const char __user **filename_user, int *flags);
#endif // #if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 1, 0)
int ksu_handle_execveat(int *fd, struct filename **filename_ptr, void *argv, void *envp, int *flags);
int ksu_handle_devpts(struct inode *inode);

#endif
