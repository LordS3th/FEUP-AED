#include "parque.h"
#include <vector>
#include <iostream>

using namespace std;
ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot),numMaximoClientes(nMaxCli){
    vagas=lotacao;
}
unsigned ParqueEstacionamento::getNumLugares() const{
    return lotacao;
}
unsigned ParqueEstacionamento::getNumMaximoClientes() const{
    return numMaximoClientes;
}
int ParqueEstacionamento::posicaoCliente(const string & nome) const{
    for (int i = 0; i < clientes.size(); i++){
        if (clientes[i].nome == nome) {
            return i;
        }
    }
    return -1;
}
bool ParqueEstacionamento::adicionaCliente(const string & nome){
    int i=clientes.size();
    if( i<numMaximoClientes){
        InfoCartao new_client;
        new_client.nome= nome;
        new_client.presente= false;
        clientes.push_back(new_client);
        return true;
    }
    else return false;
}
bool ParqueEstacionamento::entrar(const string & nome) {
    int i=posicaoCliente(nome);
    if (i == -1 || clientes[i].presente== true|| vagas ==0) {
        return false;
    }
    else{
        clientes[i].presente= true;
        vagas--;
        return true;
    }
}
bool ParqueEstacionamento::retiraCliente(const string & nome){
    int i = posicaoCliente(nome);
    if (i!=-1 && clientes[i].presente==false) {
        clientes.erase(clientes.begin() + i - 1);
        return true;
    }
    else return false;
}
bool ParqueEstacionamento::sair(const string & nome){
    int i = posicaoCliente(nome);
    if(i!=1 || clientes[i].presente==false){
        return false;
    }
    else {
        clientes[i].presente=false;
        vagas++;
        return true;
    }
}
unsigned ParqueEstacionamento::getNumLugaresOcupados() const{
    int lugar_ocupados= lotacao-vagas;
    return lugar_ocupados;
}
unsigned ParqueEstacionamento::getNumClientesAtuais() const{
    int clientes_atuais= clientes.size();
    return clientes_atuais;
}