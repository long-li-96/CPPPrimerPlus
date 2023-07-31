// 在C++中，结构体可以像类一样拥有方法。事实上，结构体和类几乎一样，
// 唯一的区别是它们的默认访问权限不同。在类中，默认的访问权限是私有的（private），
// 而在结构体中，默认的访问权限是公有的（public）
#include <iostream>
struct Rectangle {
    // 成员变量
    int width, height;

    // 构造函数
    Rectangle(int w, int h) : width(w), height(h) {}

    // 成员函数 结构方法定义
    int area() {
        return width * height;
    }

    void scale(int factor) {
        width *= factor;
        height *= factor;
    }
};

int main() {
    using std::cout, std::endl;
    Rectangle rect(10, 20);
    std::cout << "Area: " << rect.area() << std::endl;  // 输出 "Area: 200"
    rect.scale(2);
    std::cout << "Area after scaling: " << rect.area() << std::endl;  // 输出 "Area after scaling: 800"
    return 0;
}
