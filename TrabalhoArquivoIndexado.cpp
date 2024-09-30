#include<iostream>
#include<string>
#include<conio.h>
#include<cstring>

using namespace std;

struct indicecidade{
    int codigo;
    int endereco;
};

struct cidade{
    int codigo;
    string nome;
    string estado;
    int status;
};

void leituracidade(struct cidade c[], int &contcidade) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nDigite o Codigo da Cidade : ";
        cin >> c[i].codigo;
        
        if (c[i].codigo > 0) {
            bool codigoDuplicado = false;
            
            // Auxilio ChatGPT
            for (int j = 0; j < i; j++) {
                if (c[i].codigo == c[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }
            
            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                cin.ignore();
                cout << "Nome da Cidade : ";
                getline(cin, c[i].nome);
                cout << "Estado : ";
                getline(cin, c[i].estado);
                c[i].status = 0;
            }
        } else {
            saida = 0;
        }
    }
    contcidade = i - 1;
}

void leituraindicecidade(struct indicecidade idx[],int cont){
    for(int i = 0; i < cont; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}

int  busca_cidade(struct cidade c[],int cod, int &contadorbusca_cidade)
{
    int i = 0, f = contadorbusca_cidade - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != c[me].codigo;me = (i+f)/2)
    {
        if(cod > c[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == c[me].codigo)
    {
    cout << "Cidade : " <<c[me].nome <<"  Estado : " <<c[me].estado <<endl;
    return 1;
    }
    return 0;
}

struct indiceespecialidades{
    int codigo;
    int endereco;
};

struct especialidades{
    int codigo;
    string descricao;
    int status;
};

void leituraespecialidades(struct especialidades e[], int &contadorespecialidades) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nDigite o Codigo da Especialidade : ";
        cin >> e[i].codigo;

        if (e[i].codigo > 0) {
            bool codigoDuplicado = false;

            for (int j = 0; j < i; j++) {
                if (e[i].codigo == e[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }

            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                cout << "Descricao da Especialidade : ";
                cin >> e[i].descricao;
                e[i].status = 0;
            }
        } else {
            saida = 0;
        }
    }
    contadorespecialidades = i - 1;
}


void leituraindiceespecialidades(struct indiceespecialidades idx[],int cont){
    for(int i = 0; i < cont; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}

int  busca_especialidades(struct especialidades e[],int cod, int &contadorbusca_especialidades)
{

    int i = 0, f = contadorbusca_especialidades - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != e[me].codigo;me = (i+f)/2){
    
        if(cod > e[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == e[me].codigo){
    cout << "Descricao da Especialidade: " <<e[me].descricao << endl;
    return 1;
    }
    return 0;
}

struct indicemedicos{
    int codigo;
    int endereco;
};

struct medicos{
    int codigo;
    string nome;
    int codigoespecialidade;
    string endereco;
    string telefone;
    int codigocidade;
    int status;
};

void leituramedicos(struct medicos m[], struct cidade c[], struct especialidades e[], int &contadormedicos, int contcidade, int contadorespecialidades) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nCodigo do Medico : ";
        cin >> m[i].codigo;

        if (m[i].codigo > 0) {
            bool codigoDuplicado = false;

            for (int j = 0; j < i; j++) {
                if (m[i].codigo == m[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }

            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                cin.ignore();
                cout << "Nome : ";
                getline(cin, m[i].nome);
                cout << "Codigo da Especialidade : ";
                cin >> m[i].codigoespecialidade;
                busca_especialidades(e, m[i].codigoespecialidade, contadorespecialidades);
                cin.ignore();
                cout << "Endereco : ";
                getline(cin, m[i].endereco);
                cout << "Telefone : ";
                getline(cin, m[i].telefone);
                cout << "Codigo da Cidade : ";
                cin >> m[i].codigocidade;
                busca_cidade(c, m[i].codigocidade, contcidade);
                m[i].status = 0;
            }
        } else
         {
            saida = 0;
        }
    }
    contadormedicos = i - 1;
}


void leituraindicemedicos(struct indicemedicos idx[],int cont){
    for(int i = 0; i < cont; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}

int  busca_medicos(struct medicos m[],struct especialidades e[], int cod, int &contadorbusca_medicos)
{
    int i = 0, f = contadorbusca_medicos - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != m[me].codigo;me = (i+f)/2)
    {
        if(cod > m[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == m[me].codigo)
    {
    cout << "Medico : " <<m[me].nome <<endl;
    cout << "Especialidade : " <<e[i].descricao;
    return 1;
    }
    return 0;
}

void inclusaomedicos(struct indicemedicos idx[], struct medicos m[], struct especialidades e[], struct cidade c[], int &cont, int cod, int &contador_buscaespecialidades, int &contcidade) {
    cont++;
    m[cont].codigo = cod;
    
    cout << "Nome : ";
    cin >> m[cont].nome;
    

    bool especialidade_valida;
    do {
        cout << "Codigo da Especialidade : ";
        cin >> m[cont].codigoespecialidade;
        especialidade_valida = busca_especialidades(e, m[cont].codigoespecialidade, contador_buscaespecialidades);
        if (!especialidade_valida) {
            cout << "Código de especialidade inválido. Por favor, tente novamente." << endl;
        }
    } while (!especialidade_valida);
    
    cin.ignore();
    cout << "Endereco : ";
    getline(cin, m[cont].endereco);
    
    cout << "Telefone : ";
    getline(cin, m[cont].telefone);
    
    bool cidade_valida;
    do {
        cout << "Codigo da Cidade : ";
        cin >> m[cont].codigocidade;
        cidade_valida = busca_cidade(c, m[cont].codigocidade, contcidade);
        if (!cidade_valida) 
        {
            cout << "Código de cidade inválido. Por favor, tente novamente." << endl;
        }
    } while (!cidade_valida);
    
    int i;
    for (i = cont - 1; i >= 0 && idx[i].codigo > cod; i--) {
        idx[i + 1].codigo = idx[i].codigo;
        idx[i + 1].endereco = idx[i].endereco;
    }
    idx[i + 1].codigo = cod;
    idx[i + 1].endereco = cont;

    cout << "\nInclusao Realizada com Sucesso";
}


void buscaaleatoriamedicos(struct indicemedicos idx[],struct medicos m[],struct especialidades e[],struct cidade c[],int &cont,int cod,int &contador_buscaespecialidades,int &contcidade)
{

    int i = 0, f = cont;
    int me =(i + f)/2;
    for (;f >= i && cod != idx[me].codigo;me = (i+f)/2){
    
        if(cod > idx[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == idx[me].codigo){
    cout << "\nMedico ja Cadastrado!";
    i = idx[me].endereco;
    cout << "\nCodigo do Medico: " <<m[i].codigo;
    cout << "\tNome: " <<m[i].nome;
    cout << "\tCodigo da Especialidade: " << m[i].codigoespecialidade;
    cout << "\tEndereco: " <<m[i].endereco;
    cout << "\tTelefone: " <<m[i].telefone;
    cout << "\tCodigo da Cidade: " <<m[i].codigocidade;
}
else
inclusaomedicos(idx,m,e,c,cont,cod,contador_buscaespecialidades,contcidade);
}

/*void excluirmedico (struct indicemedicos idx[], struct medicos m[], int &cont, int cod){
    int i = 0, f = cont;
    int me = (i + f) / 2;
    for (; f >= i && cod != idx[me].codigo; me = (i + f) / 2){
        if (cod > idx[me].codigo)
            i = me + 1;
        else
            f = me - 1;
    }
    i = idx[me].endereco;
    if ((cod == idx[me].codigo) && m[i].status == 0){
        m[i].status = 1;
        cout << "\n\n Medico Excluido com Sucesso";
    }
    else
        cout << "Medico nao cadastrado";
}*/



struct indicepacientes{
    int codigo;
    int endereco;
};

struct pacientes{
    int codigo;
    string nome;
    string endereco;
    int codigocidade;
    int status;
};

void leiturapacientes(struct pacientes p[], int &contadorpaciente, struct cidade c[], int contcidade) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nCodigo do Paciente : ";
        cin >> p[i].codigo;

        if (p[i].codigo > 0) {
            bool codigoDuplicado = false;

            for (int j = 0; j < i; j++) {
                if (p[i].codigo == p[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }

            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                cin.ignore();
                cout << "Nome : ";
                getline(cin, p[i].nome);
                cout << "Endereco : ";
                getline(cin, p[i].endereco);
                cout << "Codigo da Cidade : ";
                cin >> p[i].codigocidade;
                busca_cidade(c, p[i].codigocidade, contcidade);
                p[i].status = 0;
            }
        } else {
            saida = 0;
        }
    }
    contadorpaciente = i - 1;
}


void leituraindicepacientes(struct indicepacientes idx[],int contadorpaciente){
    for(int i = 0; i < contadorpaciente; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}

int  busca_paciente(struct pacientes p[],struct cidade c[],int cod, int &contadorbusca_paciente)
{

    int i = 0, f = contadorbusca_paciente - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != p[me].codigo;me = (i+f)/2)
    {
        if(cod > p[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == p[me].codigo)
    {
    cout << "Paciente : " <<p[me].nome <<endl;
    cout << "Cidade : " <<c[i].nome <<endl;
    cout << "Estado : " <<c[i].estado <<endl;
    return 1;
    }
    return 0;
}



void inclusaopacientes(struct indicepacientes idx[], struct pacientes p[], struct cidade c[], int &cont, int cod, int contcidade) {
    cont++;
    p[cont].codigo = cod;
    
    cout << "Nome : ";
    cin >> p[cont].nome;
    cin.ignore();

    cout << "Endereco : ";
    getline(cin, p[cont].endereco);
    
    bool cidade_valida;
    do {
        cout << "Codigo da Cidade : ";
        cin >> p[cont].codigocidade;
        cidade_valida = busca_cidade(c, p[cont].codigocidade, contcidade);
        if (!cidade_valida) {
            cout << "Código de cidade inválido. Por favor, tente novamente." << endl;
        }
    } while (!cidade_valida);

    int i;
    for (i = cont - 1; i >= 0 && idx[i].codigo > cod; i--) {
        idx[i + 1].codigo = idx[i].codigo;
        idx[i + 1].endereco = idx[i].endereco;
    }
    idx[i + 1].codigo = cod;
    idx[i + 1].endereco = cont;
    
    cout << "\nInclusao Realizada com Sucesso";
}


void buscaaleatoriapacientes(struct indicepacientes idx[],struct pacientes p[],struct cidade c[],int &cont, int cod,int contcidade){

    int i = 0, f = cont;
    int me =(i + f)/2;
    for (;f >= i && cod != idx[me].codigo;me = (i+f)/2){
    
            if(cod > idx[me].codigo)
                i = me+1;
            else
             f = me - 1;

    }
    if(cod == idx[me].codigo){
    cout << "\nPaciente ja Cadastrado!";
    i = idx[me].endereco;
    cout << "\nCodigo do Paciente: " <<p[i].codigo;
    cout << "\tNome: " <<p[i].nome;
    cout << "\tEndereco: " << p[i].endereco;
    cout << "\tCodigo Cidade: " <<p[i].codigocidade;
    busca_cidade(c,p[cont].codigocidade,contcidade);
}
else
inclusaopacientes(idx,p,c,contcidade,cod,cont);
}

/*void excluirpaciente(struct indicepacientes idx[], struct pacientes p[], int &cont, int cod, struct consultas cs[], int contconsultas) {
    int i = 0, f = cont - 1;
    int m = (i + f) / 2;

    // Busca binária para encontrar o paciente
    for (; f >= i && cod != idx[m].codigo; m = (i + f) / 2) {
        if (cod > idx[m].codigo) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    // Verifica se o paciente foi encontrado
    if (f >= i && cod == idx[m].codigo) {
        i = idx[m].endereco;

        // Verifica se o paciente está ativo
        if (p[i].status == 0) {
            int consultaagendada = busca_consulta_agendada(cs,cod,contconsultas);

            // Verifica se o paciente tem uma consulta agendada
            if (consultaagendada == 0) {
                p[i].status = 1;
                cout << "\n\nPaciente Excluído com Sucesso";
            } else {
                cout << "\nPaciente com Consulta Agendada, Não é Possível Excluir.";
            }
        } else {
            cout << "Paciente já excluído.";
        }
    } else {
        cout << "Código Inválido.";
    }
}*/


void reorganizacaopacientes (struct indicepacientes idx[], struct pacientes p[], int &cont){
    struct pacientes* novopaciente = new pacientes[cont]; //AJUDA DO CHAT DE NOVO
	int j=-1;
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (p[i].status == 0){
            j++;
            novopaciente[j] = p[i];
            idx[j].codigo = novopaciente[j].codigo;
            idx[j].endereco = j;
        }
    }
    cont = j+1;
    for (int k = 0; k < cont; k++){
    	int i = idx[k].endereco;
    	p[k] = novopaciente [i];
	}
}

void exaustiva (struct indicepacientes idx[],struct cidade c[], struct pacientes p[], int cont){
    for (int k=0; k < cont; k++){
        int i = idx[k].endereco;
        if (p[i].status == 0){
        	cout << "\nEnd Fisico: " << i;
            cout << "\nNome: " << p[i].nome;
            cout << "\tEndereco: " << p[i].endereco;
            cout << "\tCidade: " << p[i].codigocidade;
            busca_cidade(c,p[i].codigocidade,cont);
        }
    }
}


struct indicecid{
    int codigo;
    int endereco;
};

struct cid{
    int codigo;
    string descricao;
    int status;
};



void leituraindicecid(struct indicecid idx[],int cont){
    for(int i = 0; i < cont; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}void leituracid(struct cid cd[], int &contadorcid) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nCodigo do CID : ";
        cin >> cd[i].codigo;

        if (cd[i].codigo > 0) {
            bool codigoDuplicado = false;

            for (int j = 0; j < i; j++) {
                if (cd[i].codigo == cd[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }

            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                cout << "Descricao : ";
                cin >> cd[i].descricao;
                cd[i].status = 0;
            }
        } else {
            saida = 0;
        }
    }
    contadorcid = i - 1;
}


int  busca_cid(struct cid cd[],int cod, int &contadorbusca_cid)
{

    int i = 0, f = contadorbusca_cid - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != cd[me].codigo;me = (i+f)/2)
    {
        if(cod > cd[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == cd[me].codigo)
    {
    cout << "Descricao : " <<cd[me].descricao <<endl;
    return 1;
    }
    return 0;
}

struct indicemedicamentos{
    int codigo;
    int endereco;
};

struct medicamentos{
    int codigo;
    string descricao;
    int quantidade_estoque;
    int quantidade_minima;
    int quantidade_maxima;
    float preco_unitario;
    int status;
};

void leituramedicamento(struct medicamentos md[], int &contadormedicamentos) {
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nCodigo do Medicamento : ";
        cin >> md[i].codigo;

        if (md[i].codigo > 0) {
            bool codigoDuplicado = false;

            for (int j = 0; j < i; j++) {
                if (md[i].codigo == md[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }

            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                cout << "Descricao : ";
                cin >> md[i].descricao;
                cout << "Quantidade em Estoque : ";
                cin >> md[i].quantidade_estoque;
                cout << "Quantidade Minima : ";
                cin >> md[i].quantidade_minima;
                cout << "Quantidade Maxima : ";
                cin >> md[i].quantidade_maxima;
                cout << "Preco Unitario : ";
                cin >> md[i].preco_unitario;
                md[i].status = 0;
            }
        } else {
            saida = 0;
        }
    }
    contadormedicamentos = i - 1;
}


void leituraindicemedicamentos(struct indicemedicamentos idx[],int cont){
    for(int i = 0; i < cont; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}

int  busca_medicamentos(struct medicamentos md[],int cod, int &contadorbusca_medicamentos)
{

    int i = 0, f = contadorbusca_medicamentos - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != md[me].codigo;me = (i+f)/2)
    {
        if(cod > md[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == md[me].codigo)
    {
    cout << "Medicamento : " <<md[me].descricao <<endl;
    return 1;
    }
    return 0;
}

int  busca_medicamentos2(struct medicamentos md[],int cod, int &contador_medicamentos2)
{
    int i = 0, f = contador_medicamentos2 - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != md[me].codigo;me = (i+f)/2)
    {
        if(cod > md[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == md[me].codigo)
    {
    cout << "\nDescricao : " <<md[me].descricao <<endl;
    cout << "Quantidade em Estoque : " <<md[me].quantidade_estoque;
    cout  << "\tQuantidade Minima : " <<md[me].quantidade_minima;
    cout << "\t\tQuantidade Maxima : " <<md[me].quantidade_maxima;
    cout << "\tPreco Unitario : " <<md[me].preco_unitario;
     cout << "\tValor Total em Estoque : " <<md[me].preco_unitario * md[me].quantidade_estoque;

    return 1;
    }
    else{
        cout << "Codigo Invalido !!";
    }
    return 0;
}

int  buscamedicamentosabaixoestoque(struct medicamentos md[],int cod, int &contador_medicamentos3)
{
    int i = 0, f = contador_medicamentos3 - 1;
    int me =(i + f)/2;
    for (;f >= i && cod != md[me].codigo;me = (i+f)/2)
    {
        if(cod > md[me].codigo)
            i = me+1;
        else
             f = me - 1;

    }
    if(cod == md[me].codigo && md[me].quantidade_estoque < md[me].quantidade_minima)
    {
    cout << "\nDescricao : " <<md[me].descricao <<endl;
    cout << "Quantidade em Estoque : " <<md[me].quantidade_estoque;
    cout  << "\tQuantidade Minima : " <<md[me].quantidade_minima;
    cout << "\tQuantidade Maxima : " <<md[me].quantidade_maxima;
    cout << "\tPreco Unitario : " <<md[me].preco_unitario;
    cout << "\tTotal em Estoque : " <<md[me].quantidade_estoque * md[me].preco_unitario;
    cout << "\tQuantidade a ser Comprada : " <<md[me].quantidade_minima - md[me].quantidade_estoque;
    cout << "\tValor Total a ser Comprado : "<<(md[me].quantidade_minima - md[me].quantidade_estoque) * md[me].preco_unitario;

    return 1;
    }
    else{
        cout << "Medicamento com Estoque Normal ! ";
    }
    return 0;
}

void leituramedicamentos2(struct medicamentos md[],int &contadormedicamentos)
{
        int i = 0;
        for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nCodigo do Medicamento a ser Procurado :(0 para sair) ";
        cin >> md[i].codigo;
        if(md[i].codigo >0){
        busca_medicamentos2(md,md[i].codigo,contadormedicamentos);
        }
        else saida = 0;
    }
    contadormedicamentos = i - 1;
}

void medicamentosabaixoestoque(struct medicamentos md[],int &contadormedicamentos3)
{
    int i = 0;
        for (int saida = 1; i < 20 && saida != 0; i++){
        cout << "\n\nCodigo do Medicamento a ser Procurado :(0 para sair) ";
        cin >> md[i].codigo;
        if(md[i].codigo > 0){
        buscamedicamentosabaixoestoque(md,md[i].codigo,contadormedicamentos3);
        }
        else saida = 0;
    }
    contadormedicamentos3 = i - 1;
}



struct indiceconsultas{
    int codigo;
    int endereco;
};

struct consultas{
    int codigo;
    int codigopaciente;
    int codigomedico;
    string data;
    string horario;
    int codigocid;
    int codigomedicamento;
    int quantidademedicamento;
    int confirmacao;
    int status;
};


void leituraconsulta(struct consultas cs[], int &contadorconsultas, struct especialidades e[], struct pacientes p[], int contadorpaciente, struct medicos m[], int contadormedicos, struct cid cd[], int contadorcid, struct medicamentos md[], int contadormedicamentos, struct cidade c[], float &totalMedicamentos) {
    int i = 0;
    float valortotalmedicamento = 0;
    totalMedicamentos = 0;
    int consultaconfirmada = 0;

    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nCodigo da Consulta : ";
        cin >> cs[i].codigo;

        if (cs[i].codigo > 0) {
            bool codigoDuplicado = false;

            for (int j = 0; j < i; j++) {
                if (cs[i].codigo == cs[j].codigo) {
                    codigoDuplicado = true;
                    break;
                }
            }

            if (codigoDuplicado) {
                cout << "Codigo ja existente! Tente novamente.\n";
                i--;
            } else {
                bool codigoValido;
                
                
                do {
                    cout << "Codigo do Paciente : ";
                    cin >> cs[i].codigopaciente;
                    codigoValido = busca_paciente(p, c, cs[i].codigopaciente, contadorpaciente);
                    if (!codigoValido) {
                        cout << "Codigo do Paciente nao encontrado! Tente novamente.\n";
                    }
                } while (!codigoValido);

                
                do {
                    cout << "Codigo do Medico : ";
                    cin >> cs[i].codigomedico;
                    codigoValido = busca_medicos(m, e, cs[i].codigomedico, contadormedicos);
                    if (!codigoValido) {
                        cout << "Codigo do Medico nao encontrado! Tente novamente.\n";
                    }
                } while (!codigoValido);

                cout << "\nData da Consulta : ";
                cin >> cs[i].data;

                cout << "Horario : ";
                cin >> cs[i].horario;

                do {
                    cout << "Codigo do CID : ";
                    cin >> cs[i].codigocid;
                    codigoValido = busca_cid(cd, cs[i].codigocid, contadorcid);
                    if (!codigoValido) {
                        cout << "Codigo do CID nao encontrado! Tente novamente.\n";
                    }
                } while (!codigoValido);

                // Código do Medicamento
                do {
                    cout << "Codigo do Medicamento : ";
                    cin >> cs[i].codigomedicamento;
                    codigoValido = busca_medicamentos(md, cs[i].codigomedicamento, contadormedicamentos);
                    if (!codigoValido) {
                        cout << "Codigo do Medicamento nao encontrado! Tente novamente.\n";
                    }
                } while (!codigoValido);

                int indiceMedicamento = -1;
                for (int k = 0; k < contadormedicamentos; k++) {
                    if (md[k].codigo == cs[i].codigomedicamento) {
                        indiceMedicamento = k;
                        break;
                    }
                }

                if (indiceMedicamento != -1) {
                    cout << "Quantidade do Medicamento : ";
                    cin >> cs[i].quantidademedicamento;

                    valortotalmedicamento = cs[i].quantidademedicamento * md[indiceMedicamento].preco_unitario;

                    cout << "Valor total do Medicamento : " << valortotalmedicamento << endl;

                    totalMedicamentos += valortotalmedicamento;

                    if (cs[i].quantidademedicamento <= md[indiceMedicamento].quantidade_estoque) {
                        cout << "Medicamento em Estoque =)" << endl;
                        md[indiceMedicamento].quantidade_estoque -= cs[i].quantidademedicamento;
                        cout << "Quantidade atualizada em estoque: " << md[indiceMedicamento].quantidade_estoque << endl;
                    } else {
                        cout << "Medicamento em Falta " << endl;
                    }
                } else {
                    cout << "Medicamento nao encontrado no sistema!" << endl;
                }

                cout << "Confirmar Consulta ? " << endl;
                cout << "Digite 0 Para Nao :  " << endl;
                cout << "Digite 1 Para Sim : " << endl;
                cin >> cs[i].confirmacao;

                if (cs[i].confirmacao == 0) {
                    cout << "Consulta Nao Confirmada";
                } else {
                    cout << "Consulta Confirmada" << endl;
                    consultaconfirmada++;
                }
                cs[i].status = 0;
            }
        } else {
            saida = 0;
        }
    }
    contadorconsultas = i;
}



void leituraindiceconsultas(struct indiceconsultas idx[],int cont){
    for(int i = 0; i < cont; i++){
        cout << "\nCodigo do Indice : ";
        cin >> idx[i].codigo;
        cout << "Codigo do Endereco : ";
        cin >> idx[i].endereco;
    }
}

int busca_consultas(struct consultas cs[], int cod, int &contadorconsultas, int consultaconfirmada, float totalmedicamentos)
{
    int i = 0, f = contadorconsultas - 1;
    int me = (i + f) / 2;

    for (; f >= i && cod != cs[me].codigo; me = (i + f) / 2)
    {
        if (cod > cs[me].codigo)
            i = me + 1;
        else
            f = me - 1;
    }

    if (cod == cs[me].codigo)
    {
        float valortotalconsultas = consultaconfirmada * 100;
        float valorTotalDiario = valortotalconsultas + totalmedicamentos;

        cout << "Valor Total Diario : " << valorTotalDiario << endl;
        return 1;
    }
    else
    {
        cout << "Codigo Invalido " << endl;
    }
    return 0;
}

//ChatGPT
bool pacienteTemConsultaAgendada(struct consultas cs[], int contadorconsultas, int codigopaciente) {
    int inicio = 0;
    int fim = contadorconsultas - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (cs[meio].codigopaciente == codigopaciente) {
            return true; // Paciente encontrado com consulta agendada
        } else if (cs[meio].codigopaciente < codigopaciente) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false; // Paciente não tem consulta agendada
}

//ChatGPT
void excluirpaciente(struct pacientes p[], int contadorpaciente, struct consultas cs[], int contadorconsultas, int cod) {
    //cout << "Digite o codigo do paciente para exclusao: ";
    //cin >> codigoPaciente;

    // Primeiro, verificar se o paciente tem consultas agendadas
    bool temConsulta = pacienteTemConsultaAgendada(cs, contadorconsultas,cod);

    if (temConsulta) {
        cout << "Paciente com consultas agendadas nao pode ser excluido!" << endl;
        return;
    }

    // Busca binária para encontrar o paciente no array de pacientes
    int inicio = 0;
    int fim = contadorpaciente - 1;
    int meio;
    bool pacienteEncontrado = false;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (p[meio].codigo == cod) {
            pacienteEncontrado = true;
            break;
        } else if (p[meio].codigo < cod) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (pacienteEncontrado) {
        // Exclui o paciente logicamente, ou seja, altera o status
        p[meio].status = -1; // Define status como excluído
        cout << "Paciente excluido com sucesso." << endl;
    } else {
        cout << "Paciente nao encontrado!" << endl;
    }
}

bool medicoTemConsultaAgendada(struct consultas cs[], int contadorconsultas, int codMedico) {
    int inicio = 0;
    int fim = contadorconsultas - 1;
    int meio;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (cs[meio].codigomedico == codMedico) {
            return true; // Médico encontrado com consulta agendada
        } else if (cs[meio].codigomedico < codMedico) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return false; // Médico não tem consulta agendada
}


void excluirMedico(struct medicos m[], int &contadormedicos, struct consultas cs[], int contadorconsultas, int cod) {
    //cout << "Digite o codigo do medico para exclusao: ";
    //cin >> codigoMedico;

    // Primeiro, verificar se o médico tem consultas agendadas
    bool temConsulta = medicoTemConsultaAgendada(cs, contadorconsultas, cod);

    if (temConsulta) {
        cout << "Medico com consultas agendadas nao pode ser excluido!" << endl;
        return;
    }

    // Busca binária para encontrar o médico no array de médicos
    int inicio = 0;
    int fim = contadormedicos - 1;
    int meio;
    bool medicoEncontrado = false;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (m[meio].codigo == cod) {
            medicoEncontrado = true;
            break;
        } else if (m[meio].codigo < cod) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    if (medicoEncontrado) {
        // Exclui o médico logicamente, ou seja, altera o status
        m[meio].status = -1; // Define status como excluído
        cout << "Medico excluido com sucesso." << endl;
    } else {
        cout << "Medico nao encontrado!" << endl;
    }
}



/*int busca_consulta_agendada(struct consultas cs[], int codpaciente, int contadorconsultas) {
    int i = 0, f = contadorconsultas - 1;
    int me;

    // Busca binária para encontrar a primeira consulta do paciente
    while (i <= f) {
        me = (i + f) / 2;

        if (codpaciente == cs[me].codigopaciente) {
            // Encontrou um paciente, agora verifica se ele tem consultas confirmadas
            // Verifica as consultas ao redor para garantir que todas sejam checadas
            int found = 0;

            // Verifica para trás (caso o paciente tenha múltiplas consultas)
            for (int j = me; j >= 0 && cs[j].codigopaciente == codpaciente; j--) {
                if (cs[j].confirmacao == 1) {
                    found = 1;
                    break;
                }
            }

            // Verifica para frente (caso o paciente tenha múltiplas consultas)
            for (int j = me + 1; j < contadorconsultas && cs[j].codigopaciente == codpaciente; j++) {
                if (cs[j].confirmacao == 1) {
                    found = 1;
                    break;
                }
            }

            return found;
        } else if (codpaciente > cs[me].codigopaciente) {
            i = me + 1;
        } else {
            f = me - 1;
        }
    }

    // Paciente não encontrado na lista de consultas
    return 0;
}*/



/*void excluirpaciente(struct indicepacientes idx[], struct pacientes p[], int &cont, int cod, struct consultas cs[], int contconsultas) {
    int posicaoPaciente = -1;

    // Busca linear para encontrar o paciente na lista de índices
    for (int j = 0; j < cont; j++) {
        if (idx[j].codigo == cod) {
            posicaoPaciente = j;
            break;
        }
    }

    // Verifica se o paciente foi encontrado
    if (posicaoPaciente != -1) {
        int i = idx[posicaoPaciente].endereco; // Obtém o endereço do paciente na lista de pacientes

        // Verifica se o paciente está ativo (status 0 indica que ele não está excluído)
        if (p[i].status == 0) {
            // Chama a função busca_consulta_agendada para verificar consultas agendadas
            int consultaagendada = busca_consulta_agendada(cs, cod, contconsultas);

            // Verifica se o paciente tem uma consulta agendada confirmada
            if (consultaagendada == 0) {
                p[i].status = 1; // Marca o paciente como excluído
                cout << "\n\nPaciente excluido com sucesso.";
            } else {
                cout << "\nPaciente com consulta agendada confirmada. Nao e possivel excluir.";
            }
        } else {
            cout << "\nPaciente ja esta excluido.";
        }
    } else {
        cout << "\nCódigo invalido. Paciente nao encontrado.";
    }
}*/


/*void excluirpaciente(struct indicepacientes idx[], struct pacientes p[], int &cont, int cod, struct consultas cs[], int contconsultas) {
    int i = 0, f = cont - 1;
    int m;

    // Busca binária para encontrar o paciente no índice de pacientes
    while (f >= i) {
        m = (i + f) / 2;

        if (cod == idx[m].codigo) {
            break;
        } else if (cod > idx[m].codigo) {
            i = m + 1;
        } else {
            f = m - 1;
        }
    }

    // Verifica se o paciente foi encontrado
    if (f >= i && cod == idx[m].codigo) {
        i = idx[m].endereco; // Obtém o endereço do paciente na lista de pacientes

        // Verifica se o paciente está ativo (status 0 indica que ele não está excluído)
        if (p[i].status == 0) {
            // Chama a função busca_consulta_agendada para verificar consultas agendadas
            int consultaagendada = busca_consulta_agendada(cs, cod, contconsultas);

            // Verifica se o paciente tem uma consulta agendada confirmada
            if (consultaagendada == 0) {
                p[i].status = 1; // Marca o paciente como excluído
                cout << "\n\nPaciente excluido com sucesso.";
            } else {
                cout << "\nPaciente com consulta agendada confirmada. Nao e possivel excluir.";
            }
        } else {
            cout << "\nPaciente ja esta excluido.";
        }
    } else {
        cout << "\nCodigo invalido. Paciente nao encontrado.";
    }
}*/




void leituratotalarrecadado(struct consultas cs[], int &consultaconfirmada, int &contadorconsultas, float &totalmedicamentos)
{
    int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++)
    {
        cout << "\n\nDigite 1 Para Verificar o Valor Total Arrecadado em Consultas :(0 para sair) " << endl;
        cin >> cs[i].confirmacao;

        if (cs[i].confirmacao > 0)
        {
            busca_consultas(cs, cs[i].confirmacao, contadorconsultas, consultaconfirmada, totalmedicamentos);
        }
        else
        {
            saida = 0;
        }
    }
    contadorconsultas = i - 1;
}


int main(){

    struct indicecidade id[20];
    struct cidade ci[20];
    int contador;

    struct indiceespecialidades ide[20];
    struct especialidades es[20];
    int contadorespecialidades;
    
    struct indicemedicos idm[20];
    struct medicos me[20];
    int contadormedicos;
    
    struct indicepacientes idp[20];
    struct pacientes pa[20];
    int contadorpaciente;
    
    struct indicecid  idcid[20];
    struct cid cid[20];
    int contadorcid;

    struct indicemedicamentos idmt[20];
    struct medicamentos med[20];
    int contadormedicamentos;
    float totalmedicamentos = 0;
    
    struct indiceconsultas idc[20];
    struct consultas cons[20];
    int contadorconsultas;


    int opcao = 30;
    while (opcao != 0)
    {
        cout << "[1]- Leitura Cidade:" << endl;
        cout << "[2]- Leitura Especialidades:" << endl;
        cout << "[3]- Leitura de Medicos:" << endl;
        cout << "[4]- Leitura de Pacientes:" << endl;
        cout << "[5]- Leitura de CID:" << endl;
        cout << "[6]- Leitura de Medicamentos:" << endl;
        cout << "[7]- Leitura de Consultas:" << endl;
        cout << "[8]- Inclusao de Medicos:" << endl;
        cout << "[9]- Inclusao de Pacientes:" << endl;
        cout << "[10]- Exclusao de Pacientes:" << endl;
        cout << "[11]- Exclusao de Medicos:" << endl;
        cout << "[12]- Consultar Medicamentos:" << endl;
        cout << "[13]- Consultar Medicamentos com Estoque Baixo:" << endl;
        cout << "[14]- Total Diario Arrecadado:" << endl;
        cout << "[15]- Reorganizacao de Pacientes:" << endl;


            cin >> opcao;
            switch(opcao)
            {
            case 1:
            cout << "Dados da Cidade:" << endl;
            leituracidade(ci, contador);
            cout << "\nIndice de Cidade:" << endl;
            leituraindicecidade(id,contador);
            cout << "\n===========================================" << endl;
            break;

            case 2:
            cout << "Especialidades:" << endl;
            leituraespecialidades(es,contadorespecialidades);
            cout << "\nIndice de Especialidades:" << endl;
            leituraindiceespecialidades(ide,contadorespecialidades);
            cout << "\n===========================================" << endl;
            break;
    
            case 3:
            cout << "Medicos:" << endl;
            leituramedicos(me,ci,es,contadormedicos,contador,contadorespecialidades);
            cout << "\nIndice de Medicos:" << endl;
            leituraindicemedicos(idm,contadormedicos);
            cout << "\n===========================================" << endl;
            break;

            case 4:
            cout << "Pacientes:" << endl;
            leiturapacientes(pa,contadorpaciente,ci,contador);
            cout << "\nIndice de Pacientes:" << endl;
            leituraindicepacientes(idp,contadorpaciente);
            cout << "\n===========================================" << endl;
            break;
            
            case 5:
            cout << "CID:" << endl;
            leituracid(cid,contadorcid);
            cout << "\nIndice de CID:" << endl;
            leituraindicecid(idcid,contadorcid);
            cout << "\n===========================================" << endl;
            break;
          
            case 6:
            cout << "Medicamentos:" << endl;
            leituramedicamento(med,contadormedicamentos);
            cout << "\nIndice de Medicamentos:" << endl;
            leituraindicemedicamentos(idmt,contadormedicamentos);
            cout << "\n===========================================" << endl;
            break;
            
            case 7:
            cout << "Marcar Consultas:" << endl;
            leituraconsulta(cons,contadorconsultas,es,pa,contadorpaciente,me,contadormedicos,cid,contadorcid,med,contadormedicamentos,ci,totalmedicamentos);
            cout << "\nIndice de Consultas:" << endl;
            leituraindiceconsultas(idc,contadorconsultas);
            cout << "\n===========================================" << endl;
            break;

            case 8:
            cout << "Inclusao de Medicos !" <<endl;
            for(int codpesq = 9;codpesq !=0;)
            {
                cout << "\nInsira o Codigo a ser Incluido (0 para encerrar):";
                cin >> codpesq;
                if(codpesq !=0)
                buscaaleatoriamedicos(idm,me,es,ci,contadormedicos,codpesq,contadorespecialidades,contador);
                cout << "\n===========================================" << endl;
            }
            break;
            

            case 9:
            cout << "Inclusao de Pacientes !" <<endl;
            for(int codpesq = 9;codpesq !=0;)
            {
                cout << "\nInsira o Codigo a ser Incluido (0 para encerrar):";
                cin >> codpesq;
                if(codpesq !=0)
                buscaaleatoriapacientes(idp,pa,ci,contadorpaciente,codpesq,contador);
                cout << "\n===========================================" << endl;
            }
            break;
            

            case 10:
            cout << "Exclusao de Pacientes !" <<endl;
            for(int codpesq = 9;codpesq !=0;)
            {
                cout << "Informe o Codigo a Ser Excluido :";
                cin >> codpesq;
                if(codpesq !=0)
                excluirpaciente(pa,contadorpaciente,cons,contadorconsultas,codpesq);
                cout << "\n===========================================" << endl;
            }
            break;
            

            case 11:
            cout << "Exclusao de Medicos !" <<endl;
            for(int codpesq = 9;codpesq !=0;)
            {
                cout << "\nInsira o Codigo a ser Excluido (0 para encerrar):";
                cin >> codpesq;
                if(codpesq !=0)
                excluirMedico(me,contadormedicos,cons,contadorconsultas,codpesq);
                cout << "\n===========================================" << endl;
            }
            break;

            case 12:
            cout << "Busca de Medicamentos :";
            leituramedicamentos2(med,contadormedicamentos);
            cout << "\nIndice de Medicamentos:" << endl;
            //leituraindicemedicamentos(idmt,contador);
            cout << "\n===========================================" << endl;
            break;

            case 13:
            cout << "Medicamentos com Estoque Baixo:" << endl;
            medicamentosabaixoestoque(med,contadormedicamentos);
            cout << "\nIndice de Medicamentos:" << endl;
            //leituraindicemedicamentos(idmt,contador);
            cout << "\n===========================================" << endl;
            break;

            case 14:
            cout << "Total Arrecadado" <<endl;
            leituratotalarrecadado(cons,contadorconsultas,contadorconsultas,totalmedicamentos);
            cout << "\n===========================================" << endl;
            break;

            case 15:
            cout << "Reorganizacao de Pacientes:";
            /*for (int codpesq = 9; codpesq != 0;){
            cout << "\n\nInforme o Codigo do Paciente a ser Excluido (0 para Encerrar): ";
            cin >> codpesq;
            if (codpesq != 0)
            excluirpaciente(pa,contadorpaciente,cons,contadorconsultas,codpesq);
            }*/
            cout << "\nLeitura Exaustiva dos Registros Antes da Reorganizacao: ";
            exaustiva(idp,ci,pa,contadorpaciente);
            cout << "\n===========================================" << endl;
        

            reorganizacaopacientes(idp,pa,contadorpaciente);

            cout << "\n\nLeitura Exaustiva dos Registros Depois da Reorganizacao :" <<endl;
            exaustiva(idp,ci,pa,contadorpaciente);
            break;
        }
    }
}