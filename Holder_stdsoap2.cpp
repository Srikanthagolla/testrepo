/* ---------------------------------------------------------------------- */
/*               Proprietary and Confidential Information                 */
/*                                                                        */
/* This material contains, and is part of a computer software program     */
/* which is, proprietary and confidential information owned by COMPUTER   */
/* ASSOCIATES INTERNATIONAL, INC.  The program, including this material,  */
/* may not be duplicated, disclosed or reproduced in whole or in part for */
/* any purpose without the express written authorization of COMPUTER      */
/* ASSOCIATES. All authorized reproductions must be marked with this      */
/* legend.                                                                */
/*                                                                        */
/*                           Copyright (c) 2007                           */
/*             Computer Associates International, Incorporated            */
/*                        Transforming IT Management                      */
/*                           All rights reserved                          */
/*                                                                        */
/* ---------------------------------------------------------------------- */
/*   MS-VSS Module Control Stamp                                          */
/* ---------------------------------------------------------------------- */
static char _VSS_Id[]  = "$Header: /Src/CommonDiscovery/cmnDiscoveryClientSoap/Holder_stdsoap2.cpp 7     11/13/07 2:35p Ished01 $";
static char _CA_Copyright[] = "[Info: Copyright (C) 2007 Computer Associates International, Inc.  All rights reserved.]";

/*$Log: /Src/CommonDiscovery/cmnDiscoveryClientSoap/Holder_stdsoap2.cpp $
 * 
 * 7     11/13/07 2:35p Ished01
 * Added comments to document customizations
 * 
 * 6     9/13/07 8:31p Treje05
 * * Use the customized stdsoap2.cpp file from the cmnDiscoverySoapcpp2
 * project.
 * 
 * 5     8/15/07 10:21p Treje05
 * * Removed '#ifdef WITH_OPENSSL'.  WITH_OPENSSL is always defined.
 * 
 * 4     4/25/07 8:16p Kunch03
 * Add VSS header
 * 
 */

// This file is simply a wrapper that allows this project to pull in the gSOAP stdsoap2.cpp file from its original gSOAP SDK directory, $(GSOAP_HOME).  
// However, over time we have found that because the latest versions of gSOAP are not compatible with Java AXIS, we needed to manually apply certain patches 
// to the distributed stdsoap2.cpp file.  As such, we now have a checked in version of stdsoap2.cpp checked in under the cmnDiscovery Soapcpp2 project.
//
// The following is a list of customization and official patches that were applied to the distributed gSOAP file:
//   1)  Customization to line 561 to circumvent sporadic timeout issues in certain SSL based environments.
//          Original:
//             timeout.tv_usec = 10000;
//          Updated to:
//             timeout.tv_usec = 100000;
//
//   2)  Customization to line 779 to circumvent sporadic timeout issues in certain SSL based environments.
//          Original:
//             register int timeouts = 10;
//          Updated to:
//             register int timeouts = 100;
//

#pragma warning(disable:4244 4267 4311 4996)
#include "..\cmnDiscoverySoapcpp2\stdsoap2.cpp"

// Somebody in TAU or eTrust PKI changed the function prototype
// for SSL_library_init, such that it now takes two parameters, resulting in compile
// errors for any open source that uses the functions.
//
// Fortunately, multiple overloaded SSL_library_init can be declared in C++, so we can
// right this wrong.
#ifdef WITH_ETPKI
int CA1_SSL_library_init()
{
   return SSL_library_init(OPENSSL_FIPS_MODE_ON,NULL);
}
#endif
