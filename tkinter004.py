from tkinter import *
from random import randint


def sorteio():
    computador = [randint(1, 61), randint(1, 61), randint(1, 61), randint(1, 61), randint(1, 61), randint(1, 61)]
    computador.sort()

    texto = f'''Mega sena {computador}'''

    texto_sorte["text"]= texto


janela = Tk()
janela.title('Palpite Mega Sena')
janela.geometry('350x150')
janela.configure(background='#008')
texto_orient = Label(janela, text='CLIQUE NO BOTÃO, VEJA SEU PALPITE DA SORTE')
texto_orient.grid(column=0, row=0, padx=10, pady=10)
texto_orient.configure(background='#008', foreground='#fff')
botao = Button(janela, text='Clique na Sorte!', command=sorteio)
botao.grid(column=0, row=1, padx=10, pady=10)
botao.configure(background='#ff0', foreground='#000')
texto_sorte = Label(janela,text=" ")
texto_sorte.grid(column=0, padx=10, pady=10)
texto_sorte.configure(background='#008', foreground='#fff')

janela.mainloop()
