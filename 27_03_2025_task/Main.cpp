#include <string>
#include <iostream>

// void foo();
struct Object;

struct A
{
    int number;
};

struct Object
{
    // ctor
    Object();
    //Object(bool isEmpty);
    //Object(float x, float y);
    // dector
    ~Object();

    float sum( float a );
    void log();

    bool operator==( const Object& other );
    bool operator!=( const Object& other );

    float operator[]( int index );

    float operator()();

    float x;
    float y;
    float z;
    A a;
};

float Object::operator()()
{
    return sum( 1.0f );
}

bool Object::operator==( const Object& other )
{
    return (x == other.x)
        && (y == other.y)
        && (z == other.z);
}

bool Object::operator!=( const Object& other )
{
    // return !( *this == other );
    return !operator==( other );
}

float Object::operator[]( int index )
{
    if (index == 0) {
        return x;
    }
    if (index == 1) {
        return y;
    }
    if (index == 2) {
        return z;
    }

    return -1.0f;
}

Object::Object()
{
    x = 1.0f;
    y = 2.0f;
    z = 3.0f;
    std::cout << "ctor" << std::endl;
}

Object::~Object()
{
    std::cout << "~ctor" << std::endl;
}

float Object::sum( float a )
{
    // float result = x + y + z;
    // return result;
    return x + y + z + a;
}

void Object::log()
{
    std::cout << "x: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "z: " << z << std::endl;
}

int main(int argc, char* argv[])
{
    bool isEmpty = false;
    int number = 10;

    Object obj0;
    obj0.x = 10.0f;
    obj0.a.number = number;
    obj0.log();
    // std::cout << "x: " << obj0.x << std::endl;
    // std::cout << "y: " << obj0.y << std::endl;
    // std::cout << "z: " << obj0.z << std::endl;

    Object obj1;
    obj1.log();
    std::cout << obj1.sum( 0.0f ) << std::endl;


    std::cout << obj1[999] << std::endl;
    std::cout << obj1[1] << std::endl;


    if ( obj0 == obj1 ) {
        std::cout << "Obiekty sa takie same" << std::endl;
    } else {
        std::cout << "Obiekty NIE sa takie same" << std::endl;
    }

    std::cout << obj1() << std::endl;


    return 0;
}
