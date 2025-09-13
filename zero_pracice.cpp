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
    double side;
    double perimeter;
    double square;
};

void SquareInit(Square &square){
    std::cout << "Write top left corner cords " << std::endl;
    DotInit(square.topl_corner);
    std::cout << "Write side len " << std::endl;
    std::cin >> square.side;
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
void DonInCircle(Circle &circle, Dot &dot){
    if (abs(dot.x - circle.center.x) < circle.radius && abs(dot.y - circle.center.y) < circle.radius){
        std::cout << "Dot in circle" << std::endl;
    } else {
        std::cout << "Dot not in circle" << std::endl;
    }
}

void DotInSquare(Square &square, Dot &dot){
    if (dot.x > square.topl_corner.x && dot.x < (square.topl_corner.x + square.side) && dot.y < square.topl_corner.y && dot.y > (square.topl_corner.y - square.side)){
        std::cout << "Dot in square" << std::endl;
    } else {
        std::cout << "Dot not in square" << std::endl;
    }
}

// нахождение точки на контуре
void DotOnCircle(Circle &circle, Dot &dot){
    if ((dot.x - circle.center.x) * (dot.x - circle.center.x) + (dot.y - circle.center.y) * (dot.y - circle.center.y) == circle.radius * circle.radius){
        std::cout << "Dot on circle" << std::endl;
    } else {
        std::cout << "Dot not on circle" << std::endl;
    }
}

void DotOnSquare(Square &square, Dot &dot){
     if ((dot.x == square.topl_corner.x || dot.x == square.topl_corner.x + square.side) && (dot.y == square.topl_corner.y || dot.y > square.topl_corner.y - square.side)){
        std::cout << "Dot on square" << std::endl;
    } else {
        std::cout << "Dot not on square" << std::endl;
    }
}

// пересечение фигур


int main(){
    return 0;
}

