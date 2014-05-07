/*----------------------------------------------------------------------------
 * Name:    Retarget.c
 * Purpose: 'Retarget' layer for target-dependent low level functions
 * Note(s):
 *----------------------------------------------------------------------------
 * This file is part of the uVision/ARM development tools.
 * This software may only be used under the terms of a valid, current,
 * end user licence from KEIL for a compatible version of KEIL software
 * development tools. Nothing else gives you the right to use this software.
 *
 * This software is supplied "AS IS" without warranties of any kind.
 *
 * Copyright (c) 2012 Keil - An ARM Company. All rights reserved.
 *----------------------------------------------------------------------------*/

#include <stdio.h>
#include <rt_misc.h>
#include "CE_Lib.h"



//#pragma import(__use_no_semihosting_swi)
extern int GetKey (void);
extern int SendChar (int c);


struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;
FILE __stdin;


int fputc(int c, FILE *f) {
  
	/*
	if (DEMCR & TRCENA) {
		while ( ITM_Port32(0) == 0 );
		ITM_Port8(0) = c;
	}
  return c;	
	*/
	
	int err;
  
  do{
    err = SendChar(c);
  }while (err != 0);
    
  return (err);
	
}


int fgetc(FILE *f) {
  int err;
  
  do{
    err = GetKey();
  }while (err == (-1));
  
  return (err);
}


int ferror(FILE *f) {
  /* Your implementation of ferror */
  return EOF;
}


void _ttywrch(int c) {
   int err;
  
  do{
    err = SendChar(c);
  }while (err != 0);
}

