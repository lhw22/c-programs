#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int n,a[10000000],b[1000000];
//´ó×÷Òµ²»Ç£³¶¶à¸öÊı×é £¬ËùÒÔÓÃÈ«¾Ö±äÁ¿ 
//nÎª·½±ãÉè³ÉÈ«¾Ö±äÁ¿£ 
int ma1=1,ma2,ma3;//´ú±íÈı²ã²Ëµ¥ 
int x,y,am,wi;//x,y´ú±íÊäÈëµÄ²ÎÊı£¬am±íÊ¾Ò»ĞĞÊıÁ¿£¬wi±íÊ¾¿í¶È 
void swap(int i,int j){
	int t;
	t=a[i];a[i]=a[j];a[j]=t;
}
void inc(int i) {
n+=i;
}
void printarr(){//Îª±à³Ì·½±ã£¬³ÌĞòÈ«²¿ÓÃĞ¡Ğ´£¬¹Ø¼ü×Ö£¨Èçdelete£©ÓÃÆäËûÃû³ÆÌæ´ú 
    int i;
    for(i=0;i<n;i++){
    	printf("%*d",wi,a[i]); if ((i+1)%am==0)printf("\n");
	}putchar('\n');
}
void fill(int x){
	int i;
	for (i=0;i<n;i++) a[i]=x; 
}
void randomfill(int x,int y){
	int i;
	for (i=0;i<n;i++) a[i]=x+(rand())%(y-x);
}
void seqfill(int x,int y){
	int i;
	a[0]=x;
	for (i=1;i<n;i++) a[i]=a[i-1]+y;
}
void config(){
	printf("ÇëÊäÈëÊı×éÔªËØ¸öÊı\n");puts("");scanf("%d",&n);puts("");
	printf("ÇëÊäÈëÒ»ĞĞ´òÓ¡ÔªËØ¸öÊı\n");puts("");scanf("%d",&am);puts("");
	printf("ÇëÊäÈëÃ¿¸öÔªËØµÄ´òÓ¡¿í¶È\n");puts("");scanf("%d",&wi);puts("");
}
void read(){
	int i;
	puts("ÇëÒÀ´ÎÊäÈë¸÷¸öÖµ"); 
	for(i=0;i<n;i++) scanf("%d",&a[i]);puts("");
}
void reverse(){
	int i;
	for (i=0;i<n>>1;i++) swap(i,n-i-1);
}
void deletes(int id){
	int i;
	for (i=id;i<n-1;i++)a[i]=a[i+1];
	inc(-1);
}
void deleterange(int s,int t){
	int i;
	for (i=s;i<n+s-t-1;i++) a[i]=a[i+t-s+1];
	inc(s-t-1);
}
int search(int val){
	int i;
	for (i=0;i<n;i++) if (a[i]==val) return(i);
	return(-1);
}
int isasc(){
	int i;
	for (i=1;i<n;i++) if(a[i]<a[i-1]) return 0;
	return 1;
}
int isdesc(){
	int i;
	for (i=1;i<n;i++) if(a[i]>a[i-1]) return 0;
	return 1;
}
int isequal(){
	int i;
	for (i=1;i<n;i++) if(a[i]!=a[i-1]) return 0;
	return 1;
}
int max(){
	int i,max1=-2147483646,t;
	for (i=0;i<n;i++) if (a[i]>max1) {
		max1=a[i];t=i;
	}return(max1);
}
int min(){
	int i,min1=2147483647,t;
	for (i=0;i<n;i++) if (a[i]<min1) {
		min1=a[i];t=i;
	}return(min1);
}
float average(){
	int i;
	float sum=0;
	for(i=0;i<n;i++) sum+=a[i];
	return(sum/n);
}
void insert(int pos,int val){
	int i;
	for(i=n;i>pos;i--) a[i]=a[i-1];a[pos]=val;
	inc(1);
}
float orderinsert(int val){
    int i;
	if (isasc())
	 for(i=0;i<n;i++) if(a[i]>val){
	 insert(i,val);break;}
	if (isdesc())
	 for(i=0;i<n;i++) if(a[i]<val){
	  insert(i,val);break;}
}
float variation(){
	float sum=0,ave;
    int i;
	ave=average();
	for(i=0;i<n;i++) sum+=pow(a[i]-ave,2);
	return(sum/n);
}
float deviation(){
	return(sqrt(variation()));
}
void bubblesort(int x){//x´ú±íÉıĞòÓë·ñ£¬ÉıĞòÎª1£¬½µĞòÎª0 
	int i,j;
	if (x==1) for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++)if (a[j]>a[j+1]) swap(j+1,j); 
	if (x==0) for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++)if (a[j+1]>a[j]) swap(j+1,j); 
}
void selectsort(int x){//x´ú±íÉıĞòÓë·ñ£¬ÉıĞòÎª1£¬½µĞòÎª0 
	int i,j,k;
	if (x==1)for(i=0;i<n-1;i++){k=i;
	for(j=i+1;j<n;j++) if (a[k]>a[j]) k=j;
	swap(k,i);
	}
	if (x==0)for(i=0;i<n-1;i++){k=i;
	for(j=i+1;j<n;j++) if (a[k]<a[j]) k=j;
	swap(k,i);
	}
}
void exchangesort(int x){//x´ú±íÉıĞòÓë·ñ£¬ÉıĞòÎª1£¬½µĞòÎª0 
	int i,j;
	if (x==1) for(i=0;i<n-1;i++) for(j=i+1;j<n;j++)if (a[i]<a[j]) swap(i,j); 
	if (x==0) for(i=0;i<n-1;i++) for(j=i+1;j<n;j++)if (a[i]>a[j]) swap(i,j);
}
int searchs(int val){
	int i;
	for(i=0;i<n;i++) if (a[i]==val) return(i);return(-1);
}
int bisearch(int val){//ÉıĞò½µĞò¶¼¿ÉÒÔ 
	int l=0,r=n-1,mid=(n-1)>>1;
	if (isasc){
	while (l<r) {
		if (a[mid]==val) return(mid);
		if (a[mid]>val){r=mid-1;mid=(l+r)>>1;}
		else {l=mid;mid=(l+r>>1);}
		}return(-1);
   }
	if (isdesc){
	while (l<r) {
		if (a[mid]==val) return(mid);
		if (a[mid]<val){r=mid-1;mid=(l+r)>>1;}
		else {l=mid;mid=(l+r>>1);}
		}return(-1);
   }
}
int leftrotate(int m){
	int i;
	for (i=0;i<m;i++) a[i+n]=a[i];
	n+=m;
	deleterange(0,m-1); 
}
int rightrotate(int m){
	leftrotate(n-m);
}
void josephus(int x){
    int i=0,pos,k=0;
  	for (pos=0;k<n;pos=(pos+1)%n){
  		if (a[pos]==0)i++;if (i==x){
  			i=0;k++;a[pos]=k;
		  }
	  }
}
void screen(int x,int y){

  int i,t;
  for(i=0;i<=y;i++) b[i]=0;  
  for (i=2;i<=y;i++) if (b[i]==0) {
  	t=2*i;while(t<=y) {
	  b[t]=1;t+=i;
  }
 }
  
   n=0;am=10;wi=4;
   for(i=x;i<=y;i++) if(b[i]==0){
   	a[n]=i;n++;
   }	
}
main(){
 while (ma1!=0) {
 	puts("");
 	puts("0¡¢ ÍË³ö");
 	puts("1¡¢ ÅäÖÃÏµÍ³²ÎÊı");
	puts("2¡¢ Éú³ÉÑù±¾Êı¾İ");
	puts("3¡¢ ÏÔÊ¾Êı×é");
	puts("4¡¢ É¾³ı");
	puts("5¡¢ ²åÈë");
	puts("6¡¢ Í³¼Æ");
	puts("7¡¢ ²éÕÒ");
	puts("8¡¢ ÅĞ¶Ï");
	puts("9¡¢ ÅÅÁĞÊı×éÔªËØ");
	puts("10¡¢Êı×éµÄÆäËûÓ¦ÓÃ");
	puts("ÇëÏÈ½øĞĞ²Ù×÷1ºÍ²Ù×÷2ÔÙ½øĞĞºóĞø²Ù×÷£¨²Ù×÷10²»ĞèÒªÏÈ½øĞĞ²Ù×÷2£©");
	puts("ÊäÈë0½«»áÍË³öµ±Ç°²Ëµ¥"); 
	puts("ÇëÊäÈë²Ù×÷Ö¸Áî");	
    puts("");
	scanf("%d",&ma1);puts("");
	if (ma1==1) {
		config();
	}
	if (ma1==2){
	  puts("  1£© ÓÃÖ¸¶¨·¶Î§µÄËæ»úÊıÌî³äÊı×é");
	  puts("  2£© ¼üÅÌÊäÈë");
	  puts("  3£© Õû¸öÊı×éÌîÍ¬Ò»¸öÖµ");
	  puts("  4£© ÓÃµÈ²îĞòÁĞÌî³äÊı×é£¨×¢£ºÊäÈëĞòÁĞµÄÆğÊ¼ÖµºÍÃ¿ÏîµÄ²îÖµ£©");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");
	  puts("");
      scanf("%d",&ma2);puts("");
      if (ma2==1) {puts("ÇëÊäÈëÉÏÏŞÓëÏÂÏŞ");puts("");
	    scanf("%d%d",&x,&y);puts("");randomfill(y,x);} 
      if (ma2==2) read();
      if (ma2==3){puts("ÇëÊäÈë¸ÃÖµ");puts("");
	    scanf("%d",&x);puts("");fill(x);}
      if (ma2==4){puts("ÇëÊäÈëÆğÊ¼ÖµºÍ²îÖµ");puts("");
	    scanf("%d%d",&x,&y);puts("");seqfill(x,y);}
	}
	if (ma1==3) printarr();
	if (ma1==4){
	  puts("  1£© É¾³ıÖ¸¶¨ÏÂ±êµÄÔªËØ");
	  puts("  2£© É¾³ıÖ¸¶¨ÖµµÄÔªËØ");
	  puts("  3£© É¾³ı°´Ö¸¶¨ÏÂ±êÇø¼äµÄÒ»×éÔªËØ");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("ÇëÊäÈëÏÂ±ê");puts("");scanf("%d",&x);puts("");deletes(x);} 
      if (ma2==2) {puts("ÇëÊäÈë¸ÃÖµ");puts("");scanf("%d",&x);puts("");search(x);
        while (searchs(x)!=-1){deletes(search(x));}
	  }
      if (ma2==3){puts("ÇëÊäÈëÇø¼äÉÏÏÂ½ç");puts("");
	    scanf("%d%d",&x,&y);puts("");deleterange(x,y);}  	
	}
	if (ma1==5){
	  puts("  1£©°´Ö¸¶¨ÏÂ±êÎ»ÖÃ²åÈëĞÂÔªËØ");
	  puts("  2£©ÔÚÓĞĞòÊı×éÖĞ²åÈëĞÂÔªËØ");	
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("ÇëÊäÈëÏÂ±êºÍ¸ÃÔªËØ");puts("");
	    scanf("%d%d",&x,&y);puts("");insert(x,y);} 
      if (ma2==2) {puts("ÇëÊäÈë¸ÃÖµ");puts("");
	    scanf("%d",&x);puts("");orderinsert(x);}
	}
	if (ma1==6){
	  puts("  1£©Çó×î´óÖµ");
	  puts("  2£©Çó×îĞ¡Öµ");
	  puts("  3£©ÇóÆ½¾ùÖµ");
	  puts("  4£©Çó·½²îºÍ¾ù·½²î");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
      scanf("%d",&ma2);puts("");
      if (ma2==1)printf("×î´óÖµÊÇ%d\n",max());
      if (ma2==2)printf("×îĞ¡ÖµÊÇ%d\n",min());
	  if (ma2==3)printf("Æ½¾ùÖµÊÇ%.2f\n",average());
	  if (ma2==4)printf("·½²îºÍ±ê×¼²î·Ö±ğÊÇ%.2f %.2f\n",variation(),deviation()); 
	}
	if (ma1==7){
	  puts("  1£©ÆÕÍ¨²éÕÒ");
	  puts("  2£©¶ş·Ö²éÕÒ£¨×¢£º±ØĞë±£Ö¤Êı×éÓĞĞò£¬Èç¹ûÎŞĞòÇëÏÈÅÅĞò£©");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("ÇëÊäÈë¸ÃÖµ");puts("");scanf("%d",&x);puts("");
		if (search(x)!=-1) printf("¸ÃÔªËØµÄÏÂ±êÎª%d\n",search(x));
		  else puts("¸ÃÔªËØ²»´æÔÚ");} 
      if (ma2==2) {puts("ÇëÊäÈë¸ÃÖµ");puts("");
	    scanf("%d",&x);puts("");printf("¸ÃÔªËØµÄÏÂ±êÎª%d\n",bisearch(x));}	
	}
	if (ma1==8){
	  puts("  1£©ÊÇ·ñÉıĞòÅÅÁĞ");
	  puts("  2£©ÊÇ·ñ½µĞòÅÅÁĞ");
	  puts("  3£©ÊÇ·ñÈ«²¿ÏàµÈ");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1){if (isasc())puts("ÊÇ");else puts("·ñ");}
	  if (ma2==2){if (isdesc())puts("ÊÇ");else puts("·ñ");}
	  if (ma2==3){if (isequal())puts("ÊÇ");else puts("·ñ");}
	}
	if (ma1==9){
	  puts("  1£©ÉıĞòÅÅĞò");
	  puts("  2£©½µĞòÅÅĞò");
	  puts("  3£©ÄæÖÃÊı×é");
	  puts("  4£©×óĞıÊı×é");
	  puts("  5£©ÓÒĞıÊı×é");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1){puts("    1.Ã°Åİ·¨ 2.Ñ¡Ôñ·¨ 3.½»»»·¨");puts("");
	    scanf("%d",&ma3);puts("");
		if (ma3==1) bubblesort(1);
		if (ma3==2) selectsort(1);
		if (ma3==3) exchangesort(1); 
	  }
	  if (ma2==2){puts("    1.Ã°Åİ·¨ 2.Ñ¡Ôñ·¨ 3.½»»»·¨");puts("");
	    scanf("%d",&ma3);puts("");
		if (ma3==1) bubblesort(0);
		if (ma3==2) selectsort(0);
		if (ma3==3) exchangesort(0);
	  }
	  if (ma2==3) reverse();
	  if (ma2==4){puts("ÊäÈë×óĞıÊı");puts("");scanf("%d",&x);puts("");leftrotate(x);}
	  if (ma2==5){puts("ÊäÈëÓÒĞıÊı");puts("");scanf("%d",&x);puts("");rightrotate(x);}
	}
	if (ma1==10){
	  puts("  1£©Ô¼Éª·ò»·");
	  puts("  2£©É¸·¨ÇóËØÊı");
	  puts("  ÇëÊäÈë²Ù×÷Ö¸Áî");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {
	  	puts("ÇëÊäÈë×ÜÈËÊıºÍ±¨Êı¼ä¸ô");puts("");scanf("%d%d",&n,&x);puts("");
		 fill(0);josephus(x);printf("Ó¦¸ÃÅÅÔÚ%d\n",search(n)+1);puts(""); 
	  }
	  if (ma2==2) {puts("ÇëÊäÈëËØÊıÉÏÏÂÏŞ");puts("");scanf("%d%d",&x,&y);puts("");
	  screen(x,y);puts("ËØÊı±íÒÑ´æÔÚÊı×é£¬Çë½øĞĞºóĞø²Ù×÷"); 
	  }
	} 
	} 	
}
