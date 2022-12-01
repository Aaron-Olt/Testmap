//#include <linux/kernel.h>
#include "asm/preempt.h"
#include <linux/module.h>
//#include <linux/getcpu.h>
//#include <sys/sysinfo.h>
#include <linux/percpu-defs.h>
//#include <sys/sysinfo.h>
#include <asm/ioctl.h>
#include <asm/processor.h>
#include <linux/cpumask.h>
#include <linux/ioctl.h>
#include <linux/preempt.h>
#include <linux/types.h>
#include <linux/uaccess.h>
#define EXMAP_PAGE_LEN_BITS 12

DEFINE_PER_CPU(struct exmap_iov *, per_cpu_n);

// ioctl start

#define getsoftinterupt _IOR('a', 'a', int32_t)
#define gethardinterupt _IOR('b', 'a', int32_t)

static long my_ioctl(struct file *file, unsigned cmd, unsigned long arg) {
  int answer1 = softirq_count();
  int answer2 = hardirq_count();
  switch (cmd) {
    case getsoftinterupt:
      if (copy_to_user((int32_t *)arg, &answer1, sizeof(int))){
        pr_info("softinterrupt error");
      }
      break;

    case gethardinterupt:
      if (copy_to_user((int32_t*)arg,&answer2 ,sizeof(int))){
        pr_info("hardinterrupt error");
      }
      break;

    default:
      break;
  }
  return 0;
}

//
struct exmap_iov {
  union {
    uint64_t page : 64 - EXMAP_PAGE_LEN_BITS;
    uint64_t len : EXMAP_PAGE_LEN_BITS;
  };
  struct {
    int32_t res;
    int16_t pages;
  };
};

int init_module(void) {
  int a;
  int b;
  struct cpuinfo_x86 *c;
  c = &cpu_data(0);
  a = c->x86_max_cores;
  // pr_info("%d",a);
  b = num_online_cpus();
  pr_info("The number of online Kernels = %d", b);
  pr_info("number of active cpus %d", num_active_cpus());
  pr_info("number present_cpus %d", num_present_cpus());

  pr_info("hello world\n");

  return 0;
}

void cleanup_module(void) { pr_info("goodbye world \n"); }

MODULE_LICENSE("GPL");
