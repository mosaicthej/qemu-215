/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * Copyright (C) 2018 David Abdurachmanov <david.abdurachmanov@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#if defined(__LP64__) && !defined(__SYSCALL_COMPAT)
#define __ARCH_WANT_NEW_STAT
#define __ARCH_WANT_SET_GET_RLIMIT
#endif /* __LP64__ */

#define __ARCH_WANT_SYS_CLONE3
#define __ARCH_WANT_MEMFD_SECRET

#include <asm-generic/unistd.h>

/*
 * Allows the instruction cache to be flushed from userspace.  Despite RISC-V
 * having a direct 'fence.i' instruction available to userspace (which we
 * can't trap!), that's not actually viable when running on Linux because the
 * kernel might schedule a process on another hart.  There is no way for
 * userspace to handle this without invoking the kernel (as it doesn't know the
 * thread->hart mappings), so we've defined a RISC-V specific system call to
 * flush the instruction cache.
 *
 * __NR_riscv_flush_icache is defined to flush the instruction cache over an
 * address range, with the flush applying to either all threads or just the
 * caller.  We don't currently do anything with the address range, that's just
 * in there for forwards compatibility.
 */
#ifndef __NR_riscv_flush_icache
#define __NR_riscv_flush_icache (__NR_arch_specific_syscall + 15)
#endif
__SYSCALL(__NR_riscv_flush_icache, sys_riscv_flush_icache)

/*
 * Allows userspace to query the kernel for CPU architecture and
 * microarchitecture details across a given set of CPUs.
 */
#ifndef __NR_riscv_hwprobe
#define __NR_riscv_hwprobe (__NR_arch_specific_syscall + 14)
#endif
__SYSCALL(__NR_riscv_hwprobe, sys_riscv_hwprobe)


/*
 * New syscalls for Usask CMPT-215 classroom use (2024 Winter)
 * Modified 2024-01-06
 * Mark Jia <mij623@usask.ca>
 */

/*
 * Wanted things:
 * Really want functionalities as this has:
 * https://github.com/TheThirdOne/rars/wiki/Environment-Calls
 *
 * Printer and Reader for:
 * - int
 * - char   (stage 1)
 * - string (stage 2)
 * - float
 * - double (stage 3)
 * So these will take up 2x5=10 syscalls,
 * with the existing 2 calls, there are 4 syscall numbers left.
 * will see... Maybe things like rand, or sync (sleep) stuff...
 * 
 * When the numbers runs out, can modify this again to do things
 * like, group readers and writers together, and use arguments to
 * specify which type is doing.
 */
#ifndef __NR_printInt
#define __NR_printInt (__NR_arch_specific_syscall) /* _244_ */
#endif
__SYSCALL(__NR_printInt, sys_printInt)

#ifndef __NR_readInt
#define __NR_readInt (__NR_arch_specific_syscall + 1) /* _245_ */
#endif
__SYSCALL(__NR_readInt, sys_readInt)

#ifndef __NR_printChar
#define __NR_printChar (__NR_arch_specific_syscall + 2) /* _246_ */
#endif
__SYSCALL(__NR_printChar, sys_printChar)

#ifndef __NR_readChar
#define __NR_readChar (__NR_arch_specific_syscall + 3) /* _247_ */
#endif
__SYSCALL(__NR_readChar, sys_readChar)

#ifndef __NR_printStr
#define __NR_printStr (__NR_arch_specific_syscall + 4) /* _248_ */
#endif
__SYSCALL(__NR_printStr, sys_printStr)

#ifndef __NR_readStr
#define __NR_readStr (__NR_arch_specific_syscall + 5) /* _249_ */
#endif
__SYSCALL(__NR_readStr, sys_readStr)

/*
 * Belows are TODO
 *
 * Implementation started on 2024-02-22
 * 
 */
#ifndef __NR_printFloat
#define __NR_printFloat (__NR_arch_specific_syscall + 6) /* __250__ */
#endif
__SYSCALL(__NR_printFloat, sys_printFloat)

#ifndef __NR_readFloat
#define __NR_readFloat (__NR_arch_specific_syscall + 7) /* __251__ */
#endif
__SYSCALL(__NR_readFloat, sys_readFloat)

#ifndef __NR_printDouble
#define __NR_printDouble (__NR_arch_specific_syscall + 8) /* __252__ */
#endif
__SYSCALL(__NR_printDouble, sys_printDouble)

#ifndef __NR_readDouble
#define __NR_readDouble (__NR_arch_specific_syscall + 9) /* __253__ */
#endif
__SYSCALL(__NR_readDouble, sys_readDouble)

#ifndef __NR_printHex
#define __NR_printHex (__NR_arch_specific_syscall + 10) /* __254__ */
#endif
__SYSCALL(__NR_printHex, sys_printHex)