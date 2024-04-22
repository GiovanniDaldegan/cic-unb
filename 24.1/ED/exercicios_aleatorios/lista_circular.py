# jogo de batatinha quente

class pessoa():
	def __init__(self, nome:str):
		self.nome = nome
		self.proximo = None
		self.anterior = None
	
	def set_proximo(self, _pessoa):
		self.proximo = _pessoa

class lista_circular():
	def __init__(self, _pessoa:pessoa):
		self.primeiro = _pessoa
		self.ultimo = _pessoa

		self.atual = _pessoa

	def adicionar(self, _pessoa:pessoa):
		self.ultimo.proximo = _pessoa
		_pessoa.anterior = self.ultimo
		self.ultimo = _pessoa

	def fechar(self):
		self.ultimo.proximo = self.primeiro
		self.primeiro.anterior = self.ultimo

	def set_contador(self, n:int):
		self.contador = n

	def proximo(self):
		self.atual = self.atual.proximo
		self.contador -= 1

	def queimou(self):
		self.atual.anterior.proximo = self.atual.proximo
		self.atual.proximo.anterior = self.atual.anterior
		self.atual = self.atual.proximo

pessoas = [pessoa('adrianna'), pessoa('gustavo'), pessoa('adelio'), pessoa('claudio'), pessoa('anderson')]
lista = lista_circular(pessoas[0])

for i in range(len(pessoas)):
	lista.adicionar(pessoas[i])
lista.fechar()

while lista.atual != lista.atual.proximo:
	lista.set_contador(int(input("até quanto? ")))	

	while lista.contador > 0:
		lista.proximo()
	print(f'{lista.atual.nome} saiu.')
	lista.queimou()	

print(f'\nfim de jogo. {lista.atual.nome} ganhou!!')
