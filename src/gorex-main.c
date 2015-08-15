#include <gtk/gtk.h>

#include "gorex-application.h"

int
main (int argc, char *argv[])
{
  return g_application_run (G_APPLICATION (gorex_application_new ()), argc, argv);
}
