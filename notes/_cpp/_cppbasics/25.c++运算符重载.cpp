#include<iostream>
#include<string>

class human {
public:
	int x;
	int y;
	human(int x1, int y1) :x{ x1 }, y{ y1 }{};
	human Add(const human& other) {
		return human(x + other.x, y + other.y);
	}
	human Mutil(const human& other) {
		return human(x * other.x, y * other.y);
	}
	human operator+(const human& other) {
		return Add(other);
	}
	human operator*(const human& other) {
		return Mutil(other);
	}
	bool operator==(const human& other) {
		return x == other.x && y == other.y;
	}
};
std::ostream& operator<<(std::ostream& stream, const human& other) {
	
	std::cout << "x:" << other.x << "y:" << other.y << std::endl;
	return stream;
}

int main() {
	human h1(1, 1);
	human h2(2, 2);
	human h3 = h1.Add(h2).Mutil(h2);
	human h4 = h1 + h2 * h2;

	bool equal = h1 == h2;

	std::cout << h3 << std::endl;
	return  0;
}