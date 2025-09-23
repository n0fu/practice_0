#include <iostream>
#include <cmath>
#include "func.h"

// функции для точки
void DotInit(Dot &dot){
    std::cout << "Write X " << std::endl;
    std::cin >> dot.x;
    std::cout << "Write Y " << std::endl;
    std::cin >> dot.y;
}

void DotShow(Dot &dot){
    std::cout << "X = " << dot.x << std::endl;
    std::cout << "Y = " << dot.y << std::endl;
}


// функции для круга
void CircleInit(Circle &circle){
    std::cout << "Write center cords" << std::endl;
    DotInit(circle.center);
    std::cout << "Write radius " << std::endl;
    std::cin >> circle.radius;
}

void CircleShow(Circle &circle){
    std::cout << "Center cords are" << std::endl;
    DotShow(circle.center);
    std::cout << "Radius is " << circle.radius << std::endl;
}

void CircleLen(Circle &circle){
    circle.len = 2 * 3.14 * circle.radius;
}

void CircleSquare(Circle &circle){
    circle.square = 3.14 * circle.radius * circle.radius;
}

// функции для квадрата
void SquareInit(Square &square){
    std::cout << "Write top left corner cords " << std::endl;
    DotInit(square.topl_corner);
    std::cout << "Write side len " << std::endl;
    std::cin >> square.side;
}

void SquareCornersInit(Square &square){
    square.topr_corner.x = square.topl_corner.x + square.side;
    square.topr_corner.y = square.topl_corner.y;
    square.lowl_corner.x = square.topl_corner.x;
    square.lowl_corner.y = square.topl_corner.y - square.side;
    square.lowr_corner.x = square.topl_corner.x + square.side;
    square.lowr_corner.y = square.topl_corner.y - square.side;
}

void SquareShow(Square &square){
    std::cout << "Top left cords are" << std::endl;
    DotShow(square.topl_corner);
    std::cout << "Side len is " << square.side << std::endl;
}

void SquarePerimeter(Square &square){
    square.perimeter = 4 * square.side;
}

void SquareSquare(Square &square){
    square.square = square.side * square.side;
}

// принадлежность точки фигуре
bool DotInCircle(Circle &circle, Dot &dot){
    double dx = dot.x - circle.center.x;
    double dy = dot.y - circle.center.y;
    double dist = dx*dx + dy*dy;
    return dist < circle.radius * circle.radius;
}

bool DotInSquare(Square &square, Dot &dot){
    if (dot.x > square.topl_corner.x && dot.x < (square.topl_corner.x + square.side) && 
    dot.y < square.topl_corner.y && dot.y > (square.topl_corner.y - square.side)){
        return 1;
    } else {
        return 0;
    }
}

// нахождение точки на контуре
bool DotOnCircle(Circle &circle, Dot &dot){
    double dx = dot.x - circle.center.x;
    double dy = dot.y - circle.center.y;
    double dist = dx*dx + dy*dy;
    if (dist == circle.radius * circle.radius){
        return 1;
    } else {
        return 0;
    }
}

bool DotOnSquare(Square &square, Dot &dot){
    if (dot.x >= square.topl_corner.x && dot.x <= square.topr_corner.x && (dot.y == square.topl_corner.y || dot.y == square.lowl_corner.y)){
        return 1;
    }

    if (dot.y >= square.lowl_corner.y && dot.y <= square.topr_corner.y && (dot.x == square.topl_corner.x || dot.x == square.topr_corner.x)){
        return 1;
    }
    return 0;
}

// пересечение фигур
bool CirclesIntersection(Circle &a, Circle &b){
    double dcenter = sqrt((a.center.x - b.center.x)*(a.center.x - b.center.x) + (a.center.y - b.center.y)*(a.center.y - b.center.y));
    double sumRad = a.radius + b.radius;
    double difRad = abs(a.radius - b.radius);
    if (dcenter <= sumRad && dcenter >= difRad){
        return 1;
    }
    return 0;
}

bool SquaresIntersection(Square &a, Square &b){
    double aLeftside = a.topl_corner.x, aRightside = a.topr_corner.x;
    double aBottomside = a.lowl_corner.y, aTopside = a.topl_corner.y;
    double bLeftside = b.topl_corner.x, bRightside = b.topr_corner.x;
    double bBottomside = b.lowl_corner.y, bTopside = b.topl_corner.y;

    bool x_intersection = !(aRightside <= bLeftside || bRightside <= aLeftside);
    bool y_intersection = !(aTopside <= bBottomside || bTopside <= aBottomside);
    
    return x_intersection && y_intersection ;
}

bool SquareCircleIntersection(Square &a, Circle &b){
    double closestX = b.center.x, closestY = b.center.y;
    if (b.center.x < a.topl_corner.x){
        closestX = a.topl_corner.x;
    } else if (b.center.x > a.topr_corner.x){
        closestX = a.topr_corner.x;
    }

    if (b.center.y > a.topl_corner.y){
        closestY = a.topl_corner.y;
    } else if (b.center.y < a.lowr_corner.y){
        closestY = a.lowr_corner.y;
    }

    double dist = (b.center.x - closestX)*(b.center.x - closestX) + (b.center.y - closestY)*(b.center.y - closestY);
    return dist <= b.radius*b.radius;
}


// принадлежность фигуры
bool IsCircleInCircle(Circle &a, Circle &b){
    double dist = sqrt((a.center.x - b.center.x)*(a.center.x - b.center.x) + (a.center.y - b.center.y)*(a.center.y - b.center.y));
    return (dist + a.radius) < b.radius;
}

bool IsSquareInSquare(Square &a, Square &b){
    return DotInSquare(b, a.topl_corner) &&
    DotInSquare(b, a.topr_corner) &&
    DotInSquare(b, a.lowl_corner) &&
    DotInSquare(b, a.lowr_corner);
}

bool IsSquareInCircle(Square &a, Circle &b){
    return DotInCircle(b, a.topl_corner) &&
    DotInCircle(b, a.topr_corner) &&
    DotInCircle(b, a.lowl_corner) &&
    DotInCircle(b, a.lowr_corner);
}

bool IsCircleInSquare(Circle &a, Square &b){
    double aTop = a.center.y + a.radius;
    double aBottom = a.center.y - a.radius;
    double aLeft = a.center.x - a.radius;
    double aRight = a.center.x + a.radius;

    return aTop < b.topl_corner.y &&
    aBottom > b.lowl_corner.y &&
    aLeft > b.topl_corner.x &&
    aRight < b.topr_corner.x;
}