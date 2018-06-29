#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;

struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == cursor)
                ss << "_";
            ss << (*it);
        }
        if(cursor == texto.end())
            ss << "_";
        return ss.str();
    }
};

int main(){
    list<Ambiente> ambientes;
    list<Ambiente> ambcont;
    list<Ambiente>::iterator ambite;
   Ambiente amb;

    amb.texto.push_back('>');

    ambientes.push_back(amb);
    ambcont.push_front(amb);
    ambite = ambientes.end();

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                janela.close();

            if(event.type == sf::Event::KeyPressed){
                            if(event.key.control && (event.key.code == sf::Keyboard::Z)){
                                if(event.key.control){
                                    if(ambite != ambientes.begin() && !ambientes.empty()){
                                        cout << "control z" << endl;
                                        ambcont.push_front(amb);
                                        ambientes.pop_back();
                                        if(amb.cursor != amb.texto.begin())
                                            amb.cursor--;

                                        ambite--;
                                        amb = *ambite;
                                    }
                                }
                            }

                            else if(event.key.control && (event.key.code == sf::Keyboard::R)){
                                if(event.key.control){
                                    if(ambite != ambientes.end() && !ambcont.empty()){
                                        cout << "control r" << endl;
                                        ambite++;
                                        if(ambite == ambientes.end())
                                            ambite--;

                                        ambientes.push_back(*ambcont.begin());
                                        amb = *ambcont.begin();
                                        ambcont.pop_front();
                                    }
                                }
                            }

                            else if(event.key.code == sf::Keyboard::Return){
                                if(event.key.control)
                                    cout << "enter" << endl;
                                    amb.texto.insert(amb.cursor,'\n');
                                    ambientes.push_back(amb);
                                    ambite++;
                            }

                            else if((event.key.code >= sf::Keyboard::A) &&
                               (event.key.code <= sf::Keyboard::Z)){
                                char tecla = (event.key.code - sf::Keyboard::A) + 'a';
                                cout << tecla << endl;
                                amb.texto.insert(amb.cursor, tecla);
                                ambientes.push_back(amb);
                                ambite++;
                            }

                            else if((event.key.code == sf::Keyboard::Space)){
                                cout << "espaco" << endl;
                                amb.texto.insert(amb.cursor, ' ');
                                ambientes.push_back(amb);
                                ambite++;
                            }

                            else if(event.key.code == sf::Keyboard::BackSpace){
                                cout << "backspace" << endl;
                                if(amb.cursor != amb.texto.begin()){
                                    amb.texto.erase(amb.cursor++,amb.cursor--);
                                    ambientes.push_back(amb);
                                    ambite++;
                                }
                            }

                            else if(event.key.code == sf::Keyboard::Delete){
                                cout << "delete" << endl;
                                if(amb.cursor != amb.texto.end()){
                                    amb.texto.erase(amb.cursor++);
                                    ambientes.push_back(amb);
                                    ambite++;
                                }
                            }

                            else if(event.key.code == sf::Keyboard::Left){
                                if(amb.cursor != amb.texto.begin())
                                    amb.cursor--;
                            }

                            else if(event.key.code == sf::Keyboard::Right){
                                if(amb.cursor != amb.texto.end())
                                    amb.cursor++;
                            }
                        }
                    }

                    auto pos = sf::Vector2f(30, 50);
                    janela.clear();
                    janela.draw(sfText(pos, amb.toString(), sf::Color::Green, 30));
                    janela.display();
                }
                return 0;
            }
