/*
 * Copyright (c) 2001, Adam Dunkels.
 * All rights reserved. 
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions 
 * are met: 
 * 1. Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright 
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the distribution. 
 * 3. The name of the author may not be used to endorse or promote
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
 * This file is part of the uIP TCP/IP stack.
 *
 * $Id: httpd.h,v 1.1 2006/04/17 15:18:18 kthacker Exp $
 *
 */

#ifndef __HTTPD_H__
#define __HTTPD_H__

#include "ek.h"

#include "httpd-fs.h"

void httpd_init(void);
/*DISPATCHER_UIPCALL(httpd_appcall, state);*/
void httpd_appcall(void *state);

struct httpd_buffer {
  u8_t *buf;
  int ptr;
};

struct httpd_state {
  u8_t state; 
  u16_t count;
  u8_t poll;
  char *dataptr;
  struct httpd_fs_file file;

  const char *contenttype;
  int contentlen;
  
  char *script;

  struct httpd_buffer buf;

  int getlen;
  u8_t getbuffer[100];
  u8_t hdrbuffer[100];
  
  /*
  union {
    struct c64_fs_dir d;
    struct c64_fs_file f;
    } f;*/
};

extern struct httpd_state *hs;

void webserver_log_file(u16_t *requester, char *file);

#endif /* __HTTPD_H__ */
