## Orientações
- linguagem, ferramentas, plataforma: livre escolha
- a interface deve ser gráfica ou de texto (não terminal)
- padrões e métodos a adotar
    - SCRUM + Kanban
    - histórias de usuários e épicos: MoSCoW, RICE


## Descrição

1. interface de usuário gráfica ou baseada em texto
2. criar e autenticar conta
3. CRUD de:
   - projeto
   - product backlog
   - sprint backlog
   - história de usuário
4. formatos padrões de história de usuário, critérios de aceitação

mecanismos
-  (móveis entre backlogs)

<br>

<details> <summary>Na íntegra</summary>

<ol>
    <li> interface com o usuário embasada em texto (text user interface) ou gráfica (graphic user interface); </li>
    <li> para acessar os serviços disponibilizados, cada usuário deve <strong>criar uma conta</strong> e depois ser <strong>autenticado</strong>; </li>
    <li> uma vez autenticado, o usuário tem acesso aos serviços providos pelo sistema de software; </li>
    <li> possibilitar criação leitura, atualização e exclusão de <strong>projetos</strong>; </li>
    <li> possibilitar criação leitura, atualização e exclusão de <strong>product backlogs</strong>, (pode existir só um product backlog por projeto); </li>
    <li> possibilitar criação leitura, atualização e exclusão de <strong>sprint backlogs</strong> (podem existir vários sprint backlogs por projeto); </li>
    <li> possibilitar criação leitura, atualização e exclusão de <strong>histórias de usuário</strong> (ao ser criada, história de usuário deve ser associada a product backlog); </li>
    <li> possibilitar a <strong>movimentação de histórias de usuário entre backlogs</strong>; </li>
    <li> prover o formato padrão para história de usuário <strong>Como um <i>[papel]</i> eu quero <i>[ação]</i> para <i>[benefício]</i></strong>; </li>
    <li> possibilitar criação leitura, atualização e exclusão de <strong>épicos</strong>; </li>
    <li> possibilitar <strong>vinculação de histórias de usuário a épicos</strong>; </li>
    <li> possibilitar criação leitura, atualização e exclusão de <strong>critérios de aceitação de histórias de usuário</strong>; </li>
    <li> prover o <strong>formato padrão para critério de aceitação</strong> de história de usuário <strong>Dado <i>[contexto inicial ou o estado do sistema antes da ação acontecer]</i> quando <i>[ação ou evento específico que o usuário executa]</i> então <i>[resultado esperado ou a consequência daquela ação]</i></strong>; </li>
    <li> possibilitar atribuição de <strong>pontos de história</strong> (story points) a histórias de usuário; </li>
    <li> pontos de história (story points) podem ter os valores 0, 1, 2, 3, 5, 8, 13, 21, 34 ou 55; </li>
    <li> possibilitar atribuição de <strong>etiqueta MoSCoW</strong> (M, S, C, W) a história de usuário; </li>
    <li> possibilitar atribuição de <strong>critério RICE (Reach, Impact, Confidence, Effort)</strong> a história de usuário; </li>
    <li> critério Reach (Alcance) deve ser número de usuários; critério Impact (Impacto) deve ser 3 (massivo), 2 (alto), 1 (médio), 0.5 (baixo) ou 0.25 (mínimo); critério Confidence (Confiança) deve ser valor percentual 100 (alta), 80 (média) ou 50 (baixa); critério Effort (Esforço) deve ser valor de pontos de história (0, 1, 2, 3, 5, 8, 13, 21, 34 ou 55); </li>
    <li> possibilitar o <strong>cálculo de pontuação</strong> segundo o critério RICE pela fórmula (R x I x C) / E </li>
</ol>
</details>

## Artefatos

Atividades
- Gerenciamento de projeto com Kanban
- Descrição da Aplicação de software (stakeholders, requisitos, impactos, utilização)
- Histórias de Usuário (uma pra cada requisito funcional)
- Descrição de Arquitetura

todo
- organizar quadro Kanban
    - templates de cartão
- planejar estrutura de projeto e diretórios
- definir padrões (arquivos e diretórios, classes, métodos, documentação)
- selecionar modelos
    - Classes, Objetos, MER e MR, Casos de Uso, Colaboração, Controle de Fluxo, Análise de Requisitos, 
- definir linguagens, ferramentas
    - UI, BD, bibliotecas (manipulação de texto, implementação de testes, )
- pensar interface gráfica

# Organização de Diretórios e Arquivos

## Estrutura do Projeto


## Padrão de nomes


# Configuração

## Controle de Versão

GitHub

branches separadas para cada artefato?/feature

# Ciclo de Vida/Cronograma de Sprints


# Modelos

## Casos de Uso

## Histórias de Usuário

## Arquitetura

## Banco de Dados

### Entidade-Relacionamento

# Requisitos

