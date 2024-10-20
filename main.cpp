#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <conio.h>
#include <chrono>
#include <thread>
#include <set>

using namespace std;

struct tiuringoMasina1 //vienjuoste tiuringo masina
{
    char simbPakeitimas;
    char kryptis;
    string naujaBusena;
};

struct tiuringoMasina2 //dvijuoste tiuringo masina
{
    char simbPakeitimas1;
    char simbPakeitimas2;
    char kryptis1;
    char kryptis2;
    string naujaBusena;
};

void Clear() { cout << "\x1B[2J\x1B[H"; }

int speedFunk()
{
    int temp{};
    cout << "select speed in miliseconds (0-1000, 0 if full speed): ";
    cin >> temp;
    while (true)
    {
        if (temp > 1000 || temp < 0)
        {
            cout << "neteisingas speed, try again: "; cin >> temp; 
        }
        else
            return temp;
    }
}

void veikimas1(string juosta, int pozicija, map<pair<string, char>, tiuringoMasina1> komandos, set<string> busenos)
{
    string busena = "0";
    string paskbusena{"0"};
    int speed = speedFunk();
    bool isKeyPressed=0;
    while (komandos.find({busena, juosta[pozicija - 1]}) != komandos.end() && juosta.length() < juosta.length()*3 && !kbhit())
    {
        string arrow = "   ";
        for (int i = 0; i < juosta.length(); i++)
        {
            arrow += " ";
        }
        tiuringoMasina1 komanda = komandos[{busena, juosta[pozicija - 1]}];
        juosta[pozicija - 1] = komanda.simbPakeitimas;
        busena = komanda.naujaBusena;

        if (komanda.kryptis == 'R' || komanda.kryptis == 'r')
        {
            if (pozicija < juosta.length())
                pozicija++;
            else
            {
                juosta = juosta + "_";
                pozicija++;
            }
        }
        else if (komanda.kryptis == 'L' || komanda.kryptis == 'l')
        {
            if (pozicija - 1 > 0)
                pozicija--;
            else
            {
                juosta = "_" + juosta;
            }
        }
        else if (komanda.kryptis != 'L' && komanda.kryptis != 'l' && komanda.kryptis != 'R' && komanda.kryptis != 'r')
        {
        }
        cout << juosta << endl;
        arrow[pozicija - 1] = '^';
        cout << arrow << endl;
        if (speed != 0)
        {
            this_thread::sleep_for(chrono::milliseconds{speed});
        }
        Clear();
        paskbusena = komanda.naujaBusena;
        if(kbhit()){
            isKeyPressed = 1;
        }
    }
    bool check = false;
    for (auto i : busenos)
    {
        if (paskbusena == i)
        {
            check = true;
        }
    }
    if (check == false)
    {
        cout << "programa sustojo pasiekus baigtine busena" << endl;
    }
    else if (juosta.length() == juosta.length()*3){
        cout << " programa sustojo nes pasibaige juosta" << endl;
    }
    else if(isKeyPressed == 1){
         cout << " programa sustojo nes buvo nutraukta paspaudimu" << endl;
    }
    else
        cout << "programa sustojo pasiekus neapibrezta taisykle" << endl;
    cout << "juosta atlikus operacijas: " << juosta;
    // cout << komanda[{busena, "N"}].naujaBusena;
}

void veikimas2(string juosta1, string juosta2, int pozicija1, int pozicija2, map<pair<string, pair<char, char>>, tiuringoMasina2> komanda1, set<string> busenos)
{
    string busena = "0";
    string paskbusena{};
    int speed = speedFunk();
    bool isKeyPressed=0;
    while (komanda1.find({busena, {juosta1[pozicija1 - 1], juosta2[pozicija2-1] }}) != komanda1.end() && juosta1.length() < juosta1.length()*3 && juosta2.length() < juosta2.length()*3 &&  !kbhit())
    {
        string arrow1 = "  ";
        string arrow2 = "  ";
        for (int i = 0; i < juosta1.length(); i++)
        {
            arrow1 += " ";
        }
        for (int i = 0; i < juosta2.length(); i++)
        {
            arrow2 += " ";
        }
        tiuringoMasina2 komanda = komanda1[{busena, {juosta1[pozicija1 - 1], juosta2[pozicija2 - 1]}}];
        juosta1[pozicija1 - 1] = komanda.simbPakeitimas1;
        juosta2[pozicija2 - 1] = komanda.simbPakeitimas2;
        busena = komanda.naujaBusena;

        if (komanda.kryptis1 == 'R' || komanda.kryptis1 == 'r')
        {
            if (pozicija1 < juosta1.length())
                pozicija1++;
            else
            {
                juosta1 = juosta1 + "_";
                pozicija1++;
            }
        }
        else if (komanda.kryptis1 == 'L' || komanda.kryptis1 == 'l')
        {
            if (pozicija1 - 1 > 0)
                pozicija1--;
            else
            {
                juosta1 = "_" + juosta1;
            }
        }
        else if (komanda.kryptis1 != 'r' && komanda.kryptis1 != 'R' && komanda.kryptis1 != 'l' && komanda.kryptis1 != 'L')
        {
        }
        
        if (komanda.kryptis2 == 'R' || komanda.kryptis2 == 'r')
        {
            if (pozicija2 < juosta2.length())
                pozicija2++;
            else
            {
                juosta2 = juosta2 + "_";
                pozicija2++;
            }
        }
        else if (komanda.kryptis2 == 'L' || komanda.kryptis2 == 'l')
        {
            if (pozicija2 - 1 > 0)
                pozicija2--;
            else
            {
                juosta2 = "_" + juosta2;
            }
        }
        else if (komanda.kryptis2 != 'r' || komanda.kryptis2 != 'R' || komanda.kryptis2 != 'l' || komanda.kryptis2 != 'L')
        {
        }

        cout << juosta1 << endl;
        arrow1[pozicija1 - 1] = '^';
        cout << arrow1 << endl;
        cout << endl;
        cout << juosta2 << endl;
        arrow2[pozicija2 - 1] = '^';
        cout << arrow2 << endl;
        if (speed != 0)
        {
            this_thread::sleep_for(chrono::milliseconds{speed});
        }
        Clear();
        paskbusena = komanda.naujaBusena;
        if(kbhit()){
            isKeyPressed = 1;
        }
    }
    bool check = false;
    for (auto i : busenos)
    {
        if (paskbusena == i)
        {
            check = true;
        }
    }
    if (check == false)
    {
        cout << "programa sustojo pasiekus baigtine busena" << endl;
    }
    else if(isKeyPressed == 1){
         cout << " programa sustojo nes buvo nutraukta paspaudimu" << endl;
    }
    else
        cout << "programa sustojo pasiekus neapibrezta taisykle" << endl;
    cout << "pirma juosta atlikus operacijas: " << juosta1 << endl;
    cout << "antra juosta atlikus operacijas: " << juosta2;
    // cout << komanda[{busena, "N"}].naujaBusena;
}

int main(int argc, char *argv[])
{
    string input = "inputs/";
    input += argv[1];
    ifstream in(input);
    // ifstream in("inputs/mano.txt");
    int juostKiekis, k{};
    string pradBusena;
    string juosta1;
    string juosta2;
    char galvute1, galvute2;
    int pozicija1, pozicija2;
    set<string> busenos;
    vector<tiuringoMasina1> komandos;
    vector<tiuringoMasina2> komandos2;

    map<pair<string, char>, tiuringoMasina2> komanda2;
    in >> juostKiekis;

    if (juostKiekis == 1)
    {
        map<pair<string, char>, tiuringoMasina1> komanda;
        in >> juosta1 >> pozicija1;
        while (!in.eof())
        {
            tiuringoMasina1 temp;
            in >> pradBusena >> galvute1 >> temp.simbPakeitimas >> temp.kryptis >> temp.naujaBusena;
            busenos.insert(pradBusena);
            komanda[{pradBusena, galvute1}] = {temp.simbPakeitimas, temp.kryptis, temp.naujaBusena};
        }
        veikimas1(juosta1, pozicija1, komanda, busenos);
    }

    else if (juostKiekis == 2){
        map<pair<string, pair<char, char>>, tiuringoMasina2> komanda1;
        
        in >> juosta1 >> juosta2 >> pozicija1 >> pozicija2;
        while(!in.eof()){
            tiuringoMasina1 temp1;
            tiuringoMasina1 temp2;
            in >> pradBusena >> galvute1 >> galvute2 >> temp1.simbPakeitimas >> temp2.simbPakeitimas >> temp1.kryptis>> temp2.kryptis>> temp1.naujaBusena;
            busenos.insert(pradBusena);
            komanda1[{pradBusena, {galvute1, galvute2}}] = {temp1.simbPakeitimas, temp2.simbPakeitimas, temp1.kryptis, temp2.kryptis, temp1.naujaBusena};
            
        }
        veikimas2(juosta1, juosta2, pozicija1, pozicija2, komanda1, busenos);
    }

    /*
    for(auto mapas: komanda){
        cout << mapas.first.first <<" "<< mapas.first.second <<" "<< mapas.second.simbPakeitimas <<" "<< mapas.second.kryptis <<" "<< mapas.second.naujaBusena << endl;
    }
    */
}
