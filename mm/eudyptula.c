#include <linux/kernel.h>
#include <asm/errno.h>

static const long eudyptula_id = 0xacef8c84aaa6;

asmlinkage long sys_eudyptula(unsigned int high_id, unsigned int low_id)

{
	long full_id = ((unsigned long)high_id << 32) + (unsigned long)low_id;

	pr_emerg("sys_eudyptula high_id  %lx\n", ((unsigned long)high_id << 32));
	pr_emerg("sys_eudyptula low_id %lx\n", (unsigned long)low_id);
	pr_emerg("sys_eudyptula called %lx\n", full_id);
	if (full_id == eudyptula_id) {
		pr_emerg("sys_eudyptula %lx == %lx\n", full_id, eudyptula_id);
		return 0;
	} else {
		pr_emerg("sys_eudyptula %lx != %lx\n", full_id, eudyptula_id);
		return -EINVAL;
	}

	return 0;
}
