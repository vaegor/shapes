//vector.h

#ifndef VECTOR_H_
#define VECTOR_H_

#include<algorithm>
#include<QLabel>
#include<QDebug>
#include<QString>
#include<fstream>
#include"shape.h"
#include"line.h"
#include "ellipse.h"
using std::copy;
using std::stoi;

template<class T>
class vector
{
private:
	int size;
	int capacity;
	T* elem;

public:
public:
 	vector(): size{0}, capacity{100}, elem{new T[capacity]} //default constructor
 	{
 		for(int i = 0; i < capacity; i++)
 				elem[i] = T();
 	}

 	explicit vector(int s): size{0}, capacity{s}, elem{new T[s]} //alternate constructor
 	{
 		for(int i = 0; i < capacity; i++)
 			elem[i] = T();
 	}

	vector(const vector& newVector): size{newVector.size}, capacity{newVector.capacity}, elem{new T[capacity]} //copy constructor
	{
		for(int i = 0; i < size; i++)
			elem[i] = newVector.elem[i];
	}

	vector& operator=(const vector& newVector) //copy assignment
	{
		T *p = new T[newVector.size];
		copy(newVector.elem, newVector.elem + newVector.size, p);
		delete [] elem;
		elem = p;
		size = newVector.size;
		capacity = newVector.capacity;

		return *this;
	}

		vector(const vector&& temp): size{temp.size}, capacity{temp.capacity}, elem{temp.elem} //move constructor
	{
		temp.size = 0;
		temp.capacity = 0;
		temp.elem = nullptr;
	}

		vector& operator=(vector&& temp) //move assignment
	{
		delete [] elem;
		elem = nullptr;
		elem = temp.elem;
		size = temp.size;
		capacity = temp.capacity;
		temp.elem = nullptr;
		temp.size = 0;
		temp.capacity = 100;
		return *this;
	}

	~vector() //destructor
	{
	delete[] elem;
	}

	T& operator[] (int n)
	{
		return elem[n];
	}

	const T& operator[] (int n) const
	{
	return elem[n];
	}

	int getSize() const
	{
		return size;
	}

	int getCapacity() const
	{
		return capacity;
	}

	void resize(int newsize)
	{
		reserve(newsize);
		for (int i = size; i < newsize; ++i)
			elem[i] = 0;
		size = newsize;
	}

	void reserve(int newalloc)
	{
		if(capacity <= newalloc)
			capacity = newalloc;
		else
			capacity += newalloc;
		T *p = new T[capacity];
		copy(elem, elem + size, p);
		delete [] elem;
		elem = p;
	}

	void push_back(T d)
	{
		if (capacity == 0)
			reserve(8);
		else if(size == capacity)
			reserve(2 * capacity);
		elem[size] = d;
		++size;
	}

	using iterator = T *;
	using const_iterator = const T *;

	iterator begin()
	{
		if (size == 0)
			return nullptr;
		return &elem[0];
	}

	const_iterator begin() const
	{
		if (size == 0)
			return nullptr;
		return &elem[0];
	}

	iterator end()
	{
		if (size == 0)
			return nullptr;
		return &elem[size];
	}

	const_iterator end() const
	{
		if (size == 0)
			return nullptr;
		return &elem[size];
	}

	iterator insert(iterator p, const T &val)
	{
		if(size == capacity)
			reserve(2*capacity);

		for (iterator pos = end(); pos != p; --pos)
			*pos  = *(pos - 1);
		
		size++;

		*p = val;

		return p;
	}

	iterator erase(iterator p)
	{
		if (p == end())
			return p;
		for (iterator pos = p + 1; pos != end(); ++pos)
				*(pos - 1) = *pos;
		delete(end() - 1); // delete out of scope data
		--size;
		return p;
	}
    void parser()
    {
        string data= "";
        string shapeType = "";
        int num = 0;
        int d = 0;
        string o = "";
        std::ifstream shapesFile;
        shapesFile.open("/home/cs1c/Documents/CS1Cproject-master/CS1Cofficial/shapes.txt");
        if(shapesFile.fail())
            qDebug() << "fail";
        elem = new Shape*[10];

        while(!shapesFile.eof())
        {
            //look for new shape
          getline(shapesFile,data, '-');
          //skip to ID
          getline(shapesFile, data, ' ');

          //Get ID of the shape
          getline(shapesFile, o , '\r');
          //store shape
          d = stoi(o);
          //get to shape type
          getline(shapesFile, data, ' ');
          //Get shape type
          getline(shapesFile, data, '\r');
          //store shapeType
          shapeType = data;

          if(shapeType == "Line")
          {
              int x1 = 0;
              int x2 = 0;
              int y1 = 0;
              int y2 = 0;
              elem[num] = new Line;
              // set id
              elem[num]->setID(d);
               getline(shapesFile, data, ' ');
                qDebug() << QString::fromStdString(data);
               getline(shapesFile, data, ',');
               x1 = stoi(data);
                qDebug() << QString::fromStdString(data);
               getline(shapesFile, data, ',');
               y1 = stoi(data);
               getline(shapesFile, data, ',');
               x2 = stoi(data);
               getline(shapesFile, data, '\r');
               y2 = stoi(data);
               elem[num]->setCord(x1,y1,x2,y2);
               getline(shapesFile, data, ' ');
               getline(shapesFile, data, '\r');
               elem[num]->setColor(data);
               getline(shapesFile, data, ' ');
               getline(shapesFile, data , '\r');
               d = stoi(data);
               elem[num]->setWidth(d);


          }
          num++;


          qDebug() << QString::fromStdString(data) << QString::fromStdString(shapeType);

        }
        qDebug() << num;







      //  QString b =data;
      //  qDebug() << QString::fromStdString(data);
    }

    Shape* getShapeV(const int i)
    {
        return elem[i];
    }
};

#endif /* VECTOR_H_ */




