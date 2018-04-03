#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum State {Vazio, Existe, Removido};

struct Node {
    int value;
    State state;

    Node() = default;

    Node(int value){
        this->state = Existe;
        this->value = value;
    }

    bool equals(int value){
        if(this->state == Existe)
            if(this->value == value)
                return true;
        return false;
    }
};


class Hash {
    Node * _data;
    int _capacity;
    int _size;

public:
    Hash(int capacity){
        this->_capacity = capacity;
        this->_data = new Node[capacity];
        this->_size = 0;
    }

    ~Hash(){
        delete [] this->_data;
        this->_data = nullptr;
    }


    bool inserir(int value){
        int ind = search(value);
        if(this->_data[ind].equals(value))
            return false;

        this->_data[ind] = Node(value);
        this->_size++;

        if(this->_size > (this->_capacity / 2) ){
            reinserir_todos(this->_capacity * 2);
        }

    }

    bool remover(int value){
        int ind = search(value);
        if(!this->_data[ind].equals(value))
            return false;
        this->_data[ind].state = Removido;
        this->_size--;
    }

    void reinserir_todos(int capacity){
        auto aux = this->_data;

        int max = _capacity;

        _capacity = capacity;

        _data = new Node[capacity];
        _size = 0;

        for(int i = 0; i < max; i++){
            if(aux[i].state == Existe)
                inserir(aux[i].value);
        }

        delete [] aux;

}

int search(int value){
    int base = value % this->_capacity;
    int i = 0;
    int ind = base;

    int idel = -1;

    while(!(this->_data[ind].equals(value)) &&
          !(this->_data[ind].state == Vazio) &&
          (i < this->_capacity)){
        if(idel == -1)
            if(this->_data[ind].state == Removido)
                idel = ind;
        i++;
        ind = (base + i) % this->_capacity;
    }

    if(this->_data[ind].equals(value))
        return ind;
    if(idel != -1)
        return idel;
    return ind;

}


//return se existe ou não
bool exists(int value){
    return this->_data[search(value)].equals(value);

}

    void show(){
        for(int i = 0; i < _capacity; i++){
            cout << "["  << i << " : " << this->_data[i].value << "]";
        }
        cout << endl;
    }

};

int main()
{
    int x;
    Hash table(4);
    while (true) {
       table.show();
       cin >> x;
       table.inserir(x);
    }


    return 0;
}
