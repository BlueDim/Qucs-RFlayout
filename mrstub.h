/***************************************************************************
                               mrstub.h
                             ------------------
    begin                : Thu Oct 25 2018
    copyright            : (C) 2018 by Thomas Lepoix
    email                : thomas.lepoix@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef MRSTUB_H
#define MRSTUB_H

#define _USE_MATH_DEFINES

#include <cmath>
#include "element.h"

class Mrstub : public Element {
private :
	long double m_w;
	long double m_l;
	long double m_ri;
	long double m_ro;
	long double m_alpha;
	std::string m_net1;
public :
	Mrstub(std::string _label,
		std::string _type,
		short _mirrorx,
		short _r,
		short _nport,
		long double _ri,
		long double _ro,
		short _alpha);
	~Mrstub();
	long double getW(void);
	long double getL(void);
	long double getRi(void);
	long double getRo(void);
	short getAlpha(void);
	std::string getNet1(void);
	int setNet1(std::string _net1);
////////////////////////////////////////////////////////////////////////////////
	long double getW1(void);
	long double getW2(void);
	long double getW3(void);
	long double getW4(void);
	long double getD(void);
	long double getS(void);
	std::string getNet2(void);
	std::string getNet3(void);
	std::string getNet4(void);
	int setNet2(std::string _net2);
	int setNet3(std::string _net3);
	int setNet4(std::string _net4);
};

#endif

