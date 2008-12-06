/***********************************************************************
PointPrimitive - Class for points extracted from point clouds by
intersecting three plane primitives or one line primitive and one plane
primitive.
Copyright (c) 2008 Oliver Kreylos

This file is part of the LiDAR processing and analysis package.

The LiDAR processing and analysis package is free software; you can
redistribute it and/or modify it under the terms of the GNU General
Public License as published by the Free Software Foundation; either
version 2 of the License, or (at your option) any later version.

The LiDAR processing and analysis package is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with the LiDAR processing and analysis package; if not, write to the
Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
02111-1307 USA
***********************************************************************/

#ifndef POINTPRIMITIVE_INCLUDED
#define POINTPRIMITIVE_INCLUDED

#include <Geometry/Point.h>

#include "Primitive.h"

/* Forward declarations: */
namespace Comm {
class MulticastPipe;
}
class PlanePrimitive;
class LinePrimitive;

class PointPrimitive:public Primitive
	{
	/* Elements: */
	protected:
	Point point; // The extracted point
	
	/* Constructors and destructors: */
	protected:
	PointPrimitive(void) // Dummy constructor
		{
		};
	public:
	PointPrimitive(const PlanePrimitive* p1,const PlanePrimitive* p2,const PlanePrimitive* p3,Comm::MulticastPipe* pipe); // Creates point primitive by intersecting the three given plane primitives; writes result to given pipe if !=0
	PointPrimitive(const PlanePrimitive* p,const LinePrimitive* l,Comm::MulticastPipe* pipe); // Creates point primitive by intersecting the given plane and line primitives; writes result to given pipe if !=0
	PointPrimitive(Comm::MulticastPipe* pipe); // Creates cylinder by reading cylinder data from given pipe
	PointPrimitive(Misc::File& file,const Vector& translation); // Reads a cylinder primitive from a binary file
	
	/* Methods: */
	virtual Scalar pick(const Point& pickPoint,Scalar maxPickDistance) const;
	virtual void glRenderAction(GLContextData& contextData) const;
	virtual void write(Misc::File& file,const Vector& translation) const;
	};

#endif
