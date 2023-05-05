#include "Position.h"
#include <stdlib.h> 

namespace movementManagement {

	static inline bool isDiagonal(Position lastPosition, Position newPosition) 
	{
		return (abs(newPosition.x - lastPosition.x) == abs(newPosition.y - lastPosition.y));
	}

	static inline bool isCross(Position lastPosition, Position newPosition)
	{
		return ((lastPosition.x == newPosition.x && lastPosition.y != newPosition.y) || (lastPosition.y == newPosition.y && newPosition.y != lastPosition.x));
	}

	static inline bool isNeighbour(Position lastPosition, Position newPosition)
	{
		return (abs(newPosition.x - lastPosition.x) <= 1) && (abs(newPosition.y - lastPosition.y) <= 1)
			&& !(newPosition.x == lastPosition.x && newPosition.y == lastPosition.y);
	}
}