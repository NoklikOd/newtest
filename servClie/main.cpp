//#include <iostream>
//#include <windows.h>
//#include "../2048/Random.hpp"

#include "mapa.hpp"
#include <iostream>
using namespace std;

int main(){
    interval_map<int,char> mapa('A');
    for(int i=0;i<10;i++){
        cout<<i<<" - \'"<<mapa[i]<<"\'"<<endl;
    }
    mapa.assign(2,8,'B');
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<i<<" - \'"<<mapa[i]<<"\'"<<endl;
    }
    

    /*
    Random* rand = new Random();
    const char doodle='#';
    const char still='-';
    const int stil=5;
    const int shirina=10;
    const int visota=20;
    rand->setMax(shirina);
    int jump=5;
    int power=3;
    char** map=new char*[visota];
    for(int i=0;i<visota;i++){
        map[i]=new char[shirina];
    }
    
    bool game=true;
    while(game != false){


        Sleep(500);
        system("CLS");
    }*/
    return 0;
}