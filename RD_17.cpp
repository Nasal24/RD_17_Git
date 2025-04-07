#include <iostream>
#include <stdexcept>

class Vector2d {
private:
    float x = 0.0f;
    float y = 0.0f;
    static int instance_count;

public:
 
    Vector2d() : x(0.0f), y(0.0f) { ++instance_count; }
    Vector2d(float x, float y) : x(x), y(y) { ++instance_count; }
    Vector2d(const Vector2d& other) : x(other.x), y(other.y) { ++instance_count; }


    ~Vector2d() { --instance_count; }


    Vector2d& operator=(const Vector2d& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }
        return *this;
    }


    Vector2d operator+(const Vector2d& other) const {
        return Vector2d(x + other.x, y + other.y);
    }

    Vector2d operator-(const Vector2d& other) const {
        return Vector2d(x - other.x, y - other.y);
    }


    float& operator[](std::size_t idx) {
        if (idx == 0) return x;
        if (idx == 1) return y;
        throw std::out_of_range("Index must be 0 or 1");
    }

    const float& operator[](std::size_t idx) const {
        if (idx == 0) return x;
        if (idx == 1) return y;
        throw std::out_of_range("Index must be 0 or 1");
    }


    friend std::ostream& operator<<(std::ostream& os, const Vector2d& vec) {
        os << "{" << vec.x << "; " << vec.y << "}";
        return os;
    }


    static int getInstanceCount() {
        return instance_count;
    }
};


int Vector2d::instance_count = 0;


int main() {
    Vector2d a(1.2f, 5.6f);
    Vector2d b(3.4f, -2.1f);
    Vector2d c = a + b;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c = a + b: " << c << std::endl;

    std::cout << "c[0]: " << c[0] << ", c[1]: " << c[1] << std::endl;
    std::cout << "Active instances: " << Vector2d::getInstanceCount() << std::endl;

    return 0;
}
