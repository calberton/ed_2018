#include <lib/pen.h>

/**
void linha(Pen &p, int lado, int rotacao){
    if(lado < 1)
        return;
    //p.setColor(rand()%255, rand()%255, rand()%255);

    p.walk(lado);
    p.right(90 * rotacao);
    //linha(p, lado - 5, 1);

    p.setColor(rand()%255, rand()%255, rand()%255);
    linha(p, lado - 5, -1);
}
**/

void arvore(Pen &p, int lado){
    if(lado < 10){
        return;
    }
    int ang=45;
    p.walk(lado);
    p.right(ang);
    arvore(p,lado/2);
    p.walk(-lado);
    p.right(-ang*2);
    p.walk(lado);

}

void triangulo(Pen &p, int lado){
    //p.setColor(255,255,255);
    if(lado < 10){
        return;
    }
    int ang = 120;
    for(int  i = 0; i < 3; i++){
        p.walk(lado);
        p.right(ang);
        triangulo(p,lado/2);

    }
}

void quadrado(Pen &p, int lado){
    if(lado < 10){
        return;
    }

    int ang = 270;

    for(int  i = 0; i < 4; i++){
        p.walk(lado);
        p.right(ang);
        quadrado(p,lado/4);

    }

}

void trigo(Pen &p, int lado){
    if(lado<1){
        return;
    }
    int angulo = 35;

    for(int i = 0; i < 4; i++){
        p.walk(lado);
        p.right(angulo);
        trigo(p,lado/3);
        p.left(2*angulo);
        trigo(p,lado/3);
        p.right(angulo);

    }
    p.walk(-lado*4);
}



void fractal(){
    Pen p(1200, 800);
    int lado = 100;
    //coloca o pincel na posicao x 300 y 500
    //p.setXY(600, 700);

    //faz o pincel apontar pra direita
    //p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(30);

    /**
    p.circle(200);
    linha(p, 100, -1);
    **/

    //quadrado(p,lado);

    /**
    p.setXY(249.50, 100);
    p.setHeading(0);
    triangulo(p,lado*7);

    p.setColor(0,0,0);
    p.setXY(600, 700);
    p.setHeading(90);
    p.setThickness(6);
    trigo(p,lado);

    p.setColor(255,255,0);
    p.setXY(600, 700);
    p.setHeading(90);
    p.setThickness(2);
    trigo(p,lado);
    **/
    //.clear();


    /**
    for(int i = 1;i>0;i++){
        p.setThickness(rand()%12);
        p.setColor(rand()%255,rand()%255,rand()%255);
        p.setXY(600, 300);
        p.circle(340);
        p.setColor(0,0,0);
        p.circle(340);
    }
    **/

    /**
    p.setXY(600, 700);
    p.setColor(255,255,0);
    p.setHeading(90);
    arvore(p,lado*2);
    **/



    //espera clicar no botao de fechar
    p.wait();
}

int main(){
    fractal();
    return 0;
}
