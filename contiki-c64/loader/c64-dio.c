/*
 * Copyright (c) 2003, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution. 
 * 3. All advertising materials mentioning features or use of this
 *    software must display the following acknowledgement:
 *        This product includes software developed by Adam Dunkels. 
 * 4. The name of the author may not be used to endorse or promote
 *    products derived from this software without specific prior
 *    written permission.  
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  
 *
 * This file is part of the Contiki desktop OS
 *
 * $Id: c64-dio.c,v 1.1 2003/08/04 00:12:50 adamdunkels Exp $
 *
 */

#include "c64-dio.h"
#include "c64-dio-asm.h"

/*-----------------------------------------------------------------------------------*/
void
c64_dio_read_block(unsigned char track,
		   unsigned char sector,
		   unsigned char *ptr)
{
  c64_dio_asm_track = track;
  c64_dio_asm_sector = sector;
  c64_dio_asm_ptr = ptr;
  c64_dio_asm_read_block();
}
/*-----------------------------------------------------------------------------------*/
void
c64_dio_write_block(unsigned char track,
		   unsigned char sector,
		   unsigned char *ptr)
{
  c64_dio_asm_track = track;
  c64_dio_asm_sector = sector;
  c64_dio_asm_ptr = ptr;
  c64_dio_asm_write_block();
}
/*-----------------------------------------------------------------------------------*/
void
c64_dio_init(unsigned char drive)
{
  c64_dio_asm_init(drive);
}
/*-----------------------------------------------------------------------------------*/
