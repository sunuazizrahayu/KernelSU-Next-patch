/*
 * X625D 4.9 port: the MTK kernel ships mtk_events tracepoints
 * (sspm_ipi, etc.) normally defined by kernel/trace/trace.c when
 * CONFIG_MTK_SCHED_TRACERS is enabled. Define them here only when the
 * kernel does not own them, so the KSU driver builds with either
 * configuration without duplicate __tracepoint_* symbols (CREATE_TRACE_POINTS
 * => DEFINE_TRACE + string tables).
 */
#ifndef CONFIG_MTK_SCHED_TRACERS
#define CREATE_TRACE_POINTS
#include <trace/events/mtk_events.h>
#endif
