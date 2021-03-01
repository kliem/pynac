/** @file utils.cpp
 *
 *  Implementation of several small and furry utilities needed within GiNaC
 *  but not of any interest to the user of the library. */

/*
 *  GiNaC Copyright (C) 1999-2008 Johannes Gutenberg University Mainz, Germany
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 */

#include "ex.h"
#include "numeric.h"
#include "utils.h"
#include "version.h"

namespace GiNaC {

/* Version information buried into the library */
const int version_major = GINACLIB_MAJOR_VERSION;
const int version_minor = GINACLIB_MINOR_VERSION;
const int version_micro = GINACLIB_MICRO_VERSION;


/** ctor for pole_error exception class. */
pole_error::pole_error(const std::string& what_arg, int a_degree)
	: domain_error(what_arg), deg(a_degree) { }

/** Return the degree of the pole_error exception class. */
numeric pole_error::degree() const
{
	return deg;
}

/** Integer binary logarithm */
unsigned log2(unsigned n)
{
	unsigned k;
	for (k = 0; n > 1; n >>= 1)
		++k;
	return k;
}


//////////
// flyweight chest of numbers is initialized here:
//////////

/** How many static objects were created?  Only the first one must create
 *  the static flyweights on the heap. */
int library_init::count = 0;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
// static numeric -120
const numeric *_num_120_p;
const ex _ex_120 = _ex_120;

// static numeric -60
const numeric *_num_60_p;
const ex _ex_60 = _ex_60;

// static numeric -48
const numeric *_num_48_p;
const ex _ex_48 = _ex_48;

// static numeric -30
const numeric *_num_30_p;
const ex _ex_30 = _ex_30;

// static numeric -25
const numeric *_num_25_p;
const ex _ex_25 = _ex_25;

// static numeric -24
const numeric *_num_24_p;
const ex _ex_24 = _ex_24;

// static numeric -20
const numeric *_num_20_p;
const ex _ex_20 = _ex_20;

// static numeric -18
const numeric *_num_18_p;
const ex _ex_18 = _ex_18;

// static numeric -15
const numeric *_num_15_p;
const ex _ex_15 = _ex_15;

// static numeric -12
const numeric *_num_12_p;
const ex _ex_12 = _ex_12;

// static numeric -11
const numeric *_num_11_p;
const ex _ex_11 = _ex_11;

// static numeric -10
const numeric *_num_10_p;
const ex _ex_10 = _ex_10;

// static numeric -9
const numeric *_num_9_p;
const ex _ex_9 = _ex_9;

// static numeric -8
const numeric *_num_8_p;
const ex _ex_8 = _ex_8;

// static numeric -7
const numeric *_num_7_p;
const ex _ex_7 = _ex_7;

// static numeric -6
const numeric *_num_6_p;
const ex _ex_6 = _ex_6;

// static numeric -5
const numeric *_num_5_p;
const ex _ex_5 = _ex_5;

// static numeric -4
const numeric *_num_4_p;
const ex _ex_4 = _ex_4;

// static numeric -3
const numeric *_num_3_p;
const ex _ex_3 = _ex_3;

// static numeric -2
const numeric *_num_2_p;
const ex _ex_2 = _ex_2;

// static numeric -1
const numeric *_num_1_p;
const ex _ex_1 = _ex_1;

// static numeric -1/2
const numeric *_num_1_2_p;
const ex _ex_1_2= _ex_1_2;

// static numeric -1/3
const numeric *_num_1_3_p;
const ex _ex_1_3= _ex_1_3;

// static numeric -1/4
const numeric *_num_1_4_p;
const ex _ex_1_4= _ex_1_4;

// static numeric 0
const numeric *_num0_p;
const basic *_num0_bp;
const ex _ex0 = _ex0;

// static numeric 1/4
const numeric *_num1_4_p;
const ex _ex1_4 = _ex1_4;

// static numeric 1/3
const numeric *_num1_3_p;
const ex _ex1_3 = _ex1_3;

// static numeric 1/2
const numeric *_num1_2_p;
const ex _ex1_2 = _ex1_2;

// static numeric 1
const numeric *_num1_p;
const ex _ex1 = _ex1;

// static numeric 2
const numeric *_num2_p;
const ex _ex2 = _ex2;

// static numeric 3
const numeric *_num3_p;
const ex _ex3 = _ex3;

// static numeric 4
const numeric *_num4_p;
const ex _ex4 = _ex4;

// static numeric 5
const numeric *_num5_p;
const ex _ex5 = _ex5;

// static numeric 6
const numeric *_num6_p;
const ex _ex6 = _ex6;

// static numeric 7
const numeric *_num7_p;
const ex _ex7 = _ex7;

// static numeric 8
const numeric *_num8_p;
const ex _ex8 = _ex8;

// static numeric 9
const numeric *_num9_p;
const ex _ex9 = _ex9;

// static numeric 10
const numeric *_num10_p;
const ex _ex10 = _ex10;

// static numeric 11
const numeric *_num11_p;
const ex _ex11 = _ex11;

// static numeric 12
const numeric *_num12_p;
const ex _ex12 = _ex12;

// static numeric 14
const numeric *_num14_p;
const ex _ex14 = _ex14;

// static numeric 15
const numeric *_num15_p;
const ex _ex15 = _ex15;

// static numeric 16
const numeric *_num16_p;
const ex _ex16 = _ex16;

// static numeric 18
const numeric *_num18_p;
const ex _ex18 = _ex18;

// static numeric 20
const numeric *_num20_p;
const ex _ex20 = _ex20;

// static numeric 21
const numeric *_num21_p;
const ex _ex21 = _ex21;

// static numeric 22
const numeric *_num22_p;
const ex _ex22 = _ex22;

// static numeric 24
const numeric *_num24_p;
const ex _ex24 = _ex24;

// static numeric 25
const numeric *_num25_p;
const ex _ex25 = _ex25;

// static numeric 26
const numeric *_num26_p;
const ex _ex26 = _ex26;

// static numeric 27
const numeric *_num27_p;
const ex _ex27 = _ex27;

// static numeric 28
const numeric *_num28_p;
const ex _ex28 = _ex28;

// static numeric 30
const numeric *_num30_p;
const ex _ex30 = _ex30;

// static numeric 36
const numeric *_num36_p;
const ex _ex36 = _ex36;

// static numeric 48
const numeric *_num48_p;
const ex _ex48 = _ex48;

// static numeric 60
const numeric *_num60_p;
const ex _ex60 = _ex60;

// static numeric 72
const numeric *_num72_p;
const ex _ex72 = _ex72;

// static numeric 120
const numeric *_num120_p;
const ex _ex120 = _ex120;

// static numeric 144
const numeric *_num144_p;
const ex _ex144 = _ex144;
#pragma clang diagnostic pop


// comment skeleton for header files


// member functions

	// default constructor, destructor, copy constructor and assignment operator
	// none

	// other constructors
	// none

	// functions overriding virtual functions from base classes
	// none

	// new virtual functions which can be overridden by derived classes
	// none

	// non-virtual functions in this class
	// none

// member variables
// none



// comment skeleton for implementation files


//////////
// default constructor, destructor, copy constructor and assignment operator
//////////

// public
// protected

//////////
// other constructors
//////////

// public
// none

//////////
// functions overriding virtual functions from base classes
//////////

// public
// protected
// none

//////////
// new virtual functions which can be overridden by derived classes
//////////

// public
// protected
// none

//////////
// non-virtual functions in this class
//////////

// public
// protected
// none

//////////
// static member variables
//////////

// protected
// private
// none


} // namespace GiNaC
