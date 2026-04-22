#ifndef CMARK_GFM_CORE_EXTENSIONS_H
#define CMARK_GFM_CORE_EXTENSIONS_H

#include "cmark-gfm-extension_api.h"
#include "cmark-gfm_export.h"
#include <stdbool.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

CMARK_GFM_EXPORT
void cmark_gfm_core_extensions_ensure_registered(void);

extern cmark_node_type CMARK_NODE_TABLE, CMARK_NODE_TABLE_ROW,
    CMARK_NODE_TABLE_CELL;

#ifndef CMARK_NO_SHORT_NAMES
#define NODE_TABLE CMARK_NODE_TABLE
#define NODE_TABLE_ROW CMARK_NODE_TABLE_ROW
#define NODE_TABLE_CELL CMARK_NODE_TABLE_CELL
#endif

CMARK_GFM_EXPORT
uint16_t cmark_gfm_extensions_get_table_columns(cmark_node *node);

/** Sets the number of columns for the table, returning 1 on success and 0 on error.
 */
CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_columns(cmark_node *node, uint16_t n_columns);

CMARK_GFM_EXPORT
uint8_t *cmark_gfm_extensions_get_table_alignments(cmark_node *node);

/** Sets the alignments for the table, returning 1 on success and 0 on error.
 */
CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_alignments(cmark_node *node, uint16_t ncols, uint8_t *alignments);

CMARK_GFM_EXPORT
int cmark_gfm_extensions_get_table_row_is_header(cmark_node *node);

/** Sets whether the node is a table header row, returning 1 on success and 0 on error.
 */
CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_table_row_is_header(cmark_node *node, int is_header);

CMARK_GFM_EXPORT
bool cmark_gfm_extensions_get_tasklist_item_checked(cmark_node *node);
/* For backwards compatibility */
#define cmark_gfm_extensions_tasklist_is_checked cmark_gfm_extensions_get_tasklist_item_checked

/** Sets whether a tasklist item is "checked" (completed), returning 1 on success and 0 on error.
 */
CMARK_GFM_EXPORT
int cmark_gfm_extensions_set_tasklist_item_checked(cmark_node *node, bool is_checked);

#ifdef __cplusplus
}
#endif

#endif
