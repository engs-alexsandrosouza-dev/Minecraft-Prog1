#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main() {

	srand(time(NULL));
	char  pos [20][20];

	for (int i = 0; i <= 19; i++) {
		for (int j = 0; j <= 19; j++) {         

			pos [i][j] = 'x';
		}       
	}       

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int armadilha = rand() % 20;             
			int buraco = rand()% 20;
			if (pos [armadilha][buraco] == 'x')
				pos[armadilha][buraco] = '_';
		}       
	}       

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int muro = rand() % 20;             
			int parede = rand()% 20;
			if (pos [muro][parede] == 'x') {
				pos[muro][parede] = '|';
			}
		}       
	}      

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			int arvore = rand() % 20;             
			int tronco = rand()% 20;
			if (pos [arvore][tronco] == 'x') {
				pos[arvore][tronco] = 'T';
			}
		}       
	}      

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			int fruta =  rand() % 20;
			int banana = rand()% 20;
			if (pos [fruta][banana] == 'x') {
				pos[fruta][banana] = 'F';
			}
		}      
	}       

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int pedra = rand() % 20;          
			int rocha = rand()% 20;
			if (pos [pedra][rocha] == 'x') {
				pos[pedra][rocha] = 'P';
			}
		}  
	}    

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			int animal = rand() % 20;             
			int bicho = rand()% 20;
			if (pos [animal][bicho] == 'x') {
				pos[animal][bicho] = 'A';
			}
		}    
	}      

	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			int graveto = rand() % 20;
			int galho = rand()% 20;           
			if (pos [graveto][galho] == 'x') {
				pos[graveto][galho] = 'G';
			}
		} 
	}  

	int user = rand() % 20;     
	int gamer = rand()% 20;
	pos[user][gamer] = '@';


	int pedrasnec = 0, arvoresnec = 0, frutasnec = 0, animaisnec = 0, gravetosnec = 0, missao;
	char movimento, coleta;
	string status, statusconcluido;
	int pedras = 0, arvores = 0, frutas = 0, animais = 0, gravetos = 0, vidas = 100;

	cout << "------------------------------------------------------------------------" << endl;
	cout << "               Seja bem-vindo ao Mundo Quadrado!" << endl;

	cout << "\n------------------------------------------------------------------------------------" << endl;
	cout << " Siglas: F: fruta    G: graveto     A: animal    T: tronco/árvore    P: pedras" <<endl;
	cout << "\n O ícone referente ao seu personagem é: @" <<endl;
	cout << "\n------------------------------------------------------------------------------------" << endl;

	cout << "\n  Escolha com cuidado sua aventura no mundo quadrado! " << endl;
	cout << " 1 - Luz e Calor   ";
	cout << "2 - Comida    ";                                       
	cout << "3 - Construção" << endl;
	cout << endl;
	cout << "\n Cuidado com as armadilhas!!!";
	cout << "\n Buracos: _       Paredes: |" << endl;


	cout << "\n   Escolha sua missão: [1   2   3] : " << endl;
	cin >> missao;

	switch (missao) {
	case 1:
		gravetosnec = 4;
		pedrasnec = 2;
		cout << "\n Na missão Luz e Calor seu objetivo é coletar: 4 gravetos e 2 pedras no mapa! " << endl;
		status = "Em progresso";
		break;

	case 2:
		frutasnec = 1;
		animaisnec = 3;
		cout << "\n Na missão Comida seu objetivo é coletar: 1 fruta e 3 animais! " << endl;
		status = "Em progresso";
		break;

	case 3:
		pedrasnec = 8;
		arvoresnec = 4;
		cout << "\n Na missão contrução seu objetivo é coletar: 8 pedras e 4 árvores! " << endl;
		status = "Em progresso";
		break;

	}


	if(missao != 1 && missao != 2 && missao != 3) {
		cout << "Opção inválida! ";  
		return 0;
	} 

	cout << "\n Sua posição atual é: " << user << "-" <<gamer << endl;
	cout << "\n Para se mover user as teclas w [cima] d [direita] s [baixo] a [esquerda]";
	cout << "\n";

	cout << "\n------------------------------------------------------------------------------------" << endl;

	while (status != "Concluído" && vidas > 0) {  

		for (int i = 0; i <= 19; i++) {
			for (int j = 0; j <= 19; j++) {
				if(pos[i][j]=='x') {
					cout << "  "  << ".";
				}
				else
				{
					cout << "  "  << pos [i][j];
				}

			} 
			cout << endl;
		} 

		char coleta;

		cout << "\n------------------------------------------------------------------------------------" << endl;
		cout << "                                Inventário " << endl;
		cout << "\n | Arvores: " << arvores << "         |";
		cout << "\n | Animais: " << animais << "         |";
		cout << "\n | Frutas: " << frutas << "          |";           
		cout << "\n | Gravetos: " <<gravetos << "        |";
		cout << "\n | Pedras: " << pedras << "          |";
		cout << "\n | Vidas: " << vidas << "         |";

		cout << "\nStatus atual: " << status << endl << endl;

		cout << "\n Faça um movimento: w (cima) s (baixo)  a (esquerda) d (direita) ";
		cin >> movimento;

		pos [user][gamer] = {'x'};     

		switch (movimento) {
		case 'w':
			user -=1;
			break;
		case 'W':
			user -= 1;
			break;
		case 's':
			user += 1;
			break;
		case 'S':
			user += 1;
			break;                      
		case 'a':
			gamer -= 1;
			break;
		case 'A':
			gamer -= 1;
			break;
		case 'd':
			gamer += 1;
			break;
		case 'D':
			gamer += 1;
			break;
		}

		if (user > 19) {
			user = 19;
		}
		if (user < 0) {
			user = 0;   
		}
		if (gamer > 19) {
			gamer = 19;
		}
		if (gamer < 0) {
			gamer = 0;
		}

		if (pos [user][gamer] == '_') {
			vidas -= 10;
		}
		else if (pos [user][gamer] == '|') {
			vidas -=10;
		}

		if (pos [user][gamer] != 'x' && pos [user][gamer] != '_' && pos [user][gamer] != '|' ) {
			cout << pos [user][gamer] << endl << endl;
			cout << "Você quer coletar o item: " << pos[user][gamer] << " [s ou n] ";
			cin >> coleta;
			if (coleta == 's' || coleta == 'S') {

				if (pos [user][gamer] == 'G') {
					gravetos += 1;
				}
				else if (pos [user][gamer] == 'T') {
					arvores += 1;
				}

				else if (pos [user][gamer] == 'P') {
					pedras += 1;
				}

				else if (pos [user][gamer] == 'A') {
					animais += 1;
				}
				else if (pos [user][gamer] == 'F') {
					frutas = frutas + 1;
				}
			}
		}



		pos [user][gamer] = {'@'};     

		switch (missao) {

		case 1:
			if (pedrasnec <= pedras && gravetosnec <= gravetos) {
				status = "Concluído";


			}
			else {
				status = "Em progresso";

			}
			break;

		case 2:
			if (frutasnec <= frutas && animaisnec <= animais) {
				statusconcluido = "Concluído!";
				status = "Concluído";
			}
			else {
				status = "Em progresso";

			}
			break;

		case 3:
			if (arvoresnec <= arvores && pedrasnec <= pedras) {
				status = "Concluído";
			}
			else {
				status = "Em progresso";

			}
			break;
		}

	}
	cout << "\n----------------------------------";
	cout << "\nStatus atual: " << status;
	cout << "\n----------------------------------";


	if (vidas <= 0) {
		cout << "\nVocê morreu!";
		cout << "\n----------------------------------";
		return 0;
	}


	if (missao == 1) {
		cout << "\nMissão: Luz e Calor Concluída!!";
		cout << "\n----------------------------------";
	}
	else if (missao == 2) {
		cout << "\nMissão: Comida Concluída!!";
		cout << "\n----------------------------------";
	}
	else if (missao == 3) {
		cout << "\nMissão: Construção Concluída!!";
		cout << "\n----------------------------------";
	}
}
