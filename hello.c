//#include <linux/kernel.h>
#include <linux/module.h>
//#include <linux/getcpu.h>
//#include <sys/sysinfo.h>
#include <linux/percpu-defs.h>
//#include <sys/sysinfo.h>
//#include <asm/unistd.h>
#include <asm/processor.h>
#include <linux/cpumask.h>




	

//DEFINE_PER_CPU(int,per_cpu_n); wird nicht funktionieren , benötigt Standard Typ
/*
Alternativen	Fixmapped memory

		Pages of pages 

		pcpu_embed_first_chunck & setup_percpu_segment 
		- alternative implementierung von percpu mithilfe unterliegender Funktionen
		
		dynamic percpu allocator https://lwn.net/Articles/1509/ ... __alloc_percpu
		anstelle von percpu struct , struct of percpu variables
 */
 
 
int init_module (void){
  struct cpuinfo_x86 *c  ;
  c= &cpu_data(0);
  //pr_info("%d",c->x86_max_cores);
  pr_info("number of online cpus = %d",num_online_cpus());//subset of present cpus , available cpus
  pr_info("number of active cpus %d",num_active_cpus()); // task may be moved to these cpus
  pr_info("number present_cpus %d",num_present_cpus()); //cpus plugged in


  pr_info("hello world\n");
return 0;
 
}

void cleanup_module(void){
  pr_info("goodbye world \n");
}

MODULE_LICENSE("GPL");

