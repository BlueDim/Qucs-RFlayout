/***************************************************************************
                               xycalculator.hpp
                             ------------------
    begin                : Thu Oct 25 2018
    copyright            : (C) 2018 by Thomas Lepoix
    email                : thomas.lepoix@protonmail.ch
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef XYCALCULATOR_HPP
#define XYCALCULATOR_HPP

#include <array>
#include <memory>
#include <vector>

#include "data.hpp"
#include "microstrip/element.hpp"

class Block {
public:
	std::vector<std::shared_ptr<Element>> elements;
	std::shared_ptr<Element> subst;
	std::array<long double, 4> extrem_pos;
	long double margin;

	Block(void);
	void shift(long double const x, long double const y);
	void set_extrem_pos(void);
	void print_extrem_pos(void);
	void print(void);
};

class XyCalculator {
private:

	std::vector<std::shared_ptr<Block>> all_blocks;
	Data& data;

	// Main functions
	bool check_intersection(void);
	void resolve_pac_shapes(void);
	void place_elements(void);
	void place_blocks(void);

	// Toolbox functions
	void sort_blocks(std::vector<std::shared_ptr<Block>> blocks, std::vector<std::shared_ptr<Element>> substs);
	int add_to_block(std::shared_ptr<Block>& block, std::shared_ptr<Element> const& element);
	int tab_remove(std::vector<std::shared_ptr<Element>>& elements, std::shared_ptr<Element> const& element);
	bool purgefind(std::shared_ptr<Element> const& element, std::string const net);
	int purge_nets(void);
	int purge_blocks(void);
	bool check_onenet(std::string const net);
	int activenets(std::shared_ptr<Element> const& element);
	int netmin(std::shared_ptr<Element> const& element);
	void findnext(std::shared_ptr<Element> const& current, int& current_net, std::shared_ptr<Element>& next);

public:
	XyCalculator(Data& _data);

	// Interface functions
	int run(void);
	void clear(void);
};

#endif // XYCALCULATOR_HPP
