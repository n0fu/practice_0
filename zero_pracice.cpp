#include <iostream>
#include <cmath>

struct Dot{
    int dot_cord[2];
};

void InitDot(Dot &dot){
    std::cout << "Введите координаты точки";
    for (int i = 0; i < 2; i++){
        std::cin >> dot.dot_cord[i];
    }
};

void ShowDot(Dot dot){
    for (int i = 0; i < 2; i++){
        std::cout <<  dot.dot_cord[i] << " ";
    }
};

int main(){
    Dot dot_prototype;
    InitDot(dot_prototype);
    ShowDot(dot_prototype);
    return 0;
}

