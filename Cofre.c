#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct jogo
{
	int lersenha[4];
	int acertos_p;
	int acertos_n;
}jg;

void compara_senha(int *senha, int *senhausuario, int *qtdacertospc, int *qtdacertospe, int dificuldade);
void *sorteia_valores(int *sorteio, int n);
void *ler_senha(int *aposta, int n);

int main()
{
	int n,i,ii,*x,*y,t=0,ta,j,k,saida=0;
	jg *te;
	do{
		system("clear");
		printf("Escolha o numero de dificuldade.\n1-Easy\n2-Hard\n3-Test mode\n");
		scanf("%d",&n);
		printf("Quantas tentativas deseja fazer.\n");
		scanf("%d",&ta);
		system("clear");
		te=(jg *)calloc(ta,sizeof(jg));
		if(te==NULL){
			printf("falta de memoria ram");
			return 0;
		}
		if((n>3)||(n<=0))
			do
			{
				printf("Digite apenas de 1 a 3.\n");
				scanf("%d",&n);
			}while((n>3)||(n<=0));
		switch(n)
		{
			case 1:
				n=3;
				y=sorteia_valores(y,n);
		    	break;	
			case 2:
				n=4;
				y=sorteia_valores(y,n);
		    	break;	
		    case 3:
		   		n=4;
		   		y=sorteia_valores(y,n);
		   		printf("A senha correta é ");
		   		for(i=0;i<n;i++)
		   			printf("%d",*(y+i));
		   		printf("\n");	
		   		break;		
		}
		do
		{
			x=ler_senha(x,n);
			j=0;
			k=0;
			compara_senha(x,y,&j,&k,n);
			(te+t)->acertos_n=j;
			(te+t)->acertos_p=k;				
			for(i=0;i<n;i++)
				(te+t)->lersenha[i]=*(x+i);
			printf("\n%d %d\n\n",j,k);
			t++;
		}while((t!=ta)&&(j!=n));	
		system("clear");
		printf("\ntentativa(as)   numero   resposta");		
		for(i=0;i<t;i++){
			printf("\n     %d        |   ",i+1);
			for(ii=0;ii<n;ii++)
				printf("%d",(te+i)->lersenha[ii]);
			printf("  |   %d %d",(te+i)->acertos_n,(te+i)->acertos_p);
		}	
		if(*y!=*x){
			printf("\nFalied.\nSenha correta é ");
			for(i=0;i<n;i++)
				printf("%d",*(y+i));
			printf("\n");	
		}
		else
			printf(" - Você acertou em %d tentativa(as)\n",i);
		free(te);
		t=0;
		printf("\nDigite:\n'0' para jogar novamente\n'1' para finalizar o jogo.\n");
		scanf("%d",&saida);
		if((saida!=1)&&(saida!=0))
			do{
				printf("Apenas:\n'0'(jogar de novo)\n'1'(finalizar jogo).\n");
				scanf("%d",&saida);
			}while((saida!=1)&&(saida!=0));						
	}while(saida==0);
	system("clear");
}				

void *ler_senha(int *aposta, int n)
{
	int i;
	aposta=(int *)calloc(n,sizeof(int));
	printf("digite a senha \n");
	for(i=0;i<n;i++){ 
        scanf("%d",(aposta+i));
        if((*(aposta+i)>9)||(*(aposta+i)<0))
        	do
		    {
		    	printf("numero digitado de forma incorreta, digite novamente\n");
		    	scanf("%d",(aposta+i));
		    	}while((*(aposta+i)>9)||(*(aposta+i)<0));
        	}
	return aposta;
}	
	

void *sorteia_valores(int *sorteio, int n)
{
	int i,j;
	srand((unsigned)time(NULL));
	sorteio=(int *)calloc(n,sizeof(int));
	for(i=0;i<n;i++) 
        *(sorteio+i)=rand()%10;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i!=j)
				if(*(sorteio+i)==*(sorteio+j))
					do{
						*(sorteio+i)=rand()%10;
					}
					while(*(sorteio+i)==*(sorteio+j));
	return sorteio;
}

void compara_senha(int *senha, int *senhausuario, int *qtdacertospc, int *qtdacertospe, int dificuldade)
{
	int i,ii;
	for(i=0;i<dificuldade;i++)
		if(*(senha+i)==*(senhausuario+i))
			*qtdacertospc+=1;		
	for(i=0;i<dificuldade;i++)
		for(ii=0;ii<dificuldade;ii++)
			if((*(senha+i)==*(senhausuario+ii))&&(i!=ii))
				*qtdacertospe+=1;
}



