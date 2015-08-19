#ifndef __GOREX_APPLICATION_H
#define __GOREX_APPLICATION_H

#include <gtk/gtk.h>


#define GOREX_TYPE_APPLICATION (gorex_application_get_type ())
#define GOREX_APPLICATION(obj) \
	(G_TYPE_CHECK_INSTANCE_CAST ((obj), GOREX_TYPE_APPLICATION, GorexApplication))


typedef struct _GorexApplication       GorexApplication;
typedef struct _GorexApplicationClass  GorexApplicationClass;


GType                 gorex_application_get_type    (void);
GorexApplication     *gorex_application_new         (void);


#endif /* __GOREX_APPLICATION_H */
