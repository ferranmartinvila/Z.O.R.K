#include<stdio.h>
#ifndef _dinamic_array_
#define _dinamic_array_
template<class type>
class vector{
private:

	unsigned int capacity;
	unsigned int elements;
public:
	type*buffer;


	//copy constructor
	vector(const vector& copy){
		elements = copy.elements;
		buffer = new type[elements];
		for (unsigned int i = 0; i <= elements-1; i++){
			buffer[i] = copy.buffer[i];
		}
	}

	//standar constructor
	vector(){
		capacity = 6;
		elements = 0;
		buffer = new type[capacity];
	}

	//push back
	void push_back(const type& element){
		if (elements == capacity){
			capacity *= 2;
			type *copy = new type[capacity];
			for (unsigned int k = 0; k < elements; k++){
				copy[k] = buffer[k];
			}
			copy[elements] = element;
			elements++;
			delete[] buffer;
			buffer= copy;
		}
		else{
			buffer[elements] = element;
			elements++;
		}
	}

	//push front
	void push_front(const type& element){
		if (elements + 1 == capacity){
			capacity = capacity * 2;;
			type *copy = new type[capacity];
			for (unsigned int k = 0; k < elements; k++){
				copy[k] = buffer[k];
			}
			delete[] buffer;
			buffer = copy;
		}
		for (int k = elements; k > 0; k--){
			buffer[k + 1] = buffer[k];
		}
		buffer[0] = element;
		elements++;
	}

	//empty
	bool empty(){
		return elements == 0;
	}

	//clean
	void clean(){
		buffer = nullptr;
		elements = 0;
	}

	//size
	unsigned int get_size(){
		return elements;
	}

	//capacity
	unsigned int get_capacity(){
		return capacity;
	}

	//pop_back
	void pop_back(){
		buffer[elements] = nullptr;
		elements--;
	}

};
#endif