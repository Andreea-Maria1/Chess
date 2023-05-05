#include "Position.h"
#include <stdlib.h> 

namespace movementManagement {

	static inline bool isDiagonal(Position lastPosition, Position newPosition) 
	{
		return (abs(newPosition.x - lastPosition.x) == abs(newPosition.y - lastPosition.y));
	}

	static inline bool isVertical(Position lastPosition, Position newPosition) 
	{
		return (lastPosition.x == newPosition.x && lastPosition.y != newPosition.y);
	}

	static inline bool isHorizontal(Position lastPosition, Position newPosition) 
	{
		return (newPosition.x != lastPosition.x && lastPosition.y == newPosition.y);
	}

	static inline bool isCross(Position lastPosition, Position newPosition)
	{
		return (isVertical(lastPosition, newPosition) || isHorizontal(lastPosition, newPosition)); 
	}

	static inline bool isNeighbour(Position lastPosition, Position newPosition)
	{
		return (abs(newPosition.x - lastPosition.x) <= 1) && (abs(newPosition.y - lastPosition.y) <= 1)
			&& !(newPosition.x == lastPosition.x && newPosition.y == lastPosition.y);
	}
}