/*
 * ContaCorrente.cpp
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#include "ContaCorrente.h"
#include "Cliente.h"
#include "Erro.h"

ContaCorrente::ContaCorrente() : Conta()
{
	this->limiteCredito = 0;
}

ContaCorrente::ContaCorrente(Cliente * clienteNovo, double limiteCredito): Conta(clienteNovo) {
	this->limiteCredito = limiteCredito;
}

ContaCorrente::~ContaCorrente() {
	// TODO Auto-generated destructor stub
}

double ContaCorrente::getLimiteCredito()
{
	return this->limiteCredito;
}


bool ContaCorrente::debitar(double valor, std::string descricao) {
	bool transacaorealizada = false;
	char debitoCredito = 'D';
	Movimentacao * mov = new Movimentacao(descricao, debitoCredito, valor);

	if (this->saldo + this->limiteCredito >= valor) {
		this->saldo = this->saldo - valor;
		this->movimentacoes.push_back(* mov);
		transacaorealizada = true;
	} else {
		throw Erro("Saldo insuficiente");
	}

	delete mov;

	return transacaorealizada;
}

void ContaCorrente::creditar(double valor, std::string descricao)
{
}

string ContaCorrente::type() const
{
	return "C";
}

void ContaCorrente::write(std::ostream& out) const
{
	out << *this;
}

void ContaCorrente::read(std::istream& in)
{
	in >> *this;
}


std::ostream& operator<<(std::ostream& out, const ContaCorrente& obj)
{
	//Escreve o tipo da conta
	out << "C" << "\n";
	out << obj.numConta << "\n" << obj.saldo << "\n" << *obj.cliente << "\n" << obj.proximoNumConta << "\n" << obj.movimentacoes.size() << "\n" << obj.limiteCredito << "\n";
	for (int i = 0; i < obj.movimentacoes.size(); i++) {
		out << obj.movimentacoes[i];
	}
	std::cout << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, ContaCorrente& obj)
{
	in >> obj.numConta;
	in >> obj.saldo;
	Cliente* novo = new Cliente;
	in >> *novo;
	obj.cliente = novo;
	in >> obj.proximoNumConta;
	int size;
	in >> size;
	for (int i = 0; i < size; i++) {
		Movimentacao* aux = new Movimentacao();
		in >> *aux;
		obj.movimentacoes.push_back(*aux);
		delete aux;
	}
	in >> obj.limiteCredito;
	return in;
}

//const Cliente& ContaCorrente::getCliente() const
//{
//	return *cliente;
//}
//
//const std::vector<Movimentacao> ContaCorrente::getMovimentacoes()
//{
//	return std::vector<Movimentacao>();
//}
//
//int ContaCorrente::getNumConta() const
//{
//	return 0;
//}
//
//double ContaCorrente::getSaldo() const
//{
//	return 0.0;
//}
//
//void ContaCorrente::setCliente(Cliente* newCliente)
//{
//}



//vector<Movimentacao> ContaCorrente::obterExtrato(std::string dataIni, std::string dataFim)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaCorrente::obterExtrato(std::string dataIni)
//{
//	return vector<Movimentacao>();
//}
//
//vector<Movimentacao> ContaCorrente::obterExtratoMesAtual()
//{
//	return vector<Movimentacao>();
//}
//
//double ContaCorrente::getLimiteCredito() {
//	return this->limiteCredito;
//}

