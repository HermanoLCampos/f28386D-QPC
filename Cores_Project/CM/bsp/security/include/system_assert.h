/*
 * system_assert.h
 *
 *  Created on: 5 de mar de 2024
 *      Author: ramon.martins
 */

#ifndef BSP_SECURITY_INCLUDE_SYSTEM_ASSERT_H_
#define BSP_SECURITY_INCLUDE_SYSTEM_ASSERT_H_

void system_assert(const char *filename, int assert_number);

#define FUNCTIONAL_ASSERT(id_, expr_)  \
    ((expr_) ? ((void)0) : system_assert( __FILE__ , (id_)))

#endif /* BSP_SECURITY_INCLUDE_SYSTEM_ASSERT_H_ */
