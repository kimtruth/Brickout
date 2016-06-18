#ifndef IOBJECT_H
#define IOBJECT_H
class IObject{
public:
	IObject(){}
	IObject(int x, int y, char * shape);
	virtual ~IObject();

	int x, y;
	char * shape;

	virtual void Move() = 0; //pure virtual function
	void Render();
	void Clear();
};
#endif