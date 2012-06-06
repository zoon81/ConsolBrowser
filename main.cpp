/*Használat:
Enter billenytyû megnyomása esetén a disk változó felveszi a fájl elérési útvonalát
 fájlok esetén (mappa esetén is csak a végére nem tesz / jelet)
TAB billenytyû megnyomása esetén a listában lévõ elsõ elemet választja ki amenyiben mappa volt megnyitja
 ha file akkor hibát jelez és visszalép a aktuális
könyvtárba
*/

#include <dirent.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
DIR *dp, *dp2;
struct dirent *dirp;
char disk[]="C:\\";
struct dir
    {
    char dirname[100];
    char type ;// 1= mappa 0=fájl
    };

int main()
{
    int dirdb=-1;
    int tmpbool=0;
    char findstring[50];
    struct dir dir[500];
    int selectdir;
    //printf("Meghajto: ");
    //scanf("%c",&disk);
    int fdx=-1;
    char tmp[50];
    int i,j,k;

    if ((dp = opendir(disk)) == NULL)
    {
    printf("Valoszileg egy file");
    getch();
    }

    while ((dirp = readdir(dp)) != NULL){
    dirdb++;
    strcpy(dir[dirdb].dirname,dirp->d_name);
    printf("%s\n",dir[dirdb].dirname);
 // fájl vagy mappa??
    }
char disk2[100];
    for(i=0;i<dirdb;i++)
    {
        strcpy(disk2,disk);
        strcat(disk2,dir[i].dirname);
        strcat(disk2,"\\");
    //printf("\n%s\n",disk2);
    //getch();
        if ((dp2 = opendir(disk2)) == NULL){
        dir[i].type=0;
        }
        else
        dir[i].type=1;
        if(dir[i].type==1){
        //printf("%s\t\t<Dir>\n",dir[i].dirname); //ha meg szeretnéd jeleníteni a mappa név mellet valamit
        }
        else{
        //printf("%s\n",dir[i].dirname);
    }}
    //printf("Keresd: ");
    char l;
    while(1)
    {
    find:;
    printf("\n\n\n%s",disk);
    l=getch();
    if(l == 13)
    {
        strcat(disk,dir[selectdir].dirname);
        printf("\n%s\n",disk);
        getch();
    }
    if (l== 72)
    {
        opendir:;
        for (i=strlen(disk);i>2;i--){
        if(disk[i-2]=='\\'){
        disk[i-1]='\0';
        break;
        }
        }
        system("cls");
        //printf("%s\n",disk);
        //getch();
    goto reopen;
    }
    if(l == 9)
    {

        strcat(disk,dir[selectdir].dirname);
        strcat(disk,"\\");
        system("cls");
        printf("%s\n",disk);
        reopen:;
        if ((dp = opendir(disk)) == NULL)
    {
    printf("Valoszileg egy file");
    getch();
    goto opendir;

        }
    dirdb=-1;
    while ((dirp = readdir(dp)) != NULL){
    dirdb++;
    strcpy(dir[dirdb].dirname,dirp->d_name);
    printf("%s\n",dir[dirdb].dirname);
    }
    //fájl vagy mappa ellenőrzés ismét
    for(i=0;i<dirdb;i++)
    {
        strcpy(disk2,disk);
        strcat(disk2,dir[i].dirname);
        strcat(disk2,"\\");
    //printf("\n%s\n",disk2);
    //getch();
        if ((dp2 = opendir(disk2)) == NULL){
        dir[i].type=0;
        }
        else
        dir[i].type=1;
        if(dir[i].type==1){
        //printf("%s\t\t<Dir>\n",dir[i].dirname); //ha meg szeretnéd jeleníteni a mappa név mellet valamit
        }
        else{
        //printf("%s\n",dir[i].dirname);
    }}
        fdx=-1;
        goto find;
    }
    if(l == 8)
    {
    fdx--;
    }
    else{
        fdx++;
        findstring[fdx]=l;
        }
    system("cls");
    findstring[fdx+1]='\0';

    printf("%s \n",findstring);




//printf("\n%s\n",dir[0].dirname);
for(i=0;i<dirdb+1;i++){
    for(j=0;j<strlen(dir[i].dirname);j++){
        for(k=0;k<fdx+1;k++){
            tmp[k]=dir[i].dirname[j+k];

        }
        tmp[k]='\0';
        //printf("%s %s\n",tmp,findstring);
        if(strcmp(tmp,findstring)==0){

        printf("%s\n",dir[i].dirname);
        if(tmpbool == 0)
        {
        selectdir=i;
        tmpbool=1;
        }
        goto nextword;
    }

    }
nextword:;
}

tmpbool=0;
}
/*Feladatok:
-A megtalált kúlcszót kiemeli a mapa vagy file nevébõl pl háttérszín változtatással
-Ha nem egy mappa a kijelölt elem akkor nem enged belelépni
-Meghajtó betûjelét elkérhetné kezdésként vagy akár közben is megváltortatható
*/
}

