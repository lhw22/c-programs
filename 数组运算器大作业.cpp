#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int n,a[10000000],b[1000000];
//����ҵ��ǣ��������� ��������ȫ�ֱ��� 
//nΪ�������ȫ�ֱ���� 
int ma1=1,ma2,ma3;//��������˵� 
int x,y,am,wi;//x,y��������Ĳ�����am��ʾһ��������wi��ʾ��� 
void swap(int i,int j){
	int t;
	t=a[i];a[i]=a[j];a[j]=t;
}
void inc(int i) {
n+=i;
}
void printarr(){//Ϊ��̷��㣬����ȫ����Сд���ؼ��֣���delete��������������� 
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
	printf("����������Ԫ�ظ���\n");puts("");scanf("%d",&n);puts("");
	printf("������һ�д�ӡԪ�ظ���\n");puts("");scanf("%d",&am);puts("");
	printf("������ÿ��Ԫ�صĴ�ӡ���\n");puts("");scanf("%d",&wi);puts("");
}
void read(){
	int i;
	puts("�������������ֵ"); 
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
void bubblesort(int x){//x���������������Ϊ1������Ϊ0 
	int i,j;
	if (x==1) for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++)if (a[j]>a[j+1]) swap(j+1,j); 
	if (x==0) for(i=0;i<n-1;i++) for(j=0;j<n-i-1;j++)if (a[j+1]>a[j]) swap(j+1,j); 
}
void selectsort(int x){//x���������������Ϊ1������Ϊ0 
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
void exchangesort(int x){//x���������������Ϊ1������Ϊ0 
	int i,j;
	if (x==1) for(i=0;i<n-1;i++) for(j=i+1;j<n;j++)if (a[i]<a[j]) swap(i,j); 
	if (x==0) for(i=0;i<n-1;i++) for(j=i+1;j<n;j++)if (a[i]>a[j]) swap(i,j);
}
int searchs(int val){
	int i;
	for(i=0;i<n;i++) if (a[i]==val) return(i);return(-1);
}
int bisearch(int val){//�����򶼿��� 
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
 	puts("0�� �˳�");
 	puts("1�� ����ϵͳ����");
	puts("2�� ������������");
	puts("3�� ��ʾ����");
	puts("4�� ɾ��");
	puts("5�� ����");
	puts("6�� ͳ��");
	puts("7�� ����");
	puts("8�� �ж�");
	puts("9�� ��������Ԫ��");
	puts("10�����������Ӧ��");
	puts("���Ƚ��в���1�Ͳ���2�ٽ��к�������������10����Ҫ�Ƚ��в���2��");
	puts("����0�����˳���ǰ�˵�"); 
	puts("���������ָ��");	
    puts("");
	scanf("%d",&ma1);puts("");
	if (ma1==1) {
		config();
	}
	if (ma1==2){
	  puts("  1�� ��ָ����Χ��������������");
	  puts("  2�� ��������");
	  puts("  3�� ����������ͬһ��ֵ");
	  puts("  4�� �õȲ�����������飨ע���������е���ʼֵ��ÿ��Ĳ�ֵ��");
	  puts("  ���������ָ��");
	  puts("");
      scanf("%d",&ma2);puts("");
      if (ma2==1) {puts("����������������");puts("");
	    scanf("%d%d",&x,&y);puts("");randomfill(y,x);} 
      if (ma2==2) read();
      if (ma2==3){puts("�������ֵ");puts("");
	    scanf("%d",&x);puts("");fill(x);}
      if (ma2==4){puts("��������ʼֵ�Ͳ�ֵ");puts("");
	    scanf("%d%d",&x,&y);puts("");seqfill(x,y);}
	}
	if (ma1==3) printarr();
	if (ma1==4){
	  puts("  1�� ɾ��ָ���±��Ԫ��");
	  puts("  2�� ɾ��ָ��ֵ��Ԫ��");
	  puts("  3�� ɾ����ָ���±������һ��Ԫ��");
	  puts("  ���������ָ��");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("�������±�");puts("");scanf("%d",&x);puts("");deletes(x);} 
      if (ma2==2) {puts("�������ֵ");puts("");scanf("%d",&x);puts("");search(x);
        while (searchs(x)!=-1){deletes(search(x));}
	  }
      if (ma2==3){puts("�������������½�");puts("");
	    scanf("%d%d",&x,&y);puts("");deleterange(x,y);}  	
	}
	if (ma1==5){
	  puts("  1����ָ���±�λ�ò�����Ԫ��");
	  puts("  2�������������в�����Ԫ��");	
	  puts("  ���������ָ��");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("�������±�͸�Ԫ��");puts("");
	    scanf("%d%d",&x,&y);puts("");insert(x,y);} 
      if (ma2==2) {puts("�������ֵ");puts("");
	    scanf("%d",&x);puts("");orderinsert(x);}
	}
	if (ma1==6){
	  puts("  1�������ֵ");
	  puts("  2������Сֵ");
	  puts("  3����ƽ��ֵ");
	  puts("  4���󷽲�;�����");
	  puts("  ���������ָ��");puts("");
      scanf("%d",&ma2);puts("");
      if (ma2==1)printf("���ֵ��%d\n",max());
      if (ma2==2)printf("��Сֵ��%d\n",min());
	  if (ma2==3)printf("ƽ��ֵ��%.2f\n",average());
	  if (ma2==4)printf("����ͱ�׼��ֱ���%.2f %.2f\n",variation(),deviation()); 
	}
	if (ma1==7){
	  puts("  1����ͨ����");
	  puts("  2�����ֲ��ң�ע�����뱣֤�����������������������");
	  puts("  ���������ָ��");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {puts("�������ֵ");puts("");scanf("%d",&x);puts("");
		if (search(x)!=-1) printf("��Ԫ�ص��±�Ϊ%d\n",search(x));
		  else puts("��Ԫ�ز�����");} 
      if (ma2==2) {puts("�������ֵ");puts("");
	    scanf("%d",&x);puts("");printf("��Ԫ�ص��±�Ϊ%d\n",bisearch(x));}	
	}
	if (ma1==8){
	  puts("  1���Ƿ���������");
	  puts("  2���Ƿ�������");
	  puts("  3���Ƿ�ȫ�����");
	  puts("  ���������ָ��");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1){if (isasc())puts("��");else puts("��");}
	  if (ma2==2){if (isdesc())puts("��");else puts("��");}
	  if (ma2==3){if (isequal())puts("��");else puts("��");}
	}
	if (ma1==9){
	  puts("  1����������");
	  puts("  2����������");
	  puts("  3����������");
	  puts("  4����������");
	  puts("  5����������");
	  puts("  ���������ָ��");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1){puts("    1.ð�ݷ� 2.ѡ�� 3.������");puts("");
	    scanf("%d",&ma3);puts("");
		if (ma3==1) bubblesort(1);
		if (ma3==2) selectsort(1);
		if (ma3==3) exchangesort(1); 
	  }
	  if (ma2==2){puts("    1.ð�ݷ� 2.ѡ�� 3.������");puts("");
	    scanf("%d",&ma3);puts("");
		if (ma3==1) bubblesort(0);
		if (ma3==2) selectsort(0);
		if (ma3==3) exchangesort(0);
	  }
	  if (ma2==3) reverse();
	  if (ma2==4){puts("����������");puts("");scanf("%d",&x);puts("");leftrotate(x);}
	  if (ma2==5){puts("����������");puts("");scanf("%d",&x);puts("");rightrotate(x);}
	}
	if (ma1==10){
	  puts("  1��Լɪ��");
	  puts("  2��ɸ��������");
	  puts("  ���������ָ��");puts("");
	  scanf("%d",&ma2);puts("");
	  if (ma2==1) {
	  	puts("�������������ͱ������");puts("");scanf("%d%d",&n,&x);puts("");
		 fill(0);josephus(x);printf("Ӧ������%d\n",search(n)+1);puts(""); 
	  }
	  if (ma2==2) {puts("����������������");puts("");scanf("%d%d",&x,&y);puts("");
	  screen(x,y);puts("�������Ѵ������飬����к�������"); 
	  }
	} 
	} 	
}
