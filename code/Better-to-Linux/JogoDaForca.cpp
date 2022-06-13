#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <locale.h>
#include <time.h>
/*
    Por o desenho do bonego, para cada erro uma parte do boneco é add
    consertar o erro CHAR que da para add mais de uma letra
*/

using namespace std;
void limpaTela(){
    system("clear");
}
string retornaPalavraAleatoria(){
    string palavras[10] = {"abacaxi", "manga","morango","carro","bicicleta","roleta","orgulho","trabalho","sucinto","embuste"};
    int indiceAleatorio = rand() % 10;

    return palavras[indiceAleatorio];
}
string retornaPalavraComMascara(string palavra, int tamanhoDaPalavra){
    int cont = 0;
    string palavraComMascara;
    while(cont < tamanhoDaPalavra){
        palavraComMascara += "_";
        cont++;
    }
    return palavraComMascara;
}
void exibeStatus(string palavraComMascara, string letrasJaArriscadas,int tamanhoDaPalavra,int tentativasRestantes,string mensagem,int erro){
    cout << mensagem << "\n";
    //-------------------------------------------------------------------------------------
    //drawing
    if(erro == 0){
        cout<<"____\n"<<"|\n"<<"|\n"<<"|\n"<<"|\n\n";
    }else if(erro == 1){
        cout<<"____\n"<<"|  O\n"<<"|\n"<<"|\n"<<"|\n\n";
    }else if(erro == 2){
        cout<<"____\n"<<"|  O\n"<<"|  |\n"<<"|\n"<<"|\n\n";
    }else if(erro == 3){
        cout<<"____\n"<<"|  O\n"<<"|  |\\"<<"\n|\n"<<"|\n\n";
    }else if(erro == 4){
        cout<<"____\n"<<"|  O\n"<<"| /|\\ "<<"\n|\n"<<"|\n\n";
    }else{
        cout<<"____\n"<<"|  O\n" <<"| /|\\ "<<"\n| /"<<"\n|\n\n";
    }
    //-------------------------------------------------------------------------------------
    cout <<"Palavra: "<<palavraComMascara<<" (Tamanho da palavra: "<<tamanhoDaPalavra<<")";
    cout<<"\nTentativas Restantes: "<<tentativasRestantes;
    cout<<"\nLetras arriscadas: ";
    for(int cont = 0;cont < letrasJaArriscadas.size();cont++){
        cout<<letrasJaArriscadas[cont]<<", ";
    }
}
int Jogar(int numberOfPlayers){
    string palavra;

    if(numberOfPlayers == 1){
        palavra = retornaPalavraAleatoria();
    }else{
        cout<<"\nDigite uma palavra: \n";
        cin >> palavra;
    }
    int tamanhoDaPalavra = palavra.size(), cont;
    string palavraComMascara = retornaPalavraComMascara(palavra,tamanhoDaPalavra);
    int tentativas=0,maximoDeTentativas=10,erro=0;
    int opcao;
    char letra;
    string letrasJaArriscadas, mensagem, palavraArriscada;

    bool jaDigitouLetra = false,acertouLetra=false; //ele ja inicia falso

    while(palavra != palavraComMascara && maximoDeTentativas - tentativas > 0 && erro < 6){
        limpaTela();
        //cout << "A palavra secreta é "<<palavra<<" (Tamanho da palavra: "<<tamanhoDaPalavra<<")";
        exibeStatus(palavraComMascara,letrasJaArriscadas,tamanhoDaPalavra,maximoDeTentativas - tentativas,mensagem,erro);
        cout<<"\nDigite uma letra:\nPara arriscar digite (1): \n";
        cin >> letra;
        if(letra == '1'){
            cin >> palavraArriscada;
            if(palavraArriscada == palavra){
                palavraComMascara = palavraArriscada;
            }else{
                break;
            }
        }
        for(cont=0;cont < tentativas;cont++){
            if(letrasJaArriscadas[cont]==letra){
                mensagem = "ESSA LETRA JA FOI DIGITADA";
                jaDigitouLetra=true;
            }
        }
        if(jaDigitouLetra==false){ //futuro remover
            letrasJaArriscadas += tolower(letra);
            for(cont = 0; cont < tamanhoDaPalavra; cont++){
                if(palavra[cont] == tolower(letra)){                     //validando se acertou
                    palavraComMascara[cont] = palavra[cont];
                    acertouLetra = true;
                }                                      
            }
            
            if(acertouLetra == false){//<--- Desenho Aqui no else
                mensagem = "BOA, VOCÊ ERROU! O.O";
                erro++;
                /*
                    criar um 
                */
            }else{
                mensagem = "BOA, VOCÊ ACERTOU! :)";
                acertouLetra = false;
            }
            tentativas++;
            //aq     
        }
        jaDigitouLetra = false;         //restart
        acertouLetra = false;
    }

    if(palavra == palavraComMascara){
        limpaTela();
        cout << "Parabéns, você venceu :D";
        cout << "\nDeseja reiniciar";
        cout << "\n1 - SIM";
        cout << "\n2 - NÃO\n\n";
        cin >> opcao;
        return opcao;

    }else{
        limpaTela();
        cout << "Você perdeu :(\n\n";
        cout<<"____\n"<<"|  O\n"<<"| /|\\ "<<"\n| / \\"<<"\n|\n\n";
        cout << "\nDeseja reiniciar";
        cout << "\n1 - SIM";
        cout << "\n2 - NÃO\n\n";
        cin >> opcao;
        return opcao;

    }


}

void menuInicial(){
    int opcao = 0;
    while(opcao<1 || opcao>4){
        limpaTela();
        cout << "\tBem vindo ao Jogo";
        cout<<"\n1 - Jogar sozinho";
        cout<<"\n2 - Jogar em dupla";
        cout<<"\n3 - Sobre";
        cout<<"\n4 - Sair";
        cout<<"\nEscolha uma opção e tecle ENTER:\n";
        cin >> opcao;
        switch(opcao){
            case 1:
                if(Jogar(1) == 1){
                    menuInicial();
                }
                
                break;
            case 2:
                if(Jogar(2) == 1){
                    menuInicial();
                }
                
                break;               
            case 3:
                limpaTela();
                cout<<"\tInformações do Jogo";
                cout<<"Jogo criado pelo professor João e modificado por FelixClone";
                cout<<"\n1- VOLTAR";
                cout<<"\n2- SAIR";
                cin>>opcao;
                if(opcao == 1){
                    menuInicial();
                }else if(opcao == 2){
                    break;
                }else{
                    cout<<"\nEssa opção não existe";
                }
                break;
            case 4:
                limpaTela();
                cout<<"\t\tAté logo!\n";
                break;
        }
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    srand((unsigned)time(NULL));
    menuInicial();

    return 0;
}