#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
int main(){
    std::srand(std::time(0));
    int s=0;
    int n=-1;
    std::string c;
    std::cout<<"**Black Zane GAME**\n";
    while(n!=0){
        std::cout<<"choisissez une boule de coleur(verte,rouge,jaune)\n";
        std::cin>>c;
        if (c!="verte" && c!="rouge" && c!="jaune")
        {
            std::cout<<"veuillez choisir une boule valide -_-\n";
            continue;
        }
        n=std::rand()%101;
        std::cout<<"vous avez tirez la boule de couleur "<<c<<" qui possède le numéro "<<n<<"\n";
        if(n!=0){
            s+=n;
        }
        else{
            std::cout<<"vous avez tirez une boule de numéro 0 fin du jeu\n";
        }
        std::cout<<"votre score est de "<<s<<"\n";
        
    }
}