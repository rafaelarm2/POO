/*
 * ContaCorrente.h
 *
 *  Created on: 16 de nov de 2019
 *      Author: rafaelamoreira
 */

#ifndef CONTACORRENTE_H_
#define CONTACORRENTE_H_

#include <iostream>
#include "Conta.h"
#include "SaldoDiaBase.h"

class ContaCorrente: public Conta {
protected:
	double limiteCredito;
public:
	ContaCorrente();
	ContaCorrente(Cliente * clienteNovo, double limiteCredito);
	virtual ~ContaCorrente();

	double getLimiteCredito();

	bool debitar(double valor, std::string descricao) override;
	//methods
	void creditar(double valor, std::string descricao) override;

	//Write the member variables to stream objects
	friend std::ostream& operator << (std::ostream& out, const ContaCorrente& obj);

	//Read data from stream object and fill it in member variables
	friend std::istream& operator >> (std::istream& in, ContaCorrente& obj);

	string type() const override;

	virtual void write(std::ostream& out) const override;

	virtual void read(std::istream& in) override;

	void removeElemento(int elemento);

	void adicionaElemento(SaldoDiaBase &db);


	////getters and setters
	//const Cliente& getCliente() const override;
	//const std::vector<Movimentacao> getMovimentacoes() override;
	//int getNumConta() const override;
	////static int getProximoNumConta();
	//double getSaldo() const override;

	////Seta o ponteiro pro cliente
	//void setCliente(Cliente *newCliente) override;


	//vector<Movimentacao> obterExtrato(std::string dataIni, std::string dataFim) override;
	//vector<Movimentacao> obterExtrato(std::string dataIni) override;
	//vector<Movimentacao> obterExtratoMesAtual() override;
};

#endif /* CONTACORRENTE_H_ */
