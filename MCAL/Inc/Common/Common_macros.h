/**
 * @file Common_macros.h
 * @brief Common macros for STM32 microcontrollers.
 * @date 24 Jun 2023
 * @author Romany Sobhy
 */

#ifndef COMMON_COMMON_MACROS_H_
#define COMMON_COMMON_MACROS_H_
// Set a specific bit in a register
#define SET_BIT(REG, BIT)     ((REG) |= (1U << (BIT)))

// Clear a specific bit in a register
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1U << (BIT)))

#define READ_REG(REG)           ((REG))
#define WRITE_REG(REG, VAL)     ((REG) = (VAL))
#define MODIFY_REG(REG, CLEARMASK, SETMASK) \
    WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/*--Revise it again--*/

#endif /* COMMON_COMMON_MACROS_H_ */
