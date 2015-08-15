#ifndef __GOREX_WINDOW_H
#define __GOREX_WINDOW_H

#include <gtk/gtk.h>
#include "gorex-application.h"


#define GOREX_TYPE_WINDOW (gorex_window_get_type ())
#define GOREX_WINDOW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), GOREX_TYPE_WINDOW, GorexWindow))


typedef struct _GorexWindow         GorexWindow;
typedef struct _GorexWindowClass    GorexWindowClass;


GType              gorex_window_get_type     (void);
GorexWindow       *gorex_window_new          (GorexApplication *app);
void               gorex_window_open         (GorexWindow 		 *win,
                                              GFile            *file);


#endif /* __GOREX_WINDOW_H */
