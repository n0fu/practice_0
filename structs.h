
struct Dot{           
    double x;
    double y;
};

// круг
struct Circle{
    Dot center;
    double radius;
    double square;
    double len;
};

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

