#include "outil3.h"

int estNum(char c) {
 if (c<='9' && c>='0')
  return 1;
 else
  return 0;
}
float conv_float(const char *str) {
 while (*str && !(estNum(*str) || ((*str == '-' || *str == '+') && estNum(*(str + 1)))))
  str++;
 return strtof(str, NULL);
}
struct Reponse recuperer_json(char indice[]) {   
 FILE    *infile;
 char name[100];
 strcpy(name,"data/");
 strcat(name,indice);
 strcat(name,".json");
 infile = fopen(name, "r");
 char **tab_rep;
 char str[1000];
 int i =0;
 int j = 0;
 char ch;
 tab_rep = (char**)malloc(500*(1000*sizeof(char)));
 while ((ch = fgetc(infile)) != EOF) {
  if (ch!=',') {
   str[i++]= ch;
  } else {
   tab_rep[j] =(char*) malloc(strlen(str)*sizeof(char));
   memcpy(tab_rep[j++],str,strlen(str));
   i = 0;
   memset(str,0,strlen(str));}}
 struct Reponse r;
 long int ftwl=0, ftwh=0;
 float rmp=0, tady=0;
 for(int i=0;i<j;i++) {
  if (strstr(tab_rep[i],"\"fiftyTwoWeekLow\":")!=0) {
   ftwl = (long int)((conv_float(tab_rep[i]))*1000);
   } else if (strstr(tab_rep[i],"\"fiftyTwoWeekHigh\":")!=0) {
    ftwh = (long int)((conv_float(tab_rep[i]))*1000);
   } else if (strstr(tab_rep[i],"\"regularMarketPrice\":")!=0) {
    rmp = conv_float(tab_rep[i]);
   } else if (strstr(tab_rep[i],"\"trailingAnnualDividendYield\":")!=0) {
    tady = conv_float(tab_rep[i])*100;} }
 r.indice =indice;
 float cx = 1- ((float)(ftwh-(long int)(rmp*1000))/(float)(ftwh-ftwl));
 if (cx<0.25) {
  r.classement="C-1";
 } else if (cx<0.5) { 
  r.classement="C-2";
 } else if( cx<0.75) {
  r.classement="C-3";
 } else {
  r.classement="C-4";}
 if (tady<3) {
  r.classe_dividend="DIV-1";
 } else if (tady<6){
  r.classe_dividend="DIV-2";
 } else {
  r.classe_dividend="DIV-3";
 }
 r.dividend=tady;
 r.prix_marche=rmp;
 r.aff=0;
 free(tab_rep);
 return r;
}
void afficherRep(struct Reponse r) {
 printf ("%s\t",r.indice);
 printf ("%s\t",r.classement);
 printf ("%s\t",r.classe_dividend);
 printf ("%7.2f\t",(int)(r.prix_marche*100)/100.0);
 printf ("%.2f%%\n",(int)(r.dividend*100)/100.0); 
}
void afficher(struct Reponse r, struct stat *s, char *rep[]) { 
 if ((!strcmp(rep[0],"C-5")&&!strcmp(rep[1], "DIV-5")) || !strcmp(rep[1],"DIV-0") || !strcmp(rep[0], "C-0")) {
   if (!strcmp(r.classement, "C-1")) {
    s->c1++; 
   } else if (!strcmp(r.classement, "C-2")) {
  s->c2++;
 } else if (!strcmp(r.classement, "C-3")) {
  s->c3++; 
 }else {
  s->c4++;}  
 if (!strcmp(r.classe_dividend,"DIV-1")){
  s->d1++; 
 }else if (!strcmp(r.classe_dividend,"DIV-2")){
  s->d2++;
 }else {
  s->d3++;}
  if (!strcmp(rep[3], "N")) {
   afficherRep(r); }
  s->cont++;
 } else if (!strcmp(rep[0],"C-1")) {
  if (!strcmp(r.classement,"C-1")) {
   if (!strcmp(r.classe_dividend,"DIV-1"))
   s->d1++; 
   else if (!strcmp(r.classe_dividend,"DIV-2"))
   s->d2++;
   else
   s->d3++;
   if (!strcmp(rep[3], "N")) {
    afficherRep(r);}
   r.aff=1;	
   s->cont++;
   s->c1++; }
 } else if (!strcmp(rep[0], "C-2")) {
   if (!strcmp(r.classement,"C-2")) {
    if (!strcmp(r.classe_dividend,"DIV-1")) {
     s->d1++; 
    } else if (!strcmp(r.classe_dividend,"DIV-2")) {
     s->d2++;
    } else {
     s->d3++; }
    if (!strcmp(rep[3], "N")) {
     afficherRep(r); }
    r.aff=1;
    s->cont++;
    s->c2++; }
   } else if (!strcmp(rep[0], "C-3")) {
    if(!strcmp(r.classement,"C-3")) {
     if (!strcmp(r.classe_dividend,"DIV-1")) {
      s->d1++; 
     } else if (!strcmp(r.classe_dividend,"DIV-2")) {
      s->d2++;
     } else {
      s->d3++; } 
    if (!strcmp(rep[3], "N")) {
     afficherRep(r); }
    r.aff=1;
    s->cont++;
    s->c3++; }
 } else if (!strcmp(rep[0], "C-4")) {
   if (!strcmp(r.classement,"C-4")) {
    if (!strcmp(r.classe_dividend,"DIV-1")) {
     s->d1++; 
    } else if (!strcmp(r.classe_dividend,"DIV-2")) {
     s->d2++;
    } else {
     s->d3++; }
    if (!strcmp(rep[3], "N")){ 
     afficherRep(r); }
    r.aff=1;
    s->cont++;
    s->c4++; }
 }      
 if (!strcmp(rep[1],"DIV-1")) {
  if (!strcmp(r.classe_dividend,"DIV-1")) {
   if (r.aff==0){ 
     s->d1++;
     if (!strcmp(r.classement, "C-1")) {
     s->c1++; 
    } else if (!strcmp(r.classement, "C-2")) {
     s->c2++;
    } else if (!strcmp(r.classement, "C-3")) {
     s->c3++; 
    } else {
     s->c4++; }
    if (!strcmp(rep[3], "N")) {
     afficherRep(r); }
    s->cont++; } }
 } else if (!strcmp(rep[1],"DIV-2")) {
    if (!strcmp(r.classe_dividend,"DIV-2")) { 
    if (r.aff==0){  
     s->d2++;
     if (!strcmp(r.classement, "C-1")) {
     s->c1++; 
    } else if (!strcmp(r.classement, "C-2")) {
     s->c2++;
    } else if (!strcmp(r.classement, "C-3")) {
     s->c3++; 
    } else {
     s->c4++;  }
     if (!strcmp(rep[3], "N")) {
      afficherRep(r); }
     s->cont++; } }
 } else if (!strcmp(rep[1],"DIV-3")) {
    if (!strcmp(r.classe_dividend,"DIV-3")) {
     if (r.aff==0){
      s->d3++;
      if (!strcmp(r.classement, "C-1")) {
       s->c1++; 
      } else if (!strcmp(r.classement, "C-2")) {
       s->c2++;
      } else if (!strcmp(r.classement, "C-3")) {
       s->c3++; 
      } else {
       s->c4++;  }
      if (!strcmp(rep[3], "N")) {
       afficherRep(r); }
      s->cont++; } 
    }
  }

  s->contTotal++;
  }
int cmdline(int nbr, char *args[], char *rep[]) {
 for (int i=1; i<nbr; i++) {
  if (strcmp(args[i], "-c")==0) {
   if (strcmp(args[i+1],"1")==0) {
    rep[0]="C-1";
   } else if (strcmp(args[i+1],"2")==0) { 
    rep[0]="C-2";
   } else if (strcmp(args[i+1],"3")==0) {
    rep[0]="C-3";
   } else if (strcmp(args[i+1],"4")==0) {
    rep[0]="C-4";
   } else if (strcmp(args[i+1],"0")==0) {
    rep[0]="C-0"; } }
  if (strcmp(args[i], "-d")==0) {
   if(strcmp(args[i+1],"1")==0) {
    rep[1]="DIV-1";
   } else if (strcmp(args[i+1],"2")==0) { 
    rep[1]="DIV-2";
   } else if (strcmp(args[i+1],"3")==0) {
    rep[1]="DIV-3";
   } else if (strcmp(args[i+1],"0")==0) {
    rep[1]="DIV-0"; } }
  if (strcmp(args[i], "-s")==0) {
   rep[2]="A"; }
  if (strcmp(args[i], "-t")==0) {
   rep[3]="A"; } }     
 return 1;
}
void afficherStat(struct stat s, char *rep[]) {
 printf("\ninformation de classement des indices\n");
 printf(" C-1 : %d\n",s.c1);
 printf(" C-2 : %d\n",s.c2);
 printf(" C-3 : %d\n",s.c3);
 printf(" C-4 : %d\n",s.c4);
 printf("information par classe de dividende\n");
 printf(" D-1 : %d\n",s.d1);
 printf(" D-2 : %d\n",s.d2);
 printf(" D-3 : %d\n",s.d3);  
 if (!strcmp(rep[2],"A")) {
  printf("\ninformation sommaire\n  nbr indice : %d sur %d\n",s.cont,s.contTotal);
 }
}
