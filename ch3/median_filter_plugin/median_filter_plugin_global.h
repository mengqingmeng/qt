#ifndef MEDIAN_FILTER_PLUGIN_GLOBAL_H
#define MEDIAN_FILTER_PLUGIN_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(MEDIAN_FILTER_PLUGIN_LIBRARY)
#  define MEDIAN_FILTER_PLUGIN_EXPORT Q_DECL_EXPORT
#else
#  define MEDIAN_FILTER_PLUGIN_EXPORT Q_DECL_IMPORT
#endif

#endif // MEDIAN_FILTER_PLUGIN_GLOBAL_H
