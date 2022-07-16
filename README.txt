Daniel Oliveira Nascimento - 2020054293 
Janderson Glauber Mendes dos Santos - 2020054544
Kleber Junior Alves Pereira - 2020054625

CPU -> leitura/escrita na cache e na memoria de dados

leitura -> endereço q deseja acessar; esse endereço vai pra cache; retorna o dado caso seja hit; busca na memoria de dados caso seja miss
escrita -> recebe endereço e dado; atualiza na cache; marca como sujo; quando precisar substittuir o sujo, persiste ele na memoria de dados; depois atualiza a cache

Memoria de dados:
- 1024 palavras de 32 bits

cache
- 64 blocos
- 16 bytes por bloco = 4 palavras de 32 bits = 128 bits
- mapeamento direto

entrada
endereço N de acesso a memoria; tipo da operaçao 0(leitura) 1(escrita); dado para escrita

