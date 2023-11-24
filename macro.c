
// helper
#define STRING(s) #s

// interface

#define TRACEPOINT(context, event, ...)
#define TRACEPOINT_DEFINITION(context, event, ...)
#define TRACEPOINT_ACTIVE(context, event)
#define TRACEPOINT_SEMAPHORE(context, event)

// Linux

#define LINUX_TRACEPOINT(context, event, ...)                                   \
  do {                                                                          \
        if (LINUX_TRACEPOINT_ACTIVE(context, event)) {    \
            STAP_PROBEV(context, __VA_ARGS__);                                  \
        }                                                                       \
    } while(0)


#define LINUX_TRACEPOINT_SEMAPHORE(context, event) \
  unsigned short context##_##event##_semaphore __attribute__((section(".probes")))

#define LINUX_TRACEPOINT_ACTIVE(context, event) \
  context##_##event##_semaphore > 0

// TRACEPOINT_DEFINITION not needed for Linux

// MacOS

#define MACOS_STABILITY(context) STRING(___dtrace_stability$##context##$v1$1_1_0_1_1_0_1_1_0_1_1_0_1_1_0)
#define MACOS_TYPEDEFS(context) STRING(___dtrace_typedefs$##context##$v2)

#define MACOS_TRACEPOINT(context, event, ...) \
  do { \
	  __asm__ volatile(".reference " MACOS_TYPEDEFS(context)); \
	  __dtrace_probe$##context##$##event##$v1(__VA_ARGS__); \
	  __asm__ volatile(".reference " MACOS_STABILITY(context)); \
  } while (0)

#define	MACOS_TRACEPOINT_ACTIVE(context, event) \
	({ int _r = __dtrace_isenabled$##context##$##event##$v1(); \
		__asm__ volatile(""); \
		_r; })

#define MACOS_TRACEPOINT_SEMAPHORE(context, event) \
  extern int __dtrace_isenabled$##context##$##event##$v1(void);

#define MACOS_TRACEPOINT_DEFINITION(context, event, ...) \
  extern void __dtrace_probe$##context##$##event##$v1$75696e74385f74$75696e7433325f74$75696e7436345f74$756e7369676e65642063686172202a(__VA_ARGS__);

// FreeBSD

#define FREEBSD_TRACEPOINT(context, event, ...) \
  __dtrace_##context##___##event(__VA_ARGS__)

#define	FREEBSD_TRACEPOINT_ACTIVE(context, event) \
  __dtraceenabled_##context##___##event()

#define FREEBSD_TRACEPOINT_SEMAPHORE(context, event) \
  extern int __dtraceenabled_##context##___##event(long);

#define FREEBSD_TRACEPOINT_DEFINITION(context, event, ...) \
  extern void __dtrace_##context##___##event(__VA_ARGS__);
