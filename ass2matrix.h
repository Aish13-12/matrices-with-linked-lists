struct matrixnode
{
	int data;
	struct matrixnode* nxtr;
	struct matrixnode* nxtc;
};

struct matrixnode* Array[10000];
int H=0;
int arr[10000];
int h=0; 

void creatematrix1();
void displaymatrix();
void detsq();
void detsym();
int readarray(char *str;);
int analyinpu(int i);
void appendr(struct matrixnode **head1,int data);	
struct matrixnode*createrow(int r,int n);
struct matrixnode *creatematrix(int m,int n);
void display(struct matrixnode**head1,int m,int n);

int readarray(char *str)
{
	FILE*fp;
	int i=0;
	
	
	fp=fopen(str,"r");
	while(fscanf(fp,"%d",arr+i)==1)
	{
		i++;
		fscanf(fp,",");
	}
	fclose(fp);
	return i;
}	

int analyinpu(int i)
{
	int j,l,pr=1;
	l=(int)(i/2);
	for(j=2;j<=l;j++)
	{
		if(i%j==0)
		{
			pr=0;
			break;
		}
		
	}
	if(pr==1)
	printf("The number of elements given to create this matrix is invalid since its a prime number");
	else 
	{
		int m,n;
		printf("Enter the number of rows:\n");
		scanf("%d",&m);
		
		
		if(m<=0)
		{
			printf("Invalid input\n");
			return 0;
		}	
		
		
		else
		{
			printf("Enter the number of columns:\n");
			scanf("%d",&n);
			if(n<=0)
			{
				printf("Invalid input\n");
				return 0;
			}	
			
			
			else
			{
				if(m*n==i)
				return m;
				else
				printf("%d elements cannot be made into a %d * %d matrix\n",i,m,n);
				return 0;
			}
		}
	}
				
	
}	

void appendr(struct matrixnode **head1,int data)
{
	struct matrixnode*temp;
	temp=(struct matrixnode*)malloc(sizeof(struct matrixnode));
	temp->data=data;
	temp->nxtr=NULL;
	temp->nxtc=NULL;
	if(*head1==NULL)
	*head1=temp;
	else
	{
		struct matrixnode*p=*head1;
		while(p->nxtc!=NULL)
		p=p->nxtc;
		p->nxtc=temp;
	}
}

struct matrixnode*createrow(int r,int n)
{
	struct matrixnode*temp=NULL;
	int i,j,k;
	j=(r-1)*n;
	k=r*n;
	for(i=j;i<k;i++)
	{
		appendr(&temp,arr[i]);
	}
	return temp;
}

struct matrixnode *creatematrix(int m,int n)
{
	struct matrixnode*head1=NULL;
	
	int i,r;
	if(m==1)
	{
		for(i=0;i<n;i++)
		{
			appendr(&head1,arr[i]);
		}
		return head1;
	}		
	
	
	else 
	{
		for(i=0;i<n;i++)
		{
			appendr(&head1,arr[i]);
		}		
		struct matrixnode*p=head1;
		struct matrixnode*q=head1;
		
		for(r=2;r<m+1;r++)
		{
			struct matrixnode*o;
			o=createrow(r,n);
			while(p!=NULL)
			{
				p->nxtr=o;
				p=p->nxtc;
				o=o->nxtc;
			}	 
			q=q->nxtr;
			p=q;
		}
		return head1;
	}
		
	
}					
	 	
void display(struct matrixnode**head1,int m,int n)
{
	struct matrixnode*pr=*head1;
	struct matrixnode*pc=*head1;
	int r,c;
	
	for(r=0;r<m;r++)
	{
		pc=pr;
		for(c=0;c<n;c++)
		{
			
			printf(" %d ",pc->data);
			pc=pc->nxtc;
		}
		printf("\n");
		pr=pr->nxtr;
	}
	
}			
			
void creatematrix1()
{
	char* str[128];
	
	int j,k;
	printf("Enter the file name from which you want the matrix to be created:\n");
	scanf("%s",str);
	strcat(str,".dat");
	
	j=readarray(str);
	printf("The number of elements to be converted into a matrix are %d.\n",j);
	k=analyinpu(j);
	if(k==0)
	exit(EXIT_FAILURE);
	else
	{
		Array[H]=creatematrix(k,j/k);
		printf("A matrix with id %d has been created.\n",H+1);
		H++;
	}
}		
		
void displaymatrix()
{
	int j,m,n;
	m=0;
	n=0;
	printf("\nEnter matrix id\n");
	scanf("%d",&j);
	struct matrixnode*pr,*pc;
	pr=Array[j-1];
	pc=Array[j-1];
	while(pr!=NULL)
	{
		m++;
		pr=pr->nxtr;
	}
	while(pc!=NULL)
	{
		n++;
		pc=pc->nxtc;
	}
	display(&Array[j-1],m,n);
}		
		
void detsq()
{
	int j,m,n;
	m=0;
	n=0;
	printf("Enter the molecule id\n");
	scanf("%d",&j);
	struct matrixnode*pr,*pc;
	pr=Array[j-1];
	pc=Array[j-1];
	while(pr!=NULL)
	{
		m++;
		pr=pr->nxtr;
	}
	while(pc!=NULL)
	{
		n++;
		pc=pc->nxtc;
	}	
	if(m==n)
	printf("The selected matrix is a square matrix\n");
	else
	printf("The selected matrix is not a square matrix\n");
}		
		
	
void detsym()
{
	int j,m,n;
	m=0;
	n=0;
	printf("Enter the molecule id\n");
	scanf("%d",&j);
	struct matrixnode*pr,*pc;
	pr=Array[j-1];
	pc=Array[j-1];
	while(pr!=NULL)
	{
		m++;
		pr=pr->nxtr;
	}
	while(pc!=NULL)
	{
		n++;
		pc=pc->nxtc;
	}	
	if(m==n)
	{
		struct matrixnode*rp,*cp;
		struct matrixnode*r,*c;
		rp=Array[j-1];
		cp=Array[j-1];
		int d,f;
		for(d=1;d<n;d++)
		{
			rp=rp->nxtr;
			cp=cp->nxtc;
			c=rp;
			r=cp;
			
			for(f=0;f<d;f++)
			{
				if(c->data==r->data)
				{
					c=c->nxtc;
					r=r->nxtr;
				}
				else
				break;
			}
			if(f==d)
			continue;
			else
			break;
		}
		if(d==n)
		printf("The selected matrix is symmetric\n");
		else
		printf("The selected matrix is not  symmetric\n");
		
	}
	else
	printf("The selected matrix is not symmetric");
}	
		
int compatornot(struct matrixnode*head1,struct matrixnode*head2)
{
	struct matrixnode*p1;
	struct matrixnode*p2;
	int i=0;
	int j=0;
	p1=head1;
	p2=head2;
	while(p1!=NULL)
	{
		i++;
		p1=p1->nxtc;
	}	
	while(p2!=NULL)
	{
		j++;
		p2=p2->nxtr;
	}
	if(i==j)
	return i;
	else 
	{
		printf("The selected matrices cannot be multiplied\n");
		return 0;
	}
		
}					
			
struct matrixnode* multiplyrc(int r,int c,struct matrixnode*head1,struct matrixnode*head2)
{
	int i,j,p=0;
	struct matrixnode*p1=head1;
	struct matrixnode*p2=head2;
	for(i=0;i<r-1;i++)
	p1=p1->nxtr;
	for(j=0;j<c-1;j++)
	p2=p2->nxtc;
	while(p1!=NULL)
	{
		p=p+(p1->data*p2->data);
		p1=p1->nxtc;
		p2=p2->nxtr;
	}
	struct matrixnode*temp;
	temp=(struct matrixnode*)malloc(sizeof(struct matrixnode));
	temp->data=p;
	temp->nxtc=NULL;
	temp->nxtr=NULL;
	return temp;
}		
		
struct matrixnode* crrowmult(int r,int nc2,struct matrixnode*head1,struct matrixnode*head2)
{
	struct matrixnode*i1;
	struct matrixnode*i2;
	int g;
	i1=multiplyrc(r,1,head1,head2);
    i2=i1; 
	for(g=2;g<nc2+1;g++)
	{
		i2->nxtc=multiplyrc(r,g,head1,head2);
		i2=i2->nxtc;
	}
	return i1;	
}

	
struct matrixnode* createmultiply(int nr1,int nc2,struct matrixnode*head1,struct matrixnode*head2)
{
	struct matrixnode*o1;
	struct matrixnode*o2;
	struct matrixnode*o3=crrowmult(1,nc2,head1,head2);
	struct matrixnode*o4;
	int u;
	o1=o3;
	for(u=2;u<nr1+1;u++)
	{
		o2=crrowmult(u,nc2,head1,head2);
		o4=o2;
		while(o1!=NULL)
		{
			o1->nxtr=o2;
			o1=o1->nxtc;
			o2=o2->nxtc;
		}
		o1=o4;
	}
	return o3;		
}

void multiply1()
{
	int d,s;
	int q;
	printf("The multiplcation is of the form A*B\n");
	printf("Enter the matrix id of the matrix corresponding to A\n");
	scanf("%d",&d);
	printf("Enter the matrix id of the matrix corresponding to B\n");
	scanf("%d",&s);
	struct matrixnode*head1=Array[d-1];
	struct matrixnode*head2=Array[s-1];
	q=compatornot(head1,head2);
	if(q==0)
	exit(EXIT_FAILURE);
	else
	{
		struct matrixnode*p1=head1;
		struct matrixnode*p2=head2;
		
		int r=0,c=0;
		while(p1!=NULL)
		{
			r++;
			p1=p1->nxtr;
		}
		while(p2!=NULL)
		{
			c++;
			p2=p2->nxtc;
		}
		Array[H]=createmultiply(r,c,head1,head2);
		
		printf("The resultant matrix has an id %d\n",H+1);
		H++;
		FILE *fp;
		char str[128];
		printf("Enter the file name into which the output matrix will be stored\n");
		scanf("%s",&str);
	    
		fp=fopen(str,"w");
		struct matrixnode*o1=Array[H-1];
		struct matrixnode*o2=Array[H-1];
		int k,l;
		while(o1!=NULL)
		{
			k++;
			o1=o1->nxtr;
		}
		while(o2!=NULL)
		{
			l++;
			o2=o2->nxtc;
		}
		int y,z;
		o1=Array[H-1];
		o2=Array[H-1];
		for(y=0;y<k;y++)
		{
			o1=o2;
			for(z=0;z<l;z++)
			{
				fprintf(fp," %d ",o1->data);
				o1=o1->nxtc;
			}
			fprintf(fp,"\n");
			o2=o2->nxtr;			
		}
		fclose(fp);
		
		
	}
}		
				
	
			
			
			
			

			
			
			
				
				
			
			
		
		
					
			
				
					
				
				
					
				
				
				
		
		
					
	
			
			
		
		
		
			
				
	
		
		
