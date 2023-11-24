/* Generated by the Systemtap dtrace wrapper */


#define _SDT_HAS_SEMAPHORES 1


#define STAP_HAS_SEMAPHORES 1 /* deprecated */


#include <sys/sdt.h>

/* CONTEXT_EVENT_SIMPLE ( ) */
#if defined STAP_SDT_V1
#define CONTEXT_EVENT_SIMPLE_ENABLED() __builtin_expect (event_simple_semaphore, 0)
#define context_event_simple_semaphore event_simple_semaphore
#else
#define CONTEXT_EVENT_SIMPLE_ENABLED() __builtin_expect (context_event_simple_semaphore, 0)
#endif
__extension__ extern unsigned short context_event_simple_semaphore __attribute__ ((unused)) __attribute__ ((section (".probes")));
#define CONTEXT_EVENT_SIMPLE() \
DTRACE_PROBE (context, event_simple)

/* CONTEXT_EVENT_ARGS ( uint8_t, uint32_t, uint64_t, unsigned char * ) */
#if defined STAP_SDT_V1
#define CONTEXT_EVENT_ARGS_ENABLED() __builtin_expect (event_args_semaphore, 0)
#define context_event_args_semaphore event_args_semaphore
#else
#define CONTEXT_EVENT_ARGS_ENABLED() __builtin_expect (context_event_args_semaphore, 0)
#endif
__extension__ extern unsigned short context_event_args_semaphore __attribute__ ((unused)) __attribute__ ((section (".probes")));
#define CONTEXT_EVENT_ARGS(arg1, arg2, arg3, arg4) \
DTRACE_PROBE4 (context, event_args, arg1, arg2, arg3, arg4)
