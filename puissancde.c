#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define HORIZON_TAB 29
#define VERTICAL_TAB 13
#define SPACE_MORE 3

#define DIMENSION_VERT 6
#define DIMENSION_HOR 7

void ft_putchar(char c)
{
    write(1,&c,1);
}
char initStr(char *str, int size)
{
    int i = 0;

    while(i < size - 1)
    {
        str[i] = '0';
        i++;
        str[i+1] = '\0';
    }
    return *str;
}
void init_str_str(char str[DIMENSION_VERT][DIMENSION_HOR])
{
    int i = 0;
    int y = 0;

    while(y < DIMENSION_VERT)
    {
        while(i < DIMENSION_HOR )
        {
            str[y][i] = '0';
            str[y][i+1] = '\0';
            i++;
        }
        i = 0;
        y++;
    }
}
int ft_strlen(char *str)
{
    int i= 0;

    while(str[i] != '\0')
        i++;
    return i;
}
void ft_putnbr(int nbr)
{
    int i = 0;

    if(nbr < 0)
    {
        ft_putchar('-');
        nbr *= (-1);
    }
    if(nbr > 10)
    {
        ft_putnbr(nbr/10);
        nbr %= 10;
    }
    if(nbr < 10)
    {
        ft_putchar(nbr + '0');
    }
}
void ft_putstr(char *str)
{
    int i=0;

    while(str[i] != '\0')
    {
        write(1,&str[i],1);
        i++;
    }

}
int ft_atoi(char *nb_str)
{
    int i = 0;
    double nb = 0;
    int sum = 1;

    while(nb_str[i] == '\n' || nb_str[i] == '\t' || nb_str[i] == '\r' || nb_str[i] == '\f' || nb_str[i] == ' ')
        i++;
    if(nb_str[i] == '-')
        sum *= (-1);
    while(nb_str[i] != '\0')
    {
        nb = sum * nb + nb_str[i] - '0';
        
        if(nb_str[i+1] != '\0')
            nb *= 10;
        i++;
        sum = 1;
    }
    return nb;
}
char ft_gets(char *tab, size_t max)
{
    char lt = 'a';
    int i = 0;

    initStr(tab, max);
    while(lt != '\n')
    {
        lt = getchar();
        if(lt == '\n')
            break;
        tab[i] = lt;
        i++;
        
        if((i + 1) == ft_strlen(tab))
        { ft_putstr("désoler mais vous avez introduit tro de caractère"); break;}
    }
    tab[i] = '\0';

    return *tab;
}
void swap_str(char *str, char *lstr)
{
    int i = 0;
    while(*str && i < strlen(lstr))
    {
        str[i] = lstr[i];
        i++;
    }
}
void affiche_number_puissance()
{
    int chiffres = 1;
    int counter = 0;

    for(int inc = 0; inc < 2 ; inc++)
    {
        ft_putchar(' ');  
    }
    while(chiffres <= 7)
    {
        if((counter%3)== 0)
        {
            ft_putnbr(chiffres);
            chiffres++;
        }
        ft_putchar(' ');
        counter++;

    }
    ft_putchar('\n');
}
int affiche(char tab[DIMENSION_VERT][DIMENSION_HOR])
{
    int i = 0;
    int y = 0;
    int z = 0;

    int a = 0;
    int b = 0;

    ft_putstr("\n\n");
    affiche_number_puissance();

    while(y < VERTICAL_TAB)
    {
        if( (y+1)%2 == 1)
        {
            while(i <= (HORIZON_TAB - 1))
            {
                ft_putchar('+');
                i++;

                while(z <= (SPACE_MORE-1) && i <= (HORIZON_TAB - 1))
                {
                    ft_putchar('-');
                    i++;
                    z++;
                }
                z = 0;
            }
            ft_putchar('\n');
        }
        else
        {
            while(i <= (HORIZON_TAB - 1))
            {
                ft_putchar('|');
                i++;

                while(z <= (SPACE_MORE - 1) && i <= (HORIZON_TAB - 1))
                {
                    if(z == 1 && (tab[b][a] =='o' || tab[b][a] =='x') )
                    {
                        ft_putchar(tab[b][a]);
                        a++;
                    }
                    else if(z == 1)
                    {
                        ft_putchar(' ');
                        a++;
                    }
                    else
                        ft_putchar(' ');
                    i++;
                    z++;
                }
                z = 0;
            }
            a=0;
            b++;
            ft_putchar('\n');   
        }
        i = 0;
        y++;
        
    }

    affiche_number_puissance();
    
}
int tableau_put(int pos,char lt, char tab[DIMENSION_VERT][DIMENSION_HOR])
{
    int i = 0;
    int y = DIMENSION_VERT - 1;

    int counter = 0;

    while(i < DIMENSION_HOR)
    {
        if(pos == i + 1  && tab[y][i] != 'o' && tab[y][i] != 'x')
        {
            tab[y][i] = lt;
            counter = 1;
        }
        else if(pos == i +1  && (tab[y][i] == 'o' || tab[y][i] == 'x') && y >= 0)
        {
            y--;
            i = 0;
            continue;
        }
        else if(counter == 1)
            return 0;
        i++;
    }
    return 1;
}

void affiche_tab_tab(char tab[DIMENSION_VERT][DIMENSION_HOR])
{
    int i = 0;
    int y = 0;

    while(y < DIMENSION_VERT)
    {
        while(i < DIMENSION_HOR)
        {
            ft_putchar(tab[y][i]);
            i++;
        }
        ft_putchar('\n');
        i=0;
        y++;
    }
}
int analyse_win(char tab[DIMENSION_VERT][DIMENSION_HOR], char lt)
{
    int i = 0;
    int y = 0;


    while(y < DIMENSION_VERT)
    {
        while(i < DIMENSION_HOR)
        {
            if(tab[y][i] == lt && tab[y][i+1] == lt && tab[y][i+2] == lt && tab[y][i+3] == lt)
                return 1;
            if(tab[y][i] == lt && tab[y+1][i] == lt && tab[y+2][i] == lt && tab[y+3][i] == lt)
                return 1;
            if(tab[y][i] == lt && tab[y+1][i+1] == lt && tab[y+2][i+2] == lt && tab[y+3][i+3] == lt)
                return 1;
            if(tab[y][i] == lt && tab[y-1][i+1] == lt && tab[y-2][i+2] == lt && tab[y-3][i+3] == lt)
                return 1;
            i++;
        }
        i=0;
        y++;
    }
    return 0;
}
void file_save(FILE *fp, char tab[DIMENSION_VERT][DIMENSION_HOR]){

    int i = 0;
    int y = 0;

    while(y < DIMENSION_VERT)
    {
        while(i < DIMENSION_HOR)
        {
            if(fputc(tab[y][i], fp) == EOF)
            {
                ft_putstr("L'enregistrement c'est mal passé");
                break;
            }
            i++;
        }
        if(fputc('\n', fp) == EOF)
        {
            ft_putstr("L'enregistrement c'est mal passé");
            break;
        }
        i = 0;
        
        y++;
        
    }
}
int file_recup(FILE *fp, char tab[DIMENSION_VERT][DIMENSION_HOR])
{
    int i = 0;
    int y = 0;
    int z = 0;
    

    char lt;

    while(y <= DIMENSION_VERT)
    {
        while(i <= DIMENSION_HOR)
        {

            lt = fgetc(fp);
            if(lt == EOF)
            {
                ft_putstr("Le chargement de la sauvegarde c'est bien passé ..\n");      
                return 1;
            }
            else if(lt == '\n' )
            {
                y++;
                i = 0;
                continue;
            }
            tab[y][i] = lt;
            i++;
        }
        y++;
    }
    return 0;
}
int algo_ia(char tab[DIMENSION_VERT][DIMENSION_HOR], char lt,int compteur[DIMENSION_HOR])
{
    int i = 0;
    int y = 0;
    int z = 0; // z est égale aux calculs

    

    while(y < DIMENSION_VERT)
    {
        while(tab[y][i] != '\0')
        {
            if(tab[y][i] == '0' && tab[y-1][i] != '0')
            {
                while(tab[y][i+z] == lt)
                {
                    z++;
                    if(tab[y][i+z] != lt)
                    {
                        z = 0;
                        while(tab[y][i-z])
                        {
                            z++;
                            if(z > compteur[i])
                            {
                                compteur[i] = z;
                            }
                        }
                    }
                    if(z > compteur[i])
                    {
                        compteur[i] = z;
                    }
                }
                z = 0;

                while(tab[y+z][i] == lt)
                {
                    z++;

                    if(z > compteur[i])
                    {
                        compteur[i] = z;
                    }
                }
                z = 0;

                while(tab[y+z][i+z] == lt)
                {
                    z++;

                    if(z > compteur[i])
                    {
                        compteur[i] = z;
                    }
                }
                z = 0;

                while(tab[y+z][i-z] == lt)
                {
                    z++;

                    if(z > compteur[i])
                    {
                        compteur[i] = z;
                    }
                }
                z = 0;
            }

            i++;
        }
        i = 0;
        y++;
    }

    return *(compteur); // directement a retourner dans la fonction choisis
}

static double nb_aleatoire(void)
{
    return rand() / (RAND_MAX + 1.);
}

static int nb_aleatoire_entre(int min, int max)
{
    return nb_aleatoire() * (max - min + 1) + min;
}

int choisis(int compteur[DIMENSION_HOR],int *allocation)//attention cette fontion alloue un tableau il sera nécessaire de le désactiver avant la fermeture du programme
{
    int i = 0;
    int y = 0;

    int control = 0;

    int max = 0;

    allocation = malloc(sizeof(int) * 1);

    while(i <= sizeof(int[DIMENSION_HOR]) / sizeof(int))
    {
        if(compteur[i] >= max)
        {
            allocation[control] = compteur[i];
            control++;
            allocation = realloc(allocation, sizeof(int) * control + 1);
        }
        i++;
    }
    max = nb_aleatoire_entre(0, control);

    return max;
}

int main(int argc, char **argv)
{
    int i = 0;
    char tab[DIMENSION_VERT][DIMENSION_HOR];
    int win = 0;
    char str[5];
    int selection;
    int counter = 0;
    char lt = 'x';
    int player = 0;

    int *allocation;// variable devant servir pour l'allocation

    int save = 0;

    int nb = 0;

    int compteur[DIMENSION_HOR];

    int computer_choice;
    
    FILE *fp = fopen("save.txt","r+");

    
    init_str_str(tab);
    ft_putstr("Bienvenue dans notre jeu de puissance 4 ..\n");
    ft_putstr("Voulez-vous jouer une partie 1 ou 2 joueurs (1:2) :");
    ft_gets(str,1);
    nb = ft_atoi(str);
    initStr(str, 4);
    ft_putchar('\n');


    ft_putstr("Voulez vous charger la sauvegarde ?\n");
    ft_gets(str, 5);
    ft_putchar('\n');
    ft_putchar('\n');
    ft_putchar('\n');

    if(str[0] == 'y' || str[0] == 'Y')
    {
        ft_putstr("Ok votre partie est en cours de chargement ..\n\n\n\n");
        file_recup(fp,tab);
    }

    initStr(str,5);

    if(fp == NULL)
    {
        ft_putstr("\nErreur lors du chargement de la dernière sauvegarde..\n");
    }

    
    while(analyse_win(tab, lt) == 0)
    {
        if((player%2)==0)
            lt = 'x';
        else
            lt = 'o';
        affiche(tab);
        
        ft_putstr("\nVeuillez introduire votre case joueur ");
        ft_putchar(lt);
        ft_putstr(" : ");

        if((player%2)!=0 )
        {
            ft_gets(str, 5);
            selection = ft_atoi(str);
        }
        else if(nb == 1)
        {
            algo_ia(tab,lt,compteur);
            selection = choisis(compteur, allocation);
        }
        else{
            ft_gets(str, 5);
            selection = ft_atoi(str);
        }

        if(selection > 7 || selection < 1)
        {
            ft_putstr("veuillez rentrer une valeur entre 0 et 7 \n");
            ft_putstr("Ou voulez vous sortir de la partie maintenant (y ou n) ?");
            ft_gets(str, 5);
            ft_putchar('\n');
            ft_putchar('\n');
            ft_putchar('\n');

            if(str[0] == 'y' || str[0] == 'Y')
            {
                ft_putstr("Ok cotre partie est enregistrée et vous aurez la possibilité de la reprendre prochaines fois que vous lancer ce jeu\n");
                file_save(fp, tab);
                save = 1;
                break;
            }
            continue;
        }
        if(1 == (tableau_put(selection,lt,tab)))
            ft_putstr("erreur entrée d'un jeton\n");
        player++;
    }

    lt -= 32;

    if(save == 0)
    {
        affiche(tab);
        ft_putstr("\n\n\n============BIEN JOUER JOUEUR ");
        ft_putchar(lt);
        ft_putstr(" VOUS AVEZ GAGNÉ============\n\n\n");
    }

    if(fclose(fp) == EOF)
    {
        ft_putstr("Erreur los de la fermture des flux entre le fichier et le programme PUISSANCE_4_V2");
    }

   free(allocation);

    return 0;

}