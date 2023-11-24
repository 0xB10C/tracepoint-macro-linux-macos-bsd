#include "macro.c"

--- tracepoint

Linux
LINUX_TRACEPOINT(net, inbound_message, 1, 2, 3, 4);

macOS
MACOS_TRACEPOINT(net, inbound_message, 1, 2, 3, 4);

FreeBSD
FREEBSD_TRACEPOINT(net, inbound_message, 1, 2, 3, 4);

--- semaphore

Linux
LINUX_TRACEPOINT_SEMAPHORE(net, inbound_message);

macOS
MACOS_TRACEPOINT_SEMAPHORE(net, inbound_message);

FreeBSD
FREEBSD_TRACEPOINT_SEMAPHORE(net, inbound_message);



--- definition

Linux
not applicable (does not need to define the tracepoint)

macOS
MACOS_TRACEPOINT_DEFINITION(net, inbound_message, uint8_t, uint32_t, uint64_t, unsigned char *)

FreeBSD
FREEBSD_TRACEPOINT_DEFINITION(net, inbound_message, uint8_t, uint32_t, uint64_t, unsigned char *)



--- active check

Linux
if(LINUX_TRACEPOINT_ACTIVE(net, inbound_message)) { .. }

macOS
if(MACOS_TRACEPOINT_ACTIVE(net, inbound_message)) { .. }

FreeBSD
if(FREEBSD_TRACEPOINT_ACTIVE(net, inbound_message)) { .. }

