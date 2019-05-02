#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void print_array(int tab [],int n)
{
    int i=0;

    for(i=0;i<n;i++)
    {
        printf("%d | ",tab[i]);
    }
        printf("\n");
}


// -------------------------------      TRI INSERTION      -------------------------------------
int tri_insertion(int tab [], int n)
{
    int i=0;
    int v=0;
    int j=0;
    int stock=0;
   for(i=1;i<n;i++)
    {

        if(tab[i]<tab[i-1])
        {
            j=i-1;
            stock=tab[i];
            while(tab[j]>stock && j>=0)
            {
                tab[j+1]=tab[j];
                j--;
            }
            tab[j+1]=stock;

        }
    }
     return 0;
}



// -------------------------------      TRI A BULLES      -------------------------------------
int tri_bulles(int tab [], int n)
{
    int i=0;
    int v=0;
    int j=0;
    int stock=0;
   for(i=1;i<n;i++)
    {
        if(tab[i]<tab[i-1])
        {
            stock=tab[i];
            tab[i]=tab[i-1];
            tab[i-1]=stock;
            i=0;

        }
    }
    return 0;
}




// -------------------------------      TRI FUSION      -------------------------------------
int * concat(int arr [], int nbr ,int j,int n)
{
    int tab2[n+1];
    int i=0;
    if(j==1)
    {
        tab2[0]=nbr;
    for(i=1;i<n+1;i++)
    {
        tab2[i]=arr[i-1];
        j++;
    }
    return tab2;
    }
    else if(j==2)
    {
    for(i=0;i<n-1;i++)
    {
        tab2[i]=arr[i];
    }
        tab2[n]=j;
        return tab2;
    }
    return tab2;
}

void fusion(int tab[],int l,int m, int r)
{  int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int tab1[n1], tab2[n2];
    for (i = 0; i < n1; i++)
        tab1[i] = tab[l + i];
    for (j = 0; j < n2; j++)
        tab2[j] = tab[m + 1+ j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (tab1[i] <= tab2[j])
        { tab[k] = tab1[i];
            i++;
        }
        else
        {
            tab[k] = tab2[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        tab[k] = tab1[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        tab[k] = tab2[j];
        j++;
        k++;
    }

}


void tri_fusion(int tab[],int debut,int fin)
{
    if (debut < fin)
    {
        int i = debut+(fin-debut)/2;

        tri_fusion(tab, debut, i);
        tri_fusion(tab, i+1, fin);
        fusion(tab, debut, i, fin);
    }
}


// ------------------------------   TRI RAPIDE  --------------------------------------------
void inverser(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partitionner(int T[], int premier , int dernier)
   {
    int pivot = T[dernier];
    int i = (premier - 1);

    for (int j = premier; j <= dernier-1; j++)
    {
        if (T[j] <= pivot)
        {
            i++;
            inverser(&T[i], &T[j]);
        }
    }
    inverser(&T[i + 1], &T[dernier]);
    return (i + 1);
    }
int tri_rapide(int T[], int premier, int dernier)
    {
       if(premier < dernier)
         {
             int pivot;
            pivot = partitionner(T, premier, dernier);
            tri_rapide(T, premier, pivot-1);
            tri_rapide(T, pivot+1, dernier);
        }

    }
// ---------------------------------------------- TRI PAR TAS ------------------------------------
void tamiser(int T[],int n,int noeud)
{
    int l = 2*noeud + 1;
    int r = 2*noeud + 2;
    int max = noeud;
    if (l < n && T[l] > T[max])
       { max = l; }


    if (r < n && T[r] > T[max])
        {max = r; }

    if (max != noeud)
    {
        inverser(&T[noeud], &T[max]);
        tamiser(T, n, max);
    }
}

void tri_par_tas(int T[],int n)
{
    int i,j;
    for(i=n/2;i>=0;i--)
    {
        tamiser(T,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        inverser(&T[i],&T[0]);
        tamiser(T,i,0);
    }
}

void test(int n)
{
    printf("<--------------------- TAILLE TABLEAU : %d---------------------->\n",n);
	clock_t start,end;
    time_t t;
    srand((unsigned) time(&t));
	double time;
    int tab[n];
    int i=0;
    for(i=0;i<n;i++)
    {

        tab[i]=rand()%n;
    }
    print_array(tab,n);
    start=clock();
    tri_insertion(tab,n);
    end = clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("TRI INSERTION  : %fs\n");
    print_array(tab,n);
    printf("\n");


    for(i=0;i<n;i++)
    {

        tab[i]=rand()%n;
    }
    print_array(tab,n);
    start=clock();
    tri_bulles(tab,n);
    end = clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("TRI BULLES  : %fs\n");
    print_array(tab,n);
    printf("\n");


    for(i=0;i<n;i++)
    {

        tab[i]=rand()%n;
    }
    print_array(tab,n);
    start=clock();
    tri_fusion(tab,0,n-1);
    end = clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("TRI FUSION  : %fs\n");
    print_array(tab,n);
    printf("\n");

    for(i=0;i<n;i++)
    {
        tab[i]=rand()%n;
    }
    print_array(tab,n);
    start=clock();
    tri_rapide(tab,0,n-1);
    end = clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("TRI RAPIDE  : %fs\n");
    print_array(tab,n);
    printf("\n");

    for(i=0;i<n;i++)
    {

        tab[i]=rand()%n;
    }
    print_array(tab,n);
    start=clock();
    tri_par_tas(tab,n);
    end = clock();
    time=(double)(end-start)/CLOCKS_PER_SEC;
    printf("TRI TAS  : %fs\n");
        print_array(tab,n);
        printf("\n");
}

int main()
{

    	double n[12];
	n[0]=pow(10,6)+3;
	n[1]=pow(10,6)*2+3;
	n[2]=pow(10,6)*4+37;
	n[3]=pow(10,6)*8+9;
	n[4]=pow(10,6)*16+57;
	n[5]=pow(10,6)*32+11;
	n[6]=pow(10,6)*64+31;
	n[7]=pow(10,6)*128+3;
	n[8]=pow(10,6)*256+1;
	n[9]=pow(10,6)*512+9;
	n[10]=pow(10,6)*1024+9;
	n[11]=pow(10,6)*2048+11;

    int i=0;
    for(i=0;i<12;i++)
    {
        test((int)n[i]);
    }

    return 0;
}
