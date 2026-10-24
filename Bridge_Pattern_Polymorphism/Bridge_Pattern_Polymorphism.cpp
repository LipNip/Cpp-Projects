#include <iostream>
#include <string>
using namespace std;

class Point {
	int x, y;
public:
	Point() {}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void Print() {
		cout << "x: " << this->x << " ";
		cout << "y: " << this->y << "\n";
	}
};

class Size {
	int width, height;
public:
	Size() {}
	Size(int width, int height) {
		this->width = width;
		this->height = height;
	}
	void Print() {
		cout << "width: " << this->width << " ";
		cout << "height :" << this->height << "\n";
	}
};

class Graphics {
public:
	void DrawPolygon(string color, string line, Point* points) {
		cout << "Draw Polygon!\n";
	}

	void DrawRectangle(string color, string line, Point* location, Size* size) {
		cout << "Draw Rectangle!\n";
	}

	void DrawTriangle(string color, string line, Point* points) {
		cout << "Draw Triangle!\n";
	}

	void DrawCircle(string color, string line, Point* center, double radius) {
		cout << "Draw Circle!\n";
	}
};

class LineStyle {
public:
	virtual ~LineStyle() {}			// В коді були витоки памяті, я їх пофіксив
	virtual string getLineStyle() {
		return "Solid";
	}
};

class DashLine : public LineStyle {
public:
	string getLineStyle() override {
		return "DashLine";
	}
};

class DotLine : public LineStyle {
public:
	string getLineStyle() override {
		return "DotLine";
	}
};

class DashDotLine : public LineStyle {
public:
	string getLineStyle() override {
		return "DashDotLine";
	}
};

class Shape {
protected:
	Graphics* graphics = nullptr;
	string line;
	string color;
public:
	Shape() {
		this->graphics = new Graphics();
	}
	virtual void Draw(string color, LineStyle* lineStyle) {
		this->color = color;
		this->line = lineStyle->getLineStyle();
	}

	virtual void PrintShapeInfo() {
		cout << this->color << "\n";
		cout << this->line << "\n";
	}

	virtual ~Shape() { delete graphics; }
};

class Polygon : public Shape {
	Point* points;
public:
	Polygon() {
		points = new Point[5]
		{
			 Point(10, 10),
			 Point(10, 100),
			 Point(50, 65),
			 Point(100, 100),
			 Point(85, 40)
		};
	}

	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);
		this->graphics->DrawPolygon(color, line, points);
		this->PrintShapeInfo();
	}

	void PrintShapeInfo() override {
		Shape::PrintShapeInfo();
		cout << "Coords: \n";
		for (int i = 0; i < 5; i++)
		{
			this->points[i].Print();
		}
	}

	~Polygon() override { delete[] points; }
};

class Rectangle : public Shape {
	Point* location = new Point(10, 20);
	Size* size = new Size(100, 200);
public:
	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);
		this->graphics->DrawRectangle(color, line, location, size);
		this->PrintShapeInfo();
	}

	void PrintShapeInfo() override {
		Shape::PrintShapeInfo();
		location->Print();
		size->Print();
	}

	~Rectangle() override { delete location; delete size; }
};

class Triangle : public Shape {
	Point* points;
public:
	Triangle() {
		points = new Point[3]
		{
			 Point(50, 50),
			 Point(50, 200),
			 Point(200, 200)
		};
	}

	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);
		this->graphics->DrawTriangle(color, line, points);
		this->PrintShapeInfo();
	}

	void PrintShapeInfo() override {
		Shape::PrintShapeInfo();
		cout << "Coords: \n";
		for (int i = 0; i < 3; i++) {
			this->points[i].Print();
		}
	}

	~Triangle() override { delete[] points; }
};

class Circle : public Shape {
	Point* center;
	double radius;
public:
	Circle() {
		this->center = new Point(50, 50);
		this->radius = 30;
	}

	void Draw(string color, LineStyle* lineStyle) override {
		Shape::Draw(color, lineStyle);
		this->graphics->DrawCircle(color, line, center, radius);
		this->PrintShapeInfo();
	}

	void PrintShapeInfo() override {
		Shape::PrintShapeInfo();
		this->center->Print();
		cout << this->radius;
	}

	~Circle() override { delete center; }
};

class Context {
public:
	void Draw(Shape* shape, LineStyle* lineStyle, string color)
	{
		shape->Draw(color, lineStyle);
		delete shape;
		delete lineStyle;
	}
};

int main()
{
	Context context;

	context.Draw(new Rectangle(), new DashLine(), "Red");
	cout << string(100, '-') << "\n";
	context.Draw(new Triangle(), new DotLine(), "Green");
	cout << string(100, '-') << "\n";
	context.Draw(new Polygon(), new DotLine(), "Blue");
	cout << string(100, '-') << "\n";
	context.Draw(new Circle(), new DashDotLine(), "Black");
	cout << "\n\n";
	return 0;
}