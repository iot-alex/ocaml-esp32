/***********************************************************************/
/*                                                                     */
/*                         Caml Special Light                          */
/*                                                                     */
/*            Xavier Leroy, projet Cristal, INRIA Rocquencourt         */
/*                                                                     */
/*  Copyright 1995 Institut National de Recherche en Informatique et   */
/*  Automatique.  Distributed only by permission.                      */
/*                                                                     */
/***********************************************************************/

/* $Id$ */

#include <mlvalues.h>
#include "unix.h"

#ifdef HAS_SOCKETS

#include "socketaddr.h"

value unix_connect(socket, address)   /* ML */
     value socket, address;
{
  get_sockaddr(address);
  if (connect(Int_val(socket), &sock_addr.s_gen, sock_addr_len) == -1)
    uerror("connect", Nothing);
  return Val_unit;
}

#else

value unix_connect() { invalid_argument("connect not implemented"); }
  
#endif
