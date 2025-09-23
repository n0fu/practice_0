#include <iostream>
#include <cmath>
#include "func.h"
#include <string>

void test(bool testfunc, std::string out){
    if (testfunc){
        std::cout << "OK " << out << std::endl; 
    } else {
        std::cout << "FAIL " << out << std::endl;
    }
}

int main(){
    std::cout << "Tests" << std::endl << std::endl;

    // Point inside circle
    {
        Circle c;
        c.center = {0, 0};
        c.radius = 5;
        Dot insidecircle = {3, 4};   // 3²+4²=25 → on boundary → NOT inside
        Dot insidecircle2 = {3, 3};  // 9+9=18 < 25 → inside
        Dot outsidecircle = {6, 0};  // 36 > 25 → outside

        test(!DotInCircle(c, insidecircle), "DotInCircle: point on boundary is not inside");
        test(DotInCircle(c, insidecircle2), "DotInCircle: point strictly inside");
        test(!DotInCircle(c, outsidecircle), "DotInCircle: point outside");
    }

    // Point inside square
    {
        Square s;
        s.topl_corner = {0, 4};
        s.side = 4;
        SquareCornersInit(s);

        Dot insidesquare = {2, 2};     // inside
        Dot onEdge = {0, 2};           // on left edge → NOT inside
        Dot corner = {0, 4};           // in corner → NOT inside
        Dot outsidesquare = {-1, 2};   // outside

        test(DotInSquare(s, insidesquare), "DotInSquare: point strictly inside");
        test(!DotInSquare(s, onEdge), "DotInSquare: point on edge is not inside");
        test(!DotInSquare(s, corner), "DotInSquare: point in corner is not inside");
        test(!DotInSquare(s, outsidesquare), "DotInSquare: point outside");
    }

    // Point on contour
    {
        Circle c = {{0,0}, 5, 0, 0};
        Dot onCircle = {5, 0};
        Dot notOnCircle = {4, 0};

        test(DotOnCircle(c, onCircle), "DotOnCircle: point on circle");
        test(!DotOnCircle(c, notOnCircle), "DotOnCircle: point not on circle");

        Square s;
        s.topl_corner = {0, 2};
        s.side = 2;
        SquareCornersInit(s);

        Dot onTop = {1, 2};      // on top side
        Dot onLeft = {0, 1};     // on left side
        Dot corner = {0, 2};     // in corner
        Dot inside = {1, 1};     // inside → not on contour

        test(DotOnSquare(s, onTop), "DotOnSquare: point on top side");
        test(DotOnSquare(s, onLeft), "DotOnSquare: point on left side");
        test(DotOnSquare(s, corner), "DotOnSquare: point in corner");
        test(!DotOnSquare(s, inside), "DotOnSquare: point inside is not on contour");
    }

    // Circle intersection
    {
        Circle c1 = {{2,0}, 3, 0, 0};
        Circle c2 = {{5,0}, 3, 0, 0}; // distance=5, r1+r2=6 → intersect
        Circle c3 = {{10,0}, 1, 0, 0}; // far away → no intersection
        Circle c4 = {{0,0}, 5, 0, 0}; // c1 inside c4, touching → intersect

        test(CirclesIntersection(c1, c2), "CirclesIntersection: intersect at 2 points");
        test(!CirclesIntersection(c1, c3), "CirclesIntersection: no intersection");
        test(CirclesIntersection(c1, c4), "CirclesIntersection: internal touching");
    }

    // Square intersection
    {
        Square s1, s2, s3;
        s1.topl_corner = {0, 2}; s1.side = 2; SquareCornersInit(s1);
        s2.topl_corner = {1, 3}; s2.side = 2; SquareCornersInit(s2); // intersect
        s3.topl_corner = {5, 5}; s3.side = 1; SquareCornersInit(s3); // no intersection

        test(SquaresIntersection(s1, s2), "SquaresIntersection: intersect");
        test(!SquaresIntersection(s1, s3), "SquaresIntersection: no intersection");
    }

    // Square-circle intersection
    {
        Square s;
        s.topl_corner = {0, 2}; s.side = 2; SquareCornersInit(s);
        Circle c1 = {{3, 1}, 1.5, 0, 0}; // touches right side
        Circle c2 = {{-2, 1}, 1, 0, 0};  // no intersection
        Circle c3 = {{1, 1}, 0.5, 0, 0}; // fully inside

        test(SquareCircleIntersection(s, c1), "SquareCircleIntersection: touching");
        test(!SquareCircleIntersection(s, c2), "SquareCircleIntersection: no intersection");
        test(SquareCircleIntersection(s, c3), "SquareCircleIntersection: circle inside");
    }

    // Figure containment

    // Circle inside circle
    {
        Circle inner = {{0,0}, 2, 0, 0};
        Circle outer = {{0,0}, 5, 0, 0};
        Circle touching = {{0,0}, 5, 0, 0}; // touching → not inside
        test(IsCircleInCircle(inner, outer), "IsCircleInCircle: strictly inside");
        test(!IsCircleInCircle(touching, outer), "IsCircleInCircle: touching is not inside");
    }

    // Square inside square
    {
        Square innerS, outerS;
        outerS.topl_corner = {0, 4}; outerS.side = 4; SquareCornersInit(outerS);
        innerS.topl_corner = {1, 3}; innerS.side = 2; SquareCornersInit(innerS);
        test(IsSquareInSquare(innerS, outerS), "IsSquareInSquare: strictly inside");
    }

    // Square inside circle
    {
        Circle bigCircle = {{0,0}, 10, 0, 0};
        Square smallSquare;
        smallSquare.topl_corner = {-1, 1}; smallSquare.side = 2; SquareCornersInit(smallSquare);
        test(IsSquareInCircle(smallSquare, bigCircle), "IsSquareInCircle: square inside circle");
    }

    // Circle inside square
    {
        Square bigSquare;
        bigSquare.topl_corner = {-5, 5}; bigSquare.side = 10; SquareCornersInit(bigSquare);
        Circle smallCircle = {{0,0}, 3, 0, 0};
        test(IsCircleInSquare(smallCircle, bigSquare), "IsCircleInSquare: circle inside square");
    }
    std::cout << "\nPress Enter to exit...";
    std::cin.get(); // Ждёт нажатия Enter
    return 0;
}