#include <iostream>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * next;
    Node(int value = 0,
         Node * next = nullptr){
        this->value = value;
        this->next = next;
    }
};

//class DList;//forward declaration
//class It {
//private:
//    Node * node;
//public:
//    It(Node * node){
//        this->node = node;
//    }
//    void operator++(int){
//        node = node->next;
//    }
//    void operator--(int){
//        node = node->prev;
//    }
//    int& operator*(){
//        return node->value;
//    }
//    bool operator!=(It other){
//        return node != other.node;
//    }
//    friend class DList;
//};

struct SList{
    Node * head;

    SList(){
        head = nullptr;
    }

//    ~SList(){
//        clear(begin(), end());
//        delete(head);
//        delete(tail);
//    }

    //gerar a string que corresponde a estrutura de dados
//    string serialize() {
//        stringstream ss;
//        auto node = head->next;
//        while(node != tail){
//            ss << node->value << " ";
//            node = node->next;
//        }
//        return ss.str();
//    }

//    SList(string serial){
//        head = new Node;
//        tail = new Node;
//        auto last = head;
//        stringstream ss(serial);
//        int value;
//        while(ss >> value){
//            auto node = new Node(value, last);
//            last->next = node;
//            last = node;
//        }
//        last->next = tail;
//        tail->prev = last;
//    }

    void _clear(Node * node){
        if(node->next == nullptr)
            delete node;
        _clear(node->next);
        delete(node);
    }
    void clear(){
        _clear(head);
        head = nullptr;
    }

//    void insert(It it, int value){
//        Node * pos = it.node;

//        auto node = new Node(value, pos->prev, pos);
//        pos->prev->next = node;
//        pos->prev = node;
//    }

    void push_back(int value){
        if(head == nullptr){
            head = new Node(value);
            return;
        }
        auto node = head;
        while(node->next != nullptr)
            node = node->next;
        node->next = new Node(value);
    }

    Node * _rpush_back(Node * node, int value){
        if(node == nullptr)
            return new Node(value);
        node->next = _rpush_back(node->next, value);
        return node;
    }

    void rpush_back(int value){
        head = _rpush_back(head, value);
    }

    void push_front(int value){
        auto node = new Node(value, head);
        head = node;
    }


    void inserirOrdenado (int value){

        if(head == nullptr)
            head = new Node(value);
        if(head->value > value)
            head = new Node(value, head);
        auto node = head;
        while(node->next != nullptr){
            if(node->next->value > value){
                node->next = new Node(value, node->next);
                return;
            }
            node = node->next;
        }

        node->next = new Node(value);

    }

    Node * _rinserirOdernado(Node * node, int value){
        if(node == nullptr || (node->value >= value))
    }



//    //begin primeiro nó valido
//    It begin(){
//        return It(head->next);
//    }

//    //um depois do ultimo valido
//    It end(){
//        return It(tail);
//    }

    int size(){
        auto node = head;
        int cont = 0;
        while(node != nullptr){
            cont++;
            node = node->next;
        }
        return cont;
    }

    int rsize(Node * node){
        if(node == nullptr)
            return 0;
        return 1 + rsize(node->next);
    }

//    It find(int value){
//        auto node = head->next;
//        while(node != tail){
//            if(node->value == value)
//                return It(node);
//            node = node->next;
//        }
//        return It(tail);
//    }

//    //apaga it e retorna quem ficou no lugar dele
//    It erase(It it){
//        auto node = it.node;
//        auto prox = node->next;
//        node->next->prev = node->prev;
//        node->prev->next = node->next;
//        delete(node);
//        return prox;
//    }

    bool erase(int value){
        if(head == nullptr)
            return false;
        if(head->value == value){
            auto vai_morrer = head;
            head = head->next;
            delete vai_morrer;
            return true;
        }
        auto node = head;
        while(node->next != nullptr){
            if(node->next->value == value){
                auto vai_morrer = node->next;
                node->next = node->next->next;
                delete vai_morrer;
                return true;
            }
        }
        return false;
    }

#define IS_SAD 1
#if IS_SAD
    Node * _rerase(Node * node, int value, bool *result){
        if(node == nullptr){
            *result = false;
            return nullptr;
        }
        if(node->value == value){
           auto next = node->next;
           delete node;
           *result = true;
           return next;
        }
        node->next = _rerase(node->next, value, result);
        return node;
    }

    bool rerase(int value){
        bool result;
        head = _rerase(head, value, &result);
        return result;
    }
#else
    pair<Node *, bool> _rerase(Node * node, int value){
        if(node == nullptr){
            return make_pair<nullptr, false>;
        }
        if(node->value == value){
           auto next = node->next;
           delete node;
           return make_pair(next, true);
        }
        auto par = _rerase(node->next, value);
        node->next = par.first;
        return make_pair(node, par.second);
    }

    bool rerase(int value){
        auto par = _rerase(head, value);
        head = par.first;
        return par.second;
    }
#endif

    void pop_front(){
        if(head == nullptr)
            return;
        auto vai_morrer = head;
        head = head->next;
        delete vai_morrer;
    }

    void pop_back(){
        if(head == nullptr)
            return;
        if(head->next == nullptr){
            delete head;
            head = nullptr;
            return;
        }
        auto node = head;
        while(node->next->next != nullptr)
            node = node->next;
        delete node->next;
        node->next = nullptr;
    }

    Node* _rpop_back(Node * node){
        if(node->next == nullptr){
            delete node;
            return nullptr;
        }
        node->next = _rpop_back(node->next);
        return node;
    }

    void rpop_back(){
        if(head != nullptr)
            head = _rpop_back(head);
    }

    bool isEmpty(){
        return head == nullptr;
    }

    int& front(){
        return head->value;
    }

    int& _back(Node * node){
        if(node->next == nullptr)
            return node->value;
        return _back(node->next);
    }

    int& back(Node * node){

        static int dummy = 0;
        if(node == nullptr)
            return dummy;
        return _back(head);
    }

//    string toString(){
//        string saida = "[" + this->serialize();
//        if(saida.size() > 1)
//            saida.back() = ']';
//        else
//            saida += "]";
//        return saida;
//    }
};



int main(){
    SList list;

    list.inserirOrdenado(3);
    list.inserirOrdenado(1);
    list.inserirOrdenado(8);
    list.inserirOrdenado(3);

    auto node = list.head;


    return 0;
}
