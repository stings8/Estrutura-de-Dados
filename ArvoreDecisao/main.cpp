#include <iostream>
#include <vector>

using namespace std;

namespace aluno{

struct DcNode{
    string key; //resposta
    string value;//pergunta ou afirmacao
    vector<DcNode*> filhos;

    DcNode(string key = "", string value = ""){
        this->key = key;
        this->value = value;
    }
};

struct DnTree{
    DcNode * root;
    DnTree(){
        root = new DcNode("", "vazio");
    }
    ~DnTree(){
        clear(root);
        root = nullptr;
    }

    void clear(DcNode * node){
        for(auto filho : node->filhos)
            clear(filho);
        delete node;
    }

    void _show(DcNode * node, string heranca, int num, DcNode * ref){
        char focus = (node == ref)?'>':' ';
        cout << focus;
        for(auto c : heranca.substr(0, heranca.size() - 1))
            cout << ((c == 'f')?" ":"│") << string(3, focus);

        if(node != root){
            if(heranca.back() == 'f')//no do fim
                cout << "└───" << num << ": " << node->key << "; " ;
            else//no do meio
                cout << "├───" << num << ": " << node->key << "; " ;
        }cout << node->value << endl;
        if(node->filhos.empty())
            return;
        int qtd = node->filhos.size();
        for(int i = 0; i < qtd - 1; i++){
            _show(node->filhos[i], heranca + "m", i, ref);
        }
        _show(node->filhos.back(), heranca + "f", qtd - 1, ref);
    }

    void alterar(DcNode * node){
        while(true){
            _show(root, "", 0, node);
            cout << "add _texto; back; go _num; key _k; value _v;" << endl;
            string op;
            cin >> op;
            if(op == "add"){
                string texto;
                getline(cin, texto);
                node->filhos.push_back(new DcNode(texto.substr(1), "vazio"));
            }
            if(op == "go"){
                int num;
                cin >> num;
                alterar(node->filhos[num]);
            }
            if(op == "back"){
                return;
            }
            if(op == "key"){
                string texto;
                getline(cin, texto);
                node->key = texto.substr(1);
            }
            if(op == "value"){
                string texto;
                getline(cin, texto);
                node->value = texto.substr(1);
            }
        }
    }
};

} //namespace aluno

int main(){
    aluno::DnTree tree;
    tree.alterar(tree.root);
    return 0;
}
