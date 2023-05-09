def pesquisa_binaria(lista,target):
   baixo = 0
   alto = len(lista) - 1
   counter = 0

   while baixo <= alto:
        counter += 1
        meio = (baixo + alto) // 2
        chute = lista[meio]
        if chute == target:
            print("Numero de tentativas: ",counter)
            return meio
        if chute > target:
            alto = meio - 1
        else:
            baixo = meio + 1
   return None
       
numbers = [5,12,26,49,50,79,100,128,150,200,304,340,390,430,520]


        
print(pesquisa_binaria(numbers,430))