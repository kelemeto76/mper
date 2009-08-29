/*
** Routines to parse client commands received on the control socket.
**
** --------------------------------------------------------------------------
** Author: Young Hyun
** Copyright (C) 2009 The Regents of the University of California.
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
** 
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
** 
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __MPER_PARSER_H__
#define __MPER_PARSER_H__

/*
** All pointers are to static memory.
** Copy data out if needed for non-transient use.
*/
typedef struct {
  const char* cw_name;
  keyword_code cw_code;
  keyword_type cw_type;

  union {
    uint32_t u_uint;
    const char *u_str;
    const unsigned char *u_blob; /* same pointer as u_str but different type */
    const char *u_sym;
    const char *u_addrstr;
    const char *u_prefixstr;
    struct timeval u_timeval;
  } value_un;

  size_t cw_len;  /* length of u_str / u_blob */
} control_word_t;

#define cw_uint        value_un.u_uint
#define cw_str         value_un.u_str
#define cw_blob        value_un.u_blob
#define cw_sym         value_un.u_sym
#define cw_addrstr     value_un.u_addrstr
#define cw_prefixstr   value_un.u_prefixstr
#define cw_timeval     value_un.u_timeval

control_word_t *parse_control_message(const char *message, size_t *length_out);

#endif /* __MPER_PARSER_H__ */
