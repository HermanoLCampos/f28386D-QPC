/*
 * system_assert.h
 *
 *  Created on: 5 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_SECURITY_INCLUDE_SYSTEM_ASSERT_H_
#define BSP_SECURITY_INCLUDE_SYSTEM_ASSERT_H_


#define ESTOP0 __asm("   bkpt #0")

void system_assert(const char *filename, int line);

#endif /* BSP_SECURITY_INCLUDE_SYSTEM_ASSERT_H_ */
