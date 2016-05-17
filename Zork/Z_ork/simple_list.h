#ifndef _SIMPLE_LIST_
#define _SIMLPE_LIST_
//VECTOR OF NODES
template<class type>
class list{
public:

	//DATA
	struct node{
		type data;

		node* next = nullptr;

		//constructor
		node(type data) :data(data) {}
	};

	node* first_element = nullptr;

	//FUNCTIONS
	//empty function
	bool empty(){
		return first_element == nullptr;

	}
	bool clean(){
		while (first_element){
			pop_back();
		}
		return true;
	}
	//get size function
	unsigned int get_size(){
		node* temp = first_element;
		unsigned int size = 0;
		while (temp){
			size++;
			temp = temp->next;
		}
		return size;
	}
	//last node function
	node* last_element(){
		node* temp = first_element;
		if (first_element){
			while (temp->next != nullptr){
				temp = temp->next;
			}
		}
		return temp;
	}

	//push.back function
	void push_back(const type& element_added){
		node*last = last_element();
		node*added = new node(element_added);
		if (empty()){
			first_element = added;
		}
		else last->next = added;
	}

	//push.front function
	void push_front(const type& element_added){
		node*added = new node(element_added);
		added->next = first_element;
		first_element = added;
	}

	//pop.back function
	bool pop_back(){
		if (empty() == false && get_size()>1){
			node*pre_last = first_element;
			for (unsigned int k = get_size() - 1; k > 1; k--){
				pre_last = pre_last->next;
			}
			delete last_element();
			pre_last->next = nullptr;
			return true;

		}
		else if (!empty()){
			node*last = first_element;
			first_element = nullptr;
			delete first_element;
			return true;
		}
	}

	//pop.front function
	bool pop_front(){
		if (empty() == false){
			node*temp = first_element;
			first_element = first_element->next;
			delete temp;
			return true;
		}
		else return true;
	}
	//insert position
	bool insert(unsigned int position, const type& to_add){
		if (position == 0){
			push_front(to_add);
			return true;
		}
		else if (position == get_size()){
			push_back(to_add);
			return true;
		}
		else if (position < get_size() && position > 0){
			node* temp = first_element;
			node* pre_position = first_element;
			node* added = new node<type>(to_add);
			while (position){
				temp = temp->next;
				position--;
				if (position){
					pre_position = pre_position->next;
				}
			}
			pre_position->next = added;
			added->next = temp;
			return true;
		}
		else return false;
	}
	//insert node
	bool insert_node(unsigned int position, node& added){
		if (added.data){
			node*to_add = new node(added.data);
			if (position == 0){
				to_add->next = first_element;
				first_element = to_add;
				return true;
			}
			else if (position == get_size() - 1){
				node*last = last_element();
				last->next = to_add;
				return true;
			}
			else if (position < get_size() - 1 && position > 0){
				node*pre_position = first_element;
				node* temp = first_element;
				while (position){
					temp = temp->next;
					position--;
					if (position){
						pre_position = pre_position->next;
					}
				}
				to_add->next = temp;
				pre_position->next = to_add;
				return true;
			}
		}
		else return false;
	}
	//erase position
	bool erase(unsigned int position){
		if (position == get_size() - 1){
			pop_back();
			return true;
		}
		else if (position == 0){
			pop_front();
			return true;
		}
		else if (position < get_size() && position >= 0 && !empty()){
			node*pre_position = first_element;
			node*temp = first_element;
			while (position){
				temp = temp->next;
				position--;
				if (position){
					pre_position = pre_position->next;
				}
			}
			pre_position->next = temp->next;
			delete temp;
			temp = nullptr;
			return true;
		}
		else return false;
	}

	//erase node
	node* erase_node(node* to_delete){
		node*pre_temp = first_element;
		node*deleted = new node(to_delete->data);
		if (to_delete == last_element()){
			pop_back();
		}
		else if (to_delete == first_element){
			pop_front();
		}
		else{


			while (pre_temp->next != to_delete){
				pre_temp = pre_temp->next;
			}
			pre_temp->next = to_delete->next;
			delete to_delete;
		}
		to_delete = nullptr;
		return deleted;
	}

};


#endif