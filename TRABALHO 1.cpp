#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
typedef struct produto{	
	int idprod;
	char nome[20];
	char descricao[40];
	float valor;
	int estoque;	
}Produto;
typedef struct cliente{	
	int idcliente;
	char nome[20];
	char cpf[11]; 	
}Cliente;
typedef struct vendas{	
	int codvenda;
	int codIdprod;
	char cpf[11];
	float valortotal;	
}Venda;
void cadastrarproduto(Produto *p,int numprod){
	p=p+numprod;
	int sair=0;
	system("cls");		
		p->idprod=numprod;	
		printf("\n\tCadastro de Produtos: ");
		printf("\n\n Digite o Nome do produto %d: ",numprod);
		fflush(stdin);
		fgets(p->nome,20,stdin);
		printf("\n Digite a Descricao do produto %d: ",numprod);
		fflush(stdin);
		fgets(p->descricao,40,stdin);
		printf("\n Digite o valor do produto %d: ",numprod);
		scanf("%f",&p->valor);
		printf("\n Digite a quantidade no estoque: ");
		scanf("%d",&p->estoque);
		while(sair==0){
			if((p->estoque>=0)&&(p->estoque<1000)){
		printf("\n\tCadastrado com Sucesso!\n");
		getch();
		sair=1;
			}else if(p->estoque>=1000){
				printf("\nQuantidade Indisponivel para cadastrar no estoque!\n\nDigite uma quantidade validade para o estoque: ");
				scanf("%d",&p->estoque);
			}
		}
}
int buscarprodutonome(Produto *p,int num){	
	int i,k=20;		
	char busca[20];
		printf("\n\nDigite o Nome do produto a ser procurado: ");
		fflush(stdin);
		fgets(busca,20,stdin);
			for(i=0;i<num;i++){
				k=strcmp(busca,p->nome);
				if(k==0){
					return i;
				}
				p++;
			}
		return 99;
}
int buscarprodutoid(Produto *p,int num){	
	int i,k;			
		printf("\nDigite o ID do produto a ser comprado: ");
		while(i==0){
		scanf("%d",&k);
			if(k<num){
				return k;
			}else if(k>=num){
				printf("ID Desconhecido! Digite Novamente o ID: ");
				}
		}
}
int buscarprodutoidalterar(Produto *p,int num){	
	int i=0,k;	
	printf("\nDigite o ID do produto a ser alterado: ");
	while(i==0){
		scanf("%d",&k);
				if(k<num){
					return k;
				}else if(k>=num){
					printf("ID Desconhecido! Digite Novamente o ID: ");
				}	
					
			}	
	
}
void caracproduto(Produto *p, int posicao){	
		system ("cls");			
		p=p+posicao;
			printf("\nProduto %d: ",posicao);		
			printf("\nNome: %s",p->nome);
			printf("Descricao: %s",p->descricao);
			printf("Valor: %.2f \n",p->valor);
			printf("Quantidade no Estoque: %d \n",p->estoque);
			printf("---------------------------------\n");			
}
void alterarproduto(Produto *p,int n){		
	int k,sair=0;
	k = buscarprodutoidalterar(p,n);	
	p=p+k;
		system("cls");
		printf("\nAlterando Produto %d:",p->idprod);	
		printf("\n\nDigite o novo nome do produto: ");
		fflush(stdin);
		fgets(p->nome,20,stdin);
		printf("\nDigite a nova descricao do produto: ");
		fflush(stdin);
		fgets(p->descricao,40,stdin);
		printf("\nDigite o novo valor do produto: ");
		scanf("%f",&p->valor);
		printf("\nDigite a nova quantidade do produto no estoque: ");
		scanf("%d",&p->estoque);
				while(sair==0){
			if((p->estoque>=0)&&(p->estoque<1000)){
		printf("\nAlterado com Sucesso!");
		getch();
		sair=1;
			}else if(p->estoque>=1000){
				printf("\nQuantidade Indisponivel para cadastrar no estoque!\n\nDigite uma quantidade validade para o estoque: ");
				scanf("%d",&p->estoque);
			}
		}
}
void excluirproduto(Produto *p,int num){
	int k,i=0;	
	char nomenull[20]="                 ";
	char descnull[40]="                                    ";	
	printf("\nDigite o ID do produto a ser excluido: ");
	while(i==0){
	scanf("%d",&k);	
		if(k<num){	
			p=p+k;
			strcpy(p->nome,nomenull);
			strcpy(p->descricao,descnull);
			p->valor=0;
			p->estoque=0;
			printf("\nExcluido com Sucesso!");
			getch();
			i=1;
		}else if(k>=num){
			printf("\nID Desconhecido! Digite Novamente o ID: ");
		}
	}
	}

void exibirproduto(Produto *p,int num){		
	int i;
	printf("\nEstoque de Produtos: ");
		for(i=0;i<num;i++){
			printf("\n\tProduto %d: ",p->idprod);	
			printf("\nNome: %s",p->nome);
			printf("Descricao: %s",p->descricao);
			printf("Valor: %.2f",p->valor);
			printf("\nQuantidade no Estoque: %d \n",p->estoque);
			printf("---------------------------------\n");		
			p++;		
		}

}
void cpf(Cliente *c,int numclientes){
			c=c+numclientes;		
			char validarcpf[11];
			int x=0,i,k,sair=1;
	printf("\nDigite o CPF do Cliente: ");
	while(sair==1){	
		scanf("%s",&validarcpf);	
		k=strlen(validarcpf);
		if(k==11){
			for(i=0;i<11;i++){	
				if(isdigit(validarcpf[i])){
					x++;
				}
			}
			if(x==11){
				printf("\nCPF Valido!");
				sair=2;
				strcpy(c->cpf,validarcpf);
			}else if(x<11){
				printf("\nCPF Invalido, Digite novamente: ");
				x=0;
			}
		}else if(k!=11){		
			printf("\nCPF Invalido, Digite novamente: ");	
			}			
	}
}
void cadastrarcliente(Cliente *c,int numclientes){	
	c=c+numclientes;	
	system("cls");
	c->idcliente=numclientes;
	printf("Cadastro do Cliente %d: ",c->idcliente);
	printf("\n\nDigite o Nome do cliente: ");
	fflush(stdin);
	fgets(c->nome,20,stdin);
	c=c-numclientes;
	cpf(c,numclientes);	
}
void alterarcliente(Cliente *c,int num){
	char nome[20];
	int k,i,sair=1,x,cont=0;
	printf("\n\nDigite o ID do cliente que deseja alterar: ");
	while(cont==0){
	scanf("%d",&k);	
		if(k<num){
				c=c+k;
				cont=1;
				system("cls");
				printf("\nAlterando o Cliente %d: ",k);
				printf("\nDigite o novo Nome do cliente: ");
				fflush(stdin);
				fgets(c->nome,20,stdin);
				c=c-k;
				cpf(c,k);			
		}else if(k>=num){
			printf("\nID Invalido! Digite o ID Novamente: ");
		}
}		
		getch();
}		
void exibirclientes(Cliente *c,int n){	
	int i;	
	for(i=0;i<n;i++){		
		printf("\nCliente %d: ", i);
		printf("\nNome: %s",c->nome);
		printf("\nCPF: %s",c->cpf);
		printf("\n---------------------------");		
		c++;
	}
}
void excluircliente(Cliente *c,int n){
	int i=0,num;	
	char nomenull[20]="                  ";
	char cpfnull[11]="          ";
	printf("\n\nDigite o ID do cliente que deseja excluir: ");
	while(i==0){
	scanf("%d",&num);			
			if(num<n){
				 c=c+num;				
				 strcpy(c->nome,nomenull);
				 strcpy(c->cpf,cpfnull);
				 printf("\nCliente Excluido");
				 i=1;
			}else if(num>=n){
				printf("ID Desconhecido! Digite novamente o ID: ");
			}				
	}
	getch();
}
void realizarvendas(Venda *v,Cliente *c,Produto *p,int numvendas,int numprod,int numcliente){
	int i,k=1,sair=0,esse=0,quant=6,idcliente,existe;
	v=v+numvendas;
	v->codvenda=numvendas;
		
		existe=buscarprodutoid(p,numprod);
				
		v->codIdprod=existe;
		system("cls");
		exibirclientes(c,numcliente);			
		printf("\nDigite o ID do cliente que esta efetuando a compra: ");
			while(esse==0){
				scanf("%d",&idcliente);	
				if(idcliente<numcliente){			
					c=c+idcliente;
					esse=1;
					strcpy(v->cpf,c->cpf);
					system("cls");			
					p=p+existe;	
					system("cls");
					printf("Produto: %s\n",p->nome);
					printf("Unidades em Estoque: %d",p->estoque);
					printf("\nValor Unitario: %.2f",p->valor);			
					while(sair==0){
					printf("\n\nQuantos Produtos o Cliente deseja: ");
					scanf("%d",&quant);
							if((quant<=5)&&(quant<=p->estoque)){		
								v->valortotal=(p->valor)*quant;
								printf("O Valor eh: %.2f",v->valortotal);
								printf("\n\n\tVenda Realizada com Sucesso!");
								sair=1;
								p->estoque=p->estoque-quant;	
								getch();		
						}else if(sair==0){	
							printf("\nNao e possível comprar essa quantidade!");
						}
					}
				}if(idcliente>=numcliente){
					printf("\nID Indisponivel! Digite novamente o ID: ");
				}
			}
}
void consultarvendas(Venda *v,int n){	
	system("cls");
	int i;
	for(i=0;i<n;i++){		
		printf("\nVenda %d: ",v->codvenda);
		printf("\nID Produto: %d",v->codIdprod);
		printf("\nCPF do Cliente: %s",v->cpf);
		printf("\nValor Total da venda: %.2f",v->valortotal);
		printf("\n----------------------------");
		v++;
	}
	getch();
}
int main(){
	int opcao=0;
	int i,escolha,verificarbusca=0,numclientes=0,num,numvendas=0,numprod=0;		
	Produto *prod;
	prod = (Produto*)malloc(20*sizeof(Produto));
	Cliente *cliente;
	cliente = (Cliente*)malloc(2*sizeof(Cliente));
	Venda *vendas;
	vendas = (Venda*)malloc(3*sizeof(Venda));		
		while(opcao!=12){					
			printf("\n\tMenu:\n(1) - Inserir produto \n(2) - Buscar produto \n(3) - Alterar produto \n(4) - Excluir produto \n(5) - Exibir estoque \n(6) - Cadastrar Cliente \n(7) - Alterar Cliente \n(8) - Excluir Cliente \n(9) - Exibir Clientes \n(10) - Realizar vendas \n(11) - Consultar vendas \n(12) - Sair\n\n\tOpcao: ");
			scanf("%d",&opcao);
			
				switch(opcao){
					system("cls");
					case 1:	
						if(numprod==20){
							printf("\nNão pode ser cadastrado mais de 20 produtos");
							getch();
							system("cls");
							break;
							}
						cadastrarproduto(prod,numprod);
						system("cls");
						numprod++;
						break;					
					case 2:
						system("cls");				
							verificarbusca=buscarprodutonome(prod,numprod);
						if(verificarbusca==99){	
							printf("Produto nao encontrado!");
							getch();
						}else if(verificarbusca<99){			
							printf("\n Produto encontrado! ");	
							getch();
							caracproduto(prod,verificarbusca);
							getch();
						}
							system("cls");
						break;					
					case 3:
						system("cls");
						exibirproduto(prod,numprod);
						alterarproduto(prod,numprod);
						system("cls");
						break;						
					case 4:
						system("cls");
						exibirproduto(prod,numprod);
						excluirproduto(prod,numprod);
						system("cls");
						break;						
					case 5:
						system("cls");
						exibirproduto(prod,numprod);
						getch();
						system("cls");
						break;						
					case 6:
						system("cls");
						cadastrarcliente(cliente,numclientes);
						numclientes++;
			            system("cls");
						
						break;						
					case 7:
						system("cls");
						exibirclientes(cliente,numclientes);
						alterarcliente(cliente,numclientes);
						system("cls");
						break;						
					case 8:
						system("cls");
						exibirclientes(cliente,numclientes);
						excluircliente(cliente,numclientes);
						system("cls");
						break;						
					case 9:	
						system("cls");
						exibirclientes(cliente,numclientes);
						getch();
						system("cls");
						break;							
					case 10:
						system("cls");
						exibirproduto(prod,numprod);
						realizarvendas(vendas,cliente,prod,numvendas,numprod,numclientes);
						numvendas++;
						system("cls");
						break;								
					case 11:
						system("cls");
						consultarvendas(vendas,numvendas);
						system("cls");
						break;	
					case 12:
								free(prod);
								free(cliente);
								free(vendas);
						break;					
					default:						
						printf("\n Opcao Invalida!");
						getch();
						system("cls");							
				}
		}		
}

