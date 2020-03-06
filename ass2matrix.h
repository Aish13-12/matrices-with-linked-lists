//THIS FILE IS SAVED IN A .h FORMAT .THIS WILL BE INCLUDED IN testas.2c as a heaader file

struct matrixnode//Defining a node
{
	int data;
	struct matrixnode* nxtr;
	struct matrixnode* nxtc;
};

struct matrixnode* Array[10000];//Array for storing the addresses of the created matrices
int H=0;//Keeps count of the number of matrices created
int arr[10000];//Stores the numbers resd from the file
int h=0; //Keeps count on the number of numbers stored in the array


void creatematrix1();
void displaymatrix();
void detsq();
void detsym();
void multiply1();

int readarray(char *str;);
int analyinpu(int i);
void appendr(struct matrixnode **head1,int data);	
struct matrixnode*createrow(int r,int n);
struct matrixnode *creatematrix(int m,int n);
void display(struct matrixnode**head1,int m,int n);

//Function to read numbers from a file into an array
int readarray(char *str)
{
	FILE*fp;
	int i=0;
	
	
	fp=fopen(str,"r");//Opening the chosen file in read formaat
	while(fscanf(fp,"%d",arr+i)==1)//Scanning the numbers into the array
	{
		i++;
		fscanf(fp,",");
	}
	fclose(fp);//Closing the file
	return i;//Returning the number of numbers in the file
}	

//Function to determine the number of rows and columns of a matrix
int analyinpu(int i)//Here i is the number of numbers read from the file
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
				if(m*n==i)//Only if the number of rows and columns entered multiply to give the number of numbers
				return m;
				else
				printf("%d elements cannot be made into a %d * %d matrix\n",i,m,n);
				return 0;
			}
		}
	
				
	
}	

//Function to add a node at the end of a row in the matrix
void appendr(struct matrixnode **head1,int data)//Giving the head of each row to add the elements
{
	struct matrixnode*temp;
	temp=(struct matrixnode*)malloc(sizeof(struct matrixnode));//Allocating memory to store data
	temp->data=data;
	temp->nxtr=NULL;
	temp->nxtc=NULL;
	if(*head1==NULL)
	*head1=temp;
	else
	{
		struct matrixnode*p=*head1;
		while(p->nxtc!=NULL)//Traversing to the end of the row
		p=p->nxtc;
		p->nxtc=temp;
	}
}

//Function to create a row in the matrix
struct matrixnode*createrow(int r,int n)//r is the rth row which we want to create and n is the number of columns
{
	struct matrixnode*temp=NULL;
	int i,j,k;
	j=(r-1)*n;
	k=r*n;
	for(i=j;i<k;i++)
	{
		appendr(&temp,arr[i]);//Taking the corresponding elements from the array
	}
	return temp;//returning the head of the row
}

//Function to create a matrix given the number of rows and columns

struct matrixnode *creatematrix(int m,int n)//m is the number of rows and n is the number of columns
{
	struct matrixnode*head1=NULL;//Creating a head
	
	int i,r;
	if(m==1)//If the number of rows is 1
	{
		for(i=0;i<n;i++)
		{
			appendr(&head1,arr[i]);
		}
		return head1;
	}		
	
	
	else 
	{
		for(i=0;i<n;i++)//Creating the first row
		{
			appendr(&head1,arr[i]);
		}		
		struct matrixnode*p=head1;
		struct matrixnode*q=head1;
		
		for(r=2;r<m+1;r++)
		{
			struct matrixnode*o;
			o=createrow(r,n);//Creating the rows starting from the second row
			while(p!=NULL)
			{
				//establishing connection between adjacent rows
				p->nxtr=o;
				p=p->nxtc;
				o=o->nxtc;
			}	 
			q=q->nxtr;
			p=q;
		}
		return head1;//returns of the head of the matrix
	}
		
	
}	

//Functions to display the matrix given its address and the number of columns and rows				
	 	
void display(struct matrixnode**head1,int m,int n)//m is the number of rows and n is the number of columns
{
	struct matrixnode*pr=*head1;
	struct matrixnode*pc=*head1;
	int r,c;
	
	for(r=0;r<m;r++)
	{
		pc=pr;
		for(c=0;c<n;c++)
		{
			
			printf(" %d ",pc->data);//Traversing through the columns
			pc=pc->nxtc;
		}
		printf("\n");
		pr=pr->nxtr;//Moving to the next row
	}
	
}			

//Final function to create a matrix			
void creatematrix1()
{
	char* str[128];
	
	int j,k;
	printf("Enter the file name from which you want the matrix to be created:\n");
	scanf("%s",str);//Taking the file name from which the matrix has to be created from the user
	strcat(str,".dat");
	
	j=readarray(str);//Reading the data into the array
	printf("The number of elements to be converted into a matrix are %d.\n",j);
	k=analyinpu(j);//Taking the number of rows and columns from the user(This function returns the number of rows as entered by the user)
	if(k==0)
	exit(EXIT_FAILURE);
	else
	{
		Array[H]=creatematrix(k,j/k);//Creating the matrix and storing the address in the array
		printf("A matrix with id %d has been created.\n",H+1);
		H++;
	}
}		

//Final function to display a matrix
		
void displaymatrix()
{
	int j,m,n;
	m=0;
	n=0;
	printf("\nEnter matrix id\n");
	scanf("%d",&j);//Taking the matrix id
	struct matrixnode*pr,*pc;
	pr=Array[j-1];//Obtaining the matrix id from the array
	pc=Array[j-1];
	while(pr!=NULL)//Finding  the number of rows
	{
		m++;
		pr=pr->nxtr;
	}
	while(pc!=NULL)//Number of columns
	{
		n++;
		pc=pc->nxtc;
	}
	display(&Array[j-1],m,n);//Using the display function defined above 
}
		
//Function to determine whether a matrix is square or not		
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
	while(pr!=NULL)//m is the number of rows
	{
		m++;
		pr=pr->nxtr;
	}
	while(pc!=NULL)//n is the number of columns
	{
		n++;
		pc=pc->nxtc;
	}	
	if(m==n)
	printf("The selected matrix is a square matrix\n");
	else
	printf("The selected matrix is not a square matrix\n");
}		
		
//Function to determine whether a matrix is symmetric or not	
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
	if(m==n)//If it is a square matrix
	{
		struct matrixnode*rp,*cp;
		struct matrixnode*r,*c;
		rp=Array[j-1];//to traverse along the rows
		cp=Array[j-1];//to traverse along the columns
		int d,f;
		for(d=1;d<n;d++)
		{
			rp=rp->nxtr;
			cp=cp->nxtc;
			c=rp;
			r=cp;
			
			for(f=0;f<d;f++)
			{
				if(c->data==r->data)//Comparing the data in the corresponding positions
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
		if(d==n)//If the integers in the wanted places are equal
		printf("The selected matrix is symmetric\n");
		else
		printf("The selected matrix is not  symmetric\n");
		
	}
	else//If the matrix is not square
	printf("The selected matrix is not symmetric");
}	

//Function to determine whether two matrices are compatable for multiplication or not		
int compatornot(struct matrixnode*head1,struct matrixnode*head2)//In the order of head1*head2
{
	struct matrixnode*p1;
	struct matrixnode*p2;
	int i=0;
	int j=0;
	p1=head1;
	p2=head2;
	while(p1!=NULL)//Number of columns of  head1
	{
		i++;
		p1=p1->nxtc;
	}	
	while(p2!=NULL)//Number of rows of head2
	{
		j++;
		p2=p2->nxtr;
	}
	if(i==j)//If they are equal return that common value
	return i;
	else 
	{
		printf("The selected matrices cannot be multiplied\n");
		return 0;
	}
		
}
//Function to multiply rth row from head1 and cth column in head2					
			
struct matrixnode* multiplyrc(int r,int c,struct matrixnode*head1,struct matrixnode*head2)
{
	int i,j,p=0;
	struct matrixnode*p1=head1;
	struct matrixnode*p2=head2;
	for(i=0;i<r-1;i++)
	p1=p1->nxtr;//Reaching that row
	for(j=0;j<c-1;j++)
	p2=p2->nxtc;//Reaching that column
	while(p1!=NULL)
	{
		p=p+(p1->data*p2->data);//Multiplying the coressponding data
		p1=p1->nxtc;
		p2=p2->nxtr;
	}
	struct matrixnode*temp;
	temp=(struct matrixnode*)malloc(sizeof(struct matrixnode));
	temp->data=p;//Storing the data in the new node
	temp->nxtc=NULL;
	temp->nxtr=NULL;
	return temp;//Returning the address of the node
}
		
//Creating the rth row of the matrix (obtained after multiplication)		
struct matrixnode* crrowmult(int r,int nc2,struct matrixnode*head1,struct matrixnode*head2)//nc2 is the number of columns in head2(head1*head2)
{
	struct matrixnode*i1;
	struct matrixnode*i2;
	int g;
	i1=multiplyrc(r,1,head1,head2);//Creating the first node of the row
    i2=i1; 
	for(g=2;g<nc2+1;g++)
	{
		i2->nxtc=multiplyrc(r,g,head1,head2);//Attaching the rest of the nodes to the first node
		i2=i2->nxtc;
	}
	return i1;//Returning the address of the first node	
}

//Multiplying two matrices given number of rows in head1 and columns in head2	
struct matrixnode* createmultiply(int nr1,int nc2,struct matrixnode*head1,struct matrixnode*head2)
{
	struct matrixnode*o1;
	struct matrixnode*o2;
	struct matrixnode*o3=crrowmult(1,nc2,head1,head2);//Storing the head value of first row
	struct matrixnode*o4;
	int u;
	o1=o3;
	for(u=2;u<nr1+1;u++)
	{
		o2=crrowmult(u,nc2,head1,head2);//Creating the next rows
		o4=o2;
		while(o1!=NULL)
		{
			o1->nxtr=o2;//Linking the adjacent rows
			o1=o1->nxtc;
			o2=o2->nxtc;
		}
		o1=o4;
	}
	return o3;	//returning the head of the matrix obtained after multiplication	
}

//Final function to multiply two matrices

void multiply1()
{
	int d,s;
	int q;
	printf("The multiplcation is of the form A*B\n");
	printf("Enter the matrix id of the matrix corresponding to A\n");
	scanf("%d",&d);//Taking the id of matrix corresponding to A
	printf("Enter the matrix id of the matrix corresponding to B\n");
	scanf("%d",&s);//Taking the id of matrix corresponding to B
	struct matrixnode*head1=Array[d-1];//Address of A
	struct matrixnode*head2=Array[s-1];//Address of B
	q=compatornot(head1,head2);//Finding whether they can be multiplied or not
	if(q==0)
	exit(EXIT_FAILURE);
	else
	{
		struct matrixnode*p1=head1;
		struct matrixnode*p2=head2;
		
		int r=0,c=0;
		while(p1!=NULL)//Number of rows of A
		{
			r++;
			p1=p1->nxtr;
		}
		while(p2!=NULL)//Number of columns of B
		{
			c++;
			p2=p2->nxtc;
		}
		Array[H]=createmultiply(r,c,head1,head2);//creating a matrix using the above function and saving the address of the function in the array
		
		printf("The resultant matrix has an id %d\n",H+1);
		H++;
		FILE *fp;
		char str[128];
		printf("Enter the file name into which the output matrix will be stored\n");
		scanf("%s",&str);//Taking the file name into which the matrix would be stored
	    
		fp=fopen(str,"w");//Opening the file to write
		struct matrixnode*o1=Array[H-1];
		struct matrixnode*o2=Array[H-1];
		int k,l;
		while(o1!=NULL)//Number of rows of the new matrix
		{
			k++;
			o1=o1->nxtr;
		}
		while(o2!=NULL)//Number of columns of the new matrix
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
				fprintf(fp," %d ",o1->data);//Printing the data in a row the file
				o1=o1->nxtc;
			}
			fprintf(fp,"\n");//Moving to the next row
			o2=o2->nxtr;			
		}
		fclose(fp);//Closing the file
		
		
	}
}		
				
	
			
			
			
			

			
			
			
				
				
			
			
		
		
					
			
				
					
				
				
					
				
				
				
		
		
					
	
			
			
		
		
		
			
				
	
		
		
