/*** Template file for Custom Classes ***/

/* Replace the keywords below
 *
 * Libary: liblib.h
 * Object: Cstm, Clss, cstm, clss, CSTM, CLSS
 * Parent: Parpar, Namnam, parpar, namnam, PARPAR, NAMNAM */

#pragma once
#include <liblib.h>

G_BEGIN_DECLS

G_DECLARE_FINAL_TYPE(CstmClss, cstm_clss, CSTM, CLSS, ParparNamnam);
#define CSTM_TYPE_CLSS cstm_clss_get_type()

/*** Public Functions ***/
CstmClss* cstm_clss_new();
void cstm_clss_salute(CstmClss* cstw);
/*** Public Functions ***/

G_END_DECLS
