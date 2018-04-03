#include <lib/pen.h>

void trigo(Pen &p, int dist){


    if(dist < 0.1)
        return;
    for(int i = 0; i < 7; i++){
        p.setColor(50, 205, 50);
        p.walk(dist);
        p.right(45);
        trigo(p,dist/5);
        p.left(90);
        trigo(p,dist/5);
        p.right(45);

    }
    p.setColor(240, 230, 140);
    p.walk(-dist*7);
}
//void quadrado(Pen &p, int dist){
//    if(dist < 2)
//        return;
//    p.setColor(rand()% 255, rand()% 255, rand()% 255);
//    p.walk(dist);
//    p.right(90);
//    quadrado(p, dist - 2);
//}


void circulos(Pen &p, int dist){
    if(dist < 1)
        return;

    p.circle(dist);
    for(int i = 0; i < 6; i++){
        p.right(60);
        p.up();
        p.walk(dist);
        p.down();
        circulos(p, dist * 0.4 );
        p.up();
        p.walk(-dist);
        p.down();
    }

}
void gelo(Pen &p, int dist){
    if(dist <3)
        return;
    p.right(72);
    p.walk(dist);
    gelo(p,dist/3);
    p.walk(-dist);
    p.right(72);
    p.walk(dist);
    gelo(p,dist/3);
    p.walk(-dist);
    p.right(72);
    p.walk(dist);
    gelo(p,dist/3);
    p.walk(-dist);
    p.right(72);
    p.walk(dist);
    gelo(p,dist/3);
    p.walk(-dist);
    p.right(72);
    p.walk(dist);
    gelo(p,dist/3);
    p.walk(-dist);
}

void fractal(){
    Pen p(800, 600);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 300);
    p.setThickness(1);


    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(50);
    //circulos(p,120);
    //espiral(p,50);
    trigo(p,60);
    //quadrado(p,150);
    //gelo(p,90);
    //espera clicar no botao de fechar
    p.wait();
}


int main(){
    fractal();


    return 0;
}
