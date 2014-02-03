/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License (the "License").
 * You may not use this file except in compliance with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * CDDL HEADER END
 */

/* 
 *Portions Copyright 2013 CFEngine AS 
 */

/*
 * Copyright (c) 2010, Oracle and/or its affiliates. All rights reserved.
 */
#ifndef _SOLARIS_IFADDRS_H
#define _SOLARIS_IFADDRS_H



#include <sys/types.h>

#define LIFC_ENABLED    0x20            /* Include only IFF_UP interfaces */
/*
 * The `getifaddrs' function generates a linked list of these structures.
 * Each element of the list describes one network interface.
 */
struct ifaddrs {
        struct ifaddrs  *ifa_next;      /* Pointer to the next structure. */
        char            *ifa_name;      /* Name of this network interface. */
        uint64_t         ifa_flags;      /* Flags as from SIOCGLIFFLAGS ioctl. */
        struct sockaddr *ifa_addr;      /* Network address of this interface. */
        struct sockaddr *ifa_netmask;   /* Netmask of this interface. */
        union {
                /*
                 * At most one of the following two is valid.  If the
                 * IFF_BROADCAST bit is set in `ifa_flags', then
                 * `ifa_broadaddr' is valid.  If the IFF_POINTOPOINT bit is
                 * set, then `ifa_dstaddr' is valid. It is never the case that
                 * both these bits are set at once.
                 */
        struct sockaddr *ifu_broadaddr;
        struct sockaddr *ifu_dstaddr;
        } ifa_ifu;
        void        *ifa_data; /* Address-specific data (may be unused). */
/*
 * This may have been defined in <net/if.h>.
 */
#ifndef ifa_broadaddr
#define ifa_broadaddr ifa_ifu.ifu_broadaddr /* broadcast address */
#endif
#ifndef ifa_dstaddr
#define ifa_dstaddr ifa_ifu.ifu_dstaddr /* other end of p-to-p link */
#endif
};

/*
 * Create a linked list of `struct ifaddrs' structures, one for each
 * network interface on the host machine.  If successful, store the
 * list in *ifap and return 0.  On errors, return -1 and set `errno'.
 *
 * The storage returned in *ifap is allocated dynamically and can
 * only be properly freed by passing it to `freeifaddrs'.
 */
extern int solaris_getifaddrs(struct ifaddrs **);

/* Reclaim the storage allocated by a previous `getifaddrs' call. */
extern void solaris_freeifaddrs(struct ifaddrs *);


#endif /* _SOLARIS_IFADDRS_H */