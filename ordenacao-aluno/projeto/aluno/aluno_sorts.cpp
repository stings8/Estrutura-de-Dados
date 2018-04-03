#include <math.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <SFML/Graphics.hpp>

#include "../libs/sortview.h"
#include "../libs/player.h"
using namespace std;
static SortView sview;
#if 0
//void minimum_sort(std::vector<int> &vet){
//    int tam = vet.size();
//    for(int i = 0; i < tam - 1; i++){
//        for(int j = i + 1; j < tam; j++){
//            sview.show(vet, {i, j}, "gb");
//            if(vet[j] < vet[i]){
//                sview.show(vet, {i, j}, "rb");
//                std::swap(vet[i], vet[j]);
//                sview.show(vet, {i, j}, "cb");
//            }
//        }
//    }
//}

//void bubble_sort(vector<int> &vet){
//    int aux;
//    for(int end = vet.size() - 1; end > 0; end--){
//        for(int i = 0; i < vet.size() - 1; i++){
//            sview.show(vet,{i,i+1},"gb");
//            if(vet[i+1] < vet[i]){
//                sview.show(vet,{i,i+1},"rb");
//                aux = vet[i];
//                vet[i] = vet[i+1];
//                vet[i+1]= aux;
//                sview.show(vet, {i,i+1},"cb");
//            }
//        }
//    }
//}
//void selection_sort(vector<int> &vet){
//    for(int i = 0; i < vet.size(); i++){
//        int min = i;
//        for(int j = i + 1; j < vet.size(); j++){
//            sview.show(vet, {i,j}, "gb");
//            if(vet[j] < vet[min]){
//                min = j;


//            }
//        }
//        int aux = vet[i];
//        vet[i] = vet[min];
//        vet[min] = aux;
//    }
//}
//void insertion_sort(vector<int> &vet){
//    for(int i = 1; i < vet.size(); i++){
//        int aux = vet[i];
//        sview.show(vet,{i},"r");
//        for(int j = i; (j > 0) && (aux < vet[j - 1]); j--){
//            sview.show(vet, {i,j-1},"rb");
//            vet[j] = vet[j - 1];
//        vet[j - 1] = aux;
//        sview.show(vet, {i,j},"rg");
//        }
//    }
//}

//void main_sorts(){
//    srand(time(NULL));
//    my_player->autoplay = true;
//    sview.set_bar_view();
//    sview.set_thickness(8);

//    std::vector<int> vet = init_vet(70, 50, 300);
//    //selection_sort(vet);
//    //minimum_sort(vet);
//    //bubble_sort(vet);
//    insertion_sort(vet);
//    my_player->wait();

//}

//int main(){
//    main_sorts();
//}
#endif

std::vector<int> init_vet(int qtd, int min, int max){
    std::vector<int> vet;
    vet.reserve(qtd);
    for(int i = 0; i < qtd; i++){
        vet.push_back(rand() % (max - min + 1) + min);
    }
    return vet;
}

void minimum_sort(std::vector<int> &vet){
    int tam = vet.size();
    for(int i = 0; i < tam - 1; i++){
        int menor = i;
        int maior = i;
        for(int j = i + 1; j < tam; j++){
            sview.show(vet, {i, j, menor}, "gbr");

            if(vet[j] < vet[menor]){
                menor = j;
            }

            else if (vet[j] > vet[maior]){
                maior = j;
            }
        }
        sview.show(vet, {i, menor}, "rb");
        std::swap(vet[i], vet[menor]);
        sview.show(vet, {i, menor}, "cb");
    }
}


void bubble_sort(vector<int> &vet){
    int aux;
    for(int end = vet.size(); end > 0; end--){
        for(int i = 0; i < vet.size() - 1; i++){
            sview.show(vet, {i, i+1}, "rg");
            if(vet[i+1] < vet[i]){
                sview.show(vet,{i,i+1},"rb");
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                sview.show(vet, {i,i+1},"cb");
            }
        }
    }
}

void selection_sort(vector<int> &vet){
    for(int i = 0; i < vet.size(); i++){
        int min = i;
        for(int j = i + 1; j < vet.size(); j++){
            sview.show(vet,{i,j}, "gb");
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
    }
}

void insertion_sort(vector<int> &vet){
    for(int i = 0; i < vet.size(); i++){
        int aux = vet[i];
        int j = i - 1;
        sview.show(vet, {i}, "r");
        while((j >= 0) && (aux < vet[j])){
            vet[j + 1] = vet[j];
            j--;
            sview.show(vet, {j, j+1}, "gb");
        }

        vet[j + 1] = aux;

    }


}

void merger_sort(vector<int> &vet, int i, int f){
    if(f == i + 1)
        return;
    int m = (i + f) / 2;
    merger_sort(vet, i, m);
    merger_sort(vet, m, f);
    inplace_merge(vet.begin() + i, vet.begin() + m, vet.begin() + f);
    sview.show(vet, {i,m,f}, "rgb");


}
void quick_sort(vector<int> &vet, int b, int e){

    int i = b;
    int f = e;
    int pivo = vet[i];
    while(i <= f){

        while(vet[f] > pivo && f > b)
            f--;
        while(vet[i] < pivo && i < e)
            i++;
        if(i <= f){
            swap(vet[i++], vet[f--]);
        }
    }
    if(i < e)
        quick_sort(vet, i, e);
    if(f > b)
        quick_sort(vet, b, f);
    sview.show(vet, {i,pivo,f}, "rgb");

}

void bucket_sort(vector<int> &vet){
    vector<int> aux[vet.size()];

    for(int i = 0; i < vet.size(); i++){
        int b = vet.size() * vet[i];
        aux[b].push_back(vet[i]);
    }
    for (int i = 0; i < vet.size(); i++)
        sort(aux[i].begin(), aux[i].end());

    int indc = 0;
    for(int i = 0; i < vet.size(); i++)
        for(int j = 0; j < aux[i].size(); j++)
            vet[indc++] = aux[i][j];

    for(int i = 0; i < vet.size(); i++){
    cout << vet[i];
    }

}



void sorts(){
    srand(time(NULL));
    my_player->autoplay = true;
    sview.set_bar_view();
    sview.set_thickness(8);

    std::vector<int> vet = init_vet(70, 50, 300);
    //bubble_sort(vet);
    selection_sort(vet);
    //insertion_sort(vet);
    //merger_sort(vet, 0, vet.size());
    //quick_sort(vet, 0, vet.size());
    //bucket_sort(vet);
    my_player->wait();

}

int main(){
    sorts();
}


