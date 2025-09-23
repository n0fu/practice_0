#include "structs.h"

// функции для точки
void DotInit(Dot &dot);
void DotShow(Dot &dot);

// функции для круга
void CircleInit(Circle &circle);
void CircleShow(Circle &circle);
void CircleLen(Circle &circle);
void CircleSquare(Circle &circle);

// функции для квадрата
void SquareInit(Square &square);
void SquareCornersInit(Square &square);
void SquareShow(Square &square);
void SquarePerimeter(Square &square);
void SquareSquare(Square &square);

// точка внутри фигуры
bool DotInCircle(Circle &circle, Dot &dot);
bool DotInSquare(Square &square, Dot &dot);

// точка на границе фигуры
bool DotOnCircle(Circle &circle, Dot &dot);
bool DotOnSquare(Square &square, Dot &dot);

// пересечение фигур
bool CirclesIntersection(Circle &a, Circle &b);
bool SquaresIntersection(Square &a, Square &b);
bool SquareCircleIntersection(Square &a, Circle &b);

// принадлежность фигуре
bool IsCircleInCircle(Circle &a, Circle &b);
bool IsSquareInSquare(Square &a, Square &b);
bool IsSquareInCircle(Square &a, Circle &b);
bool IsCircleInSquare(Circle &a, Square &b);