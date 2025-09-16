#include <iostream>
#include <cmath>

// точка
struct Dot{           
    double x;
    double y;
};

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

// круг
struct Circle{
    Dot center;
    double radius;
    double square;
    double len;
};

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

// квадрат
struct Square{
    Dot topl_corner;
    Dot topr_corner;
    Dot lowl_corner;
    Dot lowr_corner;
    double side;
    double perimeter;
    double square;
};

void SquareInit(Square &square){
    std::cout << "Write top left corner cords " << std::endl;
    DotInit(square.topl_corner);
    std::cout << "Write side len " << std::endl;
    std::cin >> square.side;
    square.topr_corner.x = square.topl_corner.x + square.side;
    square.topr_corner.y = square.topl_corner.y;
    square.lowl_corner.x = square.topl_corner.x;
    square.lowl_corner.y = square.topl_corner.y - square.side;
    square.lowr_corner.x = square.topl_corner.x + square.side;
    square.lowr_corner.y = square.topl_corner.y - square.side;;
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
bool DonInCircle(Circle &circle, Dot &dot){
    if (abs(dot.x - circle.center.x) < circle.radius && abs(dot.y - circle.center.y) < circle.radius){
        return 1;
    }
    return 0;
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
    if ((dot.x - circle.center.x) * (dot.x - circle.center.x) + (dot.y - circle.center.y) * (dot.y - circle.center.y) == circle.radius * circle.radius){
        return 1;
    } else {
        return 0;
    }
}

bool DotOnSquare(Square &square, Dot &dot){
     if ((dot.x == square.topl_corner.x || dot.x == square.topl_corner.x + square.side) && 
     (dot.y == square.topl_corner.y || dot.y > square.topl_corner.y - square.side)){
        return 1;
    } else {
        return 0;
    }
}

// пересечение фигур
bool CirclesIntersection(Circle &a, Circle &b){
    double dcenter = sqrt((a.center.x - b.center.x)*(a.center.x - b.center.x) + (a.center.y - b.center.y)*(a.center.y - b.center.y));
    if (a.len > b.len){
        if ((dcenter < b.radius) && dcenter > a.radius - b.radius){
            return 1;
        }
    } else {
        if ((dcenter < a.radius) && dcenter > b.radius - a.radius){
            return 1;
        }
        return 0;
    }
}

bool SquaresIntersection(Square &a, Square &b){
    if ((DotInSquare(a,b.topl_corner) && !DotInSquare(a, b.lowr_corner)) || (DotInSquare(b, a.topl_corner) && !DotInSquare(b, a.lowr_corner))){
        return 1;
    } else if ((DotInSquare(a, b.topr_corner) && !DotInSquare(a, b.lowl_corner)) || (DotInSquare(b, a.topr_corner) && !DotInSquare(b, a.lowl_corner))){
        return 1;
    }
    return 0;
}

bool SquareCircleIntersection(Square &a, Circle &b){
    if ((b.center.x + b.radius >= a.topl_corner.x || b.center.x - b.radius <= a.topr_corner.x) && 
    (b.center.y + b.radius <= a.lowl_corner.y || b.center.y - b.radius <= a.topr_corner.y)){
        if (b.center.x*b.center.x - (a.topl_corner.x - b.center.y)*(a.topl_corner.x - b.center.y) + b.radius*b.radius == 0 
        || b.center.x*b.center.x - (a.topr_corner.x - b.center.y)*(a.topr_corner.x - b.center.y) + b.radius*b.radius == 0){
            return 1;
        }
        if (b.center.y*b.center.y - (a.topl_corner.y - b.center.x)*(a.lowl_corner.y - b.center.x) + b.radius*b.radius == 0 
        || b.center.y*b.center.y - (a.topl_corner.y - b.center.x)*(a.lowl_corner.y - b.center.x) + b.radius*b.radius == 0){
            return 1;
        }
    }
    return 0;
}

// принадлежность фигуры
bool IsCircleInCircle(Circle &a, Circle &b){
    if(DonInCircle(b, a.center) && !CirclesIntersection(a,b)){
        return 1;
    }
    return 0;
}

bool IsSquareInSquare(Square &a, Square &b){
    if (DotInSquare(b,a.topl_corner) && DotInSquare(b,a.lowr_corner)){
        return 1;
    }
    return 0;
}

bool IsSquareInCircle(Square &a, Circle &b){
    Circle *pcircle;
    pcircle = new Circle;
    pcircle->center.x = a.topl_corner.x + a.side/2;
    pcircle->center.y = a.topl_corner.y - a.side/2;
    if (IsCircleInCircle(*pcircle,b)){
        delete pcircle;
        return 1;
    }
    delete pcircle;
    return 0;
}

bool IsCircleInSquare(Circle &a, Square &b){
    Square *psquare;
    psquare = new Square;
    psquare->topl_corner.x = a.center.x - a.radius/2;
    psquare->topl_corner.y = a.center.y + a.radius/2;
    psquare->lowr_corner.x = a.center.x + a.radius/2;
    psquare->lowr_corner.y = a.center.y - a.radius/2;
    if (IsSquareInSquare(*psquare, b)){
        delete psquare;
        return 1;
    }
    delete psquare;
    return 0;
}
int main(){
    return 0;
}

