// Copyright (c) 1997-2004  Utrecht University (The Netherlands),
// ETH Zurich (Switzerland), Freie Universitaet Berlin (Germany),
// INRIA Sophia-Antipolis (France), Martin-Luther-University Halle-Wittenberg
// (Germany), Max-Planck-Institute Saarbruecken (Germany), RISC Linz (Austria),
// and Tel-Aviv University (Israel).  All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; version 2.1 of the License.
// See the file LICENSE.LGPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
// 
// Author(s)     : Laurent Saboret

#ifndef CGAL_AUTO_LINK_LAPACK_H
#define CGAL_AUTO_LINK_LAPACK_H

#ifndef CGAL_NO_AUTOLINK_LAPACK


#ifndef _WIN64

// CGAL ships with ATLAS for Windows 32 bits, i.e this set of libraries (e.g. for /MD):
// liblapack.lib libf77blas.lib libcblas.lib libatlas.lib vcf2c-vc71-mt.lib
//
// Notes: - Order matters.
//        - VC++ 7.1 libraries work with VC++ 8.0. 
//        - Libraries with no "vc71" toolset are compiled by gcc/g77. They are 
//          compatible with VC++ 7.1 and 8.0, and with all VC++ runtimes.
//        - Tested with VC++ 7.1 and 8.0 only.

#define CGAL_LIB_NAME liblapack
#define CGAL_AUTO_LINK_NOMANGLE
#include <CGAL/auto_link/auto_link.h>

#define CGAL_LIB_NAME libf77blas
#define CGAL_AUTO_LINK_NOMANGLE
#include <CGAL/auto_link/auto_link.h>

#define CGAL_LIB_NAME libcblas
#define CGAL_AUTO_LINK_NOMANGLE
#include <CGAL/auto_link/auto_link.h>

#define CGAL_LIB_NAME libatlas
#define CGAL_AUTO_LINK_NOMANGLE
#include <CGAL/auto_link/auto_link.h>

#define CGAL_LIB_NAME vcf2c
#define CGAL_LIB_TOOLSET "vc71"
#include <CGAL/auto_link/auto_link.h>

// ATLAS provides BLAS and LAPACK standard Fortran interface
#define CGAL_USE_F2C

# else // if _WIN64

// ATLAS is not compatible with Win64, thus CGAL ships with CLAPACK and CBLAS.
// VC++ >= 8.0 is compatible with Windows 64 bits.
// The set set of libraries is (e.g. for /MD):
// clapack-vc80-mt.lib blas-vc80-mt.lib vcf2c-vc80-mt.lib
//
// Notes: - Order matters.
//        - Tested with VC++ 8.0 only.

#define CGAL_LIB_NAME clapack
#define CGAL_LIB_TOOLSET "vc80"
#include <CGAL/auto_link/auto_link.h>

#define CGAL_LIB_NAME blas
#define CGAL_LIB_TOOLSET "vc80"
#include <CGAL/auto_link/auto_link.h>

#define CGAL_LIB_NAME vcf2c
#define CGAL_LIB_TOOLSET "vc80"
#include <CGAL/auto_link/auto_link.h>

// CLAPACK provides LAPACK standard Fortran interface.
// blaswrap.h maps CBLAS function names to BLAS standard Fortran interface.
#define CGAL_USE_F2C
#include <blaswrap.h>

#endif // _WIN64


#endif // CGAL_NO_AUTOLINK_LAPACK

#endif // CGAL_AUTO_LINK_LAPACK_H

