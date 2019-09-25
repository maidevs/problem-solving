//*

#include<iostream>
class Point
{
	int x, y, z;

	friend std::ostream &operator << (std::ostream & output, const Point &p)
	{
		return output << p.x << " " << p.y << " " << p.z;
	}

	friend std::istream &operator >> (std::istream & input, Point &p)
	{
		input >> p.x;
		input >> p.y;
		input >> p.z;
		return input;
	}

};

class Rectangle
{
	int length, breadth;

	friend std::ostream &operator << (std::ostream & output, const Rectangle &rec)
	{
		output << rec.length << " " << rec.breadth;
		return output;
	}

	friend std::istream &operator >> (std::istream & input, Rectangle &rec)
	{
		input >> rec.length;
		input >> rec.breadth;
		return input;
	}

};

class Triangle
{
	int base, height;

	friend std::ostream &operator << (std::ostream & output, const Triangle &t)
	{
		output << t.base << " " << t.height;
		return output;
	}

	friend std::istream &operator >> (std::istream & input, Triangle &t)
	{
		input >> t.base;
		input >> t.height;
		return input;
	}
};

int main() {
	Point p;
	Triangle t;
	Rectangle r;

	std::cin >> p >> t >> r;
	std::cout << p << " " << t << " " << r << std::endl;

	std::cin >> p >> r >> t;
	std::cout << p << " " << r << " " << t << std::endl;

	std::cin >> r >> t >> p;
	std::cout << r << " " << t << " " << p << std::endl;

	std::cin >> r >> p >> t;
	std::cout << r << " " << p << " " << t << std::endl;

	std::cin >> t >> r >> p;
	std::cout << t << " " << r << " " << p << std::endl;

	std::cin >> t >> p >> r;
	std::cout << t << " " << p << " " << r << std::endl;

}