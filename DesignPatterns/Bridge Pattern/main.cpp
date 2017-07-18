#include <iostream>
using namespace std;


class Color{
	public:
		virtual void showColor() = 0;	
};

class RedColor : public Color{
	public:
		// RedColor();
		// ~RedColor();
		void showColor(){
			cout << "Red" << endl;
		}
};

class BlueColor : public Color{
	public:
		// BlueColor();
		// ~BlueColor();
		void showColor(){
			cout << "Blue" << endl;
		}
};

class Shape{
	public:
		Shape(Color* color) : m_color(color){};
		~Shape();
		virtual void showShape() = 0;
		virtual void showColor() = 0;
	protected:
		Color* m_color;
};

class Circle : public Shape{
	public:
		Circle(Color* color) : Shape(color){};
		~Circle(){};
		void showShape(){
			cout << "Circle" << endl;
		}
		void showColor(){
			m_color->showColor();
		}
};

class Rect : public Shape{
	public:
		Rect(Color* color) : Shape(color){
			m_color = color;
		};
		~Rect();
		void showShape(){
			cout << "Rect" << endl;
		}
		void showColor(){
			m_color->showColor();
		}
};


int main(int argc, char const *argv[]){
	Color* redColor = new RedColor();
	Color* blueColor = new BlueColor();

	Shape* circle = new Circle(redColor);
	Shape* rect = new Rect(blueColor);

	circle->showShape();
	circle->showColor();

	rect->showShape();
	rect->showColor();
	
	return 0;
}

