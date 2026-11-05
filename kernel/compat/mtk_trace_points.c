/*
 * X625D 4.9 port: the MTK kernel ships mtk_events tracepoints
 * (sspm_ipi, etc.) normally defined by specific drivers. In this 4.9
 * build the owning TU is not part of the build, so define them here
 * (CREATE_TRACE_POINTS => DEFINE_TRACE + string tables).
 */
#define CREATE_TRACE_POINTS
#include <trace/events/mtk_events.h>
