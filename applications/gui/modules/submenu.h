/**
 * @file submenu.h
 * GUI: SubMenu view module API
 */

#pragma once

#include <gui/view.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Submenu anonymous structure */
typedef struct Submenu Submenu;
typedef void (*SubmenuItemCallback)(void* context, uint32_t index);

/** Allocate and initialize submenu 
 * 
 * This submenu is used to select one option
 *
 * @return     Submenu instance
 */
Submenu* submenu_alloc();

/** Deinitialize and free submenu
 *
 * @param      submenu  Submenu instance
 */
void submenu_free(Submenu* submenu);

/** Get submenu view
 *
 * @param      submenu  Submenu instance
 *
 * @return     View instance that can be used for embedding
 */
View* submenu_get_view(Submenu* submenu);

/** Add item to submenu
 *
 * @param      submenu           Submenu instance
 * @param      label             menu item label
 * @param      index             menu item index, used for callback, may be
 *                               the same with other items
 * @param      callback          menu item callback
 * @param      callback_context  menu item callback context
 */
void submenu_add_item(
    Submenu* submenu,
    const char* label,
    uint32_t index,
    SubmenuItemCallback callback,
    void* callback_context);

void submenu_add_item_with_icon(
    Submenu* submenu,
    const char* label,
    const Icon* icon,
    uint32_t index,
    SubmenuItemCallback callback,
    void* callback_context);

/** Remove all items from submenu
 *
 * @param      submenu  Submenu instance
 */
void submenu_clean(Submenu* submenu);

/** Set submenu item selector
 *
 * @param      submenu  Submenu instance
 * @param      index    The index
 */
void submenu_set_selected_item(Submenu* submenu, uint32_t index);

/** Set optional header for submenu
 *
 * @param      submenu  Submenu instance
 * @param      header   header to set
 */
void submenu_set_header(Submenu* submenu, const char* header);

#ifdef __cplusplus
}
#endif
