/* === S Y N F I G ========================================================= */
/*!	\file valuenode_repeat_gradient.h
**	\brief Header file for implementation of the "Repeat Gradient" valuenode conversion.
**
**	$Id: valuenode_repeat_gradient.h 335 2007-03-16 00:39:09Z dooglus $
**
**	\legal
**	Copyright (c) 2002-2005 Robert B. Quattlebaum Jr., Adrian Bentley
**	Copyright (c) 2007 Chris Moore
**
**	This package is free software; you can redistribute it and/or
**	modify it under the terms of the GNU General Public License as
**	published by the Free Software Foundation; either version 2 of
**	the License, or (at your option) any later version.
**
**	This package is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
**	General Public License for more details.
**	\endlegal
*/
/* ========================================================================= */

/* === S T A R T =========================================================== */

#ifndef __SYNFIG_VALUENODE_REPEAT_GRADIENT_H
#define __SYNFIG_VALUENODE_REPEAT_GRADIENT_H

/* === H E A D E R S ======================================================= */

#include "valuenode.h"

/* === M A C R O S ========================================================= */

/* === C L A S S E S & S T R U C T S ======================================= */

namespace synfig {

struct ValueNode_Repeat_Gradient : public LinkableValueNode
{
	typedef etl::handle<ValueNode_Repeat_Gradient> Handle;
	typedef etl::handle<const ValueNode_Repeat_Gradient> ConstHandle;

protected:

	ValueNode_Repeat_Gradient(const Gradient& x);

private:

	ValueNode::RHandle gradient_;
	ValueNode::RHandle count_;
	ValueNode::RHandle width_;
	ValueNode::RHandle specify_start_;
	ValueNode::RHandle specify_end_;
	ValueNode::RHandle start_color_;
	ValueNode::RHandle end_color_;

public:

	virtual ~ValueNode_Repeat_Gradient();

	bool set_gradient(ValueNode::Handle a);
	bool set_count(ValueNode::Handle b);
	bool set_width(ValueNode::Handle x);
	bool set_specify_start(ValueNode::Handle a);
	bool set_specify_end(ValueNode::Handle a);
	bool set_start_color(ValueNode::Handle a);
	bool set_end_color(ValueNode::Handle a);

	virtual bool set_link_vfunc(int i,ValueNode::Handle x);

	virtual ValueNode::LooseHandle get_link_vfunc(int i)const;

	virtual int link_count()const;

	virtual String link_local_name(int i)const;
	virtual String link_name(int i)const;
	virtual int get_link_index_from_name(const String &name)const;

	virtual ValueBase operator()(Time t)const;

	virtual String get_name()const;
	virtual String get_local_name()const;

//	static bool check_type(const ValueBase::Type &type);

	LinkableValueNode* create_new()const;

public:
	using synfig::LinkableValueNode::get_link_vfunc;
	using synfig::LinkableValueNode::set_link_vfunc;
	static bool check_type(ValueBase::Type type);
	static ValueNode_Repeat_Gradient* create(const ValueBase &x=ValueBase::TYPE_GRADIENT);
}; // END of class ValueNode_Repeat_Gradient

}; // END of namespace synfig

/* === E N D =============================================================== */

#endif
