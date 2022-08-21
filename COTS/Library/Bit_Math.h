/**********************************************************************************************************************

 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Bit_Math.h
 *       Module:  
 *
 *  Description:  it has some bit wise operations     
 *  
 *********************************************************************************************************************/
#ifndef Bit_Math
#define Bit_Math
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define SET_BIT_BB(Reg,Bit) 					((*((volatile uint32_t *)( 0x42000000 +(((uint32_t)(&Reg) -0x40000000)*32)+((Bit)*4))))=0xff)
#define RESET_BIT_BB(Reg,Bit) 					((*((volatile uint32_t *)( 0x42000000 +(((uint32_t)(&Reg) -0x40000000)*32)+((Bit)*4))))=0x00)
#define SetBit(REG,BIT)							REG |= (1<<BIT)
#define ClrBit(REG,BIT) 						REG &= (~(1<<BIT))
#define SetBit2(REG,BIT)						(*(volatile uint32_t *)(((uint32_t)	REG)))|= (1<<BIT)
#define ClrBit2(REG,BIT) 						(*(volatile uint32_t *)(((uint32_t)REG )))&= (~(1<<BIT))
#define GetBit(REG,BIT) 						((REG>>BIT)&(0x01))

#endif /* Bit_Math_H */

/**********************************************************************************************************************
 *  END OF FILE: Bit_Math.h
 *********************************************************************************************************************/
