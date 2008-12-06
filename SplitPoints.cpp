/***********************************************************************
SplitPoints - Function to split an array of points according to a split
dimension and a center point component.
Copyright (c) 2007-2008 Oliver Kreylos

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

#include <Misc/Utility.h>

#include "SplitPoints.h"

unsigned int splitPoints(OctreePoint* points,unsigned int numPoints,int dimension,float split)
	{
	unsigned int l=0;
	unsigned int r=numPoints;
	while(l<r)
		{
		/* All points <l are <split: */
		while(l<numPoints&&points[l][dimension]<split)
			++l;
		
		/* All points >=r are >=split: */
		while(r>0&&points[r-1][dimension]>=split)
			--r;
		
		/* Swap if necessary: */
		if(l+1<r)
			{
			Misc::swap(points[l],points[r-1]);
			++l;
			--r;
			}
		}
	
	/* Return the number of points <split: */
	return l;
	}
